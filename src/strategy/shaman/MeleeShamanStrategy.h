/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MELEESHAMANSTRATEGY_H
#define _PLAYERBOT_MELEESHAMANSTRATEGY_H

#include "GenericShamanStrategy.h"

class PlayerbotAI;

class MeleeShamanStrategy : public GenericShamanStrategy
{
public:
    MeleeShamanStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    NextAction **getDefaultActions() override;
    std::string const getName() override { return "melee"; }
    uint32 GetType() const override { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
};

class MeleeAoeShamanStrategy : public CombatStrategy
{
public:
    MeleeAoeShamanStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "melee aoe"; }
};

#endif
