/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_WITHINAREATRIGGER_H
#define _PLAYERBOT_WITHINAREATRIGGER_H

#include "Trigger.h"

class PlayerbotAI;

struct AreaTrigger;

class WithinAreaTrigger : public Trigger
{
public:
    WithinAreaTrigger(PlayerbotAI *botAI) : Trigger(botAI, "within area trigger") {}

    bool IsActive() override;

private:
    bool IsPointInAreaTriggerZone(AreaTrigger const *atEntry, uint32 mapid, float x, float y, float z, float delta);
};

#endif
