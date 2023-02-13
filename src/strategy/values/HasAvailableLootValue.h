/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_HASAVAILABLELOOTVALUE_H
#define _PLAYERBOT_HASAVAILABLELOOTVALUE_H

#include "Value.h"

class PlayerbotAI;

class HasAvailableLootValue : public BoolCalculatedValue
{
public:
    HasAvailableLootValue(PlayerbotAI *botAI) : BoolCalculatedValue(botAI) {}

    bool Calculate() override;
};

#endif
