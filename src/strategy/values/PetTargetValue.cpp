/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "PetTargetValue.h"
#include "Playerbots.h"

Unit *PetTargetValue::Calculate()
{
    return botAI->GetBot()->GetPet();
}
