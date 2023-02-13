/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RTITRIGGERS_H
#define _PLAYERBOT_RTITRIGGERS_H

#include "Trigger.h"

class PlayerbotAI;

class NoRtiTrigger : public Trigger
{
public:
    NoRtiTrigger(PlayerbotAI *botAI) : Trigger(botAI, "no rti target") {}

    bool IsActive() override;
};

#endif
