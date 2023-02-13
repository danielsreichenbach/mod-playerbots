/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CUSTOMSTRATEGY_H
#define _PLAYERBOT_CUSTOMSTRATEGY_H

#include "Strategy.h"

#include <map>

class PlayerbotAI;

class CustomStrategy : public Strategy, public Qualified
{
public:
    CustomStrategy(PlayerbotAI *botAI);

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return std::string("custom::" + qualifier); }
    void Reset();

    static std::map<std::string, std::string> actionLinesCache;

private:
    std::vector<std::string> actionLines;
    void LoadActionLines(uint32 owner);
};

#endif
