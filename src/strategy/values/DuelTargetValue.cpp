/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DuelTargetValue.h"
#include "Playerbots.h"

Unit *DuelTargetValue::Calculate()
{
    return bot->duel ? bot->duel->Opponent : nullptr;
}
