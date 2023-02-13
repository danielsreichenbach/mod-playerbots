/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ACCEPTDUELACTION_H
#define _PLAYERBOT_ACCEPTDUELACTION_H

#include "Action.h"

class PlayerbotAI;

class AcceptDuelAction : public Action
{
public:
    AcceptDuelAction(PlayerbotAI *botAI) : Action(botAI, "accept duel") {}

    bool Execute(Event event) override;
};

#endif
