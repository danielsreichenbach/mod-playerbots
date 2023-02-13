/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "NearestCorpsesValue.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Playerbots.h"

class AnyDeadUnitInObjectRangeCheck
{
public:
    AnyDeadUnitInObjectRangeCheck(WorldObject const *obj, float range) : i_obj(obj), i_range(range) {}
    WorldObject const &GetFocusObject() const { return *i_obj; }
    bool operator()(Unit *u)
    {
        return !u->IsAlive() && i_obj->IsWithinDistInMap(u, i_range);
    }

private:
    WorldObject const *i_obj;
    float i_range;
};

void NearestCorpsesValue::FindUnits(std::list<Unit *> &targets)
{
    AnyDeadUnitInObjectRangeCheck u_check(bot, range);
    Acore::UnitListSearcher<AnyDeadUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitAllObjects(bot, searcher, range);
}

bool NearestCorpsesValue::AcceptUnit(Unit *unit)
{
    return true;
}
