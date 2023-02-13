/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ISBEHINDVALUE_H
#define _PLAYERBOT_ISBEHINDVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;

class IsBehindValue : public BoolCalculatedValue, public Qualified
{
public:
    IsBehindValue(PlayerbotAI *botAI) : BoolCalculatedValue(botAI) {}

    bool Calculate() override;
};

#endif
