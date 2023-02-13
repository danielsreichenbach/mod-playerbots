/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "EmoteStrategy.h"
#include "Playerbots.h"

void EmoteStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("seldom", NextAction::array(0, new NextAction("emote", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("suggest what to do", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("suggest trade", 1.0f), nullptr)));

    if (sPlayerbotAIConfig->randomBotSuggestDungeons)
    {
        triggers.push_back(new TriggerNode("random", NextAction::array(0, new NextAction("suggest dungeon", 1.0f), nullptr)));
    }

    if (sPlayerbotAIConfig->enableGreet)
    {
        triggers.push_back(new TriggerNode("new player nearby", NextAction::array(0, new NextAction("greet", 1.0f), nullptr)));
    }

    triggers.push_back(new TriggerNode("seldom", NextAction::array(0, new NextAction("talk", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("receive text emote", NextAction::array(0, new NextAction("emote", 10.0f), nullptr)));
    triggers.push_back(new TriggerNode("receive emote", NextAction::array(0, new NextAction("emote", 10.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("rpg mount anim", 1.0f), nullptr)));
}
