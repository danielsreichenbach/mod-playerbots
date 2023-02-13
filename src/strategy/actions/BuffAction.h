/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_BUFFACTION_H
#define _PLAYERBOT_BUFFACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class BuffAction : public InventoryAction
{
public:
    BuffAction(PlayerbotAI *botAI) : InventoryAction(botAI, "buff") {}

    bool Execute(Event event) override;

private:
    void TellHeader(uint32 subClass);
};

#endif
