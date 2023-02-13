/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICDRUIDSTRATEGY_H
#define _PLAYERBOT_GENERICDRUIDSTRATEGY_H

#include "CombatStrategy.h"

class PlayerbotAI;

class GenericDruidStrategy : public CombatStrategy
{
protected:
    GenericDruidStrategy(PlayerbotAI *botAI);

public:
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class DruidCureStrategy : public Strategy
{
public:
    DruidCureStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cure"; }
};

class DruidBoostStrategy : public Strategy
{
public:
    DruidBoostStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "boost"; }
};

class DruidCcStrategy : public Strategy
{
public:
    DruidCcStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cc"; }
};

#endif
