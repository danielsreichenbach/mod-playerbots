/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PRIESTNONCOMBATSTRATEGY_H
#define _PLAYERBOT_PRIESTNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class PriestNonCombatStrategy : public NonCombatStrategy
{
public:
    PriestNonCombatStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "nc"; }
};

class PriestBuffStrategy : public NonCombatStrategy
{
public:
    PriestBuffStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "buff"; }
};

class PriestShadowResistanceStrategy : public NonCombatStrategy
{
public:
    PriestShadowResistanceStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "rshadow"; }
};

#endif
