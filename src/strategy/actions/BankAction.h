/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_BANKACTION_H
#define _PLAYERBOT_BANKACTION_H

#include "InventoryAction.h"

class Item;
class PlayerbotAI;

class BankAction : public InventoryAction
{
public:
    BankAction(PlayerbotAI *botAI) : InventoryAction(botAI, "bank") {}

    bool Execute(Event event) override;

private:
    bool ExecuteBank(std::string const text, Unit *bank);
    void ListItems();
    bool Withdraw(uint32 itemid);
    bool Deposit(Item *pItem);
    Item *FindItemInBank(uint32 ItemId);
};

#endif
