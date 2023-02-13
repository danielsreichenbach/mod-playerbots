/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HEALPALADINSTRATEGY_H
#define _PLAYERBOT_HEALPALADINSTRATEGY_H

#include "GenericPaladinStrategy.h"

class PlayerbotAI;

class HealPaladinStrategy : public GenericPaladinStrategy
{
public:
    HealPaladinStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "heal"; }
    NextAction **getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_HEAL | STRATEGY_TYPE_MELEE; }
};

#endif
