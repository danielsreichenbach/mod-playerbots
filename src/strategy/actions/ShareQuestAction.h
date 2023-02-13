/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SHAREQUESTACTION_H
#define _PLAYERBOT_SHAREQUESTACTION_H

#include "Action.h"

class PlayerbotAI;

class ShareQuestAction : public Action
{
public:
    ShareQuestAction(PlayerbotAI *botAI) : Action(botAI, "share quest") {}

    bool Execute(Event event) override;
};

#endif
