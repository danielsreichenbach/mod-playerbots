/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ATTACKENEMYPAYERSSTRATEGYACTION_H
#define _PLAYERBOT_ATTACKENEMYPAYERSSTRATEGYACTION_H

#include "NonCombatStrategy.h"

class AttackEnemyPlayersStrategy : public NonCombatStrategy
{
public:
    AttackEnemyPlayersStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "pvp"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
