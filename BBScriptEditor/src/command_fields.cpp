#include "catalog.h"
#include <limits>
#include <type_traits>

namespace bb
{
namespace
{
Choices players()
{
    Choices r;
    for (int i = 0; i < 5; ++i)
    {
        r[i] = "Player " + QString::number(i);
    }
    return r;
}

template <class PayloadType, class ValueType>
Field member(QString name,
             const PayloadType &payload,
             ValueType PayloadType::*memberPointer,
             Choices choices = {},
             bool fixed = false,
             bool rebuild = false)
{
    Field field;
    field.name = name;
    field.value = payload.*memberPointer;
    field.low = std::numeric_limits<ValueType>::min();
    field.high = std::numeric_limits<ValueType>::max();
    field.choices = choices;
    field.fixed = fixed;
    field.rebuild = rebuild;
    field.set = [memberPointer](Command &command, qint64 newValue)
    {
        std::get<PayloadType>(command.payload).*memberPointer = ValueType(newValue);
    };
    return field;
}

} // namespace

std::vector<Field> Catalog::fields(const Mission &mission, const Command &command) const
{
    std::vector<Field> fields;
    auto objects = objectChoices(mission);
    auto selected = objectChoices(mission, true);
    auto classChoices = classes();
    std::visit(
        [&](const auto &payload)
        {
            using PayloadType = std::decay_t<decltype(payload)>;
            auto add = [&](QString name,
                           auto memberPointer,
                           Choices fieldChoices = Choices{},
                           bool fixed = false,
                           bool rebuild = false)
            {
                fields.push_back(
                    member(name, payload, memberPointer, fieldChoices, fixed, rebuild));
            };
            if constexpr (std::is_same_v<PayloadType, Move>)
            {
                add("Tile X", &PayloadType::x);
                add("Tile Y", &PayloadType::y);
                add("Object slot (0: selection)", &PayloadType::object, selected);
            }
            else if constexpr (std::is_same_v<PayloadType, Destination> ||
                               std::is_same_v<PayloadType, Demolish>)
            {
                add("Tile X", &PayloadType::x);
                add("Tile Y", &PayloadType::y);
            }
            else if constexpr (std::is_same_v<PayloadType, Target> ||
                               std::is_same_v<PayloadType, Delete>)
            {
                add("Object slot", &PayloadType::object, objects);
            }
            else if constexpr (std::is_same_v<PayloadType, Create>)
            {
                add("Object class", &PayloadType::objectClass, classChoices);
                add("Tile X", &PayloadType::x);
                add("Tile Y", &PayloadType::y);
                add("Elevation", &PayloadType::elevation);
            }
            else if constexpr (std::is_same_v<PayloadType, Texture>)
            {
                add("Texture", &PayloadType::texture, choices("textures"));
                add("Tile X", &PayloadType::x);
                add("Tile Y", &PayloadType::y);
            }
            else if constexpr (std::is_same_v<PayloadType, Speed>)
            {
                add("Speed", &PayloadType::speed);
            }
            else if constexpr (std::is_same_v<PayloadType, Terrain>)
            {
                add("Tile X", &PayloadType::x);
                add("Tile Y", &PayloadType::y);
                add("Terrain operation",
                    &PayloadType::raise,
                    {{0, "Lower terrain"}, {1, "Raise terrain"}},
                    true);
            }
            else if constexpr (std::is_same_v<PayloadType, Sync>)
            {
                add("Sync mode", &PayloadType::compare, {{0, "Request"}, {1, "Compare"}}, true);
                add("Random value", &PayloadType::random);
            }
            else if constexpr (std::is_same_v<PayloadType, Rename>)
            {
                add("Village slot", &PayloadType::object, objects);
            }
            else if constexpr (std::is_same_v<PayloadType, Action>)
            {
                add("Target slot", &PayloadType::object, objects);
                add("Action", &PayloadType::action, actionChoices());
            }
            else if constexpr (std::is_same_v<PayloadType, Spell>)
            {
                add("Spell", &PayloadType::spell, choices("spells"));
                add("Tile X", &PayloadType::x);
                add("Tile Y", &PayloadType::y);
            }
            else if constexpr (std::is_same_v<PayloadType, Property>)
            {
                add("Object slot (0: selection)", &PayloadType::object, selected, false, true);
                add("Property", &PayloadType::property, choices("properties"), false, true);
                Choices values;
                bool fixed = false;
                auto targetObject = payload.object ? mission.object(payload.object) : nullptr;
                int classId = targetObject ? targetObject->objectClass : -1;
                switch (payload.property)
                {
                case 1:
                    values = unitChoices();
                    break;
                case 2:
                    values = choices("jobs");
                    break;
                case 7:
                case 23:
                    values = objects;
                    break;
                case 8:
                    values = {{0, "Normal enemy-owner selection"}};
                    for (int i = 0; i < 5; ++i)
                    {
                        values[i + 1] = "Player " + QString::number(i);
                    }
                    fixed = true;
                    break;
                case 9:
                    values = classChoices;
                    values[0] = "Default prey: villagers and cows";
                    break;
                case 10:
                    values = unitChoices();
                    values[0] = "Any unit type";
                    break;
                case 12:
                    if (classId == 171 || classId == 191 || classId == 226)
                    {
                        values = classChoices;
                    }
                    break;
                case 14:
                case 15:
                case 20:
                case 24:
                    values = {{0, "Disabled"}, {1, "Enabled"}};
                    fixed = true;
                    break;
                case 16:
                    values = classId == 58 ? unitChoices() : classModes(classId, states);
                    break;
                case 17:
                    values = players();
                    fixed = true;
                    break;
                case 21:
                    values = classModes(classId, activities);
                    if (classId == 171 || classId == 226)
                    {
                        values = {{0, "Generation enabled"}, {1, "Generation disabled"}};
                    }
                    break;
                default:
                    break;
                }
                add("Value", &PayloadType::value, values, fixed);
            }
            else if constexpr (std::is_same_v<PayloadType, Outcome>)
            {
                add("Outcome",
                    &PayloadType::outcome,
                    {{0, "Undecided"}, {1, "Victory"}, {2, "Defeat"}},
                    true);
            }
            else if constexpr (std::is_same_v<PayloadType, Flag>)
            {
                add("Flag", &PayloadType::flag);
                add("Value", &PayloadType::value);
            }
            else if constexpr (std::is_same_v<PayloadType, Gold>)
            {
                add("Recipient player", &PayloadType::player, players(), true);
                add("Gold delta", &PayloadType::delta);
            }
            else if constexpr (std::is_same_v<PayloadType, Music>)
            {
                add("Track", &PayloadType::track, choices("tracks"));
            }
            else if constexpr (std::is_same_v<PayloadType, Sound>)
            {
                add("Sound mode",
                    &PayloadType::speech,
                    {{0, "Effect group"}, {1, "Named speech"}},
                    true,
                    true);
                if (payload.speech)
                {
                    add("Speaker slot", &PayloadType::speaker, objects);
                }
                else
                {
                    add("Effect group", &PayloadType::effect, choices("effects"));
                }
            }
        },
        command.payload);
    return fields;
}

} // namespace bb
