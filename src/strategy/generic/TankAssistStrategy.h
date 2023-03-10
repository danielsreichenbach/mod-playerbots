/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TANKASSISTSTRATEGY_H
#define _PLAYERBOT_TANKASSISTSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class TankAssistStrategy : public Strategy
{
public:
    TankAssistStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    std::string const getName() override { return "tank assist"; }
    uint32 GetType() const override { return STRATEGY_TYPE_TANK; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
