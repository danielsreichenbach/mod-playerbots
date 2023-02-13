/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_EQUIPACTION_H
#define _PLAYERBOT_EQUIPACTION_H

#include "ChatHelper.h"
#include "InventoryAction.h"

class FindItemVisitor;
class Item;
class PlayerbotAI;

class EquipAction : public InventoryAction
{
public:
    EquipAction(PlayerbotAI *botAI, std::string const name = "equip") : InventoryAction(botAI, name) {}

    bool Execute(Event event) override;
    void EquipItems(ItemIds ids);

private:
    void EquipItem(FindItemVisitor *visitor);
    uint8 GetSmallestBagSlot();
    void EquipItem(Item *item);
};

class EquipUpgradesAction : public EquipAction
{
public:
    EquipUpgradesAction(PlayerbotAI *botAI, std::string const name = "equip upgrades") : EquipAction(botAI, name) {}

    bool Execute(Event event) override;
};

#endif
