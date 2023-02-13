/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TANKTARGETVALUE_H
#define _PLAYERBOT_TANKTARGETVALUE_H

#include "TargetValue.h"

class PlayerbotAI;

class TankTargetValue : public TargetValue
{
public:
    TankTargetValue(PlayerbotAI *botAI, std::string const name = "tank target") : TargetValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
