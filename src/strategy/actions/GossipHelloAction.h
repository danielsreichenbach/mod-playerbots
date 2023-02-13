/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GOSSIPHELLOACTION_H
#define _PLAYERBOT_GOSSIPHELLOACTION_H

#include "Action.h"

class PlayerbotAI;

class GossipHelloAction : public Action
{
public:
    GossipHelloAction(PlayerbotAI *botAI) : Action(botAI, "gossip hello") {}

    bool Execute(Event event) override;

private:
    void TellGossipMenus();
    bool ProcessGossip(int32 menuToSelect);
    void TellGossipText(uint32 textId);
};

#endif
