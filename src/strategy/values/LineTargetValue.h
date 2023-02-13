/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LINETARGETVALUE_H
#define _PLAYERBOT_LINETARGETVALUE_H

#include "Value.h"

class PlayerbotAI;
class Unit;

class LineTargetValue : public UnitCalculatedValue
{
public:
    LineTargetValue(PlayerbotAI *botAI, std::string const name = "line target") : UnitCalculatedValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
