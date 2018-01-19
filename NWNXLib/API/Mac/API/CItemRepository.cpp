#include "CItemRepository.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListNode.hpp"
#include "CExoString.hpp"
#include "CNWSItem.hpp"

namespace NWNXLib {

namespace API {

CItemRepository::CItemRepository(uint32_t a0, unsigned char a1, unsigned char a2, uint32_t a3, int32_t a4)
{
    CItemRepository__CItemRepositoryCtor__0(this, a0, a1, a2, a3, a4);
}

CItemRepository::~CItemRepository()
{
    CItemRepository__CItemRepositoryDtor__0(this);
}

int32_t CItemRepository::AddItem(CNWSItem** a0, unsigned char a1, unsigned char a2, int32_t a3, int32_t a4)
{
    return CItemRepository__AddItem(this, a0, a1, a2, a3, a4);
}

int32_t CItemRepository::AddPanel()
{
    return CItemRepository__AddPanel(this);
}

int32_t CItemRepository::CalculateContentsWeight()
{
    return CItemRepository__CalculateContentsWeight(this);
}

unsigned char CItemRepository::CalculatePage(unsigned char a0, unsigned char a1)
{
    return CItemRepository__CalculatePage(this, a0, a1);
}

int32_t CItemRepository::CheckFit(CNWSItem* a0, unsigned char a1, unsigned char a2)
{
    return CItemRepository__CheckFit(this, a0, a1, a2);
}

int32_t CItemRepository::CheckItemOverlaps(CNWSItem* a0, CNWSItem* a1, unsigned char a2, unsigned char a3)
{
    return CItemRepository__CheckItemOverlaps(this, a0, a1, a2, a3);
}

uint32_t CItemRepository::FindItemWithBaseItemId(uint32_t a0, int32_t a1)
{
    return CItemRepository__FindItemWithBaseItemId(this, a0, a1);
}

uint32_t CItemRepository::FindItemWithTag(CExoString* a0)
{
    return CItemRepository__FindItemWithTag(this, a0);
}

int32_t CItemRepository::FindPosition(CNWSItem* a0, unsigned char& a1, unsigned char& a2, int32_t a3)
{
    return CItemRepository__FindPosition(this, a0, a1, a2, a3);
}

int32_t CItemRepository::GetItemInRepository(CNWSItem* a0, int32_t a1)
{
    return CItemRepository__GetItemInRepository__0(this, a0, a1);
}

uint32_t CItemRepository::GetItemInRepository(unsigned char a0, unsigned char a1)
{
    return CItemRepository__GetItemInRepository__1(this, a0, a1);
}

CNWSItem* CItemRepository::ItemListGetItem(CExoLinkedListNode* a0)
{
    return CItemRepository__ItemListGetItem(this, a0);
}

uint32_t CItemRepository::ItemListGetItemObjectID(CExoLinkedListNode* a0)
{
    return CItemRepository__ItemListGetItemObjectID(this, a0);
}

int32_t CItemRepository::MoveItem(CNWSItem* a0, unsigned char a1, unsigned char a2)
{
    return CItemRepository__MoveItem(this, a0, a1, a2);
}

int32_t CItemRepository::RemoveItem(CNWSItem* a0)
{
    return CItemRepository__RemoveItem(this, a0);
}

void CItemRepository__CItemRepositoryCtor__0(CItemRepository* thisPtr, uint32_t a0, unsigned char a1, unsigned char a2, uint32_t a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CItemRepository*, uint32_t, unsigned char, unsigned char, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__CItemRepositoryCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2, a3, a4);
}

void CItemRepository__CItemRepositoryDtor__0(CItemRepository* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CItemRepository*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__CItemRepositoryDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CItemRepository__AddItem(CItemRepository* thisPtr, CNWSItem** a0, unsigned char a1, unsigned char a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem**, unsigned char, unsigned char, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__AddItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CItemRepository__AddPanel(CItemRepository* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__AddPanel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CItemRepository__CalculateContentsWeight(CItemRepository* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__CalculateContentsWeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CItemRepository__CalculatePage(CItemRepository* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CItemRepository*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__CalculatePage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CItemRepository__CheckFit(CItemRepository* thisPtr, CNWSItem* a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__CheckFit);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CItemRepository__CheckItemOverlaps(CItemRepository* thisPtr, CNWSItem* a0, CNWSItem* a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem*, CNWSItem*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__CheckItemOverlaps);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint32_t CItemRepository__FindItemWithBaseItemId(CItemRepository* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CItemRepository*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__FindItemWithBaseItemId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CItemRepository__FindItemWithTag(CItemRepository* thisPtr, CExoString* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CItemRepository*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__FindItemWithTag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CItemRepository__FindPosition(CItemRepository* thisPtr, CNWSItem* a0, unsigned char& a1, unsigned char& a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem*, unsigned char&, unsigned char&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__FindPosition);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CItemRepository__GetItemInRepository__0(CItemRepository* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__GetItemInRepository__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CItemRepository__GetItemInRepository__1(CItemRepository* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CItemRepository*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__GetItemInRepository__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSItem* CItemRepository__ItemListGetItem(CItemRepository* thisPtr, CExoLinkedListNode* a0)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CItemRepository*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__ItemListGetItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CItemRepository__ItemListGetItemObjectID(CItemRepository* thisPtr, CExoLinkedListNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CItemRepository*, CExoLinkedListNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__ItemListGetItemObjectID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CItemRepository__MoveItem(CItemRepository* thisPtr, CNWSItem* a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__MoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CItemRepository__RemoveItem(CItemRepository* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CItemRepository*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CItemRepository__RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
