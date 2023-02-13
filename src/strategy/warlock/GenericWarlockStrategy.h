/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICWARLOCKSTRATEGY_H
#define _PLAYERBOT_GENERICWARLOCKSTRATEGY_H

#include "CombatStrategy.h"

class PlayerbotAI;

class GenericWarlockStrategy : public CombatStrategy
{
public:
    GenericWarlockStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "warlock"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    NextAction **getDefaultActions() override;
};

class WarlockBoostStrategy : public Strategy
{
public:
    WarlockBoostStrategy(PlayerbotAI *botAI) : Strategy(botAI){};

    std::string const getName() override { return "boost"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class WarlockCcStrategy : public Strategy
{
public:
    WarlockCcStrategy(PlayerbotAI *botAI) : Strategy(botAI){};

    std::string const getName() override { return "cc"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
