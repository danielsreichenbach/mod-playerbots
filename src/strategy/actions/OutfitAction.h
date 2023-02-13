/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_OUTFITACTION_H
#define _PLAYERBOT_OUTFITACTION_H

#include "EquipAction.h"
#include "ChatHelper.h"

class PlayerbotAI;

class OutfitAction : public EquipAction
{
public:
    OutfitAction(PlayerbotAI *botAI) : EquipAction(botAI, "outfit") {}

    bool Execute(Event event) override;

private:
    void List();
    void Save(std::string const name, ItemIds outfit);
    void Update(std::string const name);
};

#endif
