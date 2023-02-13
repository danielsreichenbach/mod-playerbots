/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_STUCKTRIGGERS_H
#define _PLAYERBOT_STUCKTRIGGERS_H

#include "Trigger.h"

class MoveStuckTrigger : public Trigger
{
public:
    MoveStuckTrigger(PlayerbotAI *botAI) : Trigger(botAI, "move stuck", 5) {}

    bool IsActive() override;
};

class MoveLongStuckTrigger : public Trigger
{
public:
    MoveLongStuckTrigger(PlayerbotAI *botAI) : Trigger(botAI, "move long stuck", 5) {}

    bool IsActive() override;
};

class CombatStuckTrigger : public Trigger
{
public:
    CombatStuckTrigger(PlayerbotAI *botAI) : Trigger(botAI, "combat stuck", 5) {}

    bool IsActive() override;
};

class CombatLongStuckTrigger : public Trigger
{
public:
    CombatLongStuckTrigger(PlayerbotAI *botAI) : Trigger(botAI, "combat long stuck", 5) {}

    bool IsActive() override;
};

#endif
