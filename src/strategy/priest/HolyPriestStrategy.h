/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HOLYPRIESTSTRATEGY_H
#define _PLAYERBOT_HOLYPRIESTSTRATEGY_H

#include "HealPriestStrategy.h"

class PlayerbotAI;

class HolyPriestStrategy : public HealPriestStrategy
{
public:
    HolyPriestStrategy(PlayerbotAI *botAI);

    NextAction **getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "holy"; }
    uint32 GetType() const override { return STRATEGY_TYPE_DPS | STRATEGY_TYPE_RANGED; }
};

#endif
