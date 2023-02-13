/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GRINDINGSTRATEGY_H
#define _PLAYERBOT_GRINDINGSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GrindingStrategy : public NonCombatStrategy
{
public:
    GrindingStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "grind"; }
    uint32 GetType() const override { return STRATEGY_TYPE_DPS; }
    NextAction **getDefaultActions();
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
