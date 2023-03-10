/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_GENERICPALADINSTRATEGYACTIONNODEFACTORY_H
#define _PLAYERBOT_GENERICPALADINSTRATEGYACTIONNODEFACTORY_H

#include "Action.h"
#include "NamedObjectContext.h"

class PlayerbotAI;

class GenericPaladinStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    GenericPaladinStrategyActionNodeFactory()
    {
        creators["seal of light"] = &seal_of_light;
        creators["cleanse poison"] = &cleanse_poison;
        creators["cleanse disease"] = &cleanse_disease;
        creators["cleanse magic"] = &cleanse_magic;
        creators["cleanse poison on party"] = &cleanse_poison_on_party;
        creators["cleanse disease on party"] = &cleanse_disease_on_party;
        creators["seal of wisdom"] = &seal_of_wisdom;
        creators["seal of justice"] = &seal_of_justice;
        creators["hand of reckoning"] = &hand_of_reckoning;
        creators["judgement of wisdom"] = &judgement_of_wisdom;
        creators["divine shield"] = &divine_shield;
        creators["flash of light"] = &flash_of_light;
        creators["flash of light on party"] = &flash_of_light_on_party;
        creators["holy wrath"] = &holy_wrath;
        creators["lay on hands"] = &lay_on_hands;
        creators["lay on hands on party"] = &lay_on_hands_on_party;
        creators["hammer of wrath"] = &hammer_of_wrath;
        creators["retribution aura"] = &retribution_aura;
        creators["blessing of kings"] = &blessing_of_kings;
        creators["blessing of wisdom"] = &blessing_of_wisdom;
        creators["blessing of kings on party"] = &blessing_of_kings_on_party;
        creators["blessing of wisdom on party"] = &blessing_of_wisdom_on_party;
        creators["blessing of sanctuary"] = &blessing_of_sanctuary;
    }

private:
    static ActionNode *blessing_of_sanctuary(PlayerbotAI *botAI)
    {
        return new ActionNode("blessing of sanctuary",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *blessing_of_kings(PlayerbotAI *botAI)
    {
        return new ActionNode("blessing of kings",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *blessing_of_wisdom(PlayerbotAI *botAI)
    {
        return new ActionNode("blessing of wisdom",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *blessing_of_kings_on_party(PlayerbotAI *botAI)
    {
        return new ActionNode("blessing of kings on party",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *blessing_of_wisdom_on_party(PlayerbotAI *botAI)
    {
        return new ActionNode("blessing of wisdom on party",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *retribution_aura(PlayerbotAI *botAI)
    {
        return new ActionNode("retribution aura",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("devotion aura"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *lay_on_hands(PlayerbotAI *botAI)
    {
        return new ActionNode("lay on hands",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("divine shield"), new NextAction("flash of light"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *lay_on_hands_on_party(PlayerbotAI *botAI)
    {
        return new ActionNode("lay on hands on party",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("flash of light"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *seal_of_light(PlayerbotAI *botAI)
    {
        return new ActionNode("seal of light",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("seal of justice"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *cleanse_poison(PlayerbotAI *botAI)
    {
        return new ActionNode("cleanse poison",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("purify poison"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *cleanse_magic(PlayerbotAI *botAI)
    {
        return new ActionNode("cleanse magic",
                              /*P*/ nullptr,
                              /*A*/ nullptr,
                              /*C*/ nullptr);
    }

    static ActionNode *cleanse_disease(PlayerbotAI *botAI)
    {
        return new ActionNode("cleanse disease",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("purify disease"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *cleanse_poison_on_party(PlayerbotAI *botAI)
    {
        return new ActionNode("cleanse poison on party",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("purify poison on party"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *cleanse_disease_on_party(PlayerbotAI *botAI)
    {
        return new ActionNode("cleanse disease on party",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("purify disease on party"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *seal_of_wisdom(PlayerbotAI *botAI)
    {
        return new ActionNode("seal of wisdom",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("seal of justice"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *seal_of_justice(PlayerbotAI *botAI)
    {
        return new ActionNode("seal of justice",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("seal of righteousness"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *hand_of_reckoning(PlayerbotAI *botAI)
    {
        return new ActionNode("hand of reckoning",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("judgement of justice"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *judgement_of_wisdom(PlayerbotAI *botAI)
    {
        return new ActionNode("judgement of wisdom",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("judgement of light"), nullptr),
                              /*C*/ nullptr);
    }
    static ActionNode *divine_shield(PlayerbotAI *botAI)
    {
        return new ActionNode("divine shield",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("divine protection"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *flash_of_light(PlayerbotAI *botAI)
    {
        return new ActionNode("flash of light",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("holy light"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *flash_of_light_on_party(PlayerbotAI *botAI)
    {
        return new ActionNode("flash of light on party",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("holy light on party"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *holy_wrath(PlayerbotAI *botAI)
    {
        return new ActionNode("holy wrath",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("consecration"), nullptr),
                              /*C*/ nullptr);
    }

    static ActionNode *hammer_of_wrath(PlayerbotAI *botAI)
    {
        return new ActionNode("hammer of wrath",
                              /*P*/ nullptr,
                              /*A*/ NextAction::array(0, new NextAction("melee"), nullptr),
                              /*C*/ nullptr);
    }
};

#endif
