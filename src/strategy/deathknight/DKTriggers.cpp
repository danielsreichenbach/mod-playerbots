/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DKTriggers.h"
#include "Playerbots.h"

bool DKPresenceTrigger::IsActive()
{
    Unit *target = GetTarget();
    return !botAI->HasAura("blood presence", target) && !botAI->HasAura("unholy presence", target) && !botAI->HasAura("frost presence", target);
}
