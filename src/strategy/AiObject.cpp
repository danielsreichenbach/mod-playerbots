/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "AiObject.h"
#include "Playerbots.h"

AiObject::AiObject(PlayerbotAI *botAI) : PlayerbotAIAware(botAI), bot(botAI->GetBot()), context(botAI->GetAiObjectContext()), chat(botAI->GetChatHelper())
{
}

Player *AiObject::GetMaster()
{
    return botAI->GetMaster();
}
