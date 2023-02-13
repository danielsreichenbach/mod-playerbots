/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHANGECHATACTION_H
#define _PLAYERBOT_CHANGECHATACTION_H

#include "Action.h"

class PlayerbotAI;

class ChangeChatAction : public Action
{
public:
    ChangeChatAction(PlayerbotAI *botAI) : Action(botAI, "chat") {}

    bool Execute(Event event) override;
};

#endif
