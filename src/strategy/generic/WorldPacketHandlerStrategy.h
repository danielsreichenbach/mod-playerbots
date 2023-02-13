/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_WORLDPACKETHANDLERSTRATEGY_H
#define _PLAYERBOT_WORLDPACKETHANDLERSTRATEGY_H

#include "PassTroughStrategy.h"

class PlayerbotAI;

class WorldPacketHandlerStrategy : public PassTroughStrategy
{
public:
    WorldPacketHandlerStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "default"; }
};

class ReadyCheckStrategy : public PassTroughStrategy
{
public:
    ReadyCheckStrategy(PlayerbotAI *botAI) : PassTroughStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "ready check"; }
};

#endif
