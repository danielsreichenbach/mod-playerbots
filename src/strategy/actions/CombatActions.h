/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_COMBATACTIONS_H
#define _PLAYERBOT_COMBATACTIONS_H

#include "ChangeStrategyAction.h"

class PlayerbotAI;

class SwitchToMeleeAction : public ChangeCombatStrategyAction
{
public:
    SwitchToMeleeAction(PlayerbotAI *botAI) : ChangeCombatStrategyAction(botAI, "-ranged,+close") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class SwitchToRangedAction : public ChangeCombatStrategyAction
{
public:
    SwitchToRangedAction(PlayerbotAI *botAI) : ChangeCombatStrategyAction(botAI, "-close,+ranged") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
