/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_NEARESTADSVALUE_H
#define _PLAYERBOT_NEARESTADSVALUE_H

#include "PossibleTargetsValue.h"
#include "PlayerbotAIConfig.h"

class PlayerbotAI;

class NearestAddsValue : public PossibleTargetsValue
{
public:
    NearestAddsValue(PlayerbotAI *botAI, float range = sPlayerbotAIConfig->tooCloseDistance) : PossibleTargetsValue(botAI, "nearest adds", range, true) {}

protected:
    bool AcceptUnit(Unit *unit) override;
};

#endif
