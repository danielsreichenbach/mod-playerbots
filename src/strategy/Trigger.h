/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_TRIGGER_H
#define _PLAYERBOT_TRIGGER_H

#include "Common.h"
#include "Action.h"

class PlayerbotAI;
class Unit;

class Trigger : public AiNamedObject
{
public:
    Trigger(PlayerbotAI *botAI, std::string const name = "trigger", int32 checkInterval = 1);

    virtual ~Trigger() {}

    virtual Event Check();
    virtual void ExternalEvent([[maybe_unused]] std::string const param, [[maybe_unused]] Player *owner = nullptr) {}
    virtual void ExternalEvent([[maybe_unused]] WorldPacket &packet, [[maybe_unused]] Player *owner = nullptr) {}
    virtual bool IsActive() { return false; }
    virtual NextAction **getHandlers() { return nullptr; }
    void Update() {}
    virtual void Reset() {}
    virtual Unit *GetTarget();
    virtual Value<Unit *> *GetTargetValue();
    virtual std::string const GetTargetName() { return "self target"; }

    bool needCheck();

protected:
    int32 checkInterval;
    time_t lastCheckTime;
};

class TriggerNode
{
public:
    TriggerNode(std::string const name, NextAction **handlers = nullptr) : trigger(nullptr), handlers(handlers), name(name) {} // reorder args - whipowill

    virtual ~TriggerNode()
    {
        NextAction::destroy(handlers);
    }

    Trigger *getTrigger() { return trigger; }
    void setTrigger(Trigger *trigger) { this->trigger = trigger; }
    std::string const getName() { return name; }

    NextAction **getHandlers()
    {
        return NextAction::merge(NextAction::clone(handlers), trigger->getHandlers());
    }

    float getFirstRelevance()
    {
        return handlers[0] ? handlers[0]->getRelevance() : -1;
    }

private:
    Trigger *trigger;
    NextAction **handlers;
    std::string const name;
};

#endif
