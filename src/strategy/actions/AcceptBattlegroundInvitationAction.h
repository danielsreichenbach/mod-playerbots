/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ACCEPTBATTLEGROUNDINVITATIONACTION_H
#define _PLAYERBOT_ACCEPTBATTLEGROUNDINVITATIONACTION_H

#include "Action.h"

class PlayerbotAI;

class AcceptBgInvitationAction : public Action
{
public:
    AcceptBgInvitationAction(PlayerbotAI *botAI) : Action(botAI, "accept bg invitatio") {}

    bool Execute(Event event) override;
};

#endif
