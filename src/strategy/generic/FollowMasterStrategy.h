/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_FOLLOWMASTERSTRATEGY_H
#define _PLAYERBOT_FOLLOWMASTERSTRATEGY_H

#include "NonCombatStrategy.h"

class PlayerbotAI;

class FollowMasterStrategy : public NonCombatStrategy
{
public:
    FollowMasterStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "follow"; }
    NextAction **getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
