/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GuardStrategy.h"
#include "Playerbots.h"

NextAction **GuardStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("guard", 4.0f), nullptr);
}

void GuardStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
}
