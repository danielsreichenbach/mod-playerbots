/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SERVERFACADE_H
#define _PLAYERBOT_SERVERFACADE_H

#include "Common.h"

class Player;
class Unit;
class WorldObject;

class ServerFacade
{
    public:
        ServerFacade() { };
        virtual ~ServerFacade() { };
        static ServerFacade* instance()
        {
            static ServerFacade instance;
            return &instance;
        }

	public:
        float GetDistance2d(Unit* unit, WorldObject* wo);
        float GetDistance2d(Unit* unit, float x, float y);
        bool IsDistanceLessThan(float dist1, float dist2);
        bool IsDistanceGreaterThan(float dist1, float dist2);
        bool IsDistanceGreaterOrEqualThan(float dist1, float dist2);
        bool IsDistanceLessOrEqualThan(float dist1, float dist2);

        void SetFacingTo(Player* bot, WorldObject* wo, bool force = false);

        Unit* GetChaseTarget(Unit* target);
};

#define sServerFacade ServerFacade::instance()

#endif
