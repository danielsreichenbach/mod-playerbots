/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_STANCES_H
#define _PLAYERBOT_STANCES_H

#include "Formations.h"
#include "Action.h"

class PlayerbotAI;
class Unit;

class Stance : public Formation
{
public:
    Stance(PlayerbotAI *botAI, std::string const name) : Formation(botAI, name) {}

    WorldLocation GetLocation() override;
    std::string const GetTargetName() override;
    float GetMaxDistance() override;

protected:
    virtual Unit *GetTarget();
    virtual WorldLocation GetLocationInternal() = 0;
    virtual WorldLocation GetNearLocation(float angle, float distance);
};

class MoveStance : public Stance
{
public:
    MoveStance(PlayerbotAI *botAI, std::string const name) : Stance(botAI, name) {}

protected:
    WorldLocation GetLocationInternal();
    virtual float GetAngle() = 0;
};

class StanceValue : public ManualSetValue<Stance *>
{
public:
    StanceValue(PlayerbotAI *botAI);
    ~StanceValue();

    std::string const Save() override;
    bool Load(std::string const value) override;
};

class SetStanceAction : public Action
{
public:
    SetStanceAction(PlayerbotAI *botAI) : Action(botAI, "set Stance") {}

    bool Execute(Event event) override;
};

#endif
