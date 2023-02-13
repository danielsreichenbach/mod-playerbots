/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHECKMAILACTION_H
#define _PLAYERBOT_CHECKMAILACTION_H

#include "Action.h"
#include "DatabaseEnvFwd.h"

class PlayerbotAI;

struct Mail;

class CheckMailAction : public Action
{
public:
    CheckMailAction(PlayerbotAI *botAI) : Action(botAI, "check mail") {}

    bool Execute(Event event) override;
    bool isUseful() override;

private:
    void ProcessMail(Mail *mail, Player *owner, CharacterDatabaseTransaction trans);
};

#endif
