/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_FROSTDKSTRATEGY_H
#define _PLAYERBOT_FROSTDKSTRATEGY_H

#include "GenericDKStrategy.h"

class PlayerbotAI;

class FrostDKStrategy : public GenericDKStrategy
{
public:
    FrostDKStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "frost"; }
    NextAction **getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
};

class FrostDKAoeStrategy : public CombatStrategy
{
public:
    FrostDKAoeStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "frost aoe"; }
};

#endif
