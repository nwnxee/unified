#pragma once

#include "nwnx.hpp"
#include "API/Vector.hpp"

namespace Events {

class ItemEvents
{
public:
    ItemEvents();

private:
    static int32_t CanUseItemHook(CNWSCreature*, CNWSItem*, int32_t);
    static int32_t UseItemHook(CNWSCreature*, ObjectID, uint8_t, uint8_t, ObjectID, Vector, ObjectID, int32_t);
    static void OpenInventoryHook(CNWSItem*, ObjectID);
    static void CloseInventoryHook(CNWSItem*, ObjectID, int32_t);
    static ObjectID FindItemWithBaseItemIdHook(CItemRepository*, uint32_t, int32_t);
    static int32_t LearnScrollHook(CNWSCreature*, ObjectID);
    static int32_t CanEquipItemHook(CNWSCreature*, CNWSItem*, uint32_t*, int32_t, int32_t, int32_t, CNWSPlayer*);
    static int32_t RunEquipHook(CNWSCreature*, ObjectID, uint32_t, ObjectID);
    static int32_t RunUnequipHook(CNWSCreature*, ObjectID, ObjectID, uint8_t, uint8_t, int32_t, ObjectID);
    static void ItemEventHandlerHook(CNWSItem*, uint32_t, ObjectID, void*, uint32_t, uint32_t);
    static int32_t UseLoreOnItemHook(CNWSCreature*, ObjectID);
    static void PayToIdentifyItemHook(CNWSCreature*, ObjectID, ObjectID);
    static void SplitItemHook(CNWSCreature*, CNWSItem*, int32_t);
    static int32_t AcquireItemHook(CNWSCreature*, CNWSItem**, ObjectID, ObjectID, uint8_t, uint8_t, int32_t, int32_t);
};

}
