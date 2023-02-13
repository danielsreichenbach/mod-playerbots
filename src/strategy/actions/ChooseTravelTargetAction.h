/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_CHOOSETRAVELTARGETACTION_H
#define _PLAYERBOT_CHOOSETRAVELTARGETACTION_H

#include "MovementActions.h"
#include "TravelMgr.h"

class Quest;
class PlayerbotAI;
class Unit;

struct QuestStatusData;

class ChooseTravelTargetAction : public MovementAction
{
public:
    ChooseTravelTargetAction(PlayerbotAI *botAI, std::string const name = "choose travel target") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

    static TravelDestination *FindDestination(Player *bot, std::string const name);

protected:
    void getNewTarget(TravelTarget *newTarget, TravelTarget *oldTarget);
    void setNewTarget(TravelTarget *newTarget, TravelTarget *oldTarget);
    void ReportTravelTarget(TravelTarget *newTarget, TravelTarget *oldTarget);

    bool getBestDestination(std::vector<TravelDestination *> *activeDestinations, std::vector<WorldPosition *> *activePoints);

    bool SetGroupTarget(TravelTarget *target);
    bool SetCurrentTarget(TravelTarget *target, TravelTarget *oldTarget);
    bool SetQuestTarget(TravelTarget *target, bool onlyCompleted = false);
    bool SetNewQuestTarget(TravelTarget *target);
    bool SetRpgTarget(TravelTarget *target);
    bool SetGrindTarget(TravelTarget *target);
    bool SetBossTarget(TravelTarget *target);
    bool SetExploreTarget(TravelTarget *target);
    bool SetNpcFlagTarget(TravelTarget *target, std::vector<NPCFlags> flags, std::string const name = "", std::vector<uint32> items = {});
    bool SetNullTarget(TravelTarget *target);

private:
    virtual bool needForQuest(Unit *target);
    virtual bool needItemForQuest(uint32 itemId, Quest const *questTemplate, QuestStatusData const *questStatus);
};

#endif
