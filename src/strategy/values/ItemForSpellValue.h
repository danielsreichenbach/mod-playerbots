/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ITEMFORSPELLVALUE_H
#define _PLAYERBOT_ITEMFORSPELLVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class Item;
class PlayerbotAI;
class SpellInfo;

class ItemForSpellValue : public CalculatedValue<Item *>, public Qualified
{
public:
    ItemForSpellValue(PlayerbotAI *botAI, std::string const name = "item for spell") : CalculatedValue<Item *>(botAI, name) {}

    Item *Calculate() override;

private:
    Item *GetItemFitsToSpellRequirements(uint8 slot, SpellInfo const *spellInfo);
};

#endif
