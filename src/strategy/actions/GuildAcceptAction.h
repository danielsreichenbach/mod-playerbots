/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GUILDACCEPTACTION_H
#define _PLAYERBOT_GUILDACCEPTACTION_H

#include "Action.h"

class PlayerbotAI;

class GuildAcceptAction : public Action
{
public:
    GuildAcceptAction(PlayerbotAI *botAI) : Action(botAI, "guild accept") {}

    bool Execute(Event event) override;
};

#endif
