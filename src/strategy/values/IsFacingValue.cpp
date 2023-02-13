/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "IsFacingValue.h"
#include "Playerbots.h"

bool IsFacingValue::Calculate()
{
    Unit *target = AI_VALUE(Unit *, qualifier);
    if (!target)
        return false;

    return bot->HasInArc(CAST_ANGLE_IN_FRONT, target, sPlayerbotAIConfig->sightDistance);
}
