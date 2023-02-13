/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PaladinActions.h"
#include "Event.h"
#include "Playerbots.h"

inline std::string const GetActualBlessingOfMight(Unit *target)
{
    switch (target->getClass())
    {
    case CLASS_MAGE:
    case CLASS_PRIEST:
    case CLASS_WARLOCK:
        return "blessing of wisdom";
    }

    return "blessing of might";
}

inline std::string const GetActualBlessingOfWisdom(Unit *target)
{
    switch (target->getClass())
    {
    case CLASS_WARRIOR:
    case CLASS_ROGUE:
        return "blessing of might";
    }

    return "blessing of wisdom";
}

Value<Unit *> *CastBlessingOnPartyAction::GetTargetValue()
{
    return context->GetValue<Unit *>("party member without aura", "blessing of kings,blessing of might,blessing of wisdom");
}

bool CastBlessingOfMightAction::Execute(Event event)
{
    Unit *target = GetTarget();
    if (!target)
        return false;

    return botAI->CastSpell(GetActualBlessingOfMight(target), target);
}

bool CastBlessingOfMightOnPartyAction::Execute(Event event)
{
    Unit *target = GetTarget();
    if (!target)
        return false;

    return botAI->CastSpell(GetActualBlessingOfMight(target), target);
}

bool CastBlessingOfWisdomAction::Execute(Event event)
{
    Unit *target = GetTarget();
    if (!target)
        return false;

    return botAI->CastSpell(GetActualBlessingOfWisdom(target), target);
}

bool CastBlessingOfWisdomOnPartyAction::Execute(Event event)
{
    Unit *target = GetTarget();
    if (!target)
        return false;

    return botAI->CastSpell(GetActualBlessingOfWisdom(target), target);
}

bool CastSealSpellAction::isUseful()
{
    return AI_VALUE2(bool, "combat", "self target");
}

Value<Unit *> *CastTurnUndeadAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", getName());
}
