#include "CNWSStore.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CItemRepository.hpp"
#include "CNWSArea.hpp"
#include "CNWSCreature.hpp"
#include "CNWSItem.hpp"
#include "CNWSPlayer.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"
#include "CStoreCustomer.hpp"

namespace NWNXLib {

namespace API {

CNWSStore::CNWSStore(uint32_t a0)
{
    CNWSStore__CNWSStoreCtor__0(this, a0);
}

CNWSStore::~CNWSStore()
{
    CNWSStore__CNWSStoreDtor__0(this);
}

int32_t CNWSStore::AcquireItem(CNWSItem* a0, int32_t a1, unsigned char a2, unsigned char a3)
{
    return CNWSStore__AcquireItem(this, a0, a1, a2, a3);
}

void CNWSStore::AddCustomer(CNWSPlayer* a0, char a1, char a2)
{
    return CNWSStore__AddCustomer(this, a0, a1, a2);
}

int32_t CNWSStore::AddItemToInventory(CNWSItem** a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    return CNWSStore__AddItemToInventory(this, a0, a1, a2, a3);
}

void CNWSStore::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSStore__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSStore::AIUpdate()
{
    return CNWSStore__AIUpdate(this);
}

CNWSStore* CNWSStore::AsNWSStore()
{
    return CNWSStore__AsNWSStore(this);
}

int32_t CNWSStore::CalculateItemBuyPrice(CNWSItem* a0, uint32_t a1)
{
    return CNWSStore__CalculateItemBuyPrice(this, a0, a1);
}

int32_t CNWSStore::CalculateItemSellPrice(CNWSItem* a0, uint32_t a1)
{
    return CNWSStore__CalculateItemSellPrice(this, a0, a1);
}

void CNWSStore::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSStore__EventHandler(this, a0, a1, a2, a3, a4);
}

unsigned char CNWSStore::GetAppropriateListId(uint32_t a0)
{
    return CNWSStore__GetAppropriateListId(this, a0);
}

CStoreCustomer* CNWSStore::GetCustomer(uint32_t a0)
{
    return CNWSStore__GetCustomer(this, a0);
}

unsigned char CNWSStore::GetCustomerBuyRate(uint32_t a0, int32_t a1)
{
    return CNWSStore__GetCustomerBuyRate(this, a0, a1);
}

int16_t CNWSStore::GetCustomerSellRate(uint32_t a0)
{
    return CNWSStore__GetCustomerSellRate(this, a0);
}

int32_t CNWSStore::GetIsRestrictedBuyItem(int32_t a0)
{
    return CNWSStore__GetIsRestrictedBuyItem(this, a0);
}

int32_t CNWSStore::GetItemInInventory(CExoString* a0)
{
    return CNWSStore__GetItemInInventory__0(this, a0);
}

int32_t CNWSStore::GetItemInInventory(uint32_t a0)
{
    return CNWSStore__GetItemInInventory__1(this, a0);
}

int32_t CNWSStore::LoadFromTemplate(CResRef a0, CExoString* a1)
{
    return CNWSStore__LoadFromTemplate(this, a0, a1);
}

int32_t CNWSStore::LoadStore(CResGFF* a0, CResStruct* a1, CExoString* a2)
{
    return CNWSStore__LoadStore(this, a0, a1, a2);
}

void CNWSStore::RemoveCustomer(CNWSPlayer* a0)
{
    return CNWSStore__RemoveCustomer(this, a0);
}

void CNWSStore::RemoveFromArea()
{
    return CNWSStore__RemoveFromArea(this);
}

void CNWSStore::RemoveItem(CNWSItem* a0)
{
    return CNWSStore__RemoveItem(this, a0);
}

int32_t CNWSStore::RemoveItemFromInventory(CNWSItem* a0, unsigned char a1)
{
    return CNWSStore__RemoveItemFromInventory(this, a0, a1);
}

int32_t CNWSStore::SaveStore(CResGFF* a0, CResStruct* a1)
{
    return CNWSStore__SaveStore(this, a0, a1);
}

int32_t CNWSStore::SellItem(CNWSItem* a0, CNWSCreature* a1, unsigned char a2, unsigned char a3)
{
    return CNWSStore__SellItem(this, a0, a1, a2, a3);
}

void CNWSStore__CNWSStoreCtor__0(CNWSStore* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__CNWSStoreCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSStore__CNWSStoreDtor__0(CNWSStore* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__CNWSStoreDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSStore__AcquireItem(CNWSStore* thisPtr, CNWSItem* a0, int32_t a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem*, int32_t, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__AcquireItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSStore__AddCustomer(CNWSStore* thisPtr, CNWSPlayer* a0, char a1, char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, CNWSPlayer*, char, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__AddCustomer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSStore__AddItemToInventory(CNWSStore* thisPtr, CNWSItem** a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem**, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__AddItemToInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSStore__AddToArea(CNWSStore* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSStore__AIUpdate(CNWSStore* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSStore* CNWSStore__AsNWSStore(CNWSStore* thisPtr)
{
    using FuncPtrType = CNWSStore*(__attribute__((cdecl)) *)(CNWSStore*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__AsNWSStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSStore__CalculateItemBuyPrice(CNWSStore* thisPtr, CNWSItem* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__CalculateItemBuyPrice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSStore__CalculateItemSellPrice(CNWSStore* thisPtr, CNWSItem* a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__CalculateItemSellPrice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSStore__EventHandler(CNWSStore* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

unsigned char CNWSStore__GetAppropriateListId(CNWSStore* thisPtr, uint32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSStore*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetAppropriateListId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CStoreCustomer* CNWSStore__GetCustomer(CNWSStore* thisPtr, uint32_t a0)
{
    using FuncPtrType = CStoreCustomer*(__attribute__((cdecl)) *)(CNWSStore*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetCustomer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSStore__GetCustomerBuyRate(CNWSStore* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSStore*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetCustomerBuyRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int16_t CNWSStore__GetCustomerSellRate(CNWSStore* thisPtr, uint32_t a0)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CNWSStore*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetCustomerSellRate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSStore__GetIsRestrictedBuyItem(CNWSStore* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetIsRestrictedBuyItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSStore__GetItemInInventory__0(CNWSStore* thisPtr, CExoString* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetItemInInventory__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSStore__GetItemInInventory__1(CNWSStore* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__GetItemInInventory__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSStore__LoadFromTemplate(CNWSStore* thisPtr, CResRef a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CResRef, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSStore__LoadStore(CNWSStore* thisPtr, CResGFF* a0, CResStruct* a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CResGFF*, CResStruct*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__LoadStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSStore__RemoveCustomer(CNWSStore* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__RemoveCustomer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSStore__RemoveFromArea(CNWSStore* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSStore__RemoveItem(CNWSStore* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSStore__RemoveItemFromInventory(CNWSStore* thisPtr, CNWSItem* a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__RemoveItemFromInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSStore__SaveStore(CNWSStore* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__SaveStore);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSStore__SellItem(CNWSStore* thisPtr, CNWSItem* a0, CNWSCreature* a1, unsigned char a2, unsigned char a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSStore*, CNWSItem*, CNWSCreature*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStore__SellItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

}

}
