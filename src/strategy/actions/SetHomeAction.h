/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SETHOMEACTION_H
#define _PLAYERBOT_SETHOMEACTION_H

#include "MovementActions.h"

class PlayerbotAI;

class SetHomeAction : public MovementAction
{
public:
    SetHomeAction(PlayerbotAI *botAI) : MovementAction(botAI, "home") {}

    bool Execute(Event event) override;
};

#endif
