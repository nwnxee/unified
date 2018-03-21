#pragma once

#include "API/Types.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Common.hpp"
#include "ViewPtr.hpp"
#include <cstdint>

namespace Events {

class DMActionEvents
{
public:
    DMActionEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static void HandleDMMessageHook(NWNXLib::Services::Hooks::CallType, 
        NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t, int32_t);
};

}
