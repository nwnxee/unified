#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "ViewPtr.hpp"

namespace Events {

class ItemEvents
{
public:
    ItemEvents(NWNXLib::ViewPtr<NWNXLib::Services::HooksProxy> hooker);

private:
    static int32_t UseItemHook(NWNXLib::API::CNWSCreature*, NWNXLib::API::Types::ObjectID, uint8_t,
        uint8_t, NWNXLib::API::Types::ObjectID, NWNXLib::API::Vector, NWNXLib::API::Types::ObjectID);
    static void OpenInventoryHook(NWNXLib::API::CNWSItem*, NWNXLib::API::Types::ObjectID);
    static void CloseInventoryHook(NWNXLib::API::CNWSItem*, NWNXLib::API::Types::ObjectID, int32_t);
    static int32_t AddItemHook(NWNXLib::API::CItemRepository*, NWNXLib::API::CNWSItem**, uint8_t, uint8_t, int32_t, int32_t);
    static void RemoveItemHook(NWNXLib::Services::Hooks::CallType, NWNXLib::API::CItemRepository*, NWNXLib::API::CNWSItem*);
    static uint32_t FindItemWithBaseItemIdHook(NWNXLib::API::CItemRepository*, uint32_t, int32_t);
    static int32_t LearnScrollHook(NWNXLib::API::CNWSCreature*, NWNXLib::API::Types::ObjectID);
};

}
