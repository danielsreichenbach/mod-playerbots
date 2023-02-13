/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_REVIVEFROMCORPSEACTION_H
#define _PLAYERBOT_REVIVEFROMCORPSEACTION_H

#include "MovementActions.h"

class PlayerbotAI;

struct GraveyardStruct;

class ReviveFromCorpseAction : public MovementAction
{
public:
    ReviveFromCorpseAction(PlayerbotAI *botAI) : MovementAction(botAI, "revive from corpse") {}

    bool Execute(Event event) override;
};

class FindCorpseAction : public MovementAction
{
public:
    FindCorpseAction(PlayerbotAI *botAI) : MovementAction(botAI, "find corpse") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class SpiritHealerAction : public MovementAction
{
public:
    SpiritHealerAction(PlayerbotAI *botAI, std::string const name = "spirit healer") : MovementAction(botAI, name) {}

    GraveyardStruct const *GetGrave(bool startZone);
    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
