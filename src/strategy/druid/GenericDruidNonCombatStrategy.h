/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICDRUIDNONCOMBATSTRATEGY_H
#define _PLAYERBOT_GENERICDRUIDNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GenericDruidNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericDruidNonCombatStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class GenericDruidBuffStrategy : public NonCombatStrategy
{
public:
    GenericDruidBuffStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "buff"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
