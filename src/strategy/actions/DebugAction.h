/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_DEBUGACTION_H
#define _PLAYERBOT_DEBUGACTION_H

#include "Action.h"
#include "ObjectGuid.h"
#include "TravelMgr.h"

class PlayerbotAI;
class Unit;

class DebugAction : public Action
{
public:
    DebugAction(PlayerbotAI *botAI) : Action(botAI, "Debug") {}

    bool Execute(Event event) override;

    void FakeSpell(uint32 spellId, Unit *truecaster, Unit *caster, ObjectGuid target = ObjectGuid::Empty, GuidVector otherTargets = {}, GuidVector missTargets = {}, WorldPosition source = WorldPosition(), WorldPosition dest = WorldPosition(), bool forceDest = false);
    void addAura(uint32 spellId, Unit *target);
};

#endif
