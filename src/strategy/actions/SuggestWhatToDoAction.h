/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_SUGGESTWHATTODOACTION_H
#define _PLAYERBOT_SUGGESTWHATTODOACTION_H

#include "InventoryAction.h"

class PlayerbotAI;

class SuggestWhatToDoAction : public InventoryAction
{
public:
    SuggestWhatToDoAction(PlayerbotAI *botAI, std::string const name = "suggest what to do");

    bool Execute(Event event) override;
    bool isUseful() override;

protected:
    typedef void (SuggestWhatToDoAction::*Suggestion)();
    std::vector<Suggestion> suggestions;
    void instance();
    void specificQuest();
    void grindReputation();
    void something();
    void spam(std::string msg, uint8 flags = 0, bool worldChat = false, bool guild = false);

    std::vector<uint32> GetIncompletedQuests();

private:
    static std::map<std::string, uint8> instances;
    static std::map<std::string, uint8> factions;
};

class SuggestTradeAction : public SuggestWhatToDoAction
{
public:
    SuggestTradeAction(PlayerbotAI *botAI);

    bool Execute(Event event) override;
    bool isUseful() override { return true; }
};

#endif
