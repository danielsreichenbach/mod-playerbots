/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HELPACTION_H
#define _PLAYERBOT_HELPACTION_H

#include "Action.h"
#include "NamedObjectContext.h"

class PlayerbotAI;

class HelpAction : public Action
{
public:
    HelpAction(PlayerbotAI *botAI);

    virtual ~HelpAction();
    bool Execute(Event event) override;

private:
    void TellChatCommands();
    void TellStrategies();
    std::string const CombineSupported(std::set<std::string> commands);

    NamedObjectContext<Action> *chatContext;
};

#endif
