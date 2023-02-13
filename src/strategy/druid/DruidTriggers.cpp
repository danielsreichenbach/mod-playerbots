/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DruidTriggers.h"
#include "Playerbots.h"

bool MarkOfTheWildOnPartyTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() && !botAI->HasAura("gift of the wild", GetTarget());
}

bool MarkOfTheWildTrigger::IsActive()
{
    return BuffTrigger::IsActive() && !botAI->HasAura("gift of the wild", GetTarget());
}

bool ThornsOnPartyTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() && !botAI->HasAura("thorns", GetTarget());
}

bool MoonfireTrigger::IsActive()
{
    return DebuffTrigger::IsActive() && !GetTarget()->HasUnitState(UNIT_STATE_ROOT);
}

bool EntanglingRootsKiteTrigger::IsActive()
{
    return DebuffTrigger::IsActive() && AI_VALUE(uint8, "attacker count") < 3 && !GetTarget()->GetPower(POWER_MANA);
}

bool ThornsTrigger::IsActive()
{
    return BuffTrigger::IsActive() && !botAI->HasAura("thorns", GetTarget());
}

bool BearFormTrigger::IsActive()
{
    return !botAI->HasAnyAuraOf(bot, "bear form", "dire bear form", nullptr);
}

bool TreeFormTrigger::IsActive()
{
    return !botAI->HasAura("tree of life", bot);
}

bool CatFormTrigger::IsActive()
{
    return !botAI->HasAura("cat form", bot);
}
