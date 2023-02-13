/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_EXTERNALEVENTHELPER_H
#define _PLAYERBOT_EXTERNALEVENTHELPER_H

#include "Common.h"

#include <map>

class AiObjectContext;
class Player;
class WorldPacket;

class ExternalEventHelper
{
public:
    ExternalEventHelper(AiObjectContext *aiObjectContext) : aiObjectContext(aiObjectContext) {}

    bool ParseChatCommand(std::string const command, Player *owner = nullptr);
    void HandlePacket(std::map<uint16, std::string> &handlers, WorldPacket const &packet, Player *owner = nullptr);
    bool HandleCommand(std::string const name, std::string const param, Player *owner = nullptr);

private:
    AiObjectContext *aiObjectContext;
};

#endif
