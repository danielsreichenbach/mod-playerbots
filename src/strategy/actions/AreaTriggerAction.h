/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_AREATRIGGERACTION_H
#define _PLAYERBOT_AREATRIGGERACTION_H

#include "MovementActions.h"

class PlayerbotAI;

class ReachAreaTriggerAction : public MovementAction
{
public:
    ReachAreaTriggerAction(PlayerbotAI *botAI) : MovementAction(botAI, "reach area trigger") {}

    bool Execute(Event event) override;
};

class AreaTriggerAction : public MovementAction
{
public:
    AreaTriggerAction(PlayerbotAI *botAI) : MovementAction(botAI, "area trigger") {}

    bool Execute(Event event) override;
};

#endif
