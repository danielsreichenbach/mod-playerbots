/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "MageActions.h"
#include "Playerbots.h"
#include "ServerFacade.h"

Value<Unit *> *CastPolymorphAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", getName());
}

bool CastFrostNovaAction::isUseful()
{
    return sServerFacade->IsDistanceLessOrEqualThan(AI_VALUE2(float, "distance", GetTargetName()), 10.f);
}
