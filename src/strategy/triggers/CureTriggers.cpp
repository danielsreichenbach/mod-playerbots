/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "CureTriggers.h"
#include "Playerbots.h"
#include "WorldBuffAction.h"

bool NeedCureTrigger::IsActive()
{
    Unit *target = GetTarget();
    return target && botAI->HasAuraToDispel(target, dispelType);
}

Value<Unit *> *PartyMemberNeedCureTrigger::GetTargetValue()
{
    return context->GetValue<Unit *>("party member to dispel", dispelType);
}

bool NeedWorldBuffTrigger::IsActive()
{
    return !WorldBuffAction::NeedWorldBuffs(bot).empty();
}
