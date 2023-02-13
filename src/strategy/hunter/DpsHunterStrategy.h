/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_DPSHUNTERSTRATEGY_H
#define _PLAYERBOT_DPSHUNTERSTRATEGY_H

#include "GenericHunterStrategy.h"

class PlayerbotAI;

class DpsHunterStrategy : public GenericHunterStrategy
{
public:
    DpsHunterStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "dps"; }
    NextAction **getDefaultActions() override;
};

class DpsAoeHunterStrategy : public CombatStrategy
{
public:
    DpsAoeHunterStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "aoe"; }
};

class DpsHunterDebuffStrategy : public CombatStrategy
{
public:
    DpsHunterDebuffStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "dps debuff"; }
};

#endif
