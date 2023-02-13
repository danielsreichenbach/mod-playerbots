/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_AUTOLEARNSPELLACTION_H
#define _PLAYERBOT_AUTOLEARNSPELLACTION_H

#include "Action.h"

class PlayerbotAI;

class AutoLearnSpellAction : public Action
{
public:
    AutoLearnSpellAction(PlayerbotAI *botAI, std::string const name = "auto learn spell") : Action(botAI, name) {}

    bool Execute(Event event);

private:
    void LearnSpells(std::ostringstream *out);
    void LearnTrainerSpells(std::ostringstream *out);
    void LearnQuestSpells(std::ostringstream *out);
    void LearnSpell(uint32 spellId, std::ostringstream *out);
};

#endif
