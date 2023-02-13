/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PassTroughStrategy.h"
#include "Playerbots.h"

void PassTroughStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    for (std::vector<std::string>::iterator i = supported.begin(); i != supported.end(); i++)
        triggers.push_back(new TriggerNode(i->c_str(), NextAction::array(0, new NextAction(i->c_str(), relevance), nullptr)));
}
