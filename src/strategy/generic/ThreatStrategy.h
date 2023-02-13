/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_THREATSTRATEGY_H
#define _PLAYERBOT_THREATSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class ThreatMultiplier : public Multiplier
{
public:
    ThreatMultiplier(PlayerbotAI *botAI) : Multiplier(botAI, "threat") {}

    float GetValue(Action *action) override;
};

class ThreatStrategy : public Strategy
{
public:
    ThreatStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier *> &multipliers) override;
    std::string const getName() override { return "threat"; }
};

#endif
