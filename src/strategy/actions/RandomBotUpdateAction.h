/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RANDOMBOTUPDATEACTION_H
#define _PLAYERBOT_RANDOMBOTUPDATEACTION_H

#include "Action.h"

class PlayerbotAI;

class RandomBotUpdateAction : public Action
{
public:
    RandomBotUpdateAction(PlayerbotAI *botAI) : Action(botAI, "random bot update") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
