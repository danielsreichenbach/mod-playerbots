/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "TotemsShamanStrategy.h"
#include "Playerbots.h"

TotemsShamanStrategy::TotemsShamanStrategy(PlayerbotAI *botAI) : GenericShamanStrategy(botAI)
{
}

void TotemsShamanStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    GenericShamanStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("grace of air totem", NextAction::array(0, new NextAction("grace of air totem", 16.0f), nullptr)));
    triggers.push_back(new TriggerNode("mana spring totem", NextAction::array(0, new NextAction("mana spring totem", 19.0f), nullptr)));
    triggers.push_back(new TriggerNode("strength of earth totem", NextAction::array(0, new NextAction("strength of earth totem", 18.0f), nullptr)));
    triggers.push_back(new TriggerNode("flametongue totem", NextAction::array(0, new NextAction("flametongue totem", 17.0f), nullptr)));
}
