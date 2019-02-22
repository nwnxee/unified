#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class QuickChatEvents
{
public:
    QuickChatEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandlePlayerToServerQuickChatMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t);
};

}
