/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SAVEMANAACTION_H
#define _PLAYERBOT_SAVEMANAACTION_H

#include "Action.h"

class PlayerbotAI;

class SaveManaAction : public Action
{
public:
    SaveManaAction(PlayerbotAI *botAI) : Action(botAI, "save mana") {}

    bool Execute(Event event) override;

private:
    std::string const Format(double value);
};

#endif
