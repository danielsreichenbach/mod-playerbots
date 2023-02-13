/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CURRENTTARGETVALUE_H
#define _PLAYERBOT_CURRENTTARGETVALUE_H

#include "Value.h"

class PlayerbotAI;
class Unit;

class CurrentTargetValue : public UnitManualSetValue
{
public:
    CurrentTargetValue(PlayerbotAI *botAI, std::string const name = "current target") : UnitManualSetValue(botAI, nullptr, name) {}

    Unit *Get() override;
    void Set(Unit *unit) override;

private:
    ObjectGuid selection;
};

#endif
