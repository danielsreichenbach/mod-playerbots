/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DpsAssistStrategy.h"
#include "Playerbots.h"

void DpsAssistStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("not dps target active", NextAction::array(0, new NextAction("dps assist", 50.0f), nullptr)));
}

void DpsAoeStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("not dps aoe target active", NextAction::array(0, new NextAction("dps aoe", 50.0f), nullptr)));
}
