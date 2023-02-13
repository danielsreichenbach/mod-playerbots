/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_WORLDBUFFACTION_H
#define _PLAYERBOT_WORLDBUFFACTION_H

#include "Action.h"

class PlayerbotAI;
class Unit;

class WorldBuffAction : public Action
{
public:
    WorldBuffAction(PlayerbotAI *botAI) : Action(botAI, "world buff") {}

    bool Execute(Event event) override;

    static std::vector<uint32> NeedWorldBuffs(Unit *unit);
};

#endif
