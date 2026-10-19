#include "catalog.h"
#include <algorithm>

namespace bb
{
std::vector<Issue> validate(const Mission &mission, const Catalog &catalog)
{
    std::vector<Issue> issues;
    for (int chainIndex = 0; chainIndex < 5; ++chainIndex)
    {
        auto &chain = mission.chains[chainIndex];
        if (chain.current >= 32)
        {
            issues.push_back({true, chainIndex, 0, -1, -1, "Current block must be 0–31"});
        }
        for (int blockIndex = 0; blockIndex < 32; ++blockIndex)
        {
            auto &block = chain.blocks[blockIndex];
            for (int i = 0; i < int(block.commands.size()); ++i)
            {
                auto &command = block.commands[i];
                auto add = [&](bool error, QString s)
                {
                    issues.push_back({error, chainIndex, blockIndex, 0, i, s});
                };
                if (command.malformed)
                {
                    add(true, "Malformed command packet");
                    continue;
                }
                if (command.player > 4)
                {
                    add(true, "Packet player must be 0–4");
                }
                if (!catalog.choices("commands").contains(command.type))
                {
                    add(false, QString("Unknown command type %1; preserved").arg(command.type));
                }
                for (auto &field : catalog.fields(mission, command))
                {
                    if (field.name.contains("slot") && field.value &&
                        !mission.object(int(field.value)))
                    {
                        add(false,
                            QString(
                                "Object slot %1 is absent in this snapshot; may be created later")
                                .arg(field.value));
                    }
                    else if (!field.choices.isEmpty() && !field.choices.contains(field.value))
                    {
                        add(false,
                            QString("%1 ID %2 has no catalog entry; preserved")
                                .arg(field.name)
                                .arg(field.value));
                    }
                }
                if (auto payload = std::get_if<Selection>(&command.payload))
                {
                    if (payload->objects.size() > 62)
                    {
                        add(true, "Selection supports up to 62 object slots");
                    }
                    for (auto slot : payload->objects)
                    {
                        if (!mission.object(slot))
                        {
                            add(false,
                                QString("Selected object slot %1 is absent in this snapshot")
                                    .arg(slot));
                        }
                    }
                }
                if (auto payload = std::get_if<Property>(&command.payload))
                {
                    auto object = payload->object ? mission.object(payload->object) : nullptr;
                    if (payload->property == 21 && object && object->objectClass != 171 &&
                        object->objectClass != 226)
                    {
                        int value = payload->value & 255;
                        if (value != 7 && value != 16 && value != 94 && value != 115 &&
                            !catalog.classModes(object->objectClass, catalog.activities)
                                 .contains(value))
                        {
                            add(false,
                                QString("Activity %1 has no confirmed description for class %2")
                                    .arg(value)
                                    .arg(object->objectClass));
                        }
                    }
                }
            }
            for (int i = 0; i < int(block.events.size()); ++i)
            {
                auto &event = block.events[i];
                if (!event.destination)
                {
                    issues.push_back({true,
                                      chainIndex,
                                      blockIndex,
                                      1,
                                      i,
                                      "Event output is not connected to a block"});
                }
                if (event.type < 1 || event.type > 14)
                {
                    issues.push_back({false,
                                      chainIndex,
                                      blockIndex,
                                      1,
                                      i,
                                      "Unknown event type; numeric arguments preserved"});
                }
                auto names =
                    catalog.root["eventFields"].toObject()[QString::number(event.type)].toArray();
                for (int arg = 0; arg < names.size(); ++arg)
                {
                    auto name = names[arg].toString();
                    auto value = event.args[arg];
                    if (name.contains("slot", Qt::CaseInsensitive) && !mission.object(value))
                    {
                        issues.push_back(
                            {false,
                             chainIndex,
                             blockIndex,
                             1,
                             i,
                             QString("Object slot %1 is absent in this file snapshot; may be "
                                     "created later or intentionally empty")
                                 .arg(value)});
                    }
                    if (name == "Unit type" && !catalog.unitChoices().contains(value))
                    {
                        issues.push_back(
                            {false,
                             chainIndex,
                             blockIndex,
                             1,
                             i,
                             QString("Unit type %1 has no catalog entry; preserved").arg(value)});
                    }
                }
            }
        }
    }
    std::stable_sort(issues.begin(),
                     issues.end(),
                     [](auto &a, auto &block)
                     {
                         return a.error > block.error;
                     });
    return issues;
}

} // namespace bb
