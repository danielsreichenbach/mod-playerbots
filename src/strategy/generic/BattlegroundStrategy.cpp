/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "BattlegroundStrategy.h"
#include "Playerbots.h"

void BGStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("random", NextAction::array(0, new NextAction("bg join", relevance), nullptr)));
    triggers.push_back(new TriggerNode("bg invite active", NextAction::array(0, new NextAction("bg status check", relevance), nullptr)));
}

BGStrategy::BGStrategy(PlayerbotAI *botAI) : PassTroughStrategy(botAI)
{
}

void WarsongStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("bg active", NextAction::array(0, new NextAction("bg check flag", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("low mana", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("enemy flagcarrier near", NextAction::array(0, new NextAction("attack enemy flag carrier", 80.0f), nullptr)));
    triggers.push_back(new TriggerNode("player has flag", NextAction::array(0, new NextAction("bg move to objective", 90.0f), nullptr)));
}

void AlteracStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    /* placeholder */
}

void ArathiStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("bg active", NextAction::array(0, new NextAction("bg check flag", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("low mana", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
}

void BattlegroundStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("bg waiting", NextAction::array(0, new NextAction("bg move to start", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("bg active", NextAction::array(0, new NextAction("bg move to objective", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("bg check objective", 10.0f), nullptr)));
    // triggers.push_back(new TriggerNode("enemy flagcarrier near", NextAction::array(0, new NextAction("attack enemy flag carrier", 80.0f), nullptr)));
    // triggers.push_back(new TriggerNode("team flagcarrier near", NextAction::array(0, new NextAction("bg protect fc", 40.0f), nullptr)));
    // triggers.push_back(new TriggerNode("player has flag", NextAction::array(0, new NextAction("bg move to objective", 90.0f), nullptr)));
}

void EyeStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("bg active", NextAction::array(0, new NextAction("bg check flag", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("low mana", NextAction::array(0, new NextAction("bg use buff", 30.0f), nullptr)));
    triggers.push_back(new TriggerNode("enemy flagcarrier near", NextAction::array(0, new NextAction("attack enemy flag carrier", 80.0f), nullptr)));
    triggers.push_back(new TriggerNode("player has flag", NextAction::array(0, new NextAction("bg move to objective", 90.0f), nullptr)));
}

void IsleStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("bg active", NextAction::array(0, new NextAction("bg check flag", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("timer", NextAction::array(0, new NextAction("enter vehicle", 85.0f), nullptr)));
    triggers.push_back(new TriggerNode("random", NextAction::array(0, new NextAction("leave vehicle", 80.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("hurl boulder", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("fire cannon", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("napalm", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("enemy is close", NextAction::array(0, new NextAction("steam blast", 80.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("ram", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("enemy is close", NextAction::array(0, new NextAction("ram", 79.0f), nullptr)));
    triggers.push_back(new TriggerNode("enemy out of melee", NextAction::array(0, new NextAction("steam rush", 81.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("incendiary rocket", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("rocket blast", 70.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("blade salvo", 71.0f), nullptr)));
    triggers.push_back(new TriggerNode("in vehicle", NextAction::array(0, new NextAction("glaive throw", 70.0f), nullptr)));
}

void ArenaStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("no possible targets", NextAction::array(0, new NextAction("arena tactics", 1.0f), nullptr)));
}
