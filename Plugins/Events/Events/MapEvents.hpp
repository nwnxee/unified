#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class MapEvents
{
public:
    MapEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandleMapPinSetMapPinAtMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
    static int32_t HandleMapPinChangePinMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
    static int32_t HandleMapPinDestroyMapPinMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*);
};

}
