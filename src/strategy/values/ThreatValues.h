/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_THREATVALUES_H
#define _PLAYERBOT_THREATVALUES_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;
class Unit;

class ThreatValue : public Uint8CalculatedValue, public Qualified
{
public:
    ThreatValue(PlayerbotAI *botAI, std::string const name = "threat") : Uint8CalculatedValue(botAI, name) {}

    uint8 Calculate() override;

protected:
    uint8 Calculate(Unit *target);
};

#endif
