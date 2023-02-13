/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RemoveAuraAction.h"
#include "Event.h"
#include "Playerbots.h"

RemoveAuraAction::RemoveAuraAction(PlayerbotAI *botAI) : Action(botAI, "ra")
{
}

bool RemoveAuraAction::Execute(Event event)
{
    botAI->RemoveAura(event.getParam());
    return true;
}
