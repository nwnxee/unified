#pragma once

#include "API/Types.hpp"
#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class ItemEvents
{
public:
    ItemEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t CanUseItemHook(CNWSCreature*, CNWSItem*, int32_t);
    static int32_t UseItemHook(CNWSCreature*, NWNXLib::API::Types::ObjectID, uint8_t,
        uint8_t, NWNXLib::API::Types::ObjectID, Vector, NWNXLib::API::Types::ObjectID);
    static void OpenInventoryHook(CNWSItem*, NWNXLib::API::Types::ObjectID);
    static void CloseInventoryHook(CNWSItem*, NWNXLib::API::Types::ObjectID, int32_t);
    static uint32_t FindItemWithBaseItemIdHook(CItemRepository*, uint32_t, int32_t);
    static int32_t LearnScrollHook(CNWSCreature*, NWNXLib::API::Types::ObjectID);
    static int32_t RunEquipHook(CNWSCreature*, NWNXLib::API::Types::ObjectID, uint32_t, uint32_t);
    static int32_t RunUnequipHook(CNWSCreature*, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID, uint8_t, uint8_t, int32_t, uint32_t);
    static void ItemEventHandlerHook(CNWSItem*, uint32_t, NWNXLib::API::Types::ObjectID, void*, uint32_t, uint32_t);
    static int32_t UseLoreOnItemHook(CNWSCreature*, NWNXLib::API::Types::ObjectID);
    static void PayToIdentifyItemHook(CNWSCreature*, NWNXLib::API::Types::ObjectID, NWNXLib::API::Types::ObjectID);
    static void SplitItemHook(CNWSCreature*, CNWSItem*, int32_t);
};

}
