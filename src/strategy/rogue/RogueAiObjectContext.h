/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ROGUEAIOBJECTCONTEXT_H
#define _PLAYERBOT_ROGUEAIOBJECTCONTEXT_H

#include "AiObjectContext.h"

class PlayerbotAI;

class RogueAiObjectContext : public AiObjectContext
{
public:
    RogueAiObjectContext(PlayerbotAI *botAI);
};

#endif
