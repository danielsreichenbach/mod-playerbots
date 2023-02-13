/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RANDOMBOTUPDATEVALUE_H
#define _PLAYERBOT_RANDOMBOTUPDATEVALUE_H

#include "Value.h"

class PlayerbotAI;

class RandomBotUpdateValue : public ManualSetValue<bool>
{
public:
    RandomBotUpdateValue(PlayerbotAI *botAI, std::string const name = "random bot update") : ManualSetValue<bool>(botAI, false, name) {}
};

#endif
