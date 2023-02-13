/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICHUNTERSTRATEGY_H
#define _PLAYERBOT_GENERICHUNTERSTRATEGY_H

#include "CombatStrategy.h"

class PlayerbotAI;

class GenericHunterStrategy : public CombatStrategy
{
public:
    GenericHunterStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "hunter"; }
};

class HunterBoostStrategy : public Strategy
{
public:
    HunterBoostStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    std::string const getName() override { return "boost"; }
    NextAction **getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class HunterCcStrategy : public Strategy
{
public:
    HunterCcStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cc"; }
};

#endif
