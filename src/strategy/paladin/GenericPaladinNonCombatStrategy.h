/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICPALADINNONCOMBATSTRATEGY_H
#define _PLAYERBOT_GENERICPALADINNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GenericPaladinNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericPaladinNonCombatStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
