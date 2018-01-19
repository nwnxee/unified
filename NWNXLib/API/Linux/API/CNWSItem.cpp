#include "CNWSItem.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CItemRepository.hpp"
#include "CNWSArea.hpp"
#include "CNWSCreature.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSItem::CNWSItem(uint32_t a0)
{
    CNWSItem__CNWSItemCtor(this, a0);
}

CNWSItem::~CNWSItem()
{
    CNWSItem__CNWSItemDtor__0(this);
}

int32_t CNWSItem::AcquireItem(CNWSItem** a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4)
{
    return CNWSItem__AcquireItem(this, a0, a1, a2, a3, a4);
}

int32_t CNWSItem::ActiveProperty(uint16_t a0)
{
    return CNWSItem__ActiveProperty(this, a0);
}

void CNWSItem::AddActiveProperty(CNWItemProperty a0)
{
    return CNWSItem__AddActiveProperty(this, a0);
}

void CNWSItem::AddPassiveProperty(CNWItemProperty a0)
{
    return CNWSItem__AddPassiveProperty(this, a0);
}

void CNWSItem::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSItem__AddToArea(this, a0, a1, a2, a3, a4);
}

void CNWSItem::AIUpdate()
{
    return CNWSItem__AIUpdate(this);
}

void CNWSItem::ApplyItemProperties(CNWSCreature* a0, uint32_t a1, int32_t a2)
{
    return CNWSItem__ApplyItemProperties(this, a0, a1, a2);
}

CNWSItem* CNWSItem::AsNWSItem()
{
    return CNWSItem__AsNWSItem(this);
}

void CNWSItem::CalculateBaseCosts()
{
    return CNWSItem__CalculateBaseCosts(this);
}

float CNWSItem::CalculatePassiveCost(CNWItemProperty* a0)
{
    return CNWSItem__CalculatePassiveCost(this, a0);
}

void CNWSItem::CloseInventory(uint32_t a0, int32_t a1)
{
    return CNWSItem__CloseInventory(this, a0, a1);
}

void CNWSItem::CloseItemForAllPlayers()
{
    return CNWSItem__CloseItemForAllPlayers(this);
}

int32_t CNWSItem::CompareItem(CNWSItem* a0)
{
    return CNWSItem__CompareItem(this, a0);
}

int32_t CNWSItem::ComputeArmorClass()
{
    return CNWSItem__ComputeArmorClass(this);
}

void CNWSItem::ComputeWeight()
{
    return CNWSItem__ComputeWeight(this);
}

int32_t CNWSItem::CopyItem(CNWSItem* a0, int32_t a1)
{
    return CNWSItem__CopyItem(this, a0, a1);
}

void CNWSItem::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSItem__EventHandler(this, a0, a1, a2, a3, a4);
}

CNWItemProperty* CNWSItem::GetActiveProperty(int32_t a0)
{
    return CNWSItem__GetActiveProperty(this, a0);
}

uint32_t CNWSItem::GetCost(int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSItem__GetCost(this, a0, a1, a2, a3);
}

uint16_t CNWSItem::GetDamageFlags()
{
    return CNWSItem__GetDamageFlags(this);
}

CExoLocString& CNWSItem::GetFirstName()
{
    return CNWSItem__GetFirstName(this);
}

unsigned char CNWSItem::GetMinEquipLevel()
{
    return CNWSItem__GetMinEquipLevel(this);
}

CNWItemProperty* CNWSItem::GetPassiveProperty(int32_t a0)
{
    return CNWSItem__GetPassiveProperty(this, a0);
}

int32_t CNWSItem::GetPropertyByType(CNWItemProperty** a0, uint16_t a1, uint16_t a2)
{
    return CNWSItem__GetPropertyByType(this, a0, a1, a2);
}

int32_t CNWSItem::GetPropertyByTypeExists(uint16_t a0, uint16_t a1)
{
    return CNWSItem__GetPropertyByTypeExists(this, a0, a1);
}

