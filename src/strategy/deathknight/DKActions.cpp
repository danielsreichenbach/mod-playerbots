/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "DKActions.h"
#include "Playerbots.h"

NextAction **CastDeathchillAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("frost presence"), nullptr), CastSpellAction::getPrerequisites());
}

NextAction **CastDarkCommandAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("blood presence"), nullptr), CastSpellAction::getPrerequisites());
}

NextAction **CastUnholyMeleeSpellAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("unholy presence"), nullptr), CastMeleeSpellAction::getPrerequisites());
}

NextAction **CastFrostMeleeSpellAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("frost presence"), nullptr), CastMeleeSpellAction::getPrerequisites());
}

NextAction **CastBloodMeleeSpellAction::getPrerequisites()
{
    return NextAction::merge(NextAction::array(0, new NextAction("blood presence"), nullptr), CastMeleeSpellAction::getPrerequisites());
}
