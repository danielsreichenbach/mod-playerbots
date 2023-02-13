/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "MarkRtiStrategy.h"
#include "Playerbots.h"

void MarkRtiStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("no rti target", NextAction::array(0, new NextAction("mark rti", ACTION_NORMAL), nullptr)));
}
