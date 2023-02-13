/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICHUNTERNONCOMBATSTRATEGY_H
#define _PLAYERBOT_GENERICHUNTERNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GenericHunterNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericHunterNonCombatStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class HunterPetStrategy : public Strategy
{
public:
    HunterPetStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    std::string const getName() override { return "pet"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
