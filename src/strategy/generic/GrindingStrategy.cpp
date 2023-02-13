/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GrindingStrategy.h"
#include "Playerbots.h"

NextAction **GrindingStrategy::getDefaultActions()
{
    return nullptr;
}

void GrindingStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("no target", NextAction::array(0, new NextAction("attack anything", 5.0f), nullptr)));
}
