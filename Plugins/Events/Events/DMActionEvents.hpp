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
    static int32_t HandleGiveEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&, int32_t);
    static int32_t HandleGroupEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&);
    static int32_t HandleSingleTargetEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&);
    static int32_t HandleTeleportEvent(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t, const std::string&);
    static int32_t HandleDMMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t, int32_t);
};

}
