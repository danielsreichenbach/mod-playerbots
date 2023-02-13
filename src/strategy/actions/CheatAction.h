/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "Action.h"

class PlayerbotAI;

enum class BotCheatMask : uint32;

class CheatAction : public Action
{
public:
    CheatAction(PlayerbotAI *botAI) : Action(botAI, "cheat") {}

    bool Execute(Event event) override;

private:
    static BotCheatMask GetCheatMask(std::string const cheat);
    static std::string const GetCheatName(BotCheatMask cheatMask);
    void ListCheats();
};
