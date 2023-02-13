/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PLAYERBOTDBSTORE_H
#define _PLAYERBOT_PLAYERBOTDBSTORE_H

#include "Common.h"

#include <vector>

class PlayerbotAI;

class PlayerbotDbStore
{
public:
    PlayerbotDbStore() {}
    virtual ~PlayerbotDbStore() {}
    static PlayerbotDbStore *instance()
    {
        static PlayerbotDbStore instance;
        return &instance;
    }

    void Save(PlayerbotAI *botAI);
    void Load(PlayerbotAI *botAI);
    void Reset(PlayerbotAI *botAI);

private:
    void SaveValue(uint32 guid, std::string const key, std::string const value);
    std::string const FormatStrategies(std::string const type, std::vector<std::string> strategies);
};

#define sPlayerbotDbStore PlayerbotDbStore::instance()

#endif
