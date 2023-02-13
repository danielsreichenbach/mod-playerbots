/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PLAYERBOTCOMMANDSERVER_H
#define _PLAYERBOT_PLAYERBOTCOMMANDSERVER_H

class PlayerbotCommandServer
{
public:
    PlayerbotCommandServer() {}
    virtual ~PlayerbotCommandServer() {}
    static PlayerbotCommandServer *instance()
    {
        static PlayerbotCommandServer instance;
        return &instance;
    }

    void Start();
};

#define sPlayerbotCommandServer PlayerbotCommandServer::instance()

#endif
