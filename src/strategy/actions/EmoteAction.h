/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#ifndef _PLAYERBOT_EMOTEACTION_H
#define _PLAYERBOT_EMOTEACTION_H

#include "Action.h"
#include "NamedObjectContext.h"

#include <map>

class Player;
class PlayerbotAI;
class Unit;

enum TextEmotes : uint32;

class EmoteActionBase : public Action
{
public:
    EmoteActionBase(PlayerbotAI *botAI, std::string const name);

    static uint32 GetNumberOfEmoteVariants(TextEmotes emote, uint8 race, uint8 gender);

protected:
    bool Emote(Unit *target, uint32 type, bool textEmote = false);
    bool ReceiveEmote(Player *source, uint32 emote, bool verbal = false);
    Unit *GetTarget();
    void InitEmotes();
    static std::map<std::string, uint32> emotes;
    static std::map<std::string, uint32> textEmotes;
};

class EmoteAction : public EmoteActionBase, public Qualified
{
public:
    EmoteAction(PlayerbotAI *botAI);

    bool Execute(Event event) override;
    bool isUseful() override;
};

class TalkAction : public EmoteActionBase
{
public:
    TalkAction(PlayerbotAI *botAI) : EmoteActionBase(botAI, "talk") {}

    bool Execute(Event event) override;
    static uint32 GetRandomEmote(Unit *unit, bool textEmote = false);
};

#endif
