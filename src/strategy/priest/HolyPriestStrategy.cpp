/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "HolyPriestStrategy.h"
#include "Playerbots.h"

class HolyPriestStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    HolyPriestStrategyActionNodeFactory()
    {
        creators["smite"] = &smite;
    }

private:
    static ActionNode *smite([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("smite",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("shoot"), nullptr),
                              /*C*/ nullptr);
    }
};

HolyPriestStrategy::HolyPriestStrategy(PlayerbotAI *botAI) : HealPriestStrategy(botAI)
{
    actionNodeFactories.Add(new HolyPriestStrategyActionNodeFactory());
}

NextAction **HolyPriestStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("smite", 10.0f), new NextAction("mana burn", 9.0f), new NextAction("starshards", 8.0f), nullptr);
}

void HolyPriestStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    HealPriestStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("holy fire", NextAction::array(0, new NextAction("holy fire", ACTION_NORMAL + 9), nullptr)));
    triggers.push_back(new TriggerNode("shadowfiend", NextAction::array(0, new NextAction("shadowfiend", ACTION_HIGH), nullptr)));
    triggers.push_back(new TriggerNode("medium mana", NextAction::array(0, new NextAction("shadowfiend", ACTION_HIGH), nullptr)));
    triggers.push_back(new TriggerNode("low mana", NextAction::array(0, new NextAction("mana burn", ACTION_HIGH), nullptr)));
}
