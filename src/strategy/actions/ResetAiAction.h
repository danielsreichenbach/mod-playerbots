/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RESETAIACTION_H
#define _PLAYERBOT_RESETAIACTION_H

#include "Action.h"

class PlayerbotAI;

class ResetAiAction : public Action
{
public:
    ResetAiAction(PlayerbotAI *botAI) : Action(botAI, "reset botAI") {}

    bool Execute(Event event) override;
};

#endif
