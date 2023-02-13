/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SENDMAILACTION_H
#define _PLAYERBOT_SENDMAILACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class SendMailAction : public InventoryAction
{
public:
    SendMailAction(PlayerbotAI *botAI) : InventoryAction(botAI, "sendmail") {}

    bool Execute(Event event) override;
};

#endif
