/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICDKSTRATEGY_H
#define _PLAYERBOT_GENERICDKSTRATEGY_H

#include "MeleeCombatStrategy.h"

class PlayerbotAI;

class GenericDKStrategy : public MeleeCombatStrategy
{
public:
    GenericDKStrategy(PlayerbotAI *botAI);

    std::string const getName() override { return "DK"; }
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
};

#endif
