/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_NEARESTGAMEOBJECTS_H
#define _PLAYERBOT_NEARESTGAMEOBJECTS_H

#include "Value.h"
#include "PlayerbotAIConfig.h"

class PlayerbotAI;

class NearestGameObjects : public ObjectGuidListCalculatedValue
{
public:
    NearestGameObjects(PlayerbotAI *botAI, float range = sPlayerbotAIConfig->sightDistance, bool ignoreLos = false, std::string const name = "nearest game objects") : ObjectGuidListCalculatedValue(botAI, name), range(range), ignoreLos(ignoreLos) {}

protected:
    GuidVector Calculate() override;

private:
    float range;
    bool ignoreLos;
};

#endif
