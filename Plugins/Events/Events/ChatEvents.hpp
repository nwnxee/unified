#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ChatEvents
{
public:
    ChatEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerChatMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);

};

}
