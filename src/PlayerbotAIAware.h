/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PLAYERbotAIAWARE_H
#define _PLAYERBOT_PLAYERbotAIAWARE_H

class PlayerbotAI;

class PlayerbotAIAware
{
public:
    PlayerbotAIAware(PlayerbotAI *botAI) : botAI(botAI) {}

protected:
    PlayerbotAI *botAI;
};

#endif
