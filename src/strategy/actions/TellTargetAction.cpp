/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "TellTargetAction.h"
#include "ThreatMgr.h"
#include "Event.h"
#include "Playerbots.h"

bool TellTargetAction::Execute(Event event)
{
    Unit *target = context->GetValue<Unit *>("current target")->Get();
    if (target)
    {
        std::ostringstream out;
        out << "Attacking " << target->GetName();
        botAI->TellMaster(out);

        context->GetValue<Unit *>("old target")->Set(target);
    }

    return true;
}

bool TellAttackersAction::Execute(Event event)
{
    botAI->TellMaster("--- Attackers ---");

    GuidVector attackers = context->GetValue<GuidVector>("attackers")->Get();
    for (ObjectGuid const guid : attackers)
    {
        Unit *unit = botAI->GetUnit(guid);
        if (!unit || !unit->IsAlive())
            continue;

        botAI->TellMaster(unit->GetName());
    }

    botAI->TellMaster("--- Threat ---");

    HostileReference *ref = bot->getHostileRefMgr().getFirst();
    if (!ref)
        return true;

    while (ref)
    {
        ThreatMgr *threatMgr = ref->GetSource();
        Unit *unit = threatMgr->GetOwner();
        float threat = ref->GetThreat();

        std::ostringstream out;
        out << unit->GetName() << " (" << threat << ")";
        botAI->TellMaster(out);

        ref = ref->next();
    }

    return true;
}
