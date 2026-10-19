#include "format.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>

namespace bb
{
namespace
{
[[noreturn]] void fail(const QString &s)
{
    throw std::runtime_error(s.toStdString());
}

class Reader
{
public:
    const QByteArray &data;
    qsizetype pos = 0;

    explicit Reader(const QByteArray &d) : data(d)
    {
    }

    QByteArray take(qsizetype count)
    {
        if (count < 0 || count > data.size() - pos)
        {
            fail(QString("Truncated data at byte %1 (need %2)").arg(pos).arg(count));
        }
        auto b = data.mid(pos, count);
        pos += count;
        return b;
    }

    void skip(qsizetype n)
    {
        take(n);
    }

    quint8 byte()
    {
        return quint8(take(1)[0]);
    }

    quint16 u16()
    {
        auto b = take(2);
        return qFromLittleEndian<quint16>(b.constData());
    }

    quint32 u32()
    {
        auto b = take(4);
        return qFromLittleEndian<quint32>(b.constData());
    }

    qint32 i32()
    {
        return qint32(u32());
    }

    int count(int maximum = 1000000)
    {
        auto n = i32();
        if (n < 0 || n > maximum)
        {
            fail("Invalid record count");
        }
        return n;
    }

    template <class T> T record()
    {
        auto b = take(sizeof(T));
        T t;
        std::memcpy(&t, b.constData(), sizeof t);
        return t;
    }

    QByteArray rest()
    {
        return take(data.size() - pos);
    }
};

class Writer
{
public:
    QByteArray data;

    void byte(quint8 x)
    {
        data.append(char(x));
    }

    void u16(quint16 x)
    {
        char b[2];
        qToLittleEndian(x, b);
        data.append(b, 2);
    }

    void u32(quint32 x)
    {
        char b[4];
        qToLittleEndian(x, b);
        data.append(b, 4);
    }

    void i32(qint32 x)
    {
        u32(quint32(x));
    }

    void bytes(const QByteArray &b)
    {
        data += b;
    }
};

QByteArray unrle(const QByteArray &bytes, int length)
{
    QByteArray result(length, '\0');
    Reader r(bytes);
    int at = 0;
    while (r.pos < bytes.size())
    {
        auto b = r.byte();
        if (b)
        {
            if (at < length)
            {
                result[at] = char(b);
            }
            ++at;
        }
        else
        {
            at = qMin(length, at + int(r.byte()));
        }
    }
    return result;
}

QByteArray cstring(const QByteArray &b)
{
    auto n = b.indexOf('\0');
    return n < 0 ? b : b.first(n);
}

void writeEvent(Writer &w, const Event &e)
{
    if (!e.destination)
    {
        fail("Connect every event before saving");
    }
    w.byte(e.type);
    w.byte(e.disk.reserved);
    for (auto x : e.args)
    {
        w.i32(x);
    }
    w.byte(*e.destination);
    w.byte(e.disk.reservedDestination);
    w.i32(e.enabled);
    w.u32(qFromLittleEndian(e.disk.reservedTail));
}
} // namespace

int Event::target() const
{
    return destination ? qMin<int>(*destination, BackgroundBlock) : -1;
}

QByteArray readFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        fail(file.errorString() + ": " + path);
    }
    return file.readAll();
}

QMap<QString, QByteArray> readBox(const QByteArray &data)
{
    Reader r(data);
    if (r.take(3) != "BOX")
    {
        fail("Not a BOX archive");
    }
    r.skip(5);
    QMap<QString, QByteArray> out;
    while (r.pos < data.size())
    {
        auto h = r.record<BoxEntryDisk>();
        auto name = QString::fromLatin1(cstring(QByteArray(h.name, sizeof h.name)));
        out[name.toLower()] = r.take(qFromLittleEndian(h.size));
    }
    return out;
}

