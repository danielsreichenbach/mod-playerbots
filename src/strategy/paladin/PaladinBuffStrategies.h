/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_PALADINBUFFSTRATEGIES_H
#define _PLAYERBOT_PALADINBUFFSTRATEGIES_H

#include "Strategy.h"

class PlayerbotAI;

class PaladinBuffManaStrategy : public Strategy
{
public:
    PaladinBuffManaStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bmana"; }
};

class PaladinBuffHealthStrategy : public Strategy
{
public:
    PaladinBuffHealthStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bhealth"; }
};

class PaladinBuffDpsStrategy : public Strategy
{
public:
    PaladinBuffDpsStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bdps"; }
};

class PaladinBuffArmorStrategy : public Strategy
{
public:
    PaladinBuffArmorStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "barmor"; }
};

class PaladinBuffAoeStrategy : public Strategy
{
public:
    PaladinBuffAoeStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "baoe"; }
};

class PaladinBuffThreatStrategy : public Strategy
{
public:
    PaladinBuffThreatStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bthreat"; }
};

class PaladinBuffStatsStrategy : public Strategy
{
public:
    PaladinBuffStatsStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "bstats"; }
};

class PaladinShadowResistanceStrategy : public Strategy
{
public:
    PaladinShadowResistanceStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "rshadow"; }
};

class PaladinFrostResistanceStrategy : public Strategy
{
public:
    PaladinFrostResistanceStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "rfrost"; }
};

class PaladinFireResistanceStrategy : public Strategy
{
public:
    PaladinFireResistanceStrategy(PlayerbotAI *botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode *> &triggers) override;
    std::string const getName() override { return "rfire"; }
};

#endif
