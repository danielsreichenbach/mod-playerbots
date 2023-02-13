/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SHAMANNONCOMBATSTRATEGY_H
#define _PLAYERBOT_SHAMANNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class ShamanNonCombatStrategy : public NonCombatStrategy
{
public:
    ShamanNonCombatStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    void InitMultipliers(std::vector<Multiplier *> &multipliers) override;
    std::string const getName() override { return "nc"; }
};

#endif
