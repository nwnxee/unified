#include "CNWSPlayerLUOInventory.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListNode.hpp"
#include "CNWSItem.hpp"
#include "CNWSPlayerLUOInventoryItem.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayerLUOInventory::CNWSPlayerLUOInventory()
{
    CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryCtor__0(this);
}

CNWSPlayerLUOInventory::~CNWSPlayerLUOInventory()
{
    CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryDtor__0(this);
}

void CNWSPlayerLUOInventory::ClearBarter()
{
    return CNWSPlayerLUOInventory__ClearBarter(this);
}

void CNWSPlayerLUOInventory::ClearContainer()
{
    return CNWSPlayerLUOInventory__ClearContainer(this);
}

void CNWSPlayerLUOInventory::ClearRepository()
{
    return CNWSPlayerLUOInventory__ClearRepository(this);
}

void CNWSPlayerLUOInventory::ClearSlots()
{
    return CNWSPlayerLUOInventory__ClearSlots(this);
}

void CNWSPlayerLUOInventory::ClearStore()
{
    return CNWSPlayerLUOInventory__ClearStore(this);
}

void CNWSPlayerLUOInventory::ItemListAddHead(uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3, uint32_t a4, uint32_t a5)
{
    return CNWSPlayerLUOInventory__ItemListAddHead(this, a0, a1, a2, a3, a4, a5);
}

CNWSItem* CNWSPlayerLUOInventory::ItemListGetItem(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListGetItem(this, a0, a1);
}

uint32_t CNWSPlayerLUOInventory::ItemListGetItemObjectID(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListGetItemObjectID(this, a0, a1);
}

void CNWSPlayerLUOInventory::ItemListGetNext(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListGetNext(this, a0, a1);
}

uint32_t CNWSPlayerLUOInventory::ItemListGetNumber(unsigned char a0)
{
    return CNWSPlayerLUOInventory__ItemListGetNumber(this, a0);
}

void CNWSPlayerLUOInventory::ItemListGetPrev(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListGetPrev(this, a0, a1);
}

CNWSPlayerLUOInventoryItem* CNWSPlayerLUOInventory::ItemListGetUpdateItem(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListGetUpdateItem(this, a0, a1);
}

void CNWSPlayerLUOInventory::ItemListRemove(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListRemove(this, a0, a1);
}

void CNWSPlayerLUOInventory::ItemListSetEnd(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListSetEnd(this, a0, a1);
}

void CNWSPlayerLUOInventory::ItemListSetStart(CExoLinkedListNode* a0, unsigned char a1)
{
    return CNWSPlayerLUOInventory__ItemListSetStart(this, a0, a1);
}

void CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryCtor__0(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryDtor__0(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__CNWSPlayerLUOInventoryDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSPlayerLUOInventory__ClearBarter(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ClearBarter);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLUOInventory__ClearContainer(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ClearContainer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLUOInventory__ClearRepository(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ClearRepository);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLUOInventory__ClearSlots(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ClearSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLUOInventory__ClearStore(CNWSPlayerLUOInventory* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ClearStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLUOInventory__ItemListAddHead(CNWSPlayerLUOInventory* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, unsigned char a3, uint32_t a4, uint32_t a5)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, uint32_t, unsigned char, unsigned char, unsigned char, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListAddHead);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

CNWSItem* CNWSPlayerLUOInventory__ItemListGetItem(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListGetItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSPlayerLUOInventory__ItemListGetItemObjectID(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListGetItemObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerLUOInventory__ItemListGetNext(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListGetNext);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSPlayerLUOInventory__ItemListGetNumber(CNWSPlayerLUOInventory* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListGetNumber);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerLUOInventory__ItemListGetPrev(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListGetPrev);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSPlayerLUOInventoryItem* CNWSPlayerLUOInventory__ItemListGetUpdateItem(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = CNWSPlayerLUOInventoryItem*(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListGetUpdateItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerLUOInventory__ItemListRemove(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListRemove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerLUOInventory__ItemListSetEnd(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListSetEnd);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlayerLUOInventory__ItemListSetStart(CNWSPlayerLUOInventory* thisPtr, CExoLinkedListNode* a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLUOInventory*, CExoLinkedListNode*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLUOInventory__ItemListSetStart);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
