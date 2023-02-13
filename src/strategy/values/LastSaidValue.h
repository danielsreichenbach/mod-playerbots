/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LASTSAIDVALUE_H
#define _PLAYERBOT_LASTSAIDVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;

class LastSaidValue : public ManualSetValue<time_t>, public Qualified
{
public:
    LastSaidValue(PlayerbotAI *botAI) : ManualSetValue<time_t>(botAI, time(nullptr) - 120, "last said") {}
};

class LastEmoteValue : public ManualSetValue<time_t>, public Qualified
{
public:
    LastEmoteValue(PlayerbotAI *botAI) : ManualSetValue<time_t>(botAI, time(nullptr) - 120, "last emote") {}
};

#endif
