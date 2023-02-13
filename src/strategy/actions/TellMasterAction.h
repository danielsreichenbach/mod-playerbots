/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TELLMASTERACTION_H
#define _PLAYERBOT_TELLMASTERACTION_H

#include "MovementActions.h"

class PlayerbotAI;

class TellMasterAction : public Action
{
public:
    TellMasterAction(PlayerbotAI *botAI, std::string const text) : Action(botAI, "tell master"), text(text) {}

    bool Execute(Event event) override;

private:
    std::string const text;
};

class OutOfReactRangeAction : public MovementAction
{
public:
    OutOfReactRangeAction(PlayerbotAI *botAI) : MovementAction(botAI, "tell out of react range") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
