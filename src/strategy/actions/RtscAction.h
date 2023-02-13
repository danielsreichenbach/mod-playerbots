/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RTSCACTION_H
#define _PLAYERBOT_RTSCACTION_H

#include "SeeSpellAction.h"

class PlayerbotAI;

#define RTSC_MOVE_SPELL 30758 // Aedm (Awesome Energetic do move)

class RTSCAction : public SeeSpellAction
{
public:
    RTSCAction(PlayerbotAI *botAI) : SeeSpellAction(botAI, "rtsc") {}

    bool Execute(Event event) override;
};

#endif
