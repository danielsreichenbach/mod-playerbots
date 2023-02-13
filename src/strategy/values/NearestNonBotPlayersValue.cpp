/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NearestNonBotPlayersValue.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Playerbots.h"

void NearestNonBotPlayersValue::FindUnits(std::list<Unit *> &targets)
{
    Acore::AnyUnitInObjectRangeCheck u_check(bot, range);
    Acore::UnitListSearcher<Acore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitAllObjects(bot, searcher, range);
}

bool NearestNonBotPlayersValue::AcceptUnit(Unit *unit)
{
    ObjectGuid guid = unit->GetGUID();
    return guid.IsPlayer() && !GET_PLAYERBOT_AI(((Player *)unit)) && (!((Player *)unit)->IsGameMaster() || ((Player *)unit)->isGMVisible());
}
