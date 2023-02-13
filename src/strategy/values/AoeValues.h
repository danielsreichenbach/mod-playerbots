/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_AOEVALUES_H
#define _PLAYERBOT_AOEVALUES_H

#include "Object.h"
#include "Value.h"

class PlayerbotAI;

class AoePositionValue : public CalculatedValue<WorldLocation>
{
public:
    AoePositionValue(PlayerbotAI *botAI) : CalculatedValue<WorldLocation>(botAI, "aoe position") {}

    WorldLocation Calculate() override;
};

class AoeCountValue : public CalculatedValue<uint8>
{
public:
    AoeCountValue(PlayerbotAI *botAI) : CalculatedValue<uint8>(botAI, "aoe count") {}

    uint8 Calculate() override;
};

#endif
