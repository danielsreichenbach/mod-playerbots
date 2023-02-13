/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SHAMANAIOBJECTCONTEXT_H
#define _PLAYERBOT_SHAMANAIOBJECTCONTEXT_H

#include "AiObjectContext.h"

class PlayerbotAI;

class ShamanAiObjectContext : public AiObjectContext
{
public:
    ShamanAiObjectContext(PlayerbotAI *botAI);
};

#endif
