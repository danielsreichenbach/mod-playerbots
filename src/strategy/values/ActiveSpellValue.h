/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ACTIVESPELLVALUE_H
#define _PLAYERBOT_ACTIVESPELLVALUE_H

#include "Value.h"

class PlayerbotAI;

class ActiveSpellValue : public CalculatedValue<uint32>
{
public:
    ActiveSpellValue(PlayerbotAI *botAI, std::string const name = "active spell") : CalculatedValue<uint32>(botAI, name) {}

    uint32 Calculate() override;
};

#endif
