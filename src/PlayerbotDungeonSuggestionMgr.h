/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PLAYERBOTDUNGEONSUGGESTIONMGR_H
#define _PLAYERBOT_PLAYERBOTDUNGEONSUGGESTIONMGR_H

#include "Common.h"
#include "DBCEnums.h"

#include <map>
#include <vector>

struct DungeonSuggestion
{
    std::string name;
    Difficulty difficulty;
    uint8 min_level;
    uint8 max_level;
    std::string abbrevation;
    std::string strategy;
};

class PlayerbotDungeonSuggestionMgr
{
public:
    PlayerbotDungeonSuggestionMgr(){};
    ~PlayerbotDungeonSuggestionMgr(){};
    static PlayerbotDungeonSuggestionMgr *instance()
    {
        static PlayerbotDungeonSuggestionMgr instance;
        return &instance;
    }

    void LoadDungeonSuggestions();
    std::vector<DungeonSuggestion> const GetDungeonSuggestions();

private:
    std::vector<DungeonSuggestion> m_dungeonSuggestions;
};

#define sPlayerbotDungeonSuggestionMgr PlayerbotDungeonSuggestionMgr::instance()

#endif
