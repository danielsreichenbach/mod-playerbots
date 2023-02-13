/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_DUELTARGETVALUE_H
#define _PLAYERBOT_DUELTARGETVALUE_H

#include "TargetValue.h"

class PlayerbotAI;
class Unit;

class DuelTargetValue : public TargetValue
{
public:
    DuelTargetValue(PlayerbotAI *botAI, std::string const name = "duel target") : TargetValue(botAI, name) {}

    Unit *Calculate() override;
};

#endif
