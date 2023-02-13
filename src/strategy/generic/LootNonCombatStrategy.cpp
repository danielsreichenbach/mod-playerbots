/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "LootNonCombatStrategy.h"
#include "Playerbots.h"

void LootNonCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("loot available", NextAction::array(0, new NextAction("loot", 6.0f), nullptr)));
    triggers.push_back(new TriggerNode("far from loot target", NextAction::array(0, new NextAction("move to loot", 7.0f), nullptr)));
    triggers.push_back(new TriggerNode("can loot", NextAction::array(0, new NextAction("open loot", 8.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("add all loot", 1.0f), nullptr)));
}

void GatherStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("timer", NextAction::array(0, new NextAction("add gathering loot", 2.0f), nullptr)));
}

void RevealStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("reveal gathering item", 50.0f), nullptr)));
}
