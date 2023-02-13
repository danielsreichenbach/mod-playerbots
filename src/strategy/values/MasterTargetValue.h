/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MASTERTARGETVALUE_H
#define _PLAYERBOT_MASTERTARGETVALUE_H

#include "Value.h"

class PlayerbotAI;
class Unit;

class MasterTargetValue : public UnitCalculatedValue
{
public:
    MasterTargetValue(PlayerbotAI *botAI, std::string const name = "master target") : UnitCalculatedValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
