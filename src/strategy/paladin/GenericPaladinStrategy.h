/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICPALADINSTRATEGY_H
#define _PLAYERBOT_GENERICPALADINSTRATEGY_H

#include "CombatStrategy.h"

class PlayerbotAI;

class GenericPaladinStrategy : public CombatStrategy
{
public:
    GenericPaladinStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "paladin"; }
};

class PaladinCureStrategy : public Strategy
{
public:
    PaladinCureStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cure"; }
};

class PaladinBoostStrategy : public Strategy
{
public:
    PaladinBoostStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "boost"; }
};

class PaladinCcStrategy : public Strategy
{
public:
    PaladinCcStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "cc"; }
};

#endif
