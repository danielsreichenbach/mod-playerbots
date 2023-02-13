/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_XPGAINACTION_H
#define _PLAYERBOT_XPGAINACTION_H

#include "Action.h"

class PlayerbotAI;
class Unit;

class XpGainAction : public Action
{
public:
    XpGainAction(PlayerbotAI *botAI) : Action(botAI, "xp gain") {}

    bool Execute(Event event) override;

private:
    void GiveXP(uint32 xp, Unit *victim);
};

#endif
