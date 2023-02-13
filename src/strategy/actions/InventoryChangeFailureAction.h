/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_INVENTORYCHANGEFAILUREACTION_H
#define _PLAYERBOT_INVENTORYCHANGEFAILUREACTION_H

#include "Item.h"
#include "Action.h"

class PlayerbotAI;

class InventoryChangeFailureAction : public Action
{
public:
    InventoryChangeFailureAction(PlayerbotAI *botAI) : Action(botAI, "inventory change failure") {}

    bool Execute(Event event) override;

private:
    static std::map<InventoryResult, std::string> messages;
};

#endif
