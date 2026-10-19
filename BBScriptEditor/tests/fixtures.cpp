#include "fixtures.h"
#include <cstring>

namespace fixture
{
class Bytes
{
public:
    QByteArray data;

    void byte(quint8 value)
    {
        data.append(char(value));
    }

    void u32(quint32 value)
    {
        char b[4];
        qToLittleEndian(value, b);
        data.append(b, 4);
    }

    template <class T> void record(const T &value)
    {
        data.append(reinterpret_cast<const char *>(&value), sizeof(T));
    }
};

QByteArray zeroRuns(const QByteArray &input)
{
    QByteArray out;
    for (qsizetype i = 0; i < input.size();)
    {
        if (input[i])
        {
            out += input[i++];
        }
        else
        {
            quint8 count = 0;
            while (i < input.size() && !input[i] && count < 255)
            {
                ++i;
                ++count;
            }
            out += '\0';
            out += char(count);
        }
    }
    return out;
}

QByteArray box(const QMap<QString, QByteArray> &files)
{
    Bytes b;
    b.data = QByteArray("BOX", 3) + QByteArray(5, '\0');
    for (auto it = files.begin(); it != files.end(); ++it)
    {
        bb::BoxEntryDisk h{};
        auto name = it.key().toLatin1();
        std::memcpy(h.name, name.constData(), size_t(qMin<qsizetype>(name.size(), 255)));
        h.size = qToLittleEndian<quint32>(quint32(it.value().size()));
        b.record(h);
        b.data += it.value();
    }
    return b.data;
}

QMap<QString, QByteArray> texts()
{
    return {{"editor-letter.txt",
             "First, place a test object. This text was written for editor tests."},
            {"editor-hint.txt", "*An artificial hint for editor tests."}};
}

QByteArray mission(int number)
{
    const std::array<int, 5> versions = {120, 121, 123, 124, 125};
    int version = versions[size_t(number - 1) % versions.size()];
    Bytes b;
    bb::MapHeaderDisk header{};
    auto signature = QString("MAPV1.%1").arg(version - 100, 2, 10, QChar('0')).toLatin1();
    std::memcpy(header.signature, signature.constData(), 8);
    auto title = QString("Synthetic mission %1").arg(number).toLatin1();
    std::memcpy(header.title, title.constData(), size_t(title.size()));
    header.width = header.height = 1;
    b.record(header);
    auto row = zeroRuns(QByteArray(12, '\0'));
    b.u32(quint32(row.size()));
    b.data += row;
    bb::ObjectArrayDisk objects{};
    objects.slotCount = qToLittleEndian<qint32>(22);
    b.record(objects);
    for (int slot = 0; slot < 22; ++slot)
    {
        bool present = slot == 9 || slot == 21;
        b.byte(present);
        if (!present)
        {
            continue;
        }
        bb::MapObjectDisk object{};
        object.inUse = qToLittleEndian<quint32>(1);
        object.objectClass = slot == 9 ? 199 : 87;
        object.slotIndex = qToLittleEndian<qint32>(slot);
        object.tileX = 3;
        object.tileY = 4;
        object.owner = 1;
        auto raw = QByteArray(reinterpret_cast<const char *>(&object), sizeof object);
        auto packed = zeroRuns(raw);
        b.u32(quint32(packed.size()));
        b.data += packed;
    }
    b.u32(0);
    for (int i = 0; i < 5; ++i)
    {
        b.record(bb::PlayerDisk{});
    }
    b.u32(0);
    bb::CameraDisk camera{};
    camera.gameTick = qToLittleEndian<qint32>(28);
    b.record(camera);
    std::array<bb::Chain, 5> chains{};
    auto music = bb::newCommand(24);
    std::get<bb::Music>(music.payload).track = 8;
    chains[0].blocks[0].commands.push_back(music);
    auto letter = bb::newCommand(6);
    std::get<bb::Letter>(letter.payload).text = QByteArray("[editor-letter.txt]\0", 20);
    chains[0].blocks[25].commands.push_back(letter);
    chains[0].blocks[4].commands.push_back(letter);
    auto hint = bb::newCommand(6);
    std::get<bb::Letter>(hint.payload).text = QByteArray("[editor-hint.txt]\0", 18);
    chains[0].blocks[1].commands.push_back(hint);
    chains[0].blocks[26].commands.push_back(hint);
    auto timer = [&](int from, int to)
    {
        bb::Event e;
        e.args = {108, 0, 0};
        e.destination = quint8(to);
        chains[0].blocks[from].events.push_back(e);
    };
    timer(0, 25);
    timer(25, 1);
    timer(1, 4);
    timer(4, 26);
    timer(26, 15);
    auto victory = bb::newCommand(20);
    std::get<bb::Outcome>(victory.payload).outcome = 1;
    chains[0].blocks[15].commands.push_back(victory);
    auto defeat = victory;
    std::get<bb::Outcome>(defeat.payload).outcome = 2;
    chains[0].blocks[30].commands.push_back(defeat);
    timer(31, 30);
    for (auto &chain : chains)
    {
        for (auto &block : chain.blocks)
        {
            b.u32(quint32(block.commands.size()));
            for (auto &command : block.commands)
            {
                auto packet = bb::encodePacket(command);
                auto h = command.diskHeader;
                h.active = command.active;
                h.delayTicks = qToLittleEndian(command.delay);
                h.packetLength = qToLittleEndian<quint16>(quint16(packet.size()));
                b.record(h);
                b.data += packet;
            }
            if (version >= 121)
            {
                b.u32(0);
            }
            b.u32(quint32(block.events.size()));
            for (auto &event : block.events)
            {
                bb::EventDisk e{};
                e.type = event.type;
                e.first = qToLittleEndian(event.args[0]);
                e.second = qToLittleEndian(event.args[1]);
                e.third = qToLittleEndian(event.args[2]);
                e.destination = *event.destination;
                e.enabled = qToLittleEndian<qint32>(event.enabled);
                b.record(e);
            }
            if (version >= 122)
            {
                b.u32(0);
            }
        }
        b.byte(0);
    }
    b.record(bb::ScriptGlobalsDisk{1, 0, 0});
    if (version >= 118)
    {
        b.byte(1);
    }
    if (version >= 120)
    {
        b.byte(0);
    }
    if (version >= 124)
    {
        b.record(bb::ScriptRetryDisk{});
    }
    b.data += "Artificial statistics tail";
    return b.data;
}

QMap<QString, QByteArray> campaign()
{
    QMap<QString, QByteArray> result;
    for (int n = 1; n <= 30; ++n)
    {
        result[QString("m%1.mis").arg(n)] = mission(n);
    }
    return result;
}

void populate(bb::Editor &editor)
{
    editor.catalog.letters = texts();
    for (int n = 1; n <= 30; ++n)
    {
        auto d = std::make_unique<bb::Document>();
        d->mission = bb::Mission::parse(mission(n), QString("M%1.MIS").arg(n));
        d->savedSemantic = d->mission.semantic();
        editor.documents.push_back(std::move(d));
        QSignalBlocker blocker(editor.missionBox);
        editor.missionBox->addItem(QString("Synthetic mission %1").arg(n));
    }
    editor.documentIndex = 0;
    {
        QSignalBlocker blocker(editor.missionBox);
        editor.missionBox->setCurrentIndex(0);
    }
    editor.rebuild(true);
}

Editor::Editor() : bb::Editor(false)
{
    populate(*this);
}
} // namespace fixture
