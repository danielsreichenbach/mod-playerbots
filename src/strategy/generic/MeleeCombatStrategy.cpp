/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "MeleeCombatStrategy.h"
#include "Playerbots.h"

void MeleeCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("not facing target", NextAction::array(0, new NextAction("set facing", ACTION_MOVE + 7), nullptr)));
    triggers.push_back(new TriggerNode("enemy out of melee", NextAction::array(0, new NextAction("reach melee", ACTION_MOVE + 8), nullptr)));
    triggers.push_back(new TriggerNode("enemy too close for melee", NextAction::array(0, new NextAction("move out of enemy contact", ACTION_NORMAL + 8), nullptr)));
}

void SetBehindCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    CombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("not behind target", NextAction::array(0, new NextAction("set behind", ACTION_NORMAL + 9), nullptr)));
}
