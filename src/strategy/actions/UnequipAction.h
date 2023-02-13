/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_UNEQUIPACTION_H
#define _PLAYERBOT_UNEQUIPACTION_H

#include "InventoryAction.h"

class FindItemVisitor;
class Item;
class PlayerbotAI;

class UnequipAction : public InventoryAction
{
public:
    UnequipAction(PlayerbotAI *botAI) : InventoryAction(botAI, "unequip") {}

    bool Execute(Event event) override;

private:
    void UnequipItem(Item *item);
    void UnequipItem(FindItemVisitor *visitor);
};

#endif
