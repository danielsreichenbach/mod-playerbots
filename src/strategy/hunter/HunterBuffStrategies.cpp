/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "HunterBuffStrategies.h"
#include "Playerbots.h"

void HunterBuffDpsStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("aspect of the hawk", NextAction::array(0, new NextAction("aspect of the hawk", 90.0f), nullptr)));
}

void HunterNatureResistanceStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("aspect of the wild", NextAction::array(0, new NextAction("aspect of the wild", 90.0f), nullptr)));
}

void HunterBuffSpeedStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("aspect of the pack", NextAction::array(0, new NextAction("aspect of the pack", 10.0f), nullptr)));
}

void HunterBuffManaStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("aspect of the viper", NextAction::array(0, new NextAction("aspect of the viper", 10.0f), nullptr)));
}
