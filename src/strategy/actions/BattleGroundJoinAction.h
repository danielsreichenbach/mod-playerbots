/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_BATTLEGROUNDJOINACTION_H
#define _PLAYERBOT_BATTLEGROUNDJOINACTION_H

#include "Action.h"
#include "DBCEnums.h"

class PlayerbotAI;

struct CreatureData;

enum ArenaType : uint8;
enum BattlegroundQueueTypeId : uint8;

class BGJoinAction : public Action
{
public:
    BGJoinAction(PlayerbotAI *botAI, std::string const name = "bg join") : Action(botAI, name) {}

    bool isUseful() override;
    bool canJoinBg(BattlegroundQueueTypeId queueTypeId, BattlegroundBracketId bracketId);
    virtual bool shouldJoinBg(BattlegroundQueueTypeId queueTypeId, BattlegroundBracketId bracketId);
    bool Execute(Event event) override;
    virtual bool gatherArenaTeam(ArenaType type);

protected:
    bool JoinQueue(uint32 type);
    std::vector<uint32> bgList;
    std::vector<uint32> ratedList;
};

class FreeBGJoinAction : public BGJoinAction
{
public:
    FreeBGJoinAction(PlayerbotAI *botAI, std::string const name = "free bg join") : BGJoinAction(botAI, name) {}

    bool shouldJoinBg(BattlegroundQueueTypeId queueTypeId, BattlegroundBracketId bracketId) override;
};

class BGLeaveAction : public Action
{
public:
    BGLeaveAction(PlayerbotAI *botAI, std::string const name = "bg leave") : Action(botAI) {}

    bool Execute(Event event) override;
};

class BGStatusAction : public Action
{
public:
    BGStatusAction(PlayerbotAI *botAI) : Action(botAI, "bg status") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class BGStatusCheckAction : public Action
{
public:
    BGStatusCheckAction(PlayerbotAI *botAI, std::string const name = "bg status check") : Action(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
