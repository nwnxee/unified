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
    static int32_t HandleGiveEvent(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t, int32_t, const std::string&, int32_t);
    static int32_t HandleGroupEvent(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t, int32_t, const std::string&);
    static int32_t HandleDMMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t, int32_t);
};

}
