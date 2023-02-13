/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_FURYWARRIORSTRATEGY_H
#define _PLAYERBOT_FURYWARRIORSTRATEGY_H

#include "GenericWarriorStrategy.h"

class PlayerbotAI;

class FuryWarriorStrategy : public GenericWarriorStrategy
{
public:
    FuryWarriorStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "fury"; }
    NextAction **getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
};

#endif
