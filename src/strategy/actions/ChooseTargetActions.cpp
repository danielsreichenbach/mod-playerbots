/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ChooseTargetActions.h"
#include "ChooseRpgTargetAction.h"
#include "Event.h"
#include "LootObjectStack.h"
#include "PossibleRpgTargetsValue.h"
#include "Playerbots.h"
#include "ServerFacade.h"

bool AttackEnemyPlayerAction::isUseful()
{
    // if carry flag, do not start fight
    if (bot->HasAura(23333) || bot->HasAura(23335) || bot->HasAura(34976))
        return false;

    return !sPlayerbotAIConfig->IsInPvpProhibitedZone(bot->GetAreaId());
}

bool AttackEnemyFlagCarrierAction::isUseful()
{
    Unit *target = context->GetValue<Unit *>("enemy flag carrier")->Get();
    return target && sServerFacade->IsDistanceLessOrEqualThan(sServerFacade->GetDistance2d(bot, target), 75.0f) && (bot->HasAura(23333) || bot->HasAura(23335) || bot->HasAura(34976));
}

bool AttackAnythingAction::isUseful()
{
    if (!botAI->AllowActivity(GRIND_ACTIVITY)) // Bot not allowed to be active
        return false;

    if (!AI_VALUE(bool, "can move around"))
        return false;

    if (context->GetValue<TravelTarget *>("travel target")->Get()->isTraveling() && ChooseRpgTargetAction::isFollowValid(bot, *context->GetValue<TravelTarget *>("travel target")->Get()->getPosition())) // Bot is traveling
        return false;

    Unit *target = GetTarget();

    if (!target)
        return false;

    std::string const name = std::string(target->GetName());
    if (!name.empty() && name.find("Dummy") != std::string::npos) // Target is not a targetdummy
        return false;

    if (!ChooseRpgTargetAction::isFollowValid(bot, target)) // Do not grind mobs far away from master.
        return false;

    return true;
}

bool DropTargetAction::Execute(Event event)
{
    Unit *target = context->GetValue<Unit *>("current target")->Get();
    if (target && target->isDead())
    {
        ObjectGuid guid = target->GetGUID();
        if (guid)
            context->GetValue<LootObjectStack *>("available loot")->Get()->Add(guid);
    }

    ObjectGuid pullTarget = context->GetValue<ObjectGuid>("pull target")->Get();
    GuidVector possible = botAI->GetAiObjectContext()->GetValue<GuidVector>("possible targets no los")->Get();

    if (pullTarget && find(possible.begin(), possible.end(), pullTarget) == possible.end())
    {
        context->GetValue<ObjectGuid>("pull target")->Set(ObjectGuid::Empty);
    }

    context->GetValue<Unit *>("current target")->Set(nullptr);

    bot->SetTarget(ObjectGuid::Empty);
    botAI->ChangeEngine(BOT_STATE_NON_COMBAT);
    botAI->InterruptSpell();
    bot->AttackStop();

    if (Pet *pet = bot->GetPet())
    {
        if (CreatureAI *creatureAI = ((Creature *)pet)->AI())
        {
            pet->SetReactState(REACT_PASSIVE);
            pet->GetCharmInfo()->SetCommandState(COMMAND_FOLLOW);
            pet->AttackStop();
        }
    }

    if (!urand(0, 50) && botAI->HasStrategy("emote", BOT_STATE_NON_COMBAT))
    {
        std::vector<uint32> sounds;
        if (target && target->isDead())
        {
            sounds.push_back(TEXT_EMOTE_CHEER);
            sounds.push_back(TEXT_EMOTE_CONGRATULATE);
        }
        else
        {
            sounds.push_back(304); // guard
            sounds.push_back(325); // stay
        }

        if (!sounds.empty())
            botAI->PlayEmote(sounds[urand(0, sounds.size() - 1)]);
    }

    return true;
}

bool AttackAnythingAction::Execute(Event event)
{
    bool result = AttackAction::Execute(event);
    if (result)
    {
        if (Unit *grindTarget = GetTarget())
        {
            if (char const *grindName = grindTarget->GetName().c_str())
            {
                context->GetValue<ObjectGuid>("pull target")->Set(grindTarget->GetGUID());
                bot->GetMotionMaster()->Clear();
                bot->StopMoving();
            }
        }
    }

    return result;
}

bool AttackAnythingAction::isPossible()
{
    return AttackAction::isPossible() && GetTarget();
}

bool DpsAssistAction::isUseful()
{
    // if carry flag, do not start fight
    if (bot->HasAura(23333) || bot->HasAura(23335) || bot->HasAura(34976))
        return false;

    return true;
}
