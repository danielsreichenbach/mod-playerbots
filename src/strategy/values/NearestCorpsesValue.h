/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_NEARESTCORPSESVALUE_H
#define _PLAYERBOT_NEARESTCORPSESVALUE_H

#include "NearestUnitsValue.h"
#include "PlayerbotAIConfig.h"

class PlayerbotAI;

class NearestCorpsesValue : public NearestUnitsValue
{
public:
    NearestCorpsesValue(PlayerbotAI *botAI, float range = sPlayerbotAIConfig->sightDistance) : NearestUnitsValue(botAI, "nearest corpses", range) {}

protected:
    void FindUnits(std::list<Unit *> &targets) override;
    bool AcceptUnit(Unit *unit) override;
};

#endif
