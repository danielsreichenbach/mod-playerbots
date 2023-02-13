/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TAXIACTION_H
#define _PLAYERBOT_TAXIACTION_H

#include "Action.h"

class PlayerbotAI;

class TaxiAction : public Action
{
public:
    TaxiAction(PlayerbotAI *botAI) : Action(botAI, "taxi") {}

    bool Execute(Event event) override;
};

#endif
