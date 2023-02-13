/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ISFACINGVALUE_H
#define _PLAYERBOT_ISFACINGVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;

class IsFacingValue : public BoolCalculatedValue, public Qualified
{
public:
    IsFacingValue(PlayerbotAI *botAI, std::string const name = "is facing") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

#endif
