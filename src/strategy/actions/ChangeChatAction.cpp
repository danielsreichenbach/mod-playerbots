/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ChangeChatAction.h"
#include "Event.h"
#include "Playerbots.h"

bool ChangeChatAction::Execute(Event event)
{
    std::string const text = event.getParam();
    ChatMsg parsed = chat->parseChat(text);
    if (parsed == CHAT_MSG_SYSTEM)
    {
        std::ostringstream out;
        out << "Current chat is " << chat->FormatChat(*context->GetValue<ChatMsg>("chat"));
        botAI->TellMaster(out);
    }
    else
    {
        context->GetValue<ChatMsg>("chat")->Set(parsed);

        std::ostringstream out;
        out << "Chat set to " << chat->FormatChat(parsed);
        botAI->TellMaster(out);
    }

    return true;
}
