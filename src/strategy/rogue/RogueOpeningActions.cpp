/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RogueOpeningActions.h"
#include "Playerbots.h"

Value<Unit *> *CastSapAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", getName());
}
