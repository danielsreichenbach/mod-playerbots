/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CASTTIMESTRATEGY_H
#define _PLAYERBOT_CASTTIMESTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class CastTimeMultiplier : public Multiplier
{
public:
    CastTimeMultiplier(PlayerbotAI *botAI) : Multiplier(botAI, "cast time") {}

    float GetValue(Action *action) override;
};

class CastTimeStrategy : public Strategy
{
public:
    CastTimeStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier *> &multipliers) override;
    std::string const getName() override { return "cast time"; }
};

#endif
