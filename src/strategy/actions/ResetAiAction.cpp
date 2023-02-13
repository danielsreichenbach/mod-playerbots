/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ResetAiAction.h"
#include "Event.h"
#include "Playerbots.h"
#include "PlayerbotDbStore.h"

bool ResetAiAction::Execute(Event event)
{
    sPlayerbotDbStore->Reset(botAI);
    botAI->ResetStrategies(false);
    botAI->TellMaster("AI was reset to defaults");
    return true;
}
