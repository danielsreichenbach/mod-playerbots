/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "AttackerWithoutAuraTargetValue.h"
#include "Playerbots.h"

Unit *AttackerWithoutAuraTargetValue::Calculate()
{
    GuidVector attackers = botAI->GetAiObjectContext()->GetValue<GuidVector>("attackers")->Get();
    Unit *target = botAI->GetAiObjectContext()->GetValue<Unit *>("current target")->Get();
    for (ObjectGuid const guid : attackers)
    {
        Unit *unit = botAI->GetUnit(guid);
        if (!unit || unit == target)
            continue;

        if (bot->GetDistance(unit) > botAI->GetRange("spell"))
            continue;

        if (!botAI->HasAura(qualifier, unit))
            return unit;
    }

    return nullptr;
}
