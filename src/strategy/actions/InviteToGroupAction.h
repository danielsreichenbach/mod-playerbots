/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_INVITETOGROUPACTION_H
#define _PLAYERBOT_INVITETOGROUPACTION_H

#include "Action.h"
#include "Player.h"

class PlayerbotAI;

class InviteToGroupAction : public Action
{
public:
    InviteToGroupAction(PlayerbotAI *botAI, std::string const name = "invite") : Action(botAI, name) {}

    bool Execute(Event event) override;

    virtual bool Invite(Player *player);
};

class InviteNearbyToGroupAction : public InviteToGroupAction
{
public:
    InviteNearbyToGroupAction(PlayerbotAI *botAI, std::string const name = "invite nearby") : InviteToGroupAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

// Generic guid member finder
class FindGuildMembers
{
public:
    FindGuildMembers(){};

    void operator()(Player *player)
    {
        data.push_back(player);
    };

    std::vector<Player *> const GetResult()
    {
        return data;
    };

private:
    std::vector<Player *> data;
};

class InviteGuildToGroupAction : public InviteNearbyToGroupAction
{
public:
    InviteGuildToGroupAction(PlayerbotAI *botAI, std::string const name = "invite guild") : InviteNearbyToGroupAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

private:
    std::vector<Player *> getGuildMembers();
};

#endif
