#include "CNWSInventory.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSItem.hpp"

namespace NWNXLib {

namespace API {

CNWSInventory::CNWSInventory()
{
    CNWSInventory__CNWSInventoryCtor(this);
}

CNWSInventory::~CNWSInventory()
{
    CNWSInventory__CNWSInventoryDtor__0(this);
}

int32_t CNWSInventory::GetArraySlotFromSlotFlag(uint32_t a0)
{
    return CNWSInventory__GetArraySlotFromSlotFlag(this, a0);
}

int32_t CNWSInventory::GetItemInInventory(CNWSItem* a0)
{
    return CNWSInventory__GetItemInInventory(this, a0);
}

CNWSItem* CNWSInventory::GetItemInSlot(uint32_t a0)
{
    return CNWSInventory__GetItemInSlot(this, a0);
}

uint32_t CNWSInventory::GetSlotFromItem(CNWSItem* a0)
{
    return CNWSInventory__GetSlotFromItem(this, a0);
}

void CNWSInventory::PutItemInSlot(uint32_t a0, CNWSItem* a1)
{
    return CNWSInventory__PutItemInSlot(this, a0, a1);
}

int32_t CNWSInventory::RemoveItem(CNWSItem* a0)
{
    return CNWSInventory__RemoveItem(this, a0);
}

void CNWSInventory__CNWSInventoryCtor(CNWSInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__CNWSInventoryCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSInventory__CNWSInventoryDtor__0(CNWSInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSInventory*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__CNWSInventoryDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSInventory__GetArraySlotFromSlotFlag(CNWSInventory* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSInventory*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__GetArraySlotFromSlotFlag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSInventory__GetItemInInventory(CNWSInventory* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSInventory*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__GetItemInInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWSItem* CNWSInventory__GetItemInSlot(CNWSInventory* thisPtr, uint32_t a0)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CNWSInventory*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__GetItemInSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSInventory__GetSlotFromItem(CNWSInventory* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSInventory*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__GetSlotFromItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSInventory__PutItemInSlot(CNWSInventory* thisPtr, uint32_t a0, CNWSItem* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSInventory*, uint32_t, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__PutItemInSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSInventory__RemoveItem(CNWSInventory* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSInventory*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSInventory__RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
