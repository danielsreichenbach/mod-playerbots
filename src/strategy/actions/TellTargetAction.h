/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TELLTARGETACTION_H
#define _PLAYERBOT_TELLTARGETACTION_H

#include "Action.h"

class PlayerbotAI;

class TellTargetAction : public Action
{
public:
    TellTargetAction(PlayerbotAI *botAI) : Action(botAI, "tell target") {}

    bool Execute(Event event) override;
};

class TellAttackersAction : public Action
{
public:
    TellAttackersAction(PlayerbotAI *botAI) : Action(botAI, "tell attackers") {}

    bool Execute(Event event) override;
};

#endif
