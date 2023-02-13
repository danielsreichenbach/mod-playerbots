/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHATVALUE_H
#define _PLAYERBOT_CHATVALUE_H

#include "Value.h"

class PlayerbotAI;

enum ChatMsg : uint32;

class ChatValue : public ManualSetValue<ChatMsg>
{
public:
    ChatValue(PlayerbotAI *botAI, std::string const name = "chat") : ManualSetValue<ChatMsg>(botAI, CHAT_MSG_WHISPER, name) {}
};

#endif
