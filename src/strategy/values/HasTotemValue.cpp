/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "HasTotemValue.h"
#include "Playerbots.h"

char *strstri(char const *str1, char const *str2);

bool HasTotemValue::Calculate()
{
    GuidVector units = *context->GetValue<GuidVector>("nearest npcs");
    for (ObjectGuid const guid : units)
    {
        Unit *unit = botAI->GetUnit(guid);
        if (!unit)
            continue;

        Creature *creature = dynamic_cast<Creature *>(unit);
        if (!creature || !creature->IsTotem())
            continue;

        if (strstri(creature->GetName().c_str(), qualifier.c_str()) && bot->GetDistance(creature) <= botAI->GetRange("spell"))
            return true;
    }

    return false;
}
