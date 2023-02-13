/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PassiveStrategy.h"
#include "PassiveMultiplier.h"
#include "Playerbots.h"

void PassiveStrategy::InitMultipliers(std::vector<Multiplier *> &multipliers)
{
    multipliers.push_back(new PassiveMultiplier(botAI));
}
