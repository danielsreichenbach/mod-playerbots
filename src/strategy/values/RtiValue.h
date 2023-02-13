/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_RTIVALUE_H
#define _PLAYERBOT_RTIVALUE_H

#include "Value.h"

class PlayerbotAI;

class RtiValue : public ManualSetValue<std::string>
{
	public:
        RtiValue(PlayerbotAI* botAI);

        std::string const Save() override;
        bool Load(std::string const text) override;
};

class RtiCcValue : public ManualSetValue<std::string>
{
	public:
        RtiCcValue(PlayerbotAI* botAI);

        std::string const Save() override;
        bool Load(std::string const text) override;
};

#endif
