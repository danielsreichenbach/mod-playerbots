/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GenericWarriorNonCombatStrategy.h"
#include "Playerbots.h"

void GenericWarriorNonCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("apply stone", 1.0f), nullptr)));
    triggers.push_back(new TriggerNode("battle stance", NextAction::array(0, new NextAction("battle stance", 1.0f), nullptr)));
}
