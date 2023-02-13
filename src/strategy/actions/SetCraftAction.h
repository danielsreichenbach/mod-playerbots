/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SETCRAFTACTION_H
#define _PLAYERBOT_SETCRAFTACTION_H

#include "Action.h"
#include "CraftValue.h"

class PlayerbotAI;

struct SkillLineAbilityEntry;

class SetCraftAction : public Action
{
public:
    SetCraftAction(PlayerbotAI *botAI) : Action(botAI, "craft") {}

    bool Execute(Event event) override;

    static uint32 GetCraftFee(CraftData &craftData);

private:
    void TellCraft();

    static std::map<uint32, SkillLineAbilityEntry const *> skillSpells;
};

#endif
