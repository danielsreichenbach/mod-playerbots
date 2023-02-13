/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_WORLDPACKETTRIGGER_H
#define _PLAYERBOT_WORLDPACKETTRIGGER_H

#include "Trigger.h"

class Event;
class Player;
class PlayerbotAI;
class WorldPacket;

class WorldPacketTrigger : public Trigger
{
public:
    WorldPacketTrigger(PlayerbotAI *botAI, std::string const command) : Trigger(botAI, command), triggered(false) {}

    void ExternalEvent(WorldPacket &packet, Player *owner = nullptr) override;
    Event Check() override;
    void Reset() override;

private:
    WorldPacket packet;
    bool triggered;
    Player *owner;
};

#endif
