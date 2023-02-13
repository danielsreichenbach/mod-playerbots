/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PriestActions.h"
#include "Event.h"
#include "Playerbots.h"

bool CastRemoveShadowformAction::isUseful()
{
    return botAI->HasAura("shadowform", AI_VALUE(Unit *, "self target"));
}

bool CastRemoveShadowformAction::isPossible()
{
    return true;
}

bool CastRemoveShadowformAction::Execute(Event event)
{
    botAI->RemoveAura("shadowform");
    return true;
}
