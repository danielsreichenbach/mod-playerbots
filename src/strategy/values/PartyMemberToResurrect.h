/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PARTYMEMBERTORESURRECT_H
#define _PLAYERBOT_PARTYMEMBERTORESURRECT_H

#include "PartyMemberValue.h"

class PlayerbotAI;
class Unit;

class PartyMemberToResurrect : public PartyMemberValue
{
public:
    PartyMemberToResurrect(PlayerbotAI *botAI, std::string const name = "party member to resurrect") : PartyMemberValue(botAI, name) {}

protected:
    Unit *Calculate() override;
};

#endif
