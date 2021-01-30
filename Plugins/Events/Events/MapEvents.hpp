#pragma once

#include "nwnx.hpp"

namespace Events {

class MapEvents
{
public:
    MapEvents();

private:
    static int32_t HandleMapPinSetMapPinAtMessageHook(CNWSMessage*, CNWSPlayer*);
    static int32_t HandleMapPinChangePinMessageHook(CNWSMessage*, CNWSPlayer*);
    static int32_t HandleMapPinDestroyMapPinMessageHook(CNWSMessage*, CNWSPlayer*);
};

}
