/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PARTYMEMBERTODISPEL_H
#define _PLAYERBOT_PARTYMEMBERTODISPEL_H

#include "PartyMemberValue.h"
#include "NamedObjectContext.h"

class PlayerbotAI;
class Unit;

class PartyMemberToDispel : public PartyMemberValue, public Qualified
{
public:
    PartyMemberToDispel(PlayerbotAI *botAI, std::string const name = "party member to dispel") : PartyMemberValue(botAI, name), Qualified() {}

protected:
    Unit *Calculate() override;
};

#endif
