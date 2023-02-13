/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_QUEUE_H
#define _PLAYERBOT_QUEUE_H

#include "Common.h"
#include "Action.h"

class Queue
{
public:
    Queue(void) {}
    ~Queue(void) {}

    void Push(ActionBasket *action);
    ActionNode *Pop();
    ActionBasket *Peek();
    uint32 Size();
    void RemoveExpired();

private:
    std::list<ActionBasket *> actions;
};

#endif
