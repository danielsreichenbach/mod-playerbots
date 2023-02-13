/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GUILDTRIGGER_H
#define _PLAYERBOT_GUILDTRIGGER_H

#include "Trigger.h"

class PlayerbotAI;

class PetitionTurnInTrigger : public Trigger
{
public:
    PetitionTurnInTrigger(PlayerbotAI *botAI) : Trigger(botAI) {}

    bool IsActive() override;
};

class BuyTabardTrigger : public Trigger
{
public:
    BuyTabardTrigger(PlayerbotAI *botAI) : Trigger(botAI) {}

    bool IsActive() override;
};

class LeaveLargeGuildTrigger : public Trigger
{
public:
    LeaveLargeGuildTrigger(PlayerbotAI *botAI) : Trigger(botAI) {}

    bool IsActive();
};

#endif
