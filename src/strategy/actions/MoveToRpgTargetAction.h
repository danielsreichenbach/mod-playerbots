/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MOVETORPGTARGETACTION_H
#define _PLAYERBOT_MOVETORPGTARGETACTION_H

#include "MovementActions.h"

class PlayerbotAI;

class MoveToRpgTargetAction : public MovementAction
{
public:
    MoveToRpgTargetAction(PlayerbotAI *botAI) : MovementAction(botAI, "move to rpg target") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
