/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RTSCValues.h"
#include "Playerbots.h"

bool SeeSpellLocationValue::EqualToLast(WorldPosition value)
{
    return value == lastValue;
}

WorldPosition SeeSpellLocationValue::Calculate()
{
    return value;
}

std::string const RTSCSavedLocationValue::Save()
{
    return value.to_string();
}

bool RTSCSavedLocationValue::Load(std::string const text)
{
    value = WorldPosition(text);
    return true;
}
