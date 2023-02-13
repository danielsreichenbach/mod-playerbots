/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "EnemyHealerTargetValue.h"
#include "Playerbots.h"
#include "ServerFacade.h"

Unit *EnemyHealerTargetValue::Calculate()
{
    std::string const spell = qualifier;

    GuidVector attackers = botAI->GetAiObjectContext()->GetValue<GuidVector>("attackers")->Get();
    Unit *target = botAI->GetAiObjectContext()->GetValue<Unit *>("current target")->Get();
    for (ObjectGuid const guid : attackers)
    {
        Unit *unit = botAI->GetUnit(guid);
        if (!unit || unit == target)
            continue;

        if (sServerFacade->GetDistance2d(bot, unit) > botAI->GetRange("spell"))
            continue;

        if (!botAI->IsInterruptableSpellCasting(unit, spell))
            continue;

        Spell *spell = unit->GetCurrentSpell(CURRENT_GENERIC_SPELL);
        if (spell && spell->m_spellInfo->IsPositive())
            return unit;

        spell = unit->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
        if (spell && spell->m_spellInfo->IsPositive())
            return unit;
    }

    return nullptr;
}
