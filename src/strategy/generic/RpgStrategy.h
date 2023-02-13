/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RPGSTRATEGY_H
#define _PLAYERBOT_RPGSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class RpgActionMultiplier : public Multiplier
{
public:
    RpgActionMultiplier(PlayerbotAI *botAI) : Multiplier(botAI, "rpg action") {}

    float GetValue(Action *action) override;
};

class RpgStrategy : public Strategy
{
public:
    RpgStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "rpg"; }
    NextAction **getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    void InitMultipliers(std::vector<Multiplier *> &multipliers) override;
};

#endif
