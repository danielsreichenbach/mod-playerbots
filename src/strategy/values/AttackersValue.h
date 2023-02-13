/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ATTACKERSVALUE_H
#define _PLAYERBOT_ATTACKERSVALUE_H

#include "PlayerbotAIConfig.h"
#include "Value.h"

class Group;
class Player;
class PlayerbotAI;
class Unit;

class AttackersValue : public ObjectGuidListCalculatedValue
{
public:
    AttackersValue(PlayerbotAI *botAI) : ObjectGuidListCalculatedValue(botAI, "attackers", 2) {}

    GuidVector Calculate();
    static bool IsPossibleTarget(Unit *attacker, Player *bot, float range = sPlayerbotAIConfig->sightDistance);
    static bool IsValidTarget(Unit *attacker, Player *bot);

private:
    void AddAttackersOf(Group *group, std::set<Unit *> &targets);
    void AddAttackersOf(Player *player, std::set<Unit *> &targets);
    void RemoveNonThreating(std::set<Unit *> &targets);
};

class PossibleAddsValue : public BoolCalculatedValue
{
public:
    PossibleAddsValue(PlayerbotAI *botAI, std::string const name = "possible adds") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

#endif
