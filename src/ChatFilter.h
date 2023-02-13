/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHATFILTER_H
#define _PLAYERBOT_CHATFILTER_H

#include "Common.h"
#include "PlayerbotAIAware.h"

#include <vector>

class PlayerbotAI;

class ChatFilter : public PlayerbotAIAware
{
public:
    ChatFilter(PlayerbotAI *botAI) : PlayerbotAIAware(botAI) {}
    virtual ~ChatFilter() {}

    virtual std::string const Filter(std::string &message);
};

class CompositeChatFilter : public ChatFilter
{
public:
    CompositeChatFilter(PlayerbotAI *botAI);

    virtual ~CompositeChatFilter();
    std::string const Filter(std::string &message) override;

private:
    std::vector<ChatFilter *> filters;
};

#endif
