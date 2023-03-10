/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DuelStrategy.h"
#include "Playerbots.h"

void DuelStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    PassTroughStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("duel requested", NextAction::array(0, new NextAction("accept duel", relevance), nullptr)));
    triggers.push_back(new TriggerNode("no attackers", NextAction::array(0, new NextAction("attack duel opponent", 70.0f), nullptr)));
}

DuelStrategy::DuelStrategy(PlayerbotAI *botAI) : PassTroughStrategy(botAI)
{
}

void StartDuelStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
}

StartDuelStrategy::StartDuelStrategy(PlayerbotAI *botAI) : Strategy(botAI)
{
}
