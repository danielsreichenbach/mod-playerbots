/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SEESPELLACTION_H
#define _PLAYERBOT_SEESPELLACTION_H

#include "MovementActions.h"

class Creature;
class Player;
class PlayerbotAI;
class WorldPosition;

class SeeSpellAction : public MovementAction
{
public:
    SeeSpellAction(PlayerbotAI *botAI, std::string const name = "see spell") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;

    bool SelectSpell(WorldPosition &spellPosition);
    bool MoveSpell(WorldPosition &spellPosition);

    virtual bool MoveToSpell(WorldPosition &spellPosition, bool inFormation = true);
    void SetFormationOffset(WorldPosition &spellPosition);

private:
    Creature *CreateWps(Player *wpOwner, float x, float y, float z, float o, uint32 entry, Creature *lastWp, bool important = false);
};

#endif