Command decodePacket(const QByteArray &bytes)
{
    Command command;
    command.originalPacket = bytes;
    try
    {
        Reader reader(bytes);
        command.type = reader.u16();
        auto length = reader.u16();
        command.player = reader.byte();
        if (length != bytes.size())
        {
            fail("Packet length mismatch");
        }
        switch (command.type)
        {
        case 1:
        {
            Move payload;
            payload.x = reader.byte();
            payload.y = reader.byte();
            payload.reserved = reader.byte();
            payload.object = reader.i32();
            command.payload = payload;
            break;
        }
        case 2:
            command.payload = Destination{reader.byte(), reader.byte()};
            break;
        case 3:
            command.payload = Target{reader.byte(), reader.i32()};
            break;
        case 4:
            command.payload = Create{reader.byte(), reader.byte(), reader.byte(), reader.byte()};
            break;
        case 5:
            command.payload = Texture{reader.byte(), reader.byte(), reader.byte()};
            break;
        case 6:
            command.payload = Letter{reader.rest()};
            break;
        case 7:
        {
            Selection payload;
            auto n = reader.byte();
            for (int i = 0; i < n; ++i)
            {
                payload.objects.push_back(reader.i32());
            }
            command.payload = payload;
            break;
        }
        case 8:
            command.payload = Speed{reader.byte()};
            break;
        case 9:
            command.payload = Terrain{reader.byte(), reader.byte(), reader.byte(), reader.i32()};
            break;
        case 12:
            command.payload = Demolish{reader.byte(), reader.byte()};
            break;
        case 10:
        case 11:
        case 13:
            command.payload = Empty{};
            break;
        case 14:
            command.payload = Sync{reader.byte(), reader.u16()};
            break;
        case 15:
        {
            Rename payload;
            payload.reserved = reader.byte();
            payload.object = reader.i32();
            payload.text = reader.rest();
            command.payload = payload;
            break;
        }
        case 17:
            command.payload = Action{reader.byte(), reader.i32(), reader.byte()};
            break;
        case 18:
            command.payload = Spell{reader.byte(), reader.byte(), reader.byte()};
            break;
        case 19:
            command.payload =
                Property{reader.byte(), reader.i32(), reader.byte(), reader.byte(), reader.i32()};
            break;
        case 20:
            command.payload = Outcome{reader.byte()};
            break;
        case 21:
            command.payload = Flag{reader.byte(), reader.i32()};
            break;
        case 22:
            command.payload = Gold{reader.byte(), reader.i32()};
            break;
        case 23:
            command.payload = Delete{reader.byte(), reader.i32()};
            break;
        case 24:
            command.payload = Music{reader.byte(), reader.i32()};
            break;
        case 25:
            command.payload =
                Sound{reader.byte(), reader.i32(), reader.i32(), reader.take(16), reader.i32()};
            break;
        default:
            command.payload = Unknown{reader.rest()};
            break;
        }
        command.trailing = reader.rest();
    }
    catch (const std::exception &)
    {
        command.malformed = true;
        command.payload = Unknown{bytes};
    }
    return command;
}

