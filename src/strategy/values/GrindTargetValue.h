/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GRINDTARGETVALUE_H
#define _PLAYERBOT_GRINDTARGETVALUE_H

#include "TargetValue.h"

class PlayerbotAI;
class Unit;

class GrindTargetValue : public TargetValue
{
public:
    GrindTargetValue(PlayerbotAI *botAI, std::string const name = "grind target") : TargetValue(botAI, name) {}

    Unit *Calculate() override;

private:
    uint32 GetTargetingPlayerCount(Unit *unit);
    Unit *FindTargetForGrinding(uint32 assistCount);
    bool needForQuest(Unit *target);
};

#endif
