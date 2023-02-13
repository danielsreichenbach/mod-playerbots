/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RTIACTION_H
#define _PLAYERBOT_RTIACTION_H

#include "Action.h"

class PlayerbotAI;

class RtiAction : public Action
{
public:
    RtiAction(PlayerbotAI *botAI) : Action(botAI, "rti") {}

    bool Execute(Event event) override;

private:
    void AppendRti(std::ostringstream &out, std::string const type);
};

class MarkRtiAction : public Action
{
public:
    MarkRtiAction(PlayerbotAI *botAI) : Action(botAI, "mark rti") {}

    bool Execute(Event event) override;
};

#endif
