/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GuildStrategy.h"
#include "Playerbots.h"

void GuildStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("offer petition nearby", 4.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("guild manage nearby", 4.0f), nullptr)));
    triggers.push_back(new TriggerNode("petition signed", NextAction::array(0, new NextAction("turn in petition", 10.0f), nullptr)));
    triggers.push_back(new TriggerNode("buy tabard", NextAction::array(0, new NextAction("buy tabard", 10.0f), nullptr)));
    triggers.push_back(new TriggerNode("leave large guild", NextAction::array(0, new NextAction("guild leave", 4.0f), nullptr)));
}
