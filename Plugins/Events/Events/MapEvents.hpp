#pragma once

#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class MapEvents
{
public:
    MapEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandleMapPinSetMapPinAtMessageHook(CNWSMessage*, CNWSPlayer*);
    static int32_t HandleMapPinChangePinMessageHook(CNWSMessage*, CNWSPlayer*);
    static int32_t HandleMapPinDestroyMapPinMessageHook(CNWSMessage*, CNWSPlayer*);
};

}
