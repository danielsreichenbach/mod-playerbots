/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PLACEHOLDERHELPER_H
#define _PLAYERBOT_PLACEHOLDERHELPER_H

#include "Common.h"
#include "Player.h"
#include "PlayerbotDungeonSuggestionMgr.h"

#include <map>

typedef std::map<std::string, std::string> PlaceholderMap;

class PlaceholderHelper
{
public:
    static void MapRole(PlaceholderMap &placeholders, Player *bot);
    static void MapDungeon(
        PlaceholderMap &placeholders,
        DungeonSuggestion const *dungeonSuggestion,
        Player *bot);

private:
    struct Insertion
    {
        std::ostringstream &out;
        DungeonSuggestion const *dungeonSuggestion;
    };

    static void InsertDungeonName(Insertion &insertion);
    static void InsertDungeonStrategy(Insertion &insertion);
    static void InsertDifficulty(Insertion &insertion, Player *bot);
};

#endif
