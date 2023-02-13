/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ChatCommandTrigger.h"
#include "Playerbots.h"

ChatCommandTrigger::ChatCommandTrigger(PlayerbotAI *botAI, std::string const command) : Trigger(botAI, command), triggered(false), owner(nullptr)
{
}

void ChatCommandTrigger::ExternalEvent(std::string const paramName, Player *eventPlayer)
{
    param = paramName;
    owner = eventPlayer;
    triggered = true;
}

Event ChatCommandTrigger::Check()
{
    if (!triggered)
        return Event();

    return Event(getName(), param, owner);
}

void ChatCommandTrigger::Reset()
{
    triggered = false;
}
