/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ARMSWARRIORSTRATEGY_H
#define _PLAYERBOT_ARMSWARRIORSTRATEGY_H

#include "GenericWarriorStrategy.h"

class PlayerbotAI;

class ArmsWarriorStrategy : public GenericWarriorStrategy
{
public:
    ArmsWarriorStrategy(PlayerbotAI *botAI);

public:
    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "arms"; }
    NextAction **getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
};

#endif
