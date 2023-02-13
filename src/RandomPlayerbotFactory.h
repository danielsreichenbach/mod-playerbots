/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RANDOMPLAYERBOTFACTORY_H
#define _PLAYERBOT_RANDOMPLAYERBOTFACTORY_H

#include "Common.h"

#include <map>
#include <unordered_map>
#include <vector>

class Player;
class WorldSession;

class RandomPlayerbotFactory
{
    public:
        RandomPlayerbotFactory(uint32 accountId);
		virtual ~RandomPlayerbotFactory() { }

        Player* CreateRandomBot(WorldSession* session, uint8 cls, std::unordered_map<uint8, std::vector<std::string>> names);
        static void CreateRandomBots();
        static void CreateRandomGuilds();
        static void CreateRandomArenaTeams();
        static std::string const CreateRandomGuildName();

	private:
        std::string const CreateRandomBotName(uint8 gender);
        static std::string const CreateRandomArenaTeamName();

        uint32 accountId;
        static std::map<uint8, std::vector<uint8>> availableRaces;
};

#endif
