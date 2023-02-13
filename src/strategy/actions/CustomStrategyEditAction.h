/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CUSTOMSTRATEGYEDITACTION_H
#define _PLAYERBOT_CUSTOMSTRATEGYEDITACTION_H

#include "Action.h"

class PlayerbotAI;

class CustomStrategyEditAction : public Action
{
public:
    CustomStrategyEditAction(PlayerbotAI *botAI) : Action(botAI, "cs") {}

    bool Execute(Event event) override;

private:
    bool PrintHelp();
    bool PrintActionLine(uint32 idx, std::string const command);
    bool Print(std::string const name);
    bool Edit(std::string const name, uint32 idx, std::string const command);
};

#endif
