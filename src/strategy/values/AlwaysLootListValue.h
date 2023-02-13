/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ALWAYSLOOTLISTVALUE_H
#define _PLAYERBOT_ALWAYSLOOTLISTVALUE_H

#include "Value.h"

class PlayerbotAI;

class AlwaysLootListValue : public ManualSetValue<std::set<uint32> &>
{
public:
    AlwaysLootListValue(PlayerbotAI *botAI, std::string const name = "always loot list") : ManualSetValue<std::set<uint32> &>(botAI, list, name) {}

    std::string const Save() override;
    bool Load(std::string const value) override;

private:
    std::set<uint32> list;
};

#endif
