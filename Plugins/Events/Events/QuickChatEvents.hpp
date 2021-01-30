#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class QuickChatEvents
{
public:
    QuickChatEvents();

private:
    static int32_t HandlePlayerToServerQuickChatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
