/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TRAVELSTRATEGY_H
#define _PLAYERBOT_TRAVELSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class TravelStrategy : public Strategy
{
public:
    TravelStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "travel"; }

    NextAction **getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

class ExploreStrategy : public Strategy
{
public:
    ExploreStrategy(PlayerbotAI *botAI) : Strategy(botAI){};

    std::string const getName() override { return "explore"; }
};

class MapStrategy : public Strategy
{
public:
    MapStrategy(PlayerbotAI *botAI) : Strategy(botAI){};

    std::string const getName() override { return "map"; }
};

class MapFullStrategy : public Strategy
{
public:
    MapFullStrategy(PlayerbotAI *botAI) : Strategy(botAI){};

    std::string const getName() override { return "map full"; }
};

#endif
