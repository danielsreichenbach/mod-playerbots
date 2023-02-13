/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICMAGENONCOMBATSTRATEGY_H
#define _PLAYERBOT_GENERICMAGENONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GenericMageNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericMageNonCombatStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class MageBuffManaStrategy : public Strategy
{
public:
    MageBuffManaStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bmana"; }
};

class MageBuffDpsStrategy : public Strategy
{
public:
    MageBuffDpsStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bdps"; }
};

class MageBuffStrategy : public Strategy
{
public:
    MageBuffStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "buff"; }
};

#endif
