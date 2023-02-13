/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_VEHICLEACTIONS_H
#define _PLAYERBOT_VEHICLEACTIONS_H

#include "Event.h"
#include "MovementActions.h"

class PlayerbotAI;

class EnterVehicleAction : public MovementAction
{
public:
    EnterVehicleAction(PlayerbotAI *botAI, std::string const &name = "enter vehicle") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
};

class LeaveVehicleAction : public MovementAction
{
public:
    LeaveVehicleAction(PlayerbotAI *botAI, std::string const &name = "leave vehicle") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
};

#endif
