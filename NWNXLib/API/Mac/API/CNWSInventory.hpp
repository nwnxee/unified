#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CNWSItem;

struct CNWSInventory
{
    void** m_vtable;
    uint32_t m_pEquipSlot[18];

    // The below are auto generated stubs.
    CNWSInventory(const CNWSInventory&) = default;
    CNWSInventory& operator=(const CNWSInventory&) = default;

    CNWSInventory();
    ~CNWSInventory();
    int32_t GetArraySlotFromSlotFlag(uint32_t);
    int32_t GetItemInInventory(CNWSItem*);
    CNWSItem* GetItemInSlot(uint32_t);
    uint32_t GetSlotFromItem(CNWSItem*);
    void PutItemInSlot(uint32_t, CNWSItem*);
    int32_t RemoveItem(CNWSItem*);
};

void CNWSInventory__CNWSInventoryCtor__0(CNWSInventory* thisPtr);
void CNWSInventory__CNWSInventoryDtor__0(CNWSInventory* thisPtr);
int32_t CNWSInventory__GetArraySlotFromSlotFlag(CNWSInventory* thisPtr, uint32_t);
int32_t CNWSInventory__GetItemInInventory(CNWSInventory* thisPtr, CNWSItem*);
CNWSItem* CNWSInventory__GetItemInSlot(CNWSInventory* thisPtr, uint32_t);
uint32_t CNWSInventory__GetSlotFromItem(CNWSInventory* thisPtr, CNWSItem*);
void CNWSInventory__PutItemInSlot(CNWSInventory* thisPtr, uint32_t, CNWSItem*);
int32_t CNWSInventory__RemoveItem(CNWSInventory* thisPtr, CNWSItem*);

}

}
