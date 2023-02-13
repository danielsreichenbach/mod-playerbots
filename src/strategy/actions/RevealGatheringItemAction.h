/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_REVEALGATHERINGITEMACTION_H
#define _PLAYERBOT_REVEALGATHERINGITEMACTION_H

#include "Action.h"

class PlayerbotAI;

class RevealGatheringItemAction : public Action
{
public:
    RevealGatheringItemAction(PlayerbotAI *botAI) : Action(botAI, "reveal gathering item") {}

    bool Execute(Event event) override;
};

#endif
