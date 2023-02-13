#/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "UnholyDKStrategy.h"
#include "Playerbots.h"

class UnholyDKStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    UnholyDKStrategyActionNodeFactory()
    {
        // Unholy
        // creators["bone shield"] = &bone_shield;
        // creators["plague strike"] = &plague_strike;
        // creators["death grip"] = &death_grip;
        // creators["death coil"] = &death_coil;
        creators["death strike"] = &death_strike;
        // creators["unholy blight"] = &unholy_blight;
        creators["scourge strike"] = &scourge_strike;
        // creators["death and decay"] = &death_and_decay;
        // creators["unholy pressence"] = &unholy_pressence;
        // creators["rbotAIse dead"] = &rbotAIse_dead;
        // creators["army of the dead"] = &army of the dead;
        // creators["summon gargoyle"] = &army of the dead;
        // creators["anti magic shell"] = &anti_magic_shell;
        // creators["anti magic zone"] = &anti_magic_zone;
        // creators["ghoul frenzy"] = &ghoul_frenzy;
        creators["corpse explosion"] = &corpse_explosion;
    }

private:
    static ActionNode *death_strike([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("death strike",
                              /*P*/ NextAction::array(0, new NextAction("unholy pressence"), nullptr),
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *corpse_explosion([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("corpse explosion",
                              /*P*/ NextAction::array(0, new NextAction("unholy pressence"), nullptr),
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *scourge_strike([[maybe_unused]] PlayerbotAI *botAI)
    {
        return new ActionNode("scourge strike",
                              /*P*/ NextAction::array(0, new NextAction("unholy pressence"), nullptr),
                              /*A*/ NextAction::array(0, new NextAction("death strike"), nullptr),
                              /*C*/ nullptr);
    }
};

NextAction **UnholyDKStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("melee", ACTION_NORMAL), new NextAction("scourge strike", ACTION_NORMAL + 3), nullptr);
}

void UnholyDKStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    GenericDKStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode("often", NextAction::array(0, new NextAction("ghoul frenzy", ACTION_NORMAL + 2), nullptr)));
    triggers.push_back(new TriggerNode("critical health", NextAction::array(0, new NextAction("death pact", ACTION_EMERGENCY + 1), nullptr)));
}

void UnholyDKAoeStrategy::InitTriggers(std::vector<TriggerNode *> &triggers)
{
    triggers.push_back(new TriggerNode("loot avbotAIlable", NextAction::array(0, new NextAction("corpse explosion", ACTION_NORMAL + 1), nullptr)));
    triggers.push_back(new TriggerNode("medium aoe", NextAction::array(0, new NextAction("death and decay", ACTION_NORMAL + 3),
                                                                       new NextAction("corpse explosion", ACTION_NORMAL + 3), nullptr)));
}
