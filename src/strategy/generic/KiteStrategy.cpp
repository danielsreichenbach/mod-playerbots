/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "KiteStrategy.h"
#include "Playerbots.h"

KiteStrategy::KiteStrategy(PlayerbotAI *botAI) : Strategy(botAI)
{
}

void KiteStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("has aggro", NextAction::array(0, new NextAction("runaway", 51.0f), nullptr)));
}
