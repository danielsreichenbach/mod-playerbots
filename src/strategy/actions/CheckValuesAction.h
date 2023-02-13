/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHECKVALUESACTION_H
#define _PLAYERBOT_CHECKVALUESACTION_H

#include "Action.h"

class PlayerbotAI;

class CheckValuesAction : public Action
{
public:
    CheckValuesAction(PlayerbotAI *botAI);

    bool Execute(Event event) override;
};

#endif
