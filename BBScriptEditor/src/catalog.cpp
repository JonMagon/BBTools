#include "catalog.h"
#include "game_resources.h"
#include <limits>
#include <type_traits>

namespace bb
{
namespace
{
QJsonDocument json(const QString &name)
{
    return QJsonDocument::fromJson(readFile(":/data/" + name));
}

QString txt(const QByteArray &a)
{
    return QString::fromLatin1(a.split('\0').first());
}

QString label(const Choices &c, qint64 id)
{
    return c.value(id, QString("Unknown ID %1").arg(id));
}

} // namespace

Catalog::Catalog()
{
    root = json("catalog.json").object();
    units = json("hover_names.json").object()["sex"].toObject();
    classLabels = json("class_labels.json").object();
    classIds = json("class_ids.json").object();
    activities = json("activity_catalog.json").array();
    states = json("state_catalog.json").array();
    actions = json("action_catalog.json").array();
}

void Catalog::setGameDirectory(const QString &directory)
{
    gameDirectory = directory;
    letters.clear();
    textureIcons.clear();
    auto archive = QDir(directory).filePath("mistext0.box");
    if (QFileInfo::exists(archive))
    {
        letters = readBox(readFile(archive));
    }
    try
    {
        textureIcons = loadTerrainIcons(directory);
    }
    catch (const std::exception &)
    { /* Optional artwork is unavailable. IDs remain editable. */
    }
}

Choices Catalog::choices(const QString &group) const
{
    Choices out;
    auto o = root[group].toObject();
    for (auto i = o.begin(); i != o.end(); ++i)
    {
        out[i.key().toLongLong()] = i.value().toString();
    }
    return out;
}

Choices Catalog::unitChoices() const
{
    Choices out;
    for (auto i = units.begin(); i != units.end(); ++i)
    {
        out[i.key().toInt()] = i.value().toString();
    }
    return out;
}

Choices Catalog::actionChoices() const
{
    Choices out;
    for (auto x : actions)
    {
        auto o = x.toObject();
        out[o["action"].toInt()] = o["label"].toString();
    }
    return out;
}

QString Catalog::className(int id) const
{
    auto entry = classLabels[QString::number(id)].toObject();
    if (!entry.isEmpty())
    {
        return entry["label"].toString();
    }
    for (auto i = classIds.begin(); i != classIds.end(); ++i)
    {
        if (i.value().toInt() == id)
        {
            return QString(i.key()).replace('_', ' ');
        }
    }
    return QString("object class %1 (no catalog entry)").arg(id);
}

Choices Catalog::classes() const
{
    Choices out;
    for (int i = 0; i < 256; ++i)
    {
        out[i] = className(i);
    }
    return out;
}

QString Catalog::objectName(const Mission &mission, int slot) const
{
    auto mapObject = mission.object(slot);
    if (!mapObject)
    {
        return QString("#%1 (slot absent in this file)").arg(slot);
    }
    auto name = className(mapObject->objectClass);
    if (mapObject->objectClass == 103 || mapObject->objectClass == 104)
    {
        name = label(unitChoices(), mapObject->unit) + " / " + name;
    }
    return QString("#%1 %2").arg(slot).arg(name);
}

Choices Catalog::objectChoices(const Mission &mission, bool selection) const
{
    Choices references;
    for (auto &mapObject : mission.objects)
    {
        references[mapObject.slot] = QString("%1 · P%2 · (%3, %4)")
                                         .arg(objectName(mission, mapObject.slot))
                                         .arg(mapObject.owner)
                                         .arg(mapObject.x)
                                         .arg(mapObject.y);
    }
    if (selection)
    {
        references[0] = "Selected objects";
    }
    return references;
}

Choices Catalog::classModes(int classId, const QJsonArray &entries) const
{
    Choices modes;
    for (auto entry : entries)
    {
        auto mode = entry.toObject();
        if (mode["class_id"].toInt() == classId)
        {
            modes[mode.contains("activity") ? mode["activity"].toInt() : mode["state"].toInt()] =
                mode["label"].toString();
        }
    }
    return modes;
}

QString Catalog::resolveText(const QByteArray &reference) const
{
    auto text = txt(reference);
    auto openingBracket = text.indexOf('['), closingBracket = text.indexOf(']', openingBracket + 1);
    if (openingBracket >= 0 && closingBracket > openingBracket)
    {
        auto key = text.mid(openingBracket + 1, closingBracket - openingBracket - 1).toLower();
        if (letters.contains(key))
        {
            return txt(letters[key]);
        }
    }
    return text;
}

QString Catalog::commandLabel(const Mission &mission, const Command &command) const
{
    if (command.malformed)
    {
        return "Truncated / malformed command (preserved)";
    }
    auto object = [&](int slot)
    {
        return objectName(mission, slot);
    };
    auto selected = [&](int slot)
    {
        return slot ? object(slot) : QString("selected objects");
    };
    return std::visit(
        [&](const auto &payload) -> QString
        {
            using PayloadType = std::decay_t<decltype(payload)>;
            if constexpr (std::is_same_v<PayloadType, Move>)
            {
                return QString("Move %1 to tile (%2, %3)")
                    .arg(selected(payload.object))
                    .arg(payload.x)
                    .arg(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Destination>)
            {
                return QString("Set destination tile of selected owned objects to (%1, %2)")
                    .arg(payload.x)
                    .arg(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Target>)
            {
                return "Set target of selected owned objects to " + object(payload.object);
            }
            else if constexpr (std::is_same_v<PayloadType, Create>)
            {
                return QString("Create %1 at tile (%2, %3), elevation %4")
                    .arg(className(payload.objectClass))
                    .arg(payload.x)
                    .arg(payload.y)
                    .arg(payload.elevation);
            }
            else if constexpr (std::is_same_v<PayloadType, Texture>)
            {
                return QString("Set terrain texture at tile (%1, %2) to texture %3")
                    .arg(payload.x)
                    .arg(payload.y)
                    .arg(payload.texture);
            }
            else if constexpr (std::is_same_v<PayloadType, Letter>)
            {
                const auto text = resolveText(payload.text);
                return text.startsWith('*') ? "Show hint: " + text.mid(1)
                                            : "Deliver letter: " + text;
            }
            else if constexpr (std::is_same_v<PayloadType, Selection>)
            {
                QStringList ids;
                for (auto id : payload.objects)
                {
                    ids << object(id);
                }
                return "Set command selection: " +
                       (ids.isEmpty() ? QString("empty") : ids.join(", "));
            }
            else if constexpr (std::is_same_v<PayloadType, Speed>)
            {
                return QString("Set game speed to %1").arg(payload.speed);
            }
            else if constexpr (std::is_same_v<PayloadType, Terrain>)
            {
                return QString("%1 terrain at tile (%2, %3)")
                    .arg(payload.raise ? "Raise" : "Lower")
                    .arg(payload.x)
                    .arg(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Demolish>)
            {
                return QString("Demolish at tile (%1, %2)").arg(payload.x).arg(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Sync>)
            {
                return payload.compare ? QString("Compare network random-state report %1")
                                             .arg(qint16(payload.random))
                                       : QString("Request network random-state check");
            }
            else if constexpr (std::is_same_v<PayloadType, Rename>)
            {
                return QString("Rename village at %1 to \"%2\"")
                    .arg(object(payload.object), txt(payload.text));
            }
            else if constexpr (std::is_same_v<PayloadType, Action>)
            {
                QString name = label(actionChoices(), payload.action);
                auto targetObject = mission.object(payload.object);
                int classId = targetObject ? targetObject->objectClass : -1;
                QMap<QPair<int, int>, QString> contextual = {{{7, 70}, "Reload bolt trap"},
                                                             {{7, 114}, "Lay stones"},
                                                             {{7, 115}, "Saw wood"},
                                                             {{7, 116}, "Hammer"},
                                                             {{8, 160}, "Drink potion"},
                                                             {{8, 83}, "Eat mushroom"},
                                                             {{9, 210}, "Operate lever"},
                                                             {{9, 214}, "Use fountain of youth"}};
                return contextual.value({payload.action, classId}, name) +
                       ": selected residents → " + object(payload.object);
            }
            else if constexpr (std::is_same_v<PayloadType, Spell>)
            {
                return QString("Cast %1 at tile (%2, %3) with selected objects")
                    .arg(label(choices("spells"), payload.spell))
                    .arg(payload.x)
                    .arg(payload.y);
            }
            else if constexpr (std::is_same_v<PayloadType, Property>)
            {
                auto fields = this->fields(mission, command);
                auto field = fields.back();
                QString value = field.choices.value(payload.value, QString::number(payload.value));
                auto targetObject = payload.object ? mission.object(payload.object) : nullptr;
                int classId = targetObject ? targetObject->objectClass : -1;
                if (payload.property == 21)
                {
                    if (classId == 199 && (payload.value == 0 || payload.value == 106))
                    {
                        return QString("Set %1 appearance to %2 (visual only)")
                            .arg(selected(payload.object), payload.value == 0 ? "closed" : "open");
                    }
                    if (classId == 171 || classId == 226)
                    {
                        return QString(payload.value ? "Disable generation: "
                                                     : "Enable generation: ") +
                               selected(payload.object);
                    }
                    auto modes = classModes(classId, activities);
                    if (modes.contains(payload.value & 255))
                    {
                        return modes[payload.value & 255] + ": " + selected(payload.object);
                    }
                    return QString("Set unmapped activity %1 on %2")
                        .arg(payload.value & 255)
                        .arg(selected(payload.object));
                }
                if (payload.property == 16)
                {
                    auto modes = classModes(classId, states);
                    if (modes.contains(payload.value & 255))
                    {
                        return "Set state of " + selected(payload.object) + ": " +
                               modes[payload.value & 255];
                    }
                }
                return QString("Set %1 of %2 to %3")
                    .arg(label(choices("properties"), payload.property),
                         selected(payload.object),
                         value);
            }
            else if constexpr (std::is_same_v<PayloadType, Outcome>)
            {
                return QString("Set outcome: ") +
                       Choices{{0, "undecided"}, {1, "victory"}, {2, "defeat"}}.value(
                           payload.outcome, QString::number(payload.outcome));
            }
            else if constexpr (std::is_same_v<PayloadType, Flag>)
            {
                return QString("Set global flag %1 to %2").arg(payload.flag).arg(payload.value);
            }
            else if constexpr (std::is_same_v<PayloadType, Gold>)
            {
                return QString("Add %1%2 gold to player %3")
                    .arg(payload.delta >= 0 ? "+" : "")
                    .arg(payload.delta)
                    .arg(payload.player);
            }
            else if constexpr (std::is_same_v<PayloadType, Delete>)
            {
                return payload.object ? "Delete " + object(payload.object)
                                      : QString("Delete: null slot (no action)");
            }
            else if constexpr (std::is_same_v<PayloadType, Music>)
            {
                return payload.track ? QString("Play music track %1").arg(payload.track)
                                     : QString("Stop music");
            }
            else if constexpr (std::is_same_v<PayloadType, Sound>)
            {
                return payload.speech
                           ? QString("Play sample \"%1\"%2")
                                 .arg(txt(payload.sample),
                                      payload.speaker ? " on " + object(payload.speaker) : "")
                           : QString("Play sound effect group %1 · %2")
                                 .arg(payload.effect)
                                 .arg(label(choices("effects"), payload.effect));
            }
            else
            {
                return label(choices("commands"), command.type);
            }
        },
        command.payload);
}

QString Catalog::eventLabel(const Mission &mission, const Event &event) const
{
    auto firstArgument = event.args[0], secondArgument = event.args[1],
         thirdArgument = event.args[2];
    auto object = [&](int n)
    {
        return objectName(mission, n);
    };
    switch (event.type)
    {
    case 1:
        return QString("Block age ≥ %1 ticks").arg(quint32(firstArgument));
    case 2:
    case 3:
        return QString("Player %1 gold %2 %3")
            .arg(firstArgument)
            .arg(event.type == 2 ? ">" : "<")
            .arg(secondArgument);
    case 4:
    case 5:
        return QString("Player %1 count of %2 %3 %4")
            .arg(firstArgument)
            .arg(className(secondArgument), event.type == 4 ? ">" : "<")
            .arg(quint32(thirdArgument));
    case 6:
        return "Object slot " + object(firstArgument) + " is empty";
    case 7:
        return QString("Stored position of %1 equals tile (%2, %3)")
            .arg(object(firstArgument))
            .arg(secondArgument)
            .arg(thirdArgument);
    case 8:
        return "Stored happiness of " + object(firstArgument) + " equals zero";
    case 9:
        return QString("Stored owner of %1 equals player %2")
            .arg(object(secondArgument))
            .arg(firstArgument);
    case 10:
        return "Distance between " + object(firstArgument) + " and " + object(secondArgument) +
               " is < 3 tiles";
    case 11:
        return QString("Global flag %1 is %2")
            .arg(firstArgument)
            .arg(secondArgument ? "nonzero" : "zero");
    case 12:
        if (firstArgument == 0)
        {
            return "Local player has a tree or an object with no held item within 3 tiles "
                   "(inclusive) of " +
                   object(secondArgument);
        }
        return "Local player has " + className(firstArgument) +
               " or carries that item within 3 tiles (inclusive) of " + object(secondArgument);
    case 13:
        return "Unit type " + label(unitChoices(), firstArgument) +
               ", any owner, within 3 tiles (inclusive) of " + object(secondArgument);
    case 14:
        return "Burning corpse at the tile of " + object(firstArgument) + ", at night";
    default:
        return QString("Unknown event %1: %2, %3, %4")
            .arg(event.type)
            .arg(firstArgument)
            .arg(secondArgument)
            .arg(thirdArgument);
    }
}

QString Catalog::eventExplanation(const Event &e) const
{
    return root["eventExplanations"].toObject()[QString::number(e.type)].toString();
}

QString Catalog::explanation(const Mission &m, const Command &c) const
{
    if (auto p = std::get_if<Property>(&c.payload))
    {
        auto o = p->object ? m.object(p->object) : nullptr;
        auto cls = o ? o->objectClass : -1;
        if (p->property == 21 || p->property == 16)
        {
            auto entries = p->property == 21 ? activities : states;
            for (auto e : entries)
            {
                auto x = e.toObject();
                if (x["class_id"].toInt() == cls &&
                    x[p->property == 21 ? "activity" : "state"].toInt() == (p->value & 255))
                {
                    return x["description"].toString();
                }
            }
        }
        auto keys = root["propertyExplanations"].toObject();
        return keys.value(QString("%1:%2").arg(cls).arg(p->property))
            .toString(keys.value(QString("-1:%1").arg(p->property)).toString());
    }
    if (auto p = std::get_if<Action>(&c.payload))
    {
        for (auto a : actions)
        {
            if (a.toObject()["action"].toInt() == p->action)
            {
                return a.toObject()["description"].toString();
            }
        }
    }
    return root["commandExplanations"].toObject()[QString::number(c.type)].toString();
}

} // namespace bb
