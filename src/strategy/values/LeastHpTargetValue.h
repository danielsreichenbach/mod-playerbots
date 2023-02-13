/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LEASTHPTARGETVALUE_H
#define _PLAYERBOT_LEASTHPTARGETVALUE_H

#include "TargetValue.h"

class PlayerbotAI;
class Unit;

class LeastHpTargetValue : public TargetValue
{
public:
    LeastHpTargetValue(PlayerbotAI *botAI, std::string const name = "least hp target") : TargetValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
