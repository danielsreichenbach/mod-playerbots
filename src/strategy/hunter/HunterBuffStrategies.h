/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HUNTERBUFFSTRATEGIES_H
#define _PLAYERBOT_HUNTERBUFFSTRATEGIES_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class HunterBuffSpeedStrategy : public NonCombatStrategy
{
public:
    HunterBuffSpeedStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "bspeed"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class HunterBuffManaStrategy : public NonCombatStrategy
{
public:
    HunterBuffManaStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "bmana"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class HunterBuffDpsStrategy : public NonCombatStrategy
{
public:
    HunterBuffDpsStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "bdps"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class HunterNatureResistanceStrategy : public NonCombatStrategy
{
public:
    HunterNatureResistanceStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "rnature"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
