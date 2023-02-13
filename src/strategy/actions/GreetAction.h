/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GREETACTION_H
#define _PLAYERBOT_GREETACTION_H

#include "Action.h"

class PlayerbotAI;

class GreetAction : public Action
{
public:
    GreetAction(PlayerbotAI *botAI);

    bool Execute(Event event) override;
};

#endif
