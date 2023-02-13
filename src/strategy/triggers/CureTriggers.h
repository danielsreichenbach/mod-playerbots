/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CURETRIGGERS_H
#define _PLAYERBOT_CURETRIGGERS_H

#include "GenericTriggers.h"

class PlayerbotAI;
class Unit;

class NeedCureTrigger : public SpellTrigger
{
public:
    NeedCureTrigger(PlayerbotAI *botAI, std::string const spell, uint32 dispelType) : SpellTrigger(botAI, spell, 5), dispelType(dispelType) {}

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;

protected:
    uint32 dispelType;
};

class TargetAuraDispelTrigger : public NeedCureTrigger
{
public:
    TargetAuraDispelTrigger(PlayerbotAI *botAI, std::string const spell, uint32 dispelType) : NeedCureTrigger(botAI, spell, dispelType) {}

    std::string const GetTargetName() override { return "current target"; }
};

class PartyMemberNeedCureTrigger : public NeedCureTrigger
{
public:
    PartyMemberNeedCureTrigger(PlayerbotAI *botAI, std::string const spell, uint32 dispelType) : NeedCureTrigger(botAI, spell, dispelType) {}

    Value<Unit *> *GetTargetValue() override;
};

class NeedWorldBuffTrigger : public Trigger
{
public:
    NeedWorldBuffTrigger(PlayerbotAI *botAI) : Trigger(botAI) {}

    bool IsActive() override;
};

#endif
