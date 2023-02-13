/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DpsPaladinStrategy.h"
#include "Playerbots.h"

class DpsPaladinStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    DpsPaladinStrategyActionNodeFactory()
    {
        creators["seal of vengeance"] = &seal_of_vengeance;
        creators["seal of command"] = &seal_of_command;
        creators["blessing of might"] = &blessing_of_might;
        creators["crusader strike"] = &crusader_strike;
    }

private:
    static ActionNode *seal_of_vengeance([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("seal of vengeance",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("seal of command"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *seal_of_command([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("seal of command",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("seal of wisdom"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *blessing_of_might([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("blessing of might",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("blessing of kings"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *crusader_strike([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("crusader strike",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("melee"), nullptr),
                              /*C*/ nullptr);
    }
};

DpsPaladinStrategy::DpsPaladinStrategy(PlayerbotAI *botAI) : GenericPaladinStrategy(botAI)
{
    actionNodeFactories.Add(new DpsPaladinStrategyActionNodeFactory());
}

NextAction **DpsPaladinStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("crusader strike", ACTION_NORMAL + 1), nullptr);
}

void DpsPaladinStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    GenericPaladinStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("seal", NextAction::array(0, new NextAction("seal of wisdom", 90.0f), nullptr)));
    triggers.push_back(new TriggerNode("low health", NextAction::array(0, new NextAction("divine shield", ACTION_CRITICAL_HEAL + 2), new NextAction("holy light", ACTION_CRITICAL_HEAL + 2), nullptr)));
    triggers.push_back(new TriggerNode("judgement of wisdom", NextAction::array(0, new NextAction("judgement of wisdom", ACTION_NORMAL + 2), nullptr)));
    triggers.push_back(new TriggerNode("medium aoe", NextAction::array(0, new NextAction("divine storm", ACTION_HIGH + 1), new NextAction("consecration", ACTION_HIGH + 1), nullptr)));
    triggers.push_back(new TriggerNode("art of war", NextAction::array(0, new NextAction("exorcism", ACTION_HIGH + 2), nullptr)));
}
