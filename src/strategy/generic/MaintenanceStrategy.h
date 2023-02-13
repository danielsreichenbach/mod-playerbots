/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MAINTANCESTRATEGY_H
#define _PLAYERBOT_MAINTANCESTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class MaintenanceStrategy : public NonCombatStrategy
{
public:
    MaintenanceStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "maintenance"; }
    uint32 GetType() const override { return STRATEGY_TYPE_NONCOMBAT; }
    NextAction **getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
