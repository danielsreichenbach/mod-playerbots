/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "TankWarlockStrategy.h"
#include "Playerbots.h"

class GenericWarlockStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericWarlockStrategyActionNodeFactory()
    {
        creators["summon voidwalker"] = &summon_voidwalker;
        creators["summon felguard"] = &summon_felguard;
        creators["summon succubus"] = &summon_succubus;
    }

private:
    static ActionNode *summon_voidwalker([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("summon voidwalker",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("summon imp"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *summon_felguard([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("summon felguard",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("summon succubus"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *summon_succubus([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("summon succubus",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("summon voidwalker"), nullptr),
                              /*C*/ nullptr);
    }
};

TankWarlockStrategy::TankWarlockStrategy(PlayerbotAI *botAI) : GenericWarlockStrategy(botAI)
{
    actionNodeFactories.Add(new GenericWarlockStrategyActionNodeFactory());
}

NextAction **TankWarlockStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("shoot", 10.0f), nullptr);
}

void TankWarlockStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    GenericWarlockStrategy::InitTriggers(triggers);
}
