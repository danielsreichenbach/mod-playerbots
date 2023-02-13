/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "IsBehindValue.h"
#include "Playerbots.h"

bool IsBehindValue::Calculate()
{
    Unit *target = AI_VALUE(Unit *, qualifier);
    if (!target)
        return false;

    float targetOrientation = target->GetOrientation();
    float orientation = bot->GetOrientation();
    float distance = bot->GetDistance(target);

    return distance <= ATTACK_DISTANCE && abs(targetOrientation - orientation) < M_PI / 2;
}
