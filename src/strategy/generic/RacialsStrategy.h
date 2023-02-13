/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RACIALSSTRATEGY_H
#define _PLAYERBOT_RACIALSSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class RacialsStrategy : public Strategy
{
public:
    RacialsStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "racials"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
