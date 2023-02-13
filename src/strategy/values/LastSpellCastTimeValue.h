/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LASTSPELLCASTTIMEVALUE_H
#define _PLAYERBOT_LASTSPELLCASTTIMEVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;

class LastSpellCastTimeValue : public ManualSetValue<time_t>, public Qualified
{
public:
    LastSpellCastTimeValue(PlayerbotAI *botAI) : ManualSetValue<time_t>(botAI, 0), Qualified() {}
};

#endif
