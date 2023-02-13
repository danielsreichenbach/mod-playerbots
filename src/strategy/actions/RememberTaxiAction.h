/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_REMEMBERTAXIACTION_H
#define _PLAYERBOT_REMEMBERTAXIACTION_H

#include "Action.h"

class PlayerbotAI;

class RememberTaxiAction : public Action
{
public:
    RememberTaxiAction(PlayerbotAI *botAI) : Action(botAI, "remember taxi") {}

    bool Execute(Event event) override;
};

#endif
