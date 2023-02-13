/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_REACHTARGETACTIONS_H
#define _PLAYERBOT_REACHTARGETACTIONS_H

#include "MovementActions.h"
#include "GenericSpellActions.h"

class PlayerbotAI;

class ReachTargetAction : public MovementAction
{
public:
    ReachTargetAction(PlayerbotAI *botAI, std::string const name, float distance) : MovementAction(botAI, name), distance(distance) {}

    bool Execute(Event event) override;
    bool isUseful() override;
    std::string const GetTargetName() override;

protected:
    float distance;
};

class CastReachTargetSpellAction : public CastSpellAction
{
public:
    CastReachTargetSpellAction(PlayerbotAI *botAI, std::string const spell, float distance) : CastSpellAction(botAI, spell), distance(distance) {}

    bool isUseful() override;

protected:
    float distance;
};

class ReachMeleeAction : public ReachTargetAction
{
public:
    ReachMeleeAction(PlayerbotAI *botAI) : ReachTargetAction(botAI, "reach melee", sPlayerbotAIConfig->meleeDistance) {}
};

class ReachSpellAction : public ReachTargetAction
{
public:
    ReachSpellAction(PlayerbotAI *botAI);
};

class ReachPartyMemberToHealAction : public ReachTargetAction
{
public:
    ReachPartyMemberToHealAction(PlayerbotAI *botAI);

    std::string const GetTargetName() override;
};

#endif
