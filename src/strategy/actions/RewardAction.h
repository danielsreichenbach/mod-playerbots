/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_REWARDACTION_H
#define _PLAYERBOT_REWARDACTION_H

#include "InventoryAction.h"

class PlayerbotAI;
class Object;

class RewardAction : public InventoryAction
{
public:
    RewardAction(PlayerbotAI *botAI) : InventoryAction(botAI, "reward") {}

    bool Execute(Event event) override;

private:
    bool Reward(uint32 itemId, Object *pNpc);
};

#endif
