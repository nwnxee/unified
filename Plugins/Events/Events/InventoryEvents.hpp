#pragma once

#include "API/Vector.hpp"
#include "Common.hpp"
#include "Services/Hooks/Hooks.hpp"

namespace Events {

class InventoryEvents
{
public:
    InventoryEvents(NWNXLib::Services::HooksProxy* hooker);

private:
    static int32_t HandlePlayerToServerGuiInventoryMessageHook(CNWSMessage*, CNWSPlayer*, uint8_t);
    static int32_t AddItemHook(CItemRepository*, CNWSItem**, uint8_t, uint8_t, int32_t, int32_t);
    static void RemoveItemHook(bool, CItemRepository*, CNWSItem*);
    static void AddGoldHook(CNWSCreature*, int32_t, int32_t);
    static void RemoveGoldHook(CNWSCreature*, int32_t, int32_t);
};

}
