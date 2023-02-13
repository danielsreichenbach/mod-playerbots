/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GOACTION_H
#define _PLAYERBOT_GOACTION_H

#include "MovementActions.h"

class PlayerbotAI;

class GoAction : public MovementAction
{
public:
    GoAction(PlayerbotAI *botAI) : MovementAction(botAI, "Go") {}

    bool Execute(Event event) override;
};

#endif
