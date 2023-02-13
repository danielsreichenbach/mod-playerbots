/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "TravelTriggers.h"
#include "Playerbots.h"
#include "ServerFacade.h"

bool NoTravelTargetTrigger::IsActive()
{
    return !context->GetValue<TravelTarget *>("travel target")->Get()->isActive();
}

bool FarFromTravelTargetTrigger::IsActive()
{
    return context->GetValue<TravelTarget *>("travel target")->Get()->isTraveling();
}

bool NearDarkPortalTrigger::IsActive()
{
    return bot->GetAreaId() == 72;
}

bool AtDarkPortalAzerothTrigger::IsActive()
{
    if (bot->GetAreaId() == 72)
    {
        if (sServerFacade->GetDistance2d(bot, -11906.9f, -3208.53f) < 20.0f)
        {
            return true;
        }
    }

    return false;
}

bool AtDarkPortalOutlandTrigger::IsActive()
{
    if (bot->GetAreaId() == 3539)
    {
        if (sServerFacade->GetDistance2d(bot, -248.1939f, 921.919f) < 10.0f)
        {
            return true;
        }
    }

    return false;
}
