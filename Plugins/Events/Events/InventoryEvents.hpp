#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class InventoryEvents
{
public:
    InventoryEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t HandlePlayerToServerGuiInventoryMessageHook(NWNXLib::API::CNWSMessage*, NWNXLib::API::CNWSPlayer*, uint8_t);
};

}
