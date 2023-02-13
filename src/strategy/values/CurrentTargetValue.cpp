/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "CurrentTargetValue.h"
#include "Playerbots.h"

Unit *CurrentTargetValue::Get()
{
    if (selection.IsEmpty())
        return nullptr;

    Unit *unit = ObjectAccessor::GetUnit(*bot, selection);
    if (unit && !bot->IsWithinLOSInMap(unit))
        return nullptr;

    return unit;
}

void CurrentTargetValue::Set(Unit *target)
{
    selection = target ? target->GetGUID() : ObjectGuid::Empty;
}
