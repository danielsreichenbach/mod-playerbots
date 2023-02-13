/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LOGLEVELACTION_H
#define _PLAYERBOT_LOGLEVELACTION_H

#include "LogCommon.h"
#include "Action.h"

class PlayerbotAI;

class LogLevelAction : public Action
{
public:
    LogLevelAction(PlayerbotAI *botAI) : Action(botAI, "log") {}

    bool Execute(Event event) override;

public:
    static std::string const logLevel2string(LogLevel level);
    static LogLevel string2logLevel(std::string const level);
};

#endif
