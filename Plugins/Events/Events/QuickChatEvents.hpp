#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class QuickChatEvents
{
public:
    QuickChatEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerQuickChatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
};

}
