/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SKIPSPELLSLISTVALUE_H
#define _PLAYERBOT_SKIPSPELLSLISTVALUE_H

#include "Value.h"

#include <set>

class PlayerbotAI;

class SkipSpellsListValue : public ManualSetValue<std::set<uint32> &>
{
public:
    SkipSpellsListValue(PlayerbotAI *botAI, std::string const name = "skip spells list") : ManualSetValue<std::set<uint32> &>(botAI, list, name) {}

    std::string const Save() override;
    bool Load(std::string const value) override;

private:
    std::set<uint32> list;
};

#endif
