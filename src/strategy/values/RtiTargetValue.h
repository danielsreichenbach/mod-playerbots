/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RTITARGETVALUE_H
#define _PLAYERBOT_RTITARGETVALUE_H

#include "TargetValue.h"

class PlayerbotAI;
class Unit;

class RtiTargetValue : public TargetValue
{
public:
    RtiTargetValue(PlayerbotAI *botAI, std::string const type = "rti", std::string const name = "rti target") : type(type), TargetValue(botAI, name) {}

    static int32 GetRtiIndex(std::string const rti);
    Unit *Calculate() override;

private:
    std::string const type;
};

class RtiCcTargetValue : public RtiTargetValue
{
public:
    RtiCcTargetValue(PlayerbotAI *botAI, std::string const name = "rti cc target") : RtiTargetValue(botAI, "rti cc", name) {}
};

#endif
