/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NearestUnitsValue.h"
#include "Playerbots.h"

GuidVector NearestUnitsValue::Calculate()
{
    std::list<Unit *> targets;
    FindUnits(targets);

    GuidVector results;
    for (Unit *unit : targets)
    {
        if ((ignoreLos || bot->IsWithinLOSInMap(unit)) && AcceptUnit(unit))
            results.push_back(unit->GetGUID());
    }

    return results;
}
