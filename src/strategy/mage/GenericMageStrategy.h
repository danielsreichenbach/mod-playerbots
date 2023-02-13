/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICMAGESTRATEGY_H
#define _PLAYERBOT_GENERICMAGESTRATEGY_H

#include "CombatStrategy.h"

class PlayerbotAI;

class GenericMageStrategy : public CombatStrategy
{
public:
    GenericMageStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "mage"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class MageCureStrategy : public Strategy
{
public:
    MageCureStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cure"; }
};

class MageBoostStrategy : public Strategy
{
public:
    MageBoostStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "boost"; }
};

class MageCcStrategy : public Strategy
{
public:
    MageCcStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cc"; }
};

#endif
