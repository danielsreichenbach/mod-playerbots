/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "TravelStrategy.h"
#include "Playerbots.h"

TravelStrategy::TravelStrategy(PlayerbotAI *botAI) : Strategy(botAI)
{
}

NextAction **TravelStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("travel", 1.0f), nullptr);
}

void TravelStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("no travel target", NextAction::array(0, new NextAction("choose travel target", 6.f), nullptr)));
    triggers.push_back(new TriggerNode("far from travel target", NextAction::array(0, new NextAction("move to travel target", 1), nullptr)));
}
