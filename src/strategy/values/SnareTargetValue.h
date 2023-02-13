/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SNARETARGETVALUE_H
#define _PLAYERBOT_SNARETARGETVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;
class Unit;

class SnareTargetValue : public UnitCalculatedValue, public Qualified
{
public:
    SnareTargetValue(PlayerbotAI *botAI) : UnitCalculatedValue(botAI, "snare target") {}

protected:
    Unit *Calculate() override;
};

#endif
