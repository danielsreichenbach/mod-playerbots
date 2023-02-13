/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PartyMemberToDispel.h"
#include "Playerbots.h"

class PartyMemberToDispelPredicate : public FindPlayerPredicate, public PlayerbotAIAware
{
public:
    PartyMemberToDispelPredicate(PlayerbotAI *botAI, uint32 dispelType) : PlayerbotAIAware(botAI), FindPlayerPredicate(), dispelType(dispelType) {}

    bool Check(Unit *unit) override
    {
        return unit->IsAlive() && botAI->HasAuraToDispel(unit, dispelType);
    }

private:
    uint32 dispelType;
};

Unit *PartyMemberToDispel::Calculate()
{
    uint32 dispelType = atoi(qualifier.c_str());

    PartyMemberToDispelPredicate predicate(botAI, dispelType);
    return FindPartyMember(predicate);
}
