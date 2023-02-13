/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NonCombatStrategy.h"
#include "Playerbots.h"

void NonCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("timer", NextAction::array(0, new NextAction("check mount state", 1.0f), new NextAction("check values", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("near dark portal", NextAction::array(0, new NextAction("move to dark portal", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("at dark portal azeroth", NextAction::array(0, new NextAction("use dark portal azeroth", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("at dark portal outland", NextAction::array(0, new NextAction("move from dark portal", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("need world buff", NextAction::array(0, new NextAction("world buff", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("vehicle near", NextAction::array(0, new NextAction("enter vehicle", 10.0f), nullptr)));
}

void CollisionStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("collision", NextAction::array(0, new NextAction("move out of collision", 2.0f), nullptr)));
}

void MountStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    /*triggers.push_back(new TriggerNode("no possible targets", NextAction::array(0, new NextAction("mount", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("no rpg target", NextAction::array(0, new NextAction("mount", 1.0f), nullptr)));*/
    /*triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("mount", 4.0f), nullptr)));*/
}
