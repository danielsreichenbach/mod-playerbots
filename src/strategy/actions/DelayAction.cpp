/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DelayAction.h"
#include "Event.h"
#include "Playerbots.h"

bool DelayAction::Execute(Event event)
{
    uint32 delay = sPlayerbotAIConfig->passiveDelay + sPlayerbotAIConfig->globalCoolDown;

    botAI->SetNextCheckDelay(delay);

    return true;
}

bool DelayAction::isUseful()
{
    return !botAI->AllowActivity(ALL_ACTIVITY);
}
