/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_BUYACTION_H
#define _PLAYERBOT_BUYACTION_H

#include "InventoryAction.h"

class FindItemVisitor;
class ObjectGuid;
class Item;
class Player;
class PlayerbotAI;

struct ItemTemplate;
struct VendorItemData;

class BuyAction : public InventoryAction
{
public:
    BuyAction(PlayerbotAI *botAI) : InventoryAction(botAI, "buy") {}

    bool Execute(Event event) override;

private:
    bool BuyItem(VendorItemData const *tItems, ObjectGuid vendorguid, ItemTemplate const *proto);
    bool TradeItem(FindItemVisitor *visitor, int8 slot);
    bool TradeItem(Item const *item, int8 slot);
};

#endif
