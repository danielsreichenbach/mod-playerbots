/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TELLITEMCOUNTACTION_H
#define _PLAYERBOT_TELLITEMCOUNTACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class TellItemCountAction : public InventoryAction
{
public:
    TellItemCountAction(PlayerbotAI *botAI) : InventoryAction(botAI, "c") {}

    bool Execute(Event event) override;
};

#endif
