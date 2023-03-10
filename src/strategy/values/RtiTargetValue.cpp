/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RtiTargetValue.h"
#include "Playerbots.h"
#include "ServerFacade.h"

int32 RtiTargetValue::GetRtiIndex(std::string const rti)
{
    int32 index = -1;
    if (rti == "star")
        index = 0;
    else if (rti == "circle")
        index = 1;
    else if (rti == "diamond")
        index = 2;
    else if (rti == "triangle")
        index = 3;
    else if (rti == "moon")
        index = 4;
    else if (rti == "square")
        index = 5;
    else if (rti == "cross")
        index = 6;
    else if (rti == "skull")
        index = 7;

    return index;
}

Unit *RtiTargetValue::Calculate()
{
    Group *group = bot->GetGroup();
    if (!group)
        return nullptr;

    std::string const rti = AI_VALUE(std::string, type);
    int32 index = GetRtiIndex(rti);

    if (index == -1)
        return nullptr;

    ObjectGuid guid = group->GetTargetIcon(index);
    if (!guid)
        return nullptr;

    GuidVector attackers = context->GetValue<GuidVector>("attackers")->Get();
    if (find(attackers.begin(), attackers.end(), guid) == attackers.end())
        return nullptr;

    Unit *unit = botAI->GetUnit(guid);
    if (!unit || unit->isDead() || !bot->IsWithinLOSInMap(unit) || sServerFacade->IsDistanceGreaterThan(sServerFacade->GetDistance2d(bot, unit), sPlayerbotAIConfig->sightDistance))
        return nullptr;

    return unit;
}
