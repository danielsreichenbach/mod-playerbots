/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RANGEACTION_H
#define _PLAYERBOT_RANGEACTION_H

#include "Action.h"

class PlayerbotAI;

class RangeAction : public Action
{
public:
    RangeAction(PlayerbotAI *botAI) : Action(botAI, "range") {}

    bool Execute(Event event) override;

private:
    void PrintRange(std::string const type);
};

#endif
