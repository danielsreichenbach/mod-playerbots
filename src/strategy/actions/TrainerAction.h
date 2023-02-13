/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TRAINERACTION_H
#define _PLAYERBOT_TRAINERACTION_H

#include "Action.h"
#include "ChatHelper.h"

class Creature;
class PlayerbotAI;

struct TrainerSpell;

class TrainerAction : public Action
{
public:
    TrainerAction(PlayerbotAI *botAI) : Action(botAI, "trainer") {}

    bool Execute(Event event) override;

private:
    typedef void (TrainerAction::*TrainerSpellAction)(uint32, TrainerSpell const *, std::ostringstream &msg);
    void Iterate(Creature *creature, TrainerSpellAction action, SpellIds &spells);
    void Learn(uint32 cost, TrainerSpell const *tSpell, std::ostringstream &msg);
    void TellHeader(Creature *creature);
    void TellFooter(uint32 totalCost);
};

#endif
