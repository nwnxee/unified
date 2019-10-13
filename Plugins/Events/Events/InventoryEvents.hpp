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
    static int32_t AddItemHook(NWNXLib::API::CItemRepository*, NWNXLib::API::CNWSItem**, uint8_t, uint8_t, int32_t, int32_t);
    static void RemoveItemHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CItemRepository*, NWNXLib::API::CNWSItem*);
    static void AddGoldHook(NWNXLib::API::CNWSCreature*, int32_t, int32_t);
    static void RemoveGoldHook(NWNXLib::API::CNWSCreature*, int32_t, int32_t);
};

}
