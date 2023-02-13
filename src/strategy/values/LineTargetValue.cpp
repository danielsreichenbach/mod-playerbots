/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "LineTargetValue.h"
#include "Playerbots.h"

Unit *LineTargetValue::Calculate()
{
    Player *master = GetMaster();
    if (!master)
        return nullptr;

    Group *group = master->GetGroup();
    if (!group)
        return nullptr;

    Player *prev = master;
    Group::MemberSlotList const &groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *player = ObjectAccessor::FindPlayer(itr->guid);
        if (!player || !player->IsAlive() || player == master)
            continue;

        if (player == bot)
            return prev;

        prev = player;
    }

    return master;
}
