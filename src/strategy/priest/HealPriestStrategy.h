/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HEALPRIESTSTRATEGY_H
#define _PLAYERBOT_HEALPRIESTSTRATEGY_H

#include "GenericPriestStrategy.h"

class PlayerbotAI;

class HealPriestStrategy : public GenericPriestStrategy
{
public:
    HealPriestStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    NextAction **getDefaultActions() override;
    std::string const getName() override { return "heal"; }
    uint32 GetType() const override { return STRATEGY_TYPE_HEAL; }
};

#endif
