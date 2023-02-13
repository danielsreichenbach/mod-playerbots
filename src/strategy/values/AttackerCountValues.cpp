/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "AttackerCountValues.h"
#include "Playerbots.h"

uint8 MyAttackerCountValue::Calculate()
{
    return bot->getAttackers().size();
}

bool HasAggroValue::Calculate()
{
    Unit *target = GetTarget();
    if (!target)
        return true;

    HostileReference *ref = bot->getHostileRefMgr().getFirst();
    if (!ref)
        return true; // simulate as target is not atacking anybody yet

    while (ref)
    {
        ThreatMgr *threatMgr = ref->GetSource();
        Unit *attacker = threatMgr->GetOwner();
        Unit *victim = attacker->GetVictim();
        if (victim == bot && target == attacker)
            return true;

        ref = ref->next();
    }

    ref = target->GetThreatMgr().getCurrentVictim();
    if (ref)
    {
        if (Unit *victim = ref->getTarget())
        {
            if (Player *pl = victim->ToPlayer())
            {
                if (botAI->IsTank(pl))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

uint8 AttackerCountValue::Calculate()
{
    uint32 count = 0;
    float range = sPlayerbotAIConfig->sightDistance;

    GuidVector attackers = context->GetValue<GuidVector>("attackers")->Get();
    for (ObjectGuid const guid : attackers)
    {
        Unit *unit = botAI->GetUnit(guid);
        if (!unit || !unit->IsAlive())
            continue;

        float distance = bot->GetDistance(unit);
        if (distance <= range)
            ++count;
    }

    return count;
}

uint8 BalancePercentValue::Calculate()
{
    float playerLevel = 0,
          attackerLevel = 0;

    if (Group *group = bot->GetGroup())
    {
        Group::MemberSlotList const &groupSlot = group->GetMemberSlots();
        for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
        {
            Player *player = ObjectAccessor::FindPlayer(itr->guid);
            if (!player || !player->IsAlive())
                continue;

            playerLevel += player->getLevel();
        }
    }

    GuidVector v = context->GetValue<GuidVector>("attackers")->Get();
    for (ObjectGuid const guid : v)
    {
        Creature *creature = botAI->GetCreature((guid));
        if (!creature || !creature->IsAlive())
            continue;

        uint32 level = creature->getLevel();

        switch (creature->GetCreatureTemplate()->rank)
        {
        case CREATURE_ELITE_RARE:
            level *= 2;
            break;
        case CREATURE_ELITE_ELITE:
            level *= 3;
            break;
        case CREATURE_ELITE_RAREELITE:
            level *= 3;
            break;
        case CREATURE_ELITE_WORLDBOSS:
            level *= 5;
            break;
        }

        attackerLevel += level;
    }

    if (!attackerLevel)
        return 100;

    float percent = playerLevel * 100 / attackerLevel;
    return percent <= 200 ? (uint8)percent : 200;
}

Unit *AttackerCountValue::GetTarget()
{
    AiObjectContext *ctx = AiObject::context;
    return ctx->GetValue<Unit *>(qualifier)->Get();
}

Unit *MyAttackerCountValue::GetTarget()
{
    AiObjectContext *ctx = AiObject::context;
    return ctx->GetValue<Unit *>(qualifier)->Get();
}

Unit *HasAggroValue::GetTarget()
{
    AiObjectContext *ctx = AiObject::context;
    return ctx->GetValue<Unit *>(qualifier)->Get();
}

Unit *BalancePercentValue::GetTarget()
{
    AiObjectContext *ctx = AiObject::context;
    return ctx->GetValue<Unit *>(qualifier)->Get();
}
