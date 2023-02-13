/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GUILDBANKACTION_H
#define _PLAYERBOT_GUILDBANKACTION_H

#include "InventoryAction.h"

class GameObject;
class Item;
class PlayerbotAI;

class GuildBankAction : public InventoryAction
{
public:
    GuildBankAction(PlayerbotAI *botAI) : InventoryAction(botAI, "guild bank") {}

    bool Execute(Event event) override;

private:
    bool Execute(std::string const text, GameObject *bank);
    bool MoveFromCharToBank(Item *item, GameObject *bank);
};

#endif
