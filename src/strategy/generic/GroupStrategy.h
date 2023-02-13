/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GROUPSTRATEGY_H
#define _PLAYERBOT_GROUPSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GroupStrategy : public NonCombatStrategy
{
public:
    GroupStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "group"; }
    uint32 GetType() const override { return STRATEGY_TYPE_GENERIC; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
