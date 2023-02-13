/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ReturnStrategy.h"
#include "Playerbots.h"

void ReturnStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("return", NextAction::array(0, new NextAction("set return position", 1.5f), new NextAction("return", 1.0f), nullptr)));
}
