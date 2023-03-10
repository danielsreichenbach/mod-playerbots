/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "FireMageStrategy.h"
#include "Playerbots.h"

NextAction **FireMageStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("scorch", 7.0f), new NextAction("fireball", 6.0f), new NextAction("fire blast", 5.0f), nullptr);
}

void FireMageStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    GenericMageStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("pyroblast", NextAction::array(0, new NextAction("pyroblast", 10.0f), nullptr)));
    triggers.push_back(new TriggerNode("hot streak", NextAction::array(0, new NextAction("pyroblast", 25.0f), nullptr)));
    triggers.push_back(new TriggerNode("combustion", NextAction::array(0, new NextAction("combustion", 50.0f), nullptr)));
    triggers.push_back(new TriggerNode("enemy too close for spell", NextAction::array(0, new NextAction("dragon's breath", 70.0f), nullptr)));
}

void FireMageAoeStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("medium aoe", NextAction::array(0, new NextAction("flamestrike", 20.0f), nullptr)));
    triggers.push_back(new TriggerNode("living bomb", NextAction::array(0, new NextAction("living bomb", 25.0f), nullptr)));
}
