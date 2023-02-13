/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_FLAGACTION_H
#define _PLAYERBOT_FLAGACTION_H

#include "Action.h"

class PlayerbotAI;

class FlagAction : public Action
{
public:
    FlagAction(PlayerbotAI *botAI) : Action(botAI, "flag") {}

    bool Execute(Event event) override;

private:
    bool TellUsage();
};

#endif
