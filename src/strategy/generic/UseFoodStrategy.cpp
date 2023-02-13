/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "UseFoodStrategy.h"
#include "Playerbots.h"

void UseFoodStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    Strategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("food", 3.0f), nullptr)));
    triggers.push_back(new TriggerNode("high mana", NextAction::array(0, new NextAction("drink", 3.0f), nullptr)));
}
