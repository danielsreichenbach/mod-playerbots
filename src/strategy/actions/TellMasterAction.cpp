/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "TellMasterAction.h"
#include "Event.h"
#include "Playerbots.h"

bool TellMasterAction::Execute(Event event)
{
    botAI->TellMaster(text);
    return true;
}

bool OutOfReactRangeAction::Execute(Event event)
{
    botAI->TellMaster("Wait for me!");
    return true;
}

bool OutOfReactRangeAction::isUseful()
{
    bool canFollow = Follow(AI_VALUE(Unit *, "master target"));
    if (!canFollow)
    {
        return false;
    }

    return true;
}
