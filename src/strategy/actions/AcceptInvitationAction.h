/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ACCEPTINVITATIONACTION_H
#define _PLAYERBOT_ACCEPTINVITATIONACTION_H

#include "Action.h"

class PlayerbotAI;

class AcceptInvitationAction : public Action
{
public:
    AcceptInvitationAction(PlayerbotAI *botAI) : Action(botAI, "accept invitation") {}

    bool Execute(Event event) override;
};

#endif
