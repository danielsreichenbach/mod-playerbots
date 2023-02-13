/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RandomBotUpdateAction.h"
#include "Event.h"
#include "Playerbots.h"

bool RandomBotUpdateAction::Execute(Event event)
{
    if (!sRandomPlayerbotMgr->IsRandomBot(bot))
        return false;

    if (bot->GetGroup() && botAI->GetGroupMaster())
    {
        PlayerbotAI *groupMasterBotAI = GET_PLAYERBOT_AI(botAI->GetGroupMaster());
        if (!groupMasterBotAI || groupMasterBotAI->IsRealPlayer())
            return true;
    }

    if (botAI->HasPlayerNearby(sPlayerbotAIConfig->grindDistance))
        return true;

    return sRandomPlayerbotMgr->ProcessBot(bot);
}

bool RandomBotUpdateAction::isUseful()
{
    return AI_VALUE(bool, "random bot update");
}
