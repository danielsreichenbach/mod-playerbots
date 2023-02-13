/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PASSIVESTRATEGY_H
#define _PLAYERBOT_PASSIVESTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class PassiveStrategy : public Strategy
{
public:
    PassiveStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier *> &multipliers) override;
    std::string const getName() override { return "passive"; }
};

#endif
