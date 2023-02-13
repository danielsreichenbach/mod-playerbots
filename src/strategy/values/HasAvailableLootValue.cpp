/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "HasAvailableLootValue.h"
#include "LootObjectStack.h"
#include "Playerbots.h"

bool HasAvailableLootValue::Calculate()
{
    return !AI_VALUE(bool, "can loot") && AI_VALUE(LootObjectStack *, "available loot")->CanLoot(sPlayerbotAIConfig->lootDistance);
}
