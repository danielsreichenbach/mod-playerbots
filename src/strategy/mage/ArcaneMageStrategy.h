/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ARCANEMAGESTRATEGY_H
#define _PLAYERBOT_ARCANEMAGESTRATEGY_H

#include "GenericMageStrategy.h"

class PlayerbotAI;

class ArcaneMageStrategy : public GenericMageStrategy
{
public:
    ArcaneMageStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "arcane"; }
    NextAction **getDefaultActions() override;
};

#endif
