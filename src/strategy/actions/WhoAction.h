/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_WHOACTION_H
#define _PLAYERBOT_WHOACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class WhoAction : public InventoryAction
{
public:
    WhoAction(PlayerbotAI *botAI) : InventoryAction(botAI, "who") {}

    bool Execute(Event event) override;

private:
    std::string const QueryTrade(std::string const text);
    std::string const QuerySkill(std::string const text);
    std::string const QuerySpec(std::string const text);
};

#endif
