/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "AoeHealValues.h"
#include "Playerbots.h"

uint8 AoeHealValue::Calculate()
{
    Group *group = bot->GetGroup();
    if (!group)
        return 0;

    float range = 0;
    if (qualifier == "low")
        range = sPlayerbotAIConfig->lowHealth;
    else if (qualifier == "medium")
        range = sPlayerbotAIConfig->mediumHealth;
    else if (qualifier == "critical")
        range = sPlayerbotAIConfig->criticalHealth;

    uint8 count = 0;
    Group::MemberSlotList const &groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *player = ObjectAccessor::FindPlayer(itr->guid);
        if (!player || !player->IsAlive())
            continue;

        float percent = (static_cast<float>(player->GetHealth()) / player->GetMaxHealth()) * 100;
        if (percent <= range)
            ++count;
    }

    return count;
}
