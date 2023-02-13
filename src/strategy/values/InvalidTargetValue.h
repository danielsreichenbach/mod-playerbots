/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_INVALIDTARGETVALUE_H
#define _PLAYERBOT_INVALIDTARGETVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;

class InvalidTargetValue : public BoolCalculatedValue, public Qualified
{
public:
    InvalidTargetValue(PlayerbotAI *botAI, std::string const name = "invalid target") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

#endif
