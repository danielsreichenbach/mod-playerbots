/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HIREACTION_H
#define _PLAYERBOT_HIREACTION_H

#include "Action.h"

class PlayerbotAI;

class HireAction : public Action
{
public:
    HireAction(PlayerbotAI *botAI) : Action(botAI, "hire") {}

    bool Execute(Event event) override;
};

#endif
