/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHOOSERPGTARGETACTION_H
#define _PLAYERBOT_CHOOSERPGTARGETACTION_H

#include "ObjectGuid.h"
#include "RpgAction.h"

class GuidPosition;
class Player;
class PlayerbotAI;
class WorldObject;
class WorldPosition;

class ChooseRpgTargetAction : public Action
{
public:
    ChooseRpgTargetAction(PlayerbotAI *botAI, std::string const name = "choose rpg target") : Action(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

    static bool isFollowValid(Player *bot, WorldObject *target);
    static bool isFollowValid(Player *bot, WorldPosition pos);

private:
    float getMaxRelevance(GuidPosition guidP);
    bool HasSameTarget(ObjectGuid guid, uint32 max, GuidVector const &nearGuids);
};

class ClearRpgTargetAction : public ChooseRpgTargetAction
{
public:
    ClearRpgTargetAction(PlayerbotAI *botAI) : ChooseRpgTargetAction(botAI, "clear rpg target") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
