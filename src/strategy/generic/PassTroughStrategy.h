/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PASSTHROUGHSTRATEGY_H
#define _PLAYERBOT_PASSTHROUGHSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class PassTroughStrategy : public Strategy
{
public:
    PassTroughStrategy(PlayerbotAI *botAI, float relevance = 100.0f) : Strategy(botAI), relevance(relevance) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;

protected:
    std::vector<std::string> supported;
    float relevance;
};

#endif
