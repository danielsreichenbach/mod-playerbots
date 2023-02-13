/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LOOTSTRATEGYACTION_H
#define _PLAYERBOT_LOOTSTRATEGYACTION_H

#include "Action.h"

class PlayerbotAI;

class LootStrategyAction : public Action
{
public:
    LootStrategyAction(PlayerbotAI *botAI) : Action(botAI, "ll") {}

    bool Execute(Event event) override;
};

#endif
