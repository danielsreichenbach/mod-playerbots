/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PVPTRIGGERS_H
#define _PLAYERBOT_PVPTRIGGERS_H

#include "Trigger.h"

class PlayerbotAI;

class EnemyPlayerNear : public Trigger
{
public:
    EnemyPlayerNear(PlayerbotAI *botAI) : Trigger(botAI, "enemy player near", 3) {}

    bool IsActive() override;
};

class PlayerHasNoFlag : public Trigger
{
public:
    PlayerHasNoFlag(PlayerbotAI *botAI) : Trigger(botAI, "player has no flag") {}

    bool IsActive() override;
};

class PlayerHasFlag : public Trigger
{
public:
    PlayerHasFlag(PlayerbotAI *botAI) : Trigger(botAI, "player has flag") {}

    bool IsActive() override;
};

class EnemyFlagCarrierNear : public Trigger
{
public:
    EnemyFlagCarrierNear(PlayerbotAI *botAI) : Trigger(botAI, "enemy flagcarrier near") {}

    bool IsActive() override;
};

class TeamFlagCarrierNear : public Trigger
{
public:
    TeamFlagCarrierNear(PlayerbotAI *botAI) : Trigger(botAI, "team flagcarrier near") {}

    bool IsActive() override;
};

class TeamHasFlag : public Trigger
{
public:
    TeamHasFlag(PlayerbotAI *botAI) : Trigger(botAI, "team has flag") {}

    bool IsActive() override;
};

class EnemyTeamHasFlag : public Trigger
{
public:
    EnemyTeamHasFlag(PlayerbotAI *botAI) : Trigger(botAI, "enemy team has flag") {}

    bool IsActive() override;
};

class PlayerIsInBattleground : public Trigger
{
public:
    PlayerIsInBattleground(PlayerbotAI *botAI) : Trigger(botAI, "in Battleground") {}

    bool IsActive() override;
};

class BgWaitingTrigger : public Trigger
{
public:
    BgWaitingTrigger(PlayerbotAI *botAI) : Trigger(botAI, "bg waiting", 30) {}

    bool IsActive() override;
};

class BgActiveTrigger : public Trigger
{
public:
    BgActiveTrigger(PlayerbotAI *botAI) : Trigger(botAI, "bg active", 1) {}

    bool IsActive() override;
};

class BgInviteActiveTrigger : public Trigger
{
public:
    BgInviteActiveTrigger(PlayerbotAI *botAI) : Trigger(botAI, "bg invite active", 10) {}

    bool IsActive() override;
};

class PlayerIsInBattlegroundWithoutFlag : public Trigger
{
public:
    PlayerIsInBattlegroundWithoutFlag(PlayerbotAI *botAI) : Trigger(botAI, "in Battleground without flag") {}

    bool IsActive() override;
};

class PlayerWantsInBattlegroundTrigger : public Trigger
{
public:
    PlayerWantsInBattlegroundTrigger(PlayerbotAI *botAI) : Trigger(botAI, "wants in bg") {}

    bool IsActive() override;
};

class VehicleNearTrigger : public Trigger
{
public:
    VehicleNearTrigger(PlayerbotAI *botAI) : Trigger(botAI, "vehicle near", 10) {}

    bool IsActive() override;
};

class InVehicleTrigger : public Trigger
{
public:
    InVehicleTrigger(PlayerbotAI *botAI) : Trigger(botAI, "in vehicle") {}

    bool IsActive() override;
};

#endif
