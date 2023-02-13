/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "IsMovingValue.h"
#include "Playerbots.h"

bool IsMovingValue::Calculate()
{
    Unit *target = AI_VALUE(Unit *, qualifier);

    if (!target)
        return false;

    return target->isMoving();
}

bool IsSwimmingValue::Calculate()
{
    Unit *target = AI_VALUE(Unit *, qualifier);

    if (!target)
        return false;

    return target->IsUnderWater() || target->IsInWater();
}
