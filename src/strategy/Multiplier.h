/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MULTIPLIER_H
#define _PLAYERBOT_MULTIPLIER_H

#include "AiObject.h"

class Action;
class PlayerbotAI;

class Multiplier : public AiNamedObject
{
public:
    Multiplier(PlayerbotAI *botAI, std::string const name) : AiNamedObject(botAI, name) {}
    virtual ~Multiplier() {}

    virtual float GetValue([[maybe_unused]] Action *action) { return 1.0f; }
};

#endif
