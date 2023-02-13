/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SKIPSPELLSLISTACTION_H
#define _PLAYERBOT_SKIPSPELLSLISTACTION_H

#include "Action.h"
#include "ChatHelper.h"

class PlayerbotAI;

class SkipSpellsListAction : public Action
{
public:
    SkipSpellsListAction(PlayerbotAI *botAI) : Action(botAI, "ss") {}

    bool Execute(Event event) override;

private:
    SpellIds parseIds(std::string const text);
};

#endif
