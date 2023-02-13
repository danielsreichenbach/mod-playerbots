/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "LfgStrategy.h"
#include "Playerbots.h"

void LfgStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("random", NextAction::array(0, new NextAction("lfg join", relevance), nullptr)));
    triggers.push_back(new TriggerNode("seldom", NextAction::array(0, new NextAction("lfg leave", relevance), nullptr)));
    triggers.push_back(new TriggerNode("unknown dungeon", NextAction::array(0, new NextAction("give leader in dungeon", relevance), nullptr)));
}

LfgStrategy::LfgStrategy(PlayerbotAI *botAI) : PassTroughStrategy(botAI)
{
}
