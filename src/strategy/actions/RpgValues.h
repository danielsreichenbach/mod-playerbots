/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RPGVALUES_H
#define _PLAYERBOT_RPGVALUES_H

#include "Value.h"

class PlayerbotAI;

class NextRpgActionValue : public ManualSetValue<std::string>
{
public:
    NextRpgActionValue(PlayerbotAI *botAI, std::string const defaultValue = "", std::string const name = "next rpg action") : ManualSetValue(botAI, defaultValue, name){};
};

#endif
