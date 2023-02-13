/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PARTYMEMBERVALUE_H
#define _PLAYERBOT_PARTYMEMBERVALUE_H

#include "Player.h"
#include "Value.h"

class PlayerbotAI;

class FindPlayerPredicate
{
public:
    virtual bool Check(Unit * /*unit*/) = 0;
};

class SpellEntryPredicate
{
public:
    virtual bool Check(SpellInfo const * /*spellInfo*/) = 0;
};

class PartyMemberValue : public UnitCalculatedValue
{
public:
    PartyMemberValue(PlayerbotAI *botAI, std::string const name = "party member") : UnitCalculatedValue(botAI, name) {}

    bool IsTargetOfSpellCast(Player *target, SpellEntryPredicate &predicate);

protected:
    Unit *FindPartyMember(FindPlayerPredicate &predicate, bool ignoreOutOfGroup = false);
    Unit *FindPartyMember(std::vector<Player *> *party, FindPlayerPredicate &predicate);
    virtual bool Check(Unit *player);
};

#endif
