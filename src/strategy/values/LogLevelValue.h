/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LOGLEVELVALUE_H
#define _PLAYERBOT_LOGLEVELVALUE_H

#include "Value.h"

class PlayerbotAI;

class LogLevelValue : public ManualSetValue<LogLevel>
{
public:
    LogLevelValue(PlayerbotAI *botAI, std::string const name = "log level") : ManualSetValue<LogLevel>(botAI, LOG_LEVEL_DEBUG, name) {}
};

#endif
