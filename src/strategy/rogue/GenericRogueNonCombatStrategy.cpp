/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GenericRogueNonCombatStrategy.h"
#include "Playerbots.h"

void GenericRogueNonCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("player has flag", NextAction::array(0, new NextAction("sprint", ACTION_EMERGENCY + 1), nullptr)));
    triggers.push_back(new TriggerNode("enemy flagcarrier near", NextAction::array(0, new NextAction("sprint", ACTION_EMERGENCY + 2), nullptr)));
    triggers.push_back(new TriggerNode("unstealth", NextAction::array(0, new NextAction("unstealth", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("apply poison", 1.0f), nullptr)));
}
