/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_LFGSTRATEGY_H
#define _PLAYERBOT_LFGSTRATEGY_H

#include "PassTroughStrategy.h"

class LfgStrategy : public PassTroughStrategy
{
public:
    LfgStrategy(PlayerbotAI *botAI);

    uint32 GetType() const override { return STRATEGY_TYPE_NONCOMBAT; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "lfg"; }
};

#endif
