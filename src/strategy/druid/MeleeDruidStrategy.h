/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_MELEEDRUIDSTRATEGY_H
#define _PLAYERBOT_MELEEDRUIDSTRATEGY_H

#include "CombatStrategy.h"

class MeleeDruidStrategy : public CombatStrategy
{
public:
    MeleeDruidStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "melee"; }
    NextAction **getDefaultActions() override;
};

#endif
