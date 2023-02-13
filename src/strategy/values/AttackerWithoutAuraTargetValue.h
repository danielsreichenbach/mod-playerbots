/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ATTACKERWITHOUTAURATARGETVALUE_H
#define _PLAYERBOT_ATTACKERWITHOUTAURATARGETVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class PlayerbotAI;
class Unit;

class AttackerWithoutAuraTargetValue : public UnitCalculatedValue, public Qualified
{
public:
    AttackerWithoutAuraTargetValue(PlayerbotAI *botAI) : UnitCalculatedValue(botAI, "attacker without aura") {}

protected:
    Unit *Calculate() override;
};

#endif
