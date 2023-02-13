/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "WorldPacketTrigger.h"
#include "Playerbots.h"

void WorldPacketTrigger::ExternalEvent(WorldPacket &revData, Player *eventOwner)
{
    packet = revData;
    owner = eventOwner;
    triggered = true;
}

Event WorldPacketTrigger::Check()
{
    if (!triggered)
        return Event();

    return Event(getName(), packet, owner);
}

void WorldPacketTrigger::Reset()
{
    triggered = false;
}
