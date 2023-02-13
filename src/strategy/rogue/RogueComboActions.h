/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_ROGUECOMBOACTIONS_H
#define _PLAYERBOT_ROGUECOMBOACTIONS_H

#include "GenericSpellActions.h"

class PlayerbotAI;

class CastComboAction : public CastMeleeSpellAction
{
public:
    CastComboAction(PlayerbotAI *botAI, std::string const name) : CastMeleeSpellAction(botAI, name) {}

    bool isUseful() override;
};

class CastSinisterStrikeAction : public CastComboAction
{
public:
    CastSinisterStrikeAction(PlayerbotAI *botAI) : CastComboAction(botAI, "sinister strike") {}
};

class CastMutilateAction : public CastComboAction
{
public:
    CastMutilateAction(PlayerbotAI *botAI) : CastComboAction(botAI, "mutilate") {}
};

class CastRiposteAction : public CastComboAction
{
public:
    CastRiposteAction(PlayerbotAI *botAI) : CastComboAction(botAI, "riposte") {}
};

class CastGougeAction : public CastComboAction
{
public:
    CastGougeAction(PlayerbotAI *botAI) : CastComboAction(botAI, "gouge") {}
};

class CastBackstabAction : public CastComboAction
{
public:
    CastBackstabAction(PlayerbotAI *botAI) : CastComboAction(botAI, "backstab") {}
};

#endif
