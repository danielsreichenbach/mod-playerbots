/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "GenericDKNonCombatStrategy.h"
#include "Playerbots.h"

class GenericDKNonCombatStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericDKNonCombatStrategyActionNodeFactory()
    {
        creators["bone shield"] = &bone_shield;
        creators["horn of winter"] = &horn_of_winter;
    }

private:
    static ActionNode *bone_shield([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("bone shield",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *horn_of_winter([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("horn of winter",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }
};

GenericDKNonCombatStrategy::GenericDKNonCombatStrategy(PlayerbotAI *botAI) : NonCombatStrategy(botAI)
{
    actionNodeFactories.Add(new GenericDKNonCombatStrategyActionNodeFactory());
}

void GenericDKNonCombatStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    NonCombatStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("raise dead", NextAction::array(0, new NextAction("raise dead", ACTION_NORMAL + 1), nullptr)));
    triggers.push_back(new TriggerNode("horn of winter", NextAction::array(0, new NextAction("horn of winter", 21.0f), nullptr)));
    triggers.push_back(new TriggerNode("bone shield", NextAction::array(0, new NextAction("bone shield", 21.0f), nullptr)));
}

void DKBuffDpsStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("improved icy talons", NextAction::array(0, new NextAction("improved icy talons", 19.0f), nullptr)));
}
