/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GUARDSTRATEGY_H
#define _PLAYERBOT_GUARDSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class GuardStrategy : public NonCombatStrategy
{
public:
    GuardStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "guard"; }
    NextAction **getDefaultActions();
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
