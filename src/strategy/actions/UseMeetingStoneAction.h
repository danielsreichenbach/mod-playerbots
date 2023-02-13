/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_USEMEETINGSTONEACTION_H
#define _PLAYERBOT_USEMEETINGSTONEACTION_H

#include "MovementActions.h"

class Player;
class PlayerbotAI;

class SummonAction : public MovementAction
{
public:
    SummonAction(PlayerbotAI *botAI, std::string const name = "summon") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;

protected:
    bool Teleport(Player *summoner, Player *player);
    bool SummonUsingGos(Player *summoner, Player *player);
    bool SummonUsingNpcs(Player *summoner, Player *player);
};

class UseMeetingStoneAction : public SummonAction
{
public:
    UseMeetingStoneAction(PlayerbotAI *botAI) : SummonAction(botAI, "use meeting stone") {}

    bool Execute(Event event) override;
};

#endif