uint16_t CNWSItem::GetUsedActivePropertyUsesLeft(unsigned char a0)
{
    return CNWSItem__GetUsedActivePropertyUsesLeft(this, a0);
}

int32_t CNWSItem::GetWeight()
{
    return CNWSItem__GetWeight(this);
}

void CNWSItem::InitRepository(uint32_t a0)
{
    return CNWSItem__InitRepository(this, a0);
}

int32_t CNWSItem::LoadDataFromGff(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSItem__LoadDataFromGff(this, a0, a1, a2);
}

int32_t CNWSItem::LoadFromTemplate(CResRef a0, CExoString* a1)
{
    return CNWSItem__LoadFromTemplate(this, a0, a1);
}

int32_t CNWSItem::LoadItem(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSItem__LoadItem(this, a0, a1, a2);
}

int32_t CNWSItem::MergeItem(CNWSItem* a0)
{
    return CNWSItem__MergeItem(this, a0);
}

void CNWSItem::OpenInventory(uint32_t a0)
{
    return CNWSItem__OpenInventory(this, a0);
}

void CNWSItem::ReadContainerItemsFromGff(CResGFF* a0, CResStruct* a1)
{
    return CNWSItem__ReadContainerItemsFromGff(this, a0, a1);
}

int32_t CNWSItem::RemoveActiveProperty(int32_t a0)
{
    return CNWSItem__RemoveActiveProperty(this, a0);
}

void CNWSItem::RemoveFromArea()
{
    return CNWSItem__RemoveFromArea(this);
}

void CNWSItem::RemoveItemProperties(CNWSCreature* a0, uint32_t a1)
{
    return CNWSItem__RemoveItemProperties(this, a0, a1);
}

int32_t CNWSItem::RemovePassiveProperty(int32_t a0)
{
    return CNWSItem__RemovePassiveProperty(this, a0);
}

void CNWSItem::RestoreUsedActiveProperties(int32_t a0)
{
    return CNWSItem__RestoreUsedActiveProperties(this, a0);
}

void CNWSItem::RestoreUsedActiveProperty(CNWItemProperty* a0, int32_t a1)
{
    return CNWSItem__RestoreUsedActiveProperty(this, a0, a1);
}

int32_t CNWSItem::SaveContainerItems(CResGFF* a0, CResStruct* a1)
{
    return CNWSItem__SaveContainerItems(this, a0, a1);
}

int32_t CNWSItem::SaveItem(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSItem__SaveItem(this, a0, a1, a2);
}

int32_t CNWSItem::SaveItemProperties(CResGFF* a0, CResStruct* a1)
{
    return CNWSItem__SaveItemProperties(this, a0, a1);
}

void CNWSItem::SetIdentified(int32_t a0)
{
    return CNWSItem__SetIdentified(this, a0);
}

void CNWSItem::SetNumCharges(int32_t a0, int32_t a1)
{
    return CNWSItem__SetNumCharges(this, a0, a1);
}

void CNWSItem::SetPossessor(uint32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    return CNWSItem__SetPossessor(this, a0, a1, a2, a3);
}

CNWSItem* CNWSItem::SplitItem(int32_t a0)
{
    return CNWSItem__SplitItem(this, a0);
}

void CNWSItem::UpdateUsedActiveProperties(int32_t a0)
{
    return CNWSItem__UpdateUsedActiveProperties(this, a0);
}

void CNWSItem::UpdateVisualEffect()
{
    return CNWSItem__UpdateVisualEffect(this);
}

