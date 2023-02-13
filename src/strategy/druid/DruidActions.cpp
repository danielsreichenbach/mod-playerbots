/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DruidActions.h"
#include "Event.h"
#include "Playerbots.h"

NextAction **CastAbolishPoisonAction::getAlternatives()
{
    return NextAction::merge(NextAction::array(0, new NextAction("cure poison"), nullptr), CastSpellAction::getPrerequisites());
}

NextAction **CastAbolishPoisonOnPartyAction::getAlternatives()
{
    return NextAction::merge(NextAction::array(0, new NextAction("cure poison on party"), nullptr), CastSpellAction::getPrerequisites());
}

Value<Unit *> *CastEntanglingRootsCcAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", "entangling roots");
}

bool CastEntanglingRootsCcAction::Execute(Event event)
{
    return botAI->CastSpell("entangling roots", GetTarget());
}

Value<Unit *> *CastHibernateCcAction::GetTargetValue()
{
    return context->GetValue<Unit *>("cc target", "hibernate");
}

bool CastHibernateCcAction::Execute(Event event)
{
    return botAI->CastSpell("hibernate", GetTarget());
}

NextAction **CastReviveAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("caster form"), nullptr), ResurrectPartyMemberAction::getPrerequisites());
}

NextAction **CastRebirthAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("caster form"), nullptr), ResurrectPartyMemberAction::getPrerequisites());
}
