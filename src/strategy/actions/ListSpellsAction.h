/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LISTSPELLSACTION_H
#define _PLAYERBOT_LISTSPELLSACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class ListSpellsAction : public InventoryAction
{
public:
    ListSpellsAction(PlayerbotAI *botAI, std::string const name = "spells") : InventoryAction(botAI, name) {}

    bool Execute(Event event) override;
    virtual std::vector<std::pair<uint32, std::string>> GetSpellList(std::string filter = "");

private:
    static std::map<uint32, SkillLineAbilityEntry const *> skillSpells;
    static std::set<uint32> vendorItems;
};

#endif
