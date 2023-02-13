/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_AVAILABLELOOTVALUE_H
#define _PLAYERBOT_AVAILABLELOOTVALUE_H

#include "LootObjectStack.h"
#include "Value.h"

class PlayerbotAI;

class AvailableLootValue : public ManualSetValue<LootObjectStack *>
{
public:
    AvailableLootValue(PlayerbotAI *botAI, std::string const name = "available loot");
    virtual ~AvailableLootValue();
};

class LootTargetValue : public ManualSetValue<LootObject>
{
public:
    LootTargetValue(PlayerbotAI *botAI, std::string const name = "loot target");
};

class CanLootValue : public BoolCalculatedValue
{
public:
    CanLootValue(PlayerbotAI *botAI, std::string const name = "can loot") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

#endif
