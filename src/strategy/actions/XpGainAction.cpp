/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "XpGainAction.h"
#include "Event.h"
#include "Playerbots.h"

bool XpGainAction::Execute(Event event)
{
    context->GetValue<uint32>("death count")->Set(0);

    if (!sRandomPlayerbotMgr->IsRandomBot(bot) || sPlayerbotAIConfig->playerbotsXPrate == 1)
        return true;

    WorldPacket p(event.getPacket()); // (8+4+1+4+8)
    ObjectGuid guid;
    uint32 xpgain;
    uint8 type = 0; // 00-kill_xp type, 01-non_kill_xp type
    uint32 givenXp = 0;
    float groupBonus = 0;

    p.rpos(0);
    p >> guid;   // 8 victim
    p >> xpgain; // 1 given experience
    p >> type;   // 1 00-kill_xp type, 01-non_kill_xp type

    if (!type)
    {
        p >> givenXp;    // 4 experience without rested bonus
        p >> groupBonus; // 8 group bonus
    }

    Unit *victim = nullptr;
    if (guid)
        victim = botAI->GetUnit(guid);

    xpgain = xpgain * (sPlayerbotAIConfig->playerbotsXPrate - 1);
    GiveXP(xpgain, victim);

    return true;
}

void XpGainAction::GiveXP(uint32 xp, Unit *victim)
{
    if (xp < 1)
    {
        return;
    }

    if (!bot->IsAlive())
    {
        return;
    }

    uint32 level = bot->getLevel();

    // XP to money conversion processed in Player::RewardQuest
    if (level >= sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        return;
    }

    // XP resting bonus for kill
    uint32 rested_bonus_xp = victim ? bot->GetXPRestBonus(xp) : 0;

    // SendLogXPGain(xp, victim, rested_bonus_xp);

    uint32 curXP = bot->GetUInt32Value(PLAYER_XP);
    uint32 nextLvlXP = bot->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 newXP = curXP + xp + rested_bonus_xp;

    while (newXP >= nextLvlXP && level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
    {
        newXP -= nextLvlXP;

        if (level < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            bot->GiveLevel(level + 1);
        }

        level = bot->getLevel();
        nextLvlXP = bot->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    }

    bot->SetUInt32Value(PLAYER_XP, newXP);
}
