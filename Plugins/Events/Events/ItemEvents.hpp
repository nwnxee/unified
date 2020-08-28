#pragma once

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
    static int32_t UseItemHook(CNWSCreature*, ObjectID, uint8_t,
        uint8_t, ObjectID, Vector, ObjectID, int32_t);
    static void OpenInventoryHook(CNWSItem*, ObjectID);
    static void CloseInventoryHook(CNWSItem*, ObjectID, int32_t);
    static uint32_t FindItemWithBaseItemIdHook(CItemRepository*, uint32_t, int32_t);
    static int32_t LearnScrollHook(CNWSCreature*, ObjectID);
    static int32_t CanEquipItemHook(CNWSCreature*, CNWSItem*, uint32_t*, int32_t, int32_t, int32_t, CNWSPlayer*);
    static int32_t RunEquipHook(CNWSCreature*, ObjectID, uint32_t, uint32_t);
    static int32_t RunUnequipHook(CNWSCreature*, ObjectID, ObjectID, uint8_t, uint8_t, int32_t, uint32_t);
    static void ItemEventHandlerHook(CNWSItem*, uint32_t, ObjectID, void*, uint32_t, uint32_t);
    static int32_t UseLoreOnItemHook(CNWSCreature*, ObjectID);
    static void PayToIdentifyItemHook(CNWSCreature*, ObjectID, ObjectID);
    static void SplitItemHook(CNWSCreature*, CNWSItem*, int32_t);
};

}
