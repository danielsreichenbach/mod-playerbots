/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RTSCSTRATEGY_H
#define _PLAYERBOT_RTSCSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class RTSCStrategy : public Strategy
{
public:
    RTSCStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "RTSC"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers);
};

#endif
