/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SELFTARGETVALUE_H
#define _PLAYERBOT_SELFTARGETVALUE_H

#include "Value.h"

class PlayerbotAI;
class Unit;

class SelfTargetValue : public UnitCalculatedValue
{
public:
    SelfTargetValue(PlayerbotAI *botAI, std::string const name = "self target") : UnitCalculatedValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
