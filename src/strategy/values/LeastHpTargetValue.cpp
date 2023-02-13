/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "LeastHpTargetValue.h"
#include "AttackersValue.h"
#include "Playerbots.h"

class FindLeastHpTargetStrategy : public FindNonCcTargetStrategy
{
public:
    FindLeastHpTargetStrategy(PlayerbotAI *botAI) : FindNonCcTargetStrategy(botAI), minHealth(0) {}

    void CheckAttacker(Unit *attacker, ThreatMgr *threatMgr) override
    {
        Player *bot = botAI->GetBot();
        if (IsCcTarget(attacker))
            return;

        if (!result || result->GetHealth() > attacker->GetHealth())
            result = attacker;
    }

protected:
    float minHealth;
};

Unit *LeastHpTargetValue::Calculate()
{
    FindLeastHpTargetStrategy strategy(botAI);
    return FindTarget(&strategy);
}
