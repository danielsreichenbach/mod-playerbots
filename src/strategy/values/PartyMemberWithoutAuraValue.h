/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PARTYMEMBERWITHOUTAURAVALUE_H
#define _PLAYERBOT_PARTYMEMBERWITHOUTAURAVALUE_H

#include "PartyMemberValue.h"
#include "NamedObjectContext.h"
#include "PlayerbotAIConfig.h"

class PlayerbotAI;
class Unit;

class PartyMemberWithoutAuraValue : public PartyMemberValue, public Qualified
{
public:
    PartyMemberWithoutAuraValue(PlayerbotAI *botAI, std::string const name = "party member without aura", float range = sPlayerbotAIConfig->sightDistance) : PartyMemberValue(botAI, name) {}

protected:
    Unit *Calculate() override;
};

#endif
