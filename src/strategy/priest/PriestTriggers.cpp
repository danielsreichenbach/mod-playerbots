/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PriestTriggers.h"
#include "Playerbots.h"

bool PowerWordFortitudeOnPartyTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() && !botAI->HasAura("power word : fortitude", GetTarget()) && !botAI->HasAura("prayer of fortitude", GetTarget());
}

bool PowerWordFortitudeTrigger::IsActive()
{
    return BuffTrigger::IsActive() && !botAI->HasAura("power word: fortitude", GetTarget()) && !botAI->HasAura("prayer of fortitude", GetTarget());
}

bool DivineSpiritOnPartyTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() && !botAI->HasAura("divine spirit", GetTarget()) && !botAI->HasAura("prayer of spirit", GetTarget());
}

bool DivineSpiritTrigger::IsActive()
{
    return BuffTrigger::IsActive() && !botAI->HasAura("divine spirit", GetTarget()) && !botAI->HasAura("prayer of spirit", GetTarget());
}

bool PrayerOfFortitudeTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() &&
           !botAI->HasAura("prayer of fortitude", GetTarget()) &&
           botAI->GetBot()->IsInSameGroupWith((Player *)GetTarget()) &&
           botAI->GetBuffedCount((Player *)GetTarget(), "prayer of fortitude") < 4 && !botAI->GetBuffedCount((Player *)GetTarget(), "power word: fortitude");
}

bool PrayerOfSpiritTrigger::IsActive()
{
    return BuffOnPartyTrigger::IsActive() &&
           !botAI->HasAura("prayer of spirit", GetTarget()) &&
           botAI->GetBot()->IsInSameGroupWith((Player *)GetTarget()) &&
           // botAI->GetManaPercent() > 50 &&
           botAI->GetBuffedCount((Player *)GetTarget(), "prayer of spirit") < 4 && !botAI->GetBuffedCount((Player *)GetTarget(), "divine spirit");
}

bool InnerFireTrigger::IsActive()
{
    Unit *target = GetTarget();
    return SpellTrigger::IsActive() && !botAI->HasAura(spell, target);
}

bool ShadowformTrigger::IsActive()
{
    return !botAI->HasAura("shadowform", bot);
}

bool ShadowfiendTrigger::IsActive()
{
    return BoostTrigger::IsActive() && !bot->HasSpellCooldown(34433);
}

BindingHealTrigger::BindingHealTrigger(PlayerbotAI *botAI) : PartyMemberLowHealthTrigger(botAI, "binding heal", sPlayerbotAIConfig->lowHealth, 0)
{
}

bool BindingHealTrigger::IsActive()
{
    return PartyMemberLowHealthTrigger::IsActive() && AI_VALUE2(uint8, "health", "self target") < sPlayerbotAIConfig->mediumHealth;
}
