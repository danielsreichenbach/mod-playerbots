/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ArcaneMageStrategy.h"
#include "Playerbots.h"

class ArcaneMageStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    ArcaneMageStrategyActionNodeFactory()
    {
        creators["arcane blast"] = &arcane_blast;
        creators["arcane barrage"] = &arcane_barrage;
        creators["arcane missiles"] = &arcane_missiles;
    }

private:
    static ActionNode *arcane_blast([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("arcane blast",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("arcane missiles"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *arcane_barrage([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("arcane barrage",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("arcane missiles"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *arcane_missiles([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("arcane missiles",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("shoot"), nullptr),
                              /*C*/ nullptr);
    }
};

ArcaneMageStrategy::ArcaneMageStrategy(PlayerbotAI *botAI) : GenericMageStrategy(botAI)
{
    actionNodeFactories.Add(new ArcaneMageStrategyActionNodeFactory());
}

NextAction **ArcaneMageStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("arcane barrage", 10.0f), nullptr);
}

void ArcaneMageStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    GenericMageStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("arcane blast", NextAction::array(0, new NextAction("arcane blast", 15.0f), nullptr)));
    triggers.push_back(new TriggerNode("missile barrage", NextAction::array(0, new NextAction("arcane missiles", 15.0f), nullptr)));
}
