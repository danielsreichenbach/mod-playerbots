/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LOOTSTRATEGYVALUE_H
#define _PLAYERBOT_LOOTSTRATEGYVALUE_H

#include "Value.h"

class LootStrategy;
class PlayerbotAI;

class LootStrategyValue : public ManualSetValue<LootStrategy *>
{
public:
    LootStrategyValue(PlayerbotAI *botAI, std::string const name = "loot strategy") : ManualSetValue<LootStrategy *>(botAI, normal, name) {}
    virtual ~LootStrategyValue();

    std::string const Save() override;
    bool Load(std::string const value) override;

    static LootStrategy *normal;
    static LootStrategy *gray;
    static LootStrategy *all;
    static LootStrategy *disenchant;
    static LootStrategy *instance(std::string const name);
};

#endif
