#include "CNWSPlaceable.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CItemRepository.hpp"
#include "CNWSArea.hpp"
#include "CNWSItem.hpp"
#include "CNWSObjectActionNode.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSPlaceable::CNWSPlaceable(uint32_t a0)
{
    CNWSPlaceable__CNWSPlaceableCtor__0(this, a0);
}

CNWSPlaceable::~CNWSPlaceable()
{
    CNWSPlaceable__CNWSPlaceableDtor__0(this);
}

int32_t CNWSPlaceable::AcquireItem(CNWSItem** a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4)
{
    return CNWSPlaceable__AcquireItem(this, a0, a1, a2, a3, a4);
}

uint32_t CNWSPlaceable::AcquireItemsFromObject(uint32_t a0, int32_t a1)
{
    return CNWSPlaceable__AcquireItemsFromObject(this, a0, a1);
}

int32_t CNWSPlaceable::AddCastSpellActions(uint32_t a0, int32_t a1, Vector a2, uint32_t a3, int32_t a4, unsigned char a5)
{
    return CNWSPlaceable__AddCastSpellActions(this, a0, a1, a2, a3, a4, a5);
}

void CNWSPlaceable::AddToArea(CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    return CNWSPlaceable__AddToArea(this, a0, a1, a2, a3, a4);
}

uint32_t CNWSPlaceable::AIActionCastSpell(CNWSObjectActionNode* a0)
{
    return CNWSPlaceable__AIActionCastSpell(this, a0);
}

void CNWSPlaceable::AIUpdate()
{
    return CNWSPlaceable__AIUpdate(this);
}

CNWSPlaceable* CNWSPlaceable::AsNWSPlaceable()
{
    return CNWSPlaceable__AsNWSPlaceable(this);
}

void CNWSPlaceable::CalculateActionPoints()
{
    return CNWSPlaceable__CalculateActionPoints(this);
}

void CNWSPlaceable::CloseInventory(uint32_t a0, int32_t a1)
{
    return CNWSPlaceable__CloseInventory(this, a0, a1);
}

void CNWSPlaceable::ClosePlaceableForAllPlayers()
{
    return CNWSPlaceable__ClosePlaceableForAllPlayers(this);
}

void CNWSPlaceable::DoDamage(int32_t a0)
{
    return CNWSPlaceable__DoDamage(this, a0);
}

void CNWSPlaceable::DropItemsIntoArea()
{
    return CNWSPlaceable__DropItemsIntoArea(this);
}

void CNWSPlaceable::EventHandler(uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    return CNWSPlaceable__EventHandler(this, a0, a1, a2, a3, a4);
}

uint16_t CNWSPlaceable::GetBodyBagAppearance()
{
    return CNWSPlaceable__GetBodyBagAppearance(this);
}

CResRef CNWSPlaceable::GetDialogResref()
{
    return CNWSPlaceable__GetDialogResref(this);
}

uint32_t CNWSPlaceable::GetEffectSpellId()
{
    return CNWSPlaceable__GetEffectSpellId(this);
}

CExoLocString& CNWSPlaceable::GetFirstName()
{
    return CNWSPlaceable__GetFirstName(this);
}

uint32_t CNWSPlaceable::GetItemCount(int32_t a0)
{
    return CNWSPlaceable__GetItemCount(this, a0);
}

int32_t CNWSPlaceable::GetLightIsOn()
{
    return CNWSPlaceable__GetLightIsOn(this);
}

Vector CNWSPlaceable::GetNearestActionPoint(const Vector& a0)
{
    return CNWSPlaceable__GetNearestActionPoint(this, a0);
}

int32_t CNWSPlaceable::LoadBodyBag(uint16_t a0)
{
    return CNWSPlaceable__LoadBodyBag(this, a0);
}

int32_t CNWSPlaceable::LoadFromTemplate(CResRef a0, CExoString* a1)
{
    return CNWSPlaceable__LoadFromTemplate(this, a0, a1);
}

int32_t CNWSPlaceable::LoadPlaceable(CResGFF* a0, CResStruct* a1, CExoString* a2)
{
    return CNWSPlaceable__LoadPlaceable(this, a0, a1, a2);
}

void CNWSPlaceable::OpenInventory(uint32_t a0)
{
    return CNWSPlaceable__OpenInventory(this, a0);
}

void CNWSPlaceable::PostProcess()
{
    return CNWSPlaceable__PostProcess(this);
}

void CNWSPlaceable::RemoveFromArea()
{
    return CNWSPlaceable__RemoveFromArea(this);
}

int32_t CNWSPlaceable::RemoveItem(CNWSItem* a0, int32_t a1)
{
    return CNWSPlaceable__RemoveItem(this, a0, a1);
}

