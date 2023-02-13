/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PASSLEADERSHIPTOMASTERACTION_H
#define _PLAYERBOT_PASSLEADERSHIPTOMASTERACTION_H

#include "Action.h"

class PlayerbotAI;

class PassLeadershipToMasterAction : public Action
{
public:
    PassLeadershipToMasterAction(PlayerbotAI *botAI, std::string const name = "leader", std::string const message = "Passing leader to you!") : Action(botAI, name), message(message) {}

    bool Execute(Event event) override;
    bool isUseful() override;

protected:
    std::string const message;
};

class GiveLeaderAction : public PassLeadershipToMasterAction
{
public:
    GiveLeaderAction(PlayerbotAI *botAI, std::string const message = "Lead the way!") : PassLeadershipToMasterAction(botAI, "give leader", message) {}

    bool isUseful() override;
};

#endif
