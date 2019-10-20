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
    static int32_t HandleMapPinSetMapPinAtMessageHook(CNWSMessage*, CNWSPlayer*);
    static int32_t HandleMapPinChangePinMessageHook(CNWSMessage*, CNWSPlayer*);
    static int32_t HandleMapPinDestroyMapPinMessageHook(CNWSMessage*, CNWSPlayer*);
};

}
