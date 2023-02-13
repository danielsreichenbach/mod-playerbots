/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_DPSWARLOCKSTRATEGY_H
#define _PLAYERBOT_DPSWARLOCKSTRATEGY_H

#include "GenericWarlockStrategy.h"

class PlayerbotAI;

class DpsWarlockStrategy : public GenericWarlockStrategy
{
public:
    DpsWarlockStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "dps"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    NextAction **getDefaultActions() override;
};

class DpsAoeWarlockStrategy : public CombatStrategy
{
public:
    DpsAoeWarlockStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "aoe"; }
};

class DpsWarlockDebuffStrategy : public CombatStrategy
{
public:
    DpsWarlockDebuffStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "dps debuff"; }
};

#endif