QByteArray encodePacket(const Command &command)
{
    if (command.malformed)
    {
        return command.originalPacket;
    }
    Writer writer;
    writer.u16(command.type);
    writer.u16(0);
    writer.byte(command.player);
    std::visit(
        [&](const auto &payload)
        {
            using PayloadType = std::decay_t<decltype(payload)>;
            if constexpr (std::is_same_v<PayloadType, Move>)
            {
                writer.byte(payload.x);
                writer.byte(payload.y);
                writer.byte(payload.reserved);
                writer.i32(payload.object);
            }
            else if constexpr (std::is_same_v<PayloadType, Destination> ||
                               std::is_same_v<PayloadType, Demolish>)
            {
                writer.byte(payload.x);
                writer.byte(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Target> ||
                               std::is_same_v<PayloadType, Delete>)
            {
                writer.byte(payload.reserved);
                writer.i32(payload.object);
            }
            else if constexpr (std::is_same_v<PayloadType, Create>)
            {
                writer.byte(payload.objectClass);
                writer.byte(payload.x);
                writer.byte(payload.y);
                writer.byte(payload.elevation);
            }
            else if constexpr (std::is_same_v<PayloadType, Texture>)
            {
                writer.byte(payload.texture);
                writer.byte(payload.x);
                writer.byte(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Letter>)
            {
                writer.bytes(payload.text);
            }
            else if constexpr (std::is_same_v<PayloadType, Selection>)
            {
                if (payload.objects.size() > 255)
                {
                    fail("Too many selected objects");
                }
                writer.byte(quint8(payload.objects.size()));
                for (auto x : payload.objects)
                {
                    writer.i32(x);
                }
            }
            else if constexpr (std::is_same_v<PayloadType, Speed>)
            {
                writer.byte(payload.speed);
            }
            else if constexpr (std::is_same_v<PayloadType, Terrain>)
            {
                writer.byte(payload.x);
                writer.byte(payload.y);
                writer.byte(payload.reserved);
                writer.i32(payload.raise);
            }
            else if constexpr (std::is_same_v<PayloadType, Sync>)
            {
                writer.byte(payload.compare);
                writer.u16(payload.random);
            }
            else if constexpr (std::is_same_v<PayloadType, Rename>)
            {
                writer.byte(payload.reserved);
                writer.i32(payload.object);
                writer.bytes(payload.text);
            }
            else if constexpr (std::is_same_v<PayloadType, Action>)
            {
                writer.byte(payload.reserved);
                writer.i32(payload.object);
                writer.byte(payload.action);
            }
            else if constexpr (std::is_same_v<PayloadType, Spell>)
            {
                writer.byte(payload.spell);
                writer.byte(payload.x);
                writer.byte(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Property>)
            {
                writer.byte(payload.reserved);
                writer.i32(payload.object);
                writer.byte(payload.property);
                writer.byte(payload.reservedValue);
                writer.i32(payload.value);
            }
            else if constexpr (std::is_same_v<PayloadType, Outcome>)
            {
                writer.byte(payload.outcome);
            }
            else if constexpr (std::is_same_v<PayloadType, Flag>)
            {
                writer.byte(payload.flag);
                writer.i32(payload.value);
            }
            else if constexpr (std::is_same_v<PayloadType, Gold>)
            {
                writer.byte(payload.player);
                writer.i32(payload.delta);
            }
            else if constexpr (std::is_same_v<PayloadType, Music>)
            {
                writer.byte(payload.reserved);
                writer.i32(payload.track);
            }
            else if constexpr (std::is_same_v<PayloadType, Sound>)
            {
                writer.byte(payload.reserved);
                writer.i32(payload.speech);
                writer.i32(payload.effect);
                writer.bytes(payload.sample.leftJustified(16, '\0', true));
                writer.i32(payload.speaker);
            }
            else if constexpr (std::is_same_v<PayloadType, Unknown>)
            {
                writer.bytes(payload.bytes);
            }
        },
        command.payload);
    writer.bytes(command.trailing);
    if (writer.data.size() > 65535)
    {
        fail("Packet exceeds 65535 bytes");
    }
    qToLittleEndian<quint16>(quint16(writer.data.size()),
                             writer.data.data() + offsetof(PacketHeaderDisk, length));
    return writer.data;
}

Command newCommand(quint16 type, quint8 player)
{
    Writer w;
    w.u16(type);
    w.u16(64);
    w.byte(player);
    w.bytes(QByteArray(59, '\0'));
    auto c = decodePacket(w.data);
    c.active = 1;
    c.diskHeader.dataPointer = qToLittleEndian<quint32>(1);
    return c;
}

QByteArray blockSemantic(const Block &b)
{
    Writer w;
    w.u32(quint32(b.commands.size()));
    for (auto &c : b.commands)
    {
        w.u32(c.delay);
        w.byte(c.active);
        auto p = encodePacket(c);
        w.u32(quint32(p.size()));
        w.bytes(p);
    }
    w.u32(quint32(b.events.size()));
    for (auto &e : b.events)
    {
        w.byte(e.type);
        for (auto a : e.args)
        {
            w.i32(a);
        }
        w.i32(e.destination ? int(*e.destination) : -1);
        w.i32(e.enabled);
    }
    return w.data;
}

Mission Mission::parse(const QByteArray &bytes, QString name)
{
    Reader reader(bytes);
    auto header = reader.record<MapHeaderDisk>();
    if (QByteArray(header.signature, 4) != "MAPV")
    {
        fail("Not a MAP mission/save");
    }
    Mission mission;
    mission.name = name;
    mission.source = bytes;
    mission.title = QString::fromLatin1(cstring(QByteArray(header.title, sizeof header.title)));
    bool ok = false;
    auto versionText =
        QByteArray(header.signature, sizeof header.signature).mid(4).replace(".", "");
    mission.version = versionText.toInt(&ok);
    if (!ok || mission.version < 100 || mission.version > 199)
    {
        fail("Unsupported MAP version");
    }
    for (int row = 0; row < header.height; ++row)
    {
        auto size = reader.count();
        reader.skip(size);
    }
    auto objects = reader.record<ObjectArrayDisk>();
    auto count = qFromLittleEndian(objects.slotCount);
    if (count < 0 || count > 5000)
    {
        fail("Invalid object slot count");
    }
    for (int slot = 0; slot < count; ++slot)
    {
        if (!reader.byte())
        {
            continue;
        }
        auto size = reader.count();
        auto unpacked = unrle(reader.take(size), sizeof(MapObjectDisk));
        Reader objectReader(unpacked);
        auto diskObject = objectReader.record<MapObjectDisk>();
        if (qFromLittleEndian(diskObject.pathPointer))
        {
            reader.skip(diskObject.pathLength);
        }
        if (diskObject.objectClass == 98)
        {
            reader.skip(32);
        }
        if (qFromLittleEndian(diskObject.stockPointer))
        {
            reader.skip(2);
        }
        mission.objects.push_back({slot,
                                   diskObject.objectClass,
                                   diskObject.tileX,
                                   diskObject.tileY,
                                   diskObject.owner,
                                   diskObject.unitType,
                                   diskObject.state,
                                   diskObject.activity});
    }
    auto deletions = reader.count();
    reader.skip(qsizetype(deletions) * sizeof(quint32));
    for (auto &outcome : mission.outcomes)
    {
        outcome = reader.record<PlayerDisk>().outcome;
    }
    auto mail = reader.count();
    reader.skip(qsizetype(mail) * sizeof(MailDisk));
    auto camera = reader.record<CameraDisk>();
    mission.tick = quint32(qFromLittleEndian(camera.gameTick));
    mission.scriptStart = reader.pos;
    for (auto &chain : mission.chains)
    {
        for (auto &block : chain.blocks)
        {
            auto start = reader.pos;
            auto n = reader.count(100000);
            for (int i = 0; i < n; ++i)
            {
                auto diskHeader = reader.record<TimedMessageDisk>();
                auto packet = reader.take(qFromLittleEndian(diskHeader.packetLength));
                auto command = decodePacket(packet);
                command.active = diskHeader.active;
                command.delay = qFromLittleEndian(diskHeader.delayTicks);
                command.diskHeader = diskHeader;
                block.commands.push_back(command);
            }
            if (mission.version >= 121)
            {
                block.cursor = reader.u32();
            }
            n = reader.count(100000);
            for (int i = 0; i < n; ++i)
            {
                auto diskHeader = reader.record<EventDisk>();
                Event event;
                event.type = diskHeader.type;
                event.args = {qFromLittleEndian(diskHeader.first),
                              qFromLittleEndian(diskHeader.second),
                              qFromLittleEndian(diskHeader.third)};
                event.destination = diskHeader.destination;
                event.enabled = qFromLittleEndian(diskHeader.enabled);
                event.disk = diskHeader;
                block.events.push_back(event);
            }
            if (mission.version >= 122)
            {
                block.start = reader.u32();
            }
            block.originalBytes = bytes.mid(start, reader.pos - start);
            block.originalSemantic = blockSemantic(block);
        }
        chain.current = reader.byte();
    }
    mission.scriptChainsEnd = reader.pos;
    mission.tech = reader.record<ScriptGlobalsDisk>().technology;
    if (mission.version >= 118)
    {
        reader.skip(1);
    }
    if (mission.version >= 120)
    {
        reader.skip(1);
    }
    if (mission.version >= 124)
    {
        reader.skip(sizeof(ScriptRetryDisk));
    }
    mission.scriptEnd = reader.pos;
    return mission;
}

QByteArray Mission::serialize() const
{
    Writer w;
    w.bytes(source.first(scriptStart));
    for (auto &chain : chains)
    {
        if (chain.current >= BlockCount)
        {
            fail("Current block outside 0–31");
        }
        for (auto &b : chain.blocks)
        {
            if (blockSemantic(b) == b.originalSemantic)
            {
                w.bytes(b.originalBytes);
                continue;
            }
            auto commands = b.commands;
            std::stable_sort(commands.begin(),
                             commands.end(),
                             [](auto &a, auto &b)
                             {
                                 return a.delay < b.delay;
                             });
            w.u32(quint32(commands.size()));
            for (auto &c : commands)
            {
                auto packet = encodePacket(c);
                w.byte(c.active);
                w.byte(c.diskHeader.reserved);
                w.u32(c.delay);
                w.u32(qFromLittleEndian(c.diskHeader.dataPointer));
                w.u32(qFromLittleEndian(c.diskHeader.nextPointer));
                w.u16(quint16(packet.size()));
                w.bytes(packet);
            }
            if (version >= 121)
            {
                w.u32(b.cursor);
            }
            w.u32(quint32(b.events.size()));
            for (auto &e : b.events)
            {
                writeEvent(w, e);
            }
            if (version >= 122)
            {
                w.u32(b.start);
            }
        }
        w.byte(chain.current);
    }
    w.bytes(source.mid(scriptChainsEnd));
    return w.data;
}

QByteArray Mission::semantic() const
{
    Writer w;
    for (auto &chain : chains)
    {
        w.byte(chain.current);
        for (auto &b : chain.blocks)
        {
            w.bytes(blockSemantic(b));
        }
    }
    return w.data;
}

const Object *Mission::object(int slot) const
{
    for (auto &o : objects)
    {
        if (o.slot == slot)
        {
            return &o;
        }
    }
    return nullptr;
}

void Mission::save(const QString &filename)
{
    auto bytes = serialize();
    auto check = Mission::parse(bytes, name);
    // Disk sorts delays. Compare a sorted draft so same-time order stays stable.
    auto sorted = *this;
    for (auto &c : sorted.chains)
    {
        for (auto &b : c.blocks)
        {
            std::stable_sort(b.commands.begin(),
                             b.commands.end(),
                             [](auto &a, auto &b)
                             {
                                 return a.delay < b.delay;
                             });
        }
    }
    auto normalized = check;
    for (auto &c : normalized.chains)
    {
        for (auto &b : c.blocks)
        {
            std::stable_sort(b.commands.begin(),
                             b.commands.end(),
                             [](auto &a, auto &b)
                             {
                                 return a.delay < b.delay;
                             });
        }
    }
    if (normalized.semantic() != sorted.semantic())
    {
        fail("Save verification failed");
    }
    QSaveFile file(filename);
    if (!file.open(QIODevice::WriteOnly) || file.write(bytes) != bytes.size() || !file.commit())
    {
        fail("Could not save: " + file.errorString());
    }
    check.path = QFileInfo(filename).absoluteFilePath();
    check.name = QFileInfo(filename).fileName();
    // Keep editor row order stable after Save; the file has stable delay sorting.
    // Each block's byte baseline now belongs to the new file, while its semantic
    // baseline corresponds to the editor order that produced those bytes.
    for (int ch = 0; ch < ChainCount; ++ch)
    {
        for (int b = 0; b < BlockCount; ++b)
        {
            auto &loaded = check.chains[ch].blocks[b];
            loaded.commands = chains[ch].blocks[b].commands;
            loaded.originalSemantic = blockSemantic(loaded);
        }
    }
    *this = std::move(check);
}

std::vector<int> unusedBlocks(const Chain &c)
{
    QSet<int> used{c.current, 31};
    for (int i = 0; i < 32; ++i)
    {
        auto &b = c.blocks[i];
        if (!b.commands.empty() || !b.events.empty())
        {
            used.insert(i);
        }
        for (auto &e : b.events)
        {
            if (e.destination)
            {
                used.insert(e.target());
            }
        }
    }
    std::vector<int> out;
    for (int i = 0; i < 31; ++i)
    {
        if (!used.contains(i))
        {
            out.push_back(i);
        }
    }
    return out;
}
} // namespace bb
