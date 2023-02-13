/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ARENATEAMACTION_H
#define _PLAYERBOT_ARENATEAMACTION_H

#include "Action.h"

class PlayerbotAI;

class ArenaTeamAcceptAction : public Action
{
public:
    ArenaTeamAcceptAction(PlayerbotAI *botAI) : Action(botAI, "arena team accept") {}

    bool Execute(Event event) override;
};

#endif
