/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_FIREMAGESTRATEGY_H
#define _PLAYERBOT_FIREMAGESTRATEGY_H

#include "GenericMageStrategy.h"

class PlayerbotAI;

class FireMageStrategy : public GenericMageStrategy
{
public:
    FireMageStrategy(PlayerbotAI *botAI) : GenericMageStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "fire"; }
    NextAction **getDefaultActions() override;
};

class FireMageAoeStrategy : public CombatStrategy
{
public:
    FireMageAoeStrategy(PlayerbotAI *botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "fire aoe"; }
};

#endif
