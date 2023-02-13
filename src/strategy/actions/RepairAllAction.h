/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_REPAIRALLACTION_H
#define _PLAYERBOT_REPAIRALLACTION_H

#include "Action.h"

class PlayerbotAI;

class RepairAllAction : public Action
{
public:
    RepairAllAction(PlayerbotAI *botAI) : Action(botAI, "repair") {}

    bool Execute(Event event) override;
};

#endif
