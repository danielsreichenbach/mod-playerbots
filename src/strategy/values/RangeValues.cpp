/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "RangeValues.h"
#include "Playerbots.h"

RangeValue::RangeValue(PlayerbotAI *botAI) : ManualSetValue<float>(botAI, 0.f, "range"), Qualified()
{
}

std::string const RangeValue::Save()
{
    std::ostringstream out;
    out << value;
    return out.str();
}

bool RangeValue::Load(std::string const text)
{
    value = atof(text.c_str());
    return true;
}
