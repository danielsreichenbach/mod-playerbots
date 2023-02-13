/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_QUERYITEMUSAGEACTION_H
#define _PLAYERBOT_QUERYITEMUSAGEACTION_H

#include "InventoryAction.h"

class Quest;
class PlayerbotAI;

struct ItemTemplate;
struct QuestStatusData;

class QueryItemUsageAction : public InventoryAction
{
public:
    QueryItemUsageAction(PlayerbotAI *botAI, std::string const name = "query item usage") : InventoryAction(botAI, name) {}

    bool Execute(Event event) override;

protected:
    uint32 GetCount(ItemTemplate const *item);
    std::string const QueryItem(ItemTemplate const *item, uint32 count, uint32 total);
    std::string const QueryItemUsage(ItemTemplate const *item);
    std::string const QueryItemPrice(ItemTemplate const *item);
    std::string const QueryQuestItem(uint32 itemId, Quest const *questTemplate, QuestStatusData const *questStatus);
    std::string const QueryQuestItem(uint32 itemId);

private:
    std::ostringstream out;
};

#endif
