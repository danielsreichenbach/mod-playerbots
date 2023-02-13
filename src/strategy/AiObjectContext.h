/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_AIOBJECTCONTEXT_H
#define _PLAYERBOT_AIOBJECTCONTEXT_H

#include "Common.h"
#include "NamedObjectContext.h"
#include "PlayerbotAIAware.h"
#include "Strategy.h"
#include "Trigger.h"
#include "Value.h"

#include <sstream>
#include <string>

class PlayerbotAI;

class AiObjectContext : public PlayerbotAIAware
{
public:
    AiObjectContext(PlayerbotAI *botAI);
    virtual ~AiObjectContext() {}

    virtual Strategy *GetStrategy(std::string const name);
    virtual std::set<std::string> GetSiblingStrategy(std::string const name);
    virtual Trigger *GetTrigger(std::string const name);
    virtual Action *GetAction(std::string const name);
    virtual UntypedValue *GetUntypedValue(std::string const name);

    template <class T>
    Value<T> *GetValue(std::string const name)
    {
        return dynamic_cast<Value<T> *>(GetUntypedValue(name));
    }

    template <class T>
    Value<T> *GetValue(std::string const name, std::string const param)
    {
        return GetValue<T>((std::string(name) + "::" + param));
    }

    template <class T>
    Value<T> *GetValue(std::string const name, int32 param)
    {
        std::ostringstream out;
        out << param;
        return GetValue<T>(name, out.str());
    }

    std::set<std::string> GetValues();
    std::set<std::string> GetSupportedStrategies();
    std::set<std::string> GetSupportedActions();
    std::string const FormatValues();

    virtual void Update();
    virtual void Reset();
    virtual void AddShared(NamedObjectContext<UntypedValue> *sharedValues);

    std::vector<std::string> Save();
    void Load(std::vector<std::string> data);

    std::vector<std::string> performanceStack;

protected:
    NamedObjectContextList<Strategy> strategyContexts;
    NamedObjectContextList<Action> actionContexts;
    NamedObjectContextList<Trigger> triggerContexts;
    NamedObjectContextList<UntypedValue> valueContexts;
};

#endif
