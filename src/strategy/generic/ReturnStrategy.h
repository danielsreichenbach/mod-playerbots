/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RETURNSTRATEGY_H
#define _PLAYERBOT_RETURNSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class ReturnStrategy : public NonCombatStrategy
{
public:
    ReturnStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "return"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
