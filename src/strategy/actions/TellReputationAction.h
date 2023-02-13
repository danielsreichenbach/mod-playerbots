/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TELLREPUTATIONACTION_H
#define _PLAYERBOT_TELLREPUTATIONACTION_H

#include "Action.h"

class PlayerbotAI;

class TellReputationAction : public Action
{
public:
    TellReputationAction(PlayerbotAI *botAI) : Action(botAI, "reputation") {}

    bool Execute(Event event) override;
};

#endif
