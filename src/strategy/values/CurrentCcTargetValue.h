/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CURRENTCCTARGETVALUE_H
#define _PLAYERBOT_CURRENTCCTARGETVALUE_H

#include "TargetValue.h"
#include "NamedObjectContext.h"

class PlayerbotAI;
class Unit;

class CurrentCcTargetValue : public TargetValue, public Qualified
{
public:
    CurrentCcTargetValue(PlayerbotAI *botAI, std::string const name = "current cc target") : TargetValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
