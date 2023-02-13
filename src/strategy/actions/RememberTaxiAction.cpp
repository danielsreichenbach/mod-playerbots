/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RememberTaxiAction.h"
#include "Event.h"
#include "LastMovementValue.h"
#include "Playerbots.h"

bool RememberTaxiAction::Execute(Event event)
{
    WorldPacket p(event.getPacket());
    p.rpos(0);

    switch (p.GetOpcode())
    {
    case CMSG_ACTIVATETAXI:
    {
        LastMovement &movement = context->GetValue<LastMovement &>("last taxi")->Get();
        movement.taxiNodes.clear();
        movement.taxiNodes.resize(2);

        p >> movement.taxiMaster >> movement.taxiNodes[0] >> movement.taxiNodes[1];
        return true;
    }
    case CMSG_ACTIVATETAXIEXPRESS:
    {
        ObjectGuid guid;
        uint32 node_count, totalcost;
        p >> guid >> node_count;

        LastMovement &movement = context->GetValue<LastMovement &>("last taxi")->Get();
        movement.taxiNodes.clear();
        for (uint32 i = 0; i < node_count; ++i)
        {
            uint32 node;
            p >> node;
            movement.taxiNodes.push_back(node);
        }

        return true;
    }
    }

    return false;
}
