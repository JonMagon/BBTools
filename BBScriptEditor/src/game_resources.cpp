#include "game_resources.h"
#include "format.h"
#include <cstring>
#include <stdexcept>

namespace bb
{
namespace
{
#pragma pack(push, 1)

struct DosHeader
{
    char magic[2];
    quint8 reserved[58];
    quint32 peOffset;
};

struct PeHeader
{
    char magic[4];
    quint16 machine, sections;
    quint32 timestamp, symbolTable, symbolCount;
    quint16 optionalSize, characteristics;
};

struct DataDirectory
{
    quint32 address, size;
};

struct OptionalHeader
{
    quint16 magic;
    quint8 linkerMajor, linkerMinor;
    quint32 codeSize, initializedSize, uninitializedSize, entryPoint, codeBase, dataBase, imageBase;
    quint32 sectionAlignment, fileAlignment;
    quint16 osMajor, osMinor, imageMajor, imageMinor, subsystemMajor, subsystemMinor;
    quint32 win32Version, imageSize, headersSize, checksum;
    quint16 subsystem, dllFlags;
    quint32 stackReserve, stackCommit, heapReserve, heapCommit, loaderFlags, directoryCount;
    DataDirectory directories[16];
};

struct Section
{
    char name[8];
    quint32 virtualSize, address, rawSize, rawOffset, relocations, lineNumbers;
    quint16 relocationCount, lineCount;
    quint32 flags;
};

struct ResourceDirectory
{
    quint32 flags, timestamp;
    quint16 major, minor, namedCount, idCount;
};

struct ResourceEntry
{
    quint32 name, child;
};

struct ResourceData
{
    quint32 address, size, codepage, reserved;
};

struct DibHeader
{
    quint32 size;
    qint32 width, height;
    quint16 planes, bitDepth;
    quint32 compression, imageSize;
    qint32 xResolution, yResolution;
    quint32 colorsUsed, importantColors;
};

struct Bgra
{
    quint8 blue, green, red, reserved;
};

struct MfbHeader
{
    char magic[6];
    qint16 width, height, hotspotX, hotspotY, flags, frames;
};

#pragma pack(pop)
static_assert(sizeof(DosHeader) == 64 && sizeof(PeHeader) == 24 && sizeof(OptionalHeader) == 224);
static_assert(sizeof(Section) == 40 && sizeof(ResourceDirectory) == 16 &&
              sizeof(ResourceEntry) == 8);
static_assert(sizeof(ResourceData) == 16 && sizeof(DibHeader) == 40 && sizeof(MfbHeader) == 18);

[[noreturn]] void invalid()
{
    throw std::runtime_error("Invalid game image resource");
}

QByteArray slice(const QByteArray &bytes, qsizetype offset, qsizetype length)
{
    if (offset < 0 || length < 0 || offset > bytes.size() || length > bytes.size() - offset)
    {
        invalid();
    }
    return bytes.mid(offset, length);
}

template <class T> T record(const QByteArray &bytes, qsizetype at)
{
    auto b = slice(bytes, at, sizeof(T));
    T result;
    std::memcpy(&result, b.constData(), sizeof(T));
    return result;
}

QByteArray springBitmap(const QByteArray &exe)
{
    auto dos = record<DosHeader>(exe, 0);
    if (QByteArray(dos.magic, 2) != "MZ")
    {
        invalid();
    }
    qsizetype pe = qFromLittleEndian(dos.peOffset);
    auto header = record<PeHeader>(exe, pe);
    if (QByteArray(header.magic, 4) != QByteArray("PE\0\0", 4))
    {
        invalid();
    }
    auto optional = record<OptionalHeader>(exe, pe + sizeof(PeHeader));
    if (qFromLittleEndian(optional.magic) != 0x10b)
    {
        invalid();
    }
    QList<Section> sections;
    qsizetype sectionStart = pe + sizeof(PeHeader) + qFromLittleEndian(header.optionalSize);
    for (int i = 0; i < qFromLittleEndian(header.sections); ++i)
    {
        sections.append(record<Section>(exe, sectionStart + i * sizeof(Section)));
    }
    auto offset = [&](quint32 address) -> qsizetype
    {
        for (auto &s : sections)
        {
            quint32 start = qFromLittleEndian(s.address),
                    size = qMax(qFromLittleEndian(s.virtualSize), qFromLittleEndian(s.rawSize));
            if (address >= start && address - start < size)
            {
                return qsizetype(qFromLittleEndian(s.rawOffset)) + address - start;
            }
        }
        invalid();
    };
    qsizetype base = offset(qFromLittleEndian(optional.directories[2].address));
    auto entries = [&](qsizetype at)
    {
        auto d = record<ResourceDirectory>(exe, at);
        int n = qFromLittleEndian(d.namedCount) + qFromLittleEndian(d.idCount);
        if (n > 10000)
        {
            invalid();
        }
        QList<ResourceEntry> result;
        for (int i = 0; i < n; ++i)
        {
            result.append(record<ResourceEntry>(exe, at + sizeof(d) + i * sizeof(ResourceEntry)));
        }
        return result;
    };
    for (auto type : entries(base))
    {
        if (qFromLittleEndian(type.name) != 2)
        {
            continue;
        }
        for (auto bitmap : entries(base + (qFromLittleEndian(type.child) & 0x7fffffff)))
        {
            quint32 id = qFromLittleEndian(bitmap.name);
            if (!(id & 0x80000000))
            {
                continue;
            }
            qsizetype at = base + (id & 0x7fffffff);
            auto n = record<quint16>(exe, at);
            n = qFromLittleEndian(n);
            QString name;
            for (int i = 0; i < n; ++i)
            {
                name += QChar(qFromLittleEndian(record<quint16>(exe, at + 2 + i * 2)));
            }
            if (name != "SPRING")
            {
                continue;
            }
            for (auto language : entries(base + (qFromLittleEndian(bitmap.child) & 0x7fffffff)))
            {
                auto data = record<ResourceData>(
                    exe, base + (qFromLittleEndian(language.child) & 0x7fffffff));
                return slice(
                    exe, offset(qFromLittleEndian(data.address)), qFromLittleEndian(data.size));
            }
        }
    }
    invalid();
}
} // namespace

QByteArray readBoxEntry(const QString &archive, const QString &name)
{
    QFile file(archive);
    if (!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error(file.errorString().toStdString());
    }
    if (file.read(3) != "BOX" || !file.seek(8))
    {
        invalid();
    }
    while (file.pos() < file.size())
    {
        auto bytes = file.read(sizeof(BoxEntryDisk));
        if (bytes.size() != sizeof(BoxEntryDisk))
        {
            invalid();
        }
        BoxEntryDisk h;
        std::memcpy(&h, bytes.constData(), sizeof h);
        auto entry = QString::fromLatin1(QByteArray(h.name, sizeof h.name).split('\0').first());
        auto size = qFromLittleEndian(h.size);
        if (size > file.size() - file.pos())
        {
            invalid();
        }
        if (entry.compare(name, Qt::CaseInsensitive) == 0)
        {
            return file.read(size);
        }
        if (!file.seek(file.pos() + size))
        {
            invalid();
        }
    }
    throw std::runtime_error(("Missing archive entry: " + name).toStdString());
}

QMap<int, QIcon> loadTerrainIcons(const QString &directory)
{
    auto dib = springBitmap(readFile(QDir(directory).filePath("beasts.exe")));
    auto d = record<DibHeader>(dib, 0);
    QList<QRgb> palette;
    for (int i = 0; i < 256; ++i)
    {
        auto b = record<Bgra>(dib, qFromLittleEndian(d.size) + i * sizeof(Bgra));
        palette.append(qRgb(b.red, b.green, b.blue));
    }
    auto data = readBoxEntry(QDir(directory).filePath("video.box"), "maptile.mfb");
    auto h = record<MfbHeader>(data, 0);
    if (QByteArray(h.magic, 3) != "MFB")
    {
        invalid();
    }
    int width = qFromLittleEndian(h.width), height = qFromLittleEndian(h.height),
        flags = qFromLittleEndian(h.flags), frames = qFromLittleEndian(h.frames);
    if (width <= 0 || height <= 0 || qint64(width) * height > 10000000 || frames < 0)
    {
        invalid();
    }
    qsizetype at = sizeof(h);
    QMap<int, QIcon> result;
    for (int frame = 0; frame < qMin(frames, 256); ++frame)
    {
        QByteArray pixels;
        if (flags & 2)
        {
            auto count = qFromLittleEndian(record<qint32>(data, at));
            at += sizeof(qint32);
            auto raw = slice(data, at, count);
            at += count;
            if (raw.isEmpty())
            {
                invalid();
            }
            quint8 marker = quint8(raw[0]);
            qsizetype i = 0;
            while (i < raw.size() && pixels.size() < width * height)
            {
                quint8 b = quint8(raw[i++]);
                if (b == marker)
                {
                    if (i >= raw.size())
                    {
                        invalid();
                    }
                    pixels += QByteArray(quint8(raw[i++]), char(marker));
                }
                else
                {
                    pixels += char(b);
                }
            }
            pixels = pixels.leftJustified(width * height, char(marker), true);
        }
        else
        {
            pixels = slice(data, at, width * height);
            at += width * height;
        }
        QImage image(width, height, QImage::Format_Indexed8);
        image.setColorTable(palette);
        for (int y = 0; y < height; ++y)
        {
            std::memcpy(image.scanLine(y), pixels.constData() + y * width, size_t(width));
        }
        result[frame] = QIcon(QPixmap::fromImage(image));
    }
    return result;
}
} // namespace bb
