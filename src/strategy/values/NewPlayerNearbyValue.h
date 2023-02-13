/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_NEWPLAYERNEARBYVALUE_H
#define _PLAYERBOT_NEWPLAYERNEARBYVALUE_H

#include "ObjectGuid.h"
#include "Value.h"

class PlayerbotAI;

class NewPlayerNearbyValue : public CalculatedValue<ObjectGuid>
{
public:
    NewPlayerNearbyValue(PlayerbotAI *botAI) : CalculatedValue<ObjectGuid>(botAI, "new player nearby") {}

    ObjectGuid Calculate() override;
};

class AlreadySeenPlayersValue : public ManualSetValue<GuidSet &>
{
public:
    AlreadySeenPlayersValue(PlayerbotAI *botAI) : ManualSetValue<GuidSet &>(botAI, data, "already seen players") {}

    GuidSet data;
};

#endif
