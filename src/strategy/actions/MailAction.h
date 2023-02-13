/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MAILACTION_H
#define _PLAYERBOT_MAILACTION_H

#include "InventoryAction.h"

class ObjectGuid;
class PlayerbotAI;

struct Mail;

class MailProcessor
{
public:
    virtual bool Before([[maybe_unused]] PlayerbotAI *botAI) { return true; }
    virtual bool Process(uint32 index, Mail *mail, PlayerbotAI *botAI) = 0;
    virtual bool After([[maybe_unused]] PlayerbotAI *botAI) { return true; }

    static ObjectGuid FindMailbox(PlayerbotAI *botAI);

protected:
    void RemoveMail(Player *bot, uint32 id, ObjectGuid mailbox);
};

class MailAction : public InventoryAction
{
public:
    MailAction(PlayerbotAI *botAI) : InventoryAction(botAI, "mail") {}

    bool Execute(Event event) override;

private:
    static std::map<std::string, MailProcessor *> processors;
};

#endif
