/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TRADEACTION_H
#define _PLAYERBOT_TRADEACTION_H

#include "InventoryAction.h"

class Item;
class PlayerbotAI;

class TradeAction : public InventoryAction
{
public:
    TradeAction(PlayerbotAI *botAI) : InventoryAction(botAI, "trade") {}

    bool Execute(Event event) override;

private:
    bool TradeItem(Item const *item, int8 slot);

    static std::map<std::string, uint32> slots;
};

#endif
