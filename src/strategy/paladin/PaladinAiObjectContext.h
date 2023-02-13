/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PALADINAIOBJECTCONTEXT_H
#define _PLAYERBOT_PALADINAIOBJECTCONTEXT_H

#include "AiObjectContext.h"

class PlayerbotAI;

class PaladinAiObjectContext : public AiObjectContext
{
public:
    PaladinAiObjectContext(PlayerbotAI *botAI);
};

#endif
