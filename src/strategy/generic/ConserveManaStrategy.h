/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CONSERVEMANASTRATEGY_H
#define _PLAYERBOT_CONSERVEMANASTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class ConserveManaMultiplier : public Multiplier
{
public:
    ConserveManaMultiplier(PlayerbotAI *botAI) : Multiplier(botAI, "conserve mana") {}

    float GetValue(Action *action) override;
};

class SaveManaMultiplier : public Multiplier
{
public:
    SaveManaMultiplier(PlayerbotAI *botAI) : Multiplier(botAI, "save mana") {}

    float GetValue(Action *action) override;
};

class ConserveManaStrategy : public Strategy
{
public:
    ConserveManaStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier *> &multipliers) override;
    std::string const getName() override { return "conserve mana"; }
};

#endif
