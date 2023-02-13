/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NearestAdsValue.h"
#include "Playerbots.h"

bool NearestAddsValue::AcceptUnit(Unit *unit)
{
    Unit *target = AI_VALUE(Unit *, "current target");
    return unit != target;
}
