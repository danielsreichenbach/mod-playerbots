/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RESETINSTANCESACTION_H
#define _PLAYERBOT_RESETINSTANCESACTION_H

#include "Action.h"

class PlayerbotAI;

class ResetInstancesAction : public Action
{
public:
    ResetInstancesAction(PlayerbotAI *botAI) : Action(botAI, "reset instances") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
