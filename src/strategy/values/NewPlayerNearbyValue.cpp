/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NewPlayerNearbyValue.h"
#include "Playerbots.h"

ObjectGuid NewPlayerNearbyValue::Calculate()
{
    GuidVector players = botAI->GetAiObjectContext()->GetValue<GuidVector>("nearest friendly players")->Get();
    GuidSet &alreadySeenPlayers = botAI->GetAiObjectContext()->GetValue<GuidSet &>("already seen players")->Get();
    for (ObjectGuid const guid : players)
    {
        if (alreadySeenPlayers.find(guid) == alreadySeenPlayers.end())
            return guid;
    }

    return ObjectGuid::Empty;
}
