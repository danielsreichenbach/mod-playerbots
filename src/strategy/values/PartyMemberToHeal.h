/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PARTYMEMBERTOHEAL_H
#define _PLAYERBOT_PARTYMEMBERTOHEAL_H

#include "PartyMemberValue.h"

class Pet;
class PlayerbotAI;
class Unit;

class PartyMemberToHeal : public PartyMemberValue
{
public:
    PartyMemberToHeal(PlayerbotAI *botAI, std::string const name = "party member to heal") : PartyMemberValue(botAI, name) {}

protected:
    Unit *Calculate() override;
    bool Check(Unit *player) override;
};

class PartyMemberToProtect : public PartyMemberValue
{
public:
    PartyMemberToProtect(PlayerbotAI *botAI, std::string const name = "party member to protect") : PartyMemberValue(botAI, name) {}

protected:
    Unit *Calculate() override;
};

#endif
