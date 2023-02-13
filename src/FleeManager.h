/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_FLEEMANAGER_H
#define _PLAYERBOT_FLEEMANAGER_H

#include "Common.h"
#include "TravelMgr.h"

#include <vector>

class Player;
class PlayerbotAI;

class FleePoint
{
public:
    FleePoint(PlayerbotAI *botAI, float x, float y, float z) : botAI(botAI), sumDistance(0.0f), minDistance(0.0f), x(x), y(y), z(z) {}

    float x;
    float y;
    float z;

    float sumDistance;
    float minDistance;

private:
    PlayerbotAI *botAI;
};

class FleeManager
{
public:
    FleeManager(Player *bot, float maxAllowedDistance, float followAngle, bool forceMaxDistance = false, WorldPosition startPosition = WorldPosition());

    bool CalculateDestination(float *rx, float *ry, float *rz);
    bool isUseful();

private:
    void calculatePossibleDestinations(std::vector<FleePoint *> &points);
    void calculateDistanceToCreatures(FleePoint *point);
    void cleanup(std::vector<FleePoint *> &points);
    FleePoint *selectOptimalDestination(std::vector<FleePoint *> &points);
    bool isBetterThan(FleePoint *point, FleePoint *other);

    Player *bot;
    float maxAllowedDistance;
    [[maybe_unused]] float followAngle; // unused - whipowill
    bool forceMaxDistance;
    WorldPosition startPosition;
};

#endif
