/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ACCEPTRESURRECTACTION_H
#define _PLAYERBOT_ACCEPTRESURRECTACTION_H

#include "Action.h"

class PlayerbotAI;

class AcceptResurrectAction : public Action
{
public:
    AcceptResurrectAction(PlayerbotAI *botAI) : Action(botAI, "accept resurrect") {}

    bool Execute(Event event) override;
};

#endif
