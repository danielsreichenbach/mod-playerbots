/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TELEPORTACTION_H
#define _PLAYERBOT_TELEPORTACTION_H

#include "Action.h"

class PlayerbotAI;

class TeleportAction : public Action
{
public:
    TeleportAction(PlayerbotAI *botAI) : Action(botAI, "teleport") {}

    bool Execute(Event event) override;
};

#endif