int32_t CNWSPlaceable::SavePlaceable(CResGFF* a0, CResStruct* a1, int32_t a2)
{
    return CNWSPlaceable__SavePlaceable(this, a0, a1, a2);
}

void CNWSPlaceable::SetEffectSpellId(uint32_t a0)
{
    return CNWSPlaceable__SetEffectSpellId(this, a0);
}

void CNWSPlaceable::SetLightIsOn(int32_t a0)
{
    return CNWSPlaceable__SetLightIsOn(this, a0);
}

void CNWSPlaceable::SetOrientation(Vector a0)
{
    return CNWSPlaceable__SetOrientation(this, a0);
}

void CNWSPlaceable__CNWSPlaceableCtor__0(CNWSPlaceable* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__CNWSPlaceableCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CNWSPlaceable__CNWSPlaceableDtor__0(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__CNWSPlaceableDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSPlaceable__AcquireItem(CNWSPlaceable* thisPtr, CNWSItem** a0, uint32_t a1, unsigned char a2, unsigned char a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, CNWSItem**, uint32_t, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AcquireItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CNWSPlaceable__AcquireItemsFromObject(CNWSPlaceable* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AcquireItemsFromObject);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSPlaceable__AddCastSpellActions(CNWSPlaceable* thisPtr, uint32_t a0, int32_t a1, Vector a2, uint32_t a3, int32_t a4, unsigned char a5)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t, int32_t, Vector, uint32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AddCastSpellActions);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNWSPlaceable__AddToArea(CNWSPlaceable* thisPtr, CNWSArea* a0, float a1, float a2, float a3, int32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, CNWSArea*, float, float, float, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AddToArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint32_t CNWSPlaceable__AIActionCastSpell(CNWSPlaceable* thisPtr, CNWSObjectActionNode* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AIActionCastSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlaceable__AIUpdate(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AIUpdate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CNWSPlaceable* CNWSPlaceable__AsNWSPlaceable(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = CNWSPlaceable*(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__AsNWSPlaceable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlaceable__CalculateActionPoints(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__CalculateActionPoints);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlaceable__CloseInventory(CNWSPlaceable* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__CloseInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSPlaceable__ClosePlaceableForAllPlayers(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__ClosePlaceableForAllPlayers);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlaceable__DoDamage(CNWSPlaceable* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__DoDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlaceable__DropItemsIntoArea(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__DropItemsIntoArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlaceable__EventHandler(CNWSPlaceable* thisPtr, uint32_t a0, uint32_t a1, void* a2, uint32_t a3, uint32_t a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t, uint32_t, void*, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__EventHandler);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

uint16_t CNWSPlaceable__GetBodyBagAppearance(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetBodyBagAppearance);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CResRef CNWSPlaceable__GetDialogResref(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetDialogResref);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSPlaceable__GetEffectSpellId(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoLocString& CNWSPlaceable__GetFirstName(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = CExoLocString&(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetFirstName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CNWSPlaceable__GetItemCount(CNWSPlaceable* thisPtr, int32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetItemCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSPlaceable__GetLightIsOn(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetLightIsOn);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

Vector CNWSPlaceable__GetNearestActionPoint(CNWSPlaceable* thisPtr, const Vector& a0)
{
    using FuncPtrType = Vector(__attribute__((cdecl)) *)(CNWSPlaceable*, const Vector&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__GetNearestActionPoint);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSPlaceable__LoadBodyBag(CNWSPlaceable* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__LoadBodyBag);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSPlaceable__LoadFromTemplate(CNWSPlaceable* thisPtr, CResRef a0, CExoString* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, CResRef, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__LoadFromTemplate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSPlaceable__LoadPlaceable(CNWSPlaceable* thisPtr, CResGFF* a0, CResStruct* a1, CExoString* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, CResGFF*, CResStruct*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__LoadPlaceable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSPlaceable__OpenInventory(CNWSPlaceable* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__OpenInventory);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlaceable__PostProcess(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__PostProcess);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlaceable__RemoveFromArea(CNWSPlaceable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__RemoveFromArea);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlaceable__RemoveItem(CNWSPlaceable* thisPtr, CNWSItem* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, CNWSItem*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__RemoveItem);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSPlaceable__SavePlaceable(CNWSPlaceable* thisPtr, CResGFF* a0, CResStruct* a1, int32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlaceable*, CResGFF*, CResStruct*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__SavePlaceable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSPlaceable__SetEffectSpellId(CNWSPlaceable* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__SetEffectSpellId);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlaceable__SetLightIsOn(CNWSPlaceable* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__SetLightIsOn);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlaceable__SetOrientation(CNWSPlaceable* thisPtr, Vector a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlaceable*, Vector);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlaceable__SetOrientation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
