/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_USEPOTIONSSTRATEGY_H
#define _PLAYERBOT_USEPOTIONSSTRATEGY_H

#include "Strategy.h"

class PlayerbotAI;

class UsePotionsStrategy : public Strategy
{
public:
    UsePotionsStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "potions"; }
};

#endif
