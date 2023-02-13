/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_DPSTARGETVALUE_H
#define _PLAYERBOT_DPSTARGETVALUE_H

#include "RtiTargetValue.h"

class PlayerbotAI;

class DpsTargetValue : public RtiTargetValue
{
public:
    DpsTargetValue(PlayerbotAI *botAI, std::string const type = "rti", std::string const name = "dps target") : RtiTargetValue(botAI, type, name) {}

    Unit *Calculate() override;
};

class DpsAoeTargetValue : public RtiTargetValue
{
public:
    DpsAoeTargetValue(PlayerbotAI *botAI, std::string const type = "rti", std::string const name = "dps aoe target") : RtiTargetValue(botAI, type, name) {}

    Unit *Calculate() override;
};

#endif
