#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class QuickbarEvents
{
public:
    QuickbarEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerGuiQuickbar_SetButtonHook(CNWSMessage*, CNWSPlayer*, uint8_t, uint8_t);
};

}
