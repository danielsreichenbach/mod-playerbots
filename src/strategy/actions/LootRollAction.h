/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LOOTROLLACTION_H
#define _PLAYERBOT_LOOTROLLACTION_H

#include "QueryItemUsageAction.h"

class PlayerbotAI;

struct ItemTemplate;

enum RollVote : uint32;

class LootRollAction : public QueryItemUsageAction
{
public:
    LootRollAction(PlayerbotAI *botAI, std::string const name = "loot roll") : QueryItemUsageAction(botAI, name) {}

    bool Execute(Event event) override;

protected:
    RollVote CalculateRollVote(ItemTemplate const *proto);
};

class MasterLootRollAction : public LootRollAction
{
public:
    MasterLootRollAction(PlayerbotAI *botAI) : LootRollAction(botAI, "master loot roll") {}

    bool isUseful() override;
    bool Execute(Event event) override;
};

#endif
