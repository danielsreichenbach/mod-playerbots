/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_WTSACTION_H
#define _PLAYERBOT_WTSACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class WtsAction : public InventoryAction
{
public:
    WtsAction(PlayerbotAI *botAI) : InventoryAction(botAI, "wts") {}

    bool Execute(Event event) override;
};

#endif
