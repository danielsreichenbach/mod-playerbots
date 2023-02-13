/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PASSIVEMULTIPLIER_H
#define _PLAYERBOT_PASSIVEMULTIPLIER_H

#include "Multiplier.h"

#include <vector>

class Action;
class PlayerbotAI;

class PassiveMultiplier : public Multiplier
{
public:
    PassiveMultiplier(PlayerbotAI *botAI);

    float GetValue(Action *action) override;

private:
    static std::vector<std::string> allowedActions;
    static std::vector<std::string> allowedParts;
};

#endif
