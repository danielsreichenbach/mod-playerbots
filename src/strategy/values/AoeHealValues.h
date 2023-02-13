/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_AOEHEALVALUES_H
#define _PLAYERBOT_AOEHEALVALUES_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;

class AoeHealValue : public Uint8CalculatedValue, public Qualified
{
public:
    AoeHealValue(PlayerbotAI *botAI, std::string const name = "aoe heal") : Uint8CalculatedValue(botAI, name) {}

    uint8 Calculate() override;
};

#endif