void CNWSItem__CNWSItemCtor(CNWSItem* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CNWSItemCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSItem__CNWSItemDtor__0(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CNWSItemDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSItem__AcquireItem(CNWSItem* thisPtr, CNWSItem** a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CNWSItem**, uint32_t, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__AcquireItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWSItem__ActiveProperty(CNWSItem* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__ActiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__AddActiveProperty(CNWSItem* thisPtr, CNWItemProperty a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CNWItemProperty);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__AddActiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__AddPassiveProperty(CNWSItem* thisPtr, CNWItemProperty a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CNWItemProperty);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__AddPassiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__AddToArea(CNWSItem* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSItem__AIUpdate(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSItem__ApplyItemProperties(CNWSItem* thisPtr, CNWSCreature* a0, uint32_t a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CNWSCreature*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__ApplyItemProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CNWSItem* CNWSItem__AsNWSItem(CNWSItem* thisPtr)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__AsNWSItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSItem__CalculateBaseCosts(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CalculateBaseCosts);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

float CNWSItem__CalculatePassiveCost(CNWSItem* thisPtr, CNWItemProperty* a0)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CNWSItem*, CNWItemProperty*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CalculatePassiveCost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__CloseInventory(CNWSItem* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CloseInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSItem__CloseItemForAllPlayers(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CloseItemForAllPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSItem__CompareItem(CNWSItem* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CompareItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSItem__ComputeArmorClass(CNWSItem* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__ComputeArmorClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSItem__ComputeWeight(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__ComputeWeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSItem__CopyItem(CNWSItem* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__CopyItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSItem__EventHandler(CNWSItem* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

CNWItemProperty* CNWSItem__GetActiveProperty(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWItemProperty*(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetActiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSItem__GetCost(CNWSItem* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSItem*, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetCost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint16_t CNWSItem__GetDamageFlags(CNWSItem* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetDamageFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSItem__GetFirstName(CNWSItem* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWSItem__GetMinEquipLevel(CNWSItem* thisPtr)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetMinEquipLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWItemProperty* CNWSItem__GetPassiveProperty(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWItemProperty*(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetPassiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSItem__GetPropertyByType(CNWSItem* thisPtr, CNWItemProperty** a0, uint16_t a1, uint16_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CNWItemProperty**, uint16_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetPropertyByType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSItem__GetPropertyByTypeExists(CNWSItem* thisPtr, uint16_t a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, uint16_t, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetPropertyByTypeExists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint16_t CNWSItem__GetUsedActivePropertyUsesLeft(CNWSItem* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSItem*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetUsedActivePropertyUsesLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSItem__GetWeight(CNWSItem* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__GetWeight);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSItem__InitRepository(CNWSItem* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__InitRepository);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSItem__LoadDataFromGff(CNWSItem* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__LoadDataFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSItem__LoadFromTemplate(CNWSItem* thisPtr, CResRef a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CResRef, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSItem__LoadItem(CNWSItem* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__LoadItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSItem__MergeItem(CNWSItem* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__MergeItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__OpenInventory(CNWSItem* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__OpenInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__ReadContainerItemsFromGff(CNWSItem* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__ReadContainerItemsFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSItem__RemoveActiveProperty(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__RemoveActiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__RemoveFromArea(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSItem__RemoveItemProperties(CNWSItem* thisPtr, CNWSCreature* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CNWSCreature*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__RemoveItemProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSItem__RemovePassiveProperty(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__RemovePassiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__RestoreUsedActiveProperties(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__RestoreUsedActiveProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__RestoreUsedActiveProperty(CNWSItem* thisPtr, CNWItemProperty* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, CNWItemProperty*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__RestoreUsedActiveProperty);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSItem__SaveContainerItems(CNWSItem* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SaveContainerItems);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSItem__SaveItem(CNWSItem* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SaveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSItem__SaveItemProperties(CNWSItem* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSItem*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SaveItemProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSItem__SetIdentified(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SetIdentified);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__SetNumCharges(CNWSItem* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SetNumCharges);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSItem__SetPossessor(CNWSItem* thisPtr, uint32_t a0, int32_t a1, int32_t a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, uint32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SetPossessor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

CNWSItem* CNWSItem__SplitItem(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = CNWSItem*(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__SplitItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__UpdateUsedActiveProperties(CNWSItem* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__UpdateUsedActiveProperties);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSItem__UpdateVisualEffect(CNWSItem* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSItem__UpdateVisualEffect);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
