/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ResetInstancesAction.h"
#include "Playerbots.h"

bool ResetInstancesAction::Execute(Event event)
{
    WorldPacket packet(CMSG_RESET_INSTANCES, 0);
    bot->GetSession()->HandleResetInstancesOpcode(packet);

    botAI->TellMaster("Resetting all instances");
    return true;
}

bool ResetInstancesAction::isUseful()
{
    return botAI->GetGroupMaster() == bot;
};
