/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PETITIONSIGNACTION_H
#define _PLAYERBOT_PETITIONSIGNACTION_H

#include "Action.h"

class PlayerbotAI;

class PetitionSignAction : public Action
{
public:
    PetitionSignAction(PlayerbotAI *botAI) : Action(botAI, "petition sign") {}

    bool Execute(Event event) override;
};

#endif
