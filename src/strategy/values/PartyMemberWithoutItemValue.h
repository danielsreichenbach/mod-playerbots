/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PARTYMEMBERWITHOUTITEMVALUE_H
#define _PLAYERBOT_PARTYMEMBERWITHOUTITEMVALUE_H

#include "PartyMemberValue.h"
#include "NamedObjectContext.h"
#include "PlayerbotAIConfig.h"

class PlayerbotAI;
class Unit;

class PartyMemberWithoutItemValue : public PartyMemberValue, public Qualified
{
public:
    PartyMemberWithoutItemValue(PlayerbotAI *botAI, std::string const name = "party member without item", float range = sPlayerbotAIConfig->farDistance) : PartyMemberValue(botAI, name) {}

protected:
    Unit *Calculate() override;
    virtual FindPlayerPredicate *CreatePredicate();
};

class PartyMemberWithoutFoodValue : public PartyMemberWithoutItemValue
{
public:
    PartyMemberWithoutFoodValue(PlayerbotAI *botAI, std::string const name = "party member without food") : PartyMemberWithoutItemValue(botAI, name) {}

protected:
    FindPlayerPredicate *CreatePredicate() override;
};

class PartyMemberWithoutWaterValue : public PartyMemberWithoutItemValue
{
public:
    PartyMemberWithoutWaterValue(PlayerbotAI *botAI, std::string const name = "party member without water") : PartyMemberWithoutItemValue(botAI, name) {}

protected:
    FindPlayerPredicate *CreatePredicate() override;
};

#endif
