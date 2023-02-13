/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "AvailableLootValue.h"
#include "LootObjectStack.h"
#include "Playerbots.h"
#include "ServerFacade.h"

AvailableLootValue::AvailableLootValue(PlayerbotAI *botAI, std::string const name) : ManualSetValue<LootObjectStack *>(botAI, nullptr, name)
{
    value = new LootObjectStack(botAI->GetBot());
}

AvailableLootValue::~AvailableLootValue()
{
    delete value;
}

LootTargetValue::LootTargetValue(PlayerbotAI *botAI, std::string const name) : ManualSetValue<LootObject>(botAI, LootObject(), name)
{
}

bool CanLootValue::Calculate()
{
    LootObject loot = AI_VALUE(LootObject, "loot target");
    return !loot.IsEmpty() && loot.GetWorldObject(bot) && loot.IsLootPossible(bot) &&
           sServerFacade->IsDistanceLessOrEqualThan(AI_VALUE2(float, "distance", "loot target"), INTERACTION_DISTANCE);
}
