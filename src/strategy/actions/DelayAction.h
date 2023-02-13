/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_DELAYACTION_H
#define _PLAYERBOT_DELAYACTION_H

#include "Action.h"

class PlayerbotAI;

class DelayAction : public Action
{
public:
    DelayAction(PlayerbotAI *botAI) : Action(botAI, "delay") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
