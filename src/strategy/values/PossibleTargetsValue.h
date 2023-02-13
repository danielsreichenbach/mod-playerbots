/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_POSSIBLETARGETSVALUE_H
#define _PLAYERBOT_POSSIBLETARGETSVALUE_H

#include "NearestUnitsValue.h"
#include "PlayerbotAIConfig.h"

class PlayerbotAI;

class PossibleTargetsValue : public NearestUnitsValue
{
public:
    PossibleTargetsValue(PlayerbotAI *botAI, std::string const name = "possible targets", float range = sPlayerbotAIConfig->sightDistance, bool ignoreLos = false) : NearestUnitsValue(botAI, name, range, ignoreLos) {}

protected:
    void FindUnits(std::list<Unit *> &targets) override;
    bool AcceptUnit(Unit *unit) override;
};

class AllTargetsValue : public PossibleTargetsValue
{
public:
    AllTargetsValue(PlayerbotAI *botAI, float range = sPlayerbotAIConfig->sightDistance) : PossibleTargetsValue(botAI, "all targets", range, true) {}
};

#endif
