/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TELLTARGETSTRATEGY_H
#define _PLAYERBOT_TELLTARGETSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class TellTargetStrategy : public Strategy
{
public:
    TellTargetStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "TellTarget"; }
};

#endif
