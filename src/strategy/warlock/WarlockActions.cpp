/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "WarlockActions.h"
#include "Event.h"
#include "Playerbots.h"

bool CastDrainSoulAction::isUseful()
{
    return AI_VALUE2(uint32, "item count", "soul shard") < uint32(AI_VALUE(uint8, "bag space") * 0.2);
}

Value<Unit *> *CastBanishAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", "banish");
}

bool CastBanishAction::Execute(Event event)
{
    return botAI->CastSpell("banish", GetTarget());
}

Value<Unit *> *CastFearOnCcAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", "fear");
}

bool CastFearOnCcAction::Execute(Event event)
{
    return botAI->CastSpell("fear", GetTarget());
}

bool CastFearOnCcAction::isPossible()
{
    return botAI->CanCastSpell("fear", GetTarget());
}

bool CastFearOnCcAction::isUseful()
{
    return true;
}

bool CastLifeTapAction::isUseful()
{
    return AI_VALUE2(uint8, "health", "self target") > sPlayerbotAIConfig->lowHealth;
}
