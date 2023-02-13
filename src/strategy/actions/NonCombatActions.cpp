/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NonCombatActions.h"
#include "Event.h"
#include "Playerbots.h"

bool DrinkAction::Execute(Event event)
{
    if (bot->IsInCombat())
        return false;

    bool hasMana = AI_VALUE2(bool, "has mana", "self target");
    if (!hasMana)
        return false;

    if (sPlayerbotAIConfig->freeFood)
    {
        if (bot->IsNonMeleeSpellCast(true))
            return false;

        bot->ClearUnitState(UNIT_STATE_CHASE);
        bot->ClearUnitState(UNIT_STATE_FOLLOW);

        if (bot->isMoving())
        {
            bot->StopMoving();
            botAI->SetNextCheckDelay(sPlayerbotAIConfig->globalCoolDown);
            return false;
        }

        bot->AddUnitState(UNIT_STAND_STATE_SIT);
        botAI->InterruptSpell();

        // float hp = bot->GetHealthPercent();
        float mp = bot->GetPowerPct(POWER_MANA);
        float p = mp;
        float delay;

        if (!bot->InBattleground())
            delay = 27000.0f * (100 - p) / 100.0f;
        else
            delay = 20000.0f * (100 - p) / 100.0f;

        botAI->CastSpell(24707, bot);
        botAI->SetNextCheckDelay(delay);

        return true;
    }

    return UseItemAction::Execute(event);
}

bool DrinkAction::isUseful()
{
    return UseItemAction::isUseful() && AI_VALUE2(uint8, "mana", "self target") < 85;
}

bool DrinkAction::isPossible()
{
    return sPlayerbotAIConfig->freeFood || UseItemAction::isPossible();
}

bool EatAction::Execute(Event event)
{
    if (bot->IsInCombat())
        return false;

    if (sPlayerbotAIConfig->freeFood)
    {
        if (bot->IsNonMeleeSpellCast(true))
            return false;

        bot->ClearUnitState(UNIT_STATE_CHASE);
        bot->ClearUnitState(UNIT_STATE_FOLLOW);

        if (bot->isMoving())
        {
            bot->StopMoving();
            botAI->SetNextCheckDelay(sPlayerbotAIConfig->globalCoolDown);
            return false;
        }

        bot->AddUnitState(UNIT_STAND_STATE_SIT);
        botAI->InterruptSpell();

        float hp = bot->GetHealthPct();
        // float mp = bot->HasMana() ? bot->GetPowerPercent() : 0.f;
        float p = hp;
        float delay;

        if (!bot->InBattleground())
            delay = 27000.0f * (100 - p) / 100.0f;
        else
            delay = 20000.0f * (100 - p) / 100.0f;

        botAI->CastSpell(24707, bot);
        botAI->SetNextCheckDelay(delay);

        return true;
    }

    return UseItemAction::Execute(event);
}

bool EatAction::isUseful()
{
    return UseItemAction::isUseful() && AI_VALUE2(uint8, "health", "self target") < sPlayerbotAIConfig->lowHealth;
}

bool EatAction::isPossible()
{
    return sPlayerbotAIConfig->freeFood || UseItemAction::isPossible();
}
