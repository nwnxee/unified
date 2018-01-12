#include "CNWSPlayerLastUpdateObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoArrayListTemplatedCNWSStats_SpellLikeAbility.hpp"

namespace NWNXLib {

namespace API {

CNWSPlayerLastUpdateObject::CNWSPlayerLastUpdateObject()
{
    CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectCtor__0(this);
}

CNWSPlayerLastUpdateObject::~CNWSPlayerLastUpdateObject()
{
    CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectDtor__0(this);
}

void CNWSPlayerLastUpdateObject::AddKnownSpell(unsigned char a0, unsigned char a1, uint32_t a2)
{
    return CNWSPlayerLastUpdateObject__AddKnownSpell(this, a0, a1, a2);
}

void CNWSPlayerLastUpdateObject::ClearActionQueue()
{
    return CNWSPlayerLastUpdateObject__ClearActionQueue(this);
}

void CNWSPlayerLastUpdateObject::ClearAutoMapData()
{
    return CNWSPlayerLastUpdateObject__ClearAutoMapData(this);
}

void CNWSPlayerLastUpdateObject::ClearEffectIcons()
{
    return CNWSPlayerLastUpdateObject__ClearEffectIcons(this);
}

void CNWSPlayerLastUpdateObject::ClearKnownSpells()
{
    return CNWSPlayerLastUpdateObject__ClearKnownSpells(this);
}

void CNWSPlayerLastUpdateObject::ClearKnownSpellUsesLeft()
{
    return CNWSPlayerLastUpdateObject__ClearKnownSpellUsesLeft(this);
}

void CNWSPlayerLastUpdateObject::ClearMemorizedSpells()
{
    return CNWSPlayerLastUpdateObject__ClearMemorizedSpells(this);
}

void CNWSPlayerLastUpdateObject::ClearSpellAddDeleteLists()
{
    return CNWSPlayerLastUpdateObject__ClearSpellAddDeleteLists(this);
}

void CNWSPlayerLastUpdateObject::ClearVisibilityList()
{
    return CNWSPlayerLastUpdateObject__ClearVisibilityList(this);
}

int32_t CNWSPlayerLastUpdateObject::GetIsDomainSpell(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__GetIsDomainSpell(this, a0, a1, a2);
}

uint32_t CNWSPlayerLastUpdateObject::GetKnownSpell(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__GetKnownSpell(this, a0, a1, a2);
}

unsigned char CNWSPlayerLastUpdateObject::GetKnownSpellUsesLeft(unsigned char a0, unsigned char a1)
{
    return CNWSPlayerLastUpdateObject__GetKnownSpellUsesLeft(this, a0, a1);
}

uint32_t CNWSPlayerLastUpdateObject::GetMemorizedSpell(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__GetMemorizedSpell(this, a0, a1, a2);
}

unsigned char CNWSPlayerLastUpdateObject::GetMemorizedSpellMetaType(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__GetMemorizedSpellMetaType(this, a0, a1, a2);
}

int32_t CNWSPlayerLastUpdateObject::GetMemorizedSpellReadied(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__GetMemorizedSpellReadied(this, a0, a1, a2);
}

int32_t CNWSPlayerLastUpdateObject::InitializeAutoMapData()
{
    return CNWSPlayerLastUpdateObject__InitializeAutoMapData(this);
}

void CNWSPlayerLastUpdateObject::ResetAutoMapData(uint32_t a0)
{
    return CNWSPlayerLastUpdateObject__ResetAutoMapData(this, a0);
}

void CNWSPlayerLastUpdateObject::SetKnownSpellUsesLeft(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__SetKnownSpellUsesLeft(this, a0, a1, a2);
}

void CNWSPlayerLastUpdateObject::SetMemorizedSpellReadied(unsigned char a0, unsigned char a1, unsigned char a2, int32_t a3)
{
    return CNWSPlayerLastUpdateObject__SetMemorizedSpellReadied(this, a0, a1, a2, a3);
}

void CNWSPlayerLastUpdateObject::SetMemorizedSpellSlot(unsigned char a0, unsigned char a1, unsigned char a2, uint32_t a3, int32_t a4, unsigned char a5)
{
    return CNWSPlayerLastUpdateObject__SetMemorizedSpellSlot(this, a0, a1, a2, a3, a4, a5);
}

void CNWSPlayerLastUpdateObject::SetNumberMemorizedSpellSlots(unsigned char a0, unsigned char a1, unsigned char a2)
{
    return CNWSPlayerLastUpdateObject__SetNumberMemorizedSpellSlots(this, a0, a1, a2);
}

void CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectCtor__0(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectDtor__0(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__CNWSPlayerLastUpdateObjectDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSPlayerLastUpdateObject__AddKnownSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__AddKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSPlayerLastUpdateObject__ClearActionQueue(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearActionQueue);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearAutoMapData(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearEffectIcons(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearEffectIcons);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearKnownSpells(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearKnownSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearKnownSpellUsesLeft(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearKnownSpellUsesLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearMemorizedSpells(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearMemorizedSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearSpellAddDeleteLists(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearSpellAddDeleteLists);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ClearVisibilityList(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ClearVisibilityList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CNWSPlayerLastUpdateObject__GetIsDomainSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__GetIsDomainSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CNWSPlayerLastUpdateObject__GetKnownSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__GetKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSPlayerLastUpdateObject__GetKnownSpellUsesLeft(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__GetKnownSpellUsesLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSPlayerLastUpdateObject__GetMemorizedSpell(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__GetMemorizedSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char CNWSPlayerLastUpdateObject__GetMemorizedSpellMetaType(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__GetMemorizedSpellMetaType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSPlayerLastUpdateObject__GetMemorizedSpellReadied(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__GetMemorizedSpellReadied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CNWSPlayerLastUpdateObject__InitializeAutoMapData(CNWSPlayerLastUpdateObject* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__InitializeAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSPlayerLastUpdateObject__ResetAutoMapData(CNWSPlayerLastUpdateObject* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__ResetAutoMapData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerLastUpdateObject__SetKnownSpellUsesLeft(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__SetKnownSpellUsesLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSPlayerLastUpdateObject__SetMemorizedSpellReadied(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2, int32_t a3)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__SetMemorizedSpellReadied);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CNWSPlayerLastUpdateObject__SetMemorizedSpellSlot(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2, uint32_t a3, int32_t a4, unsigned char a5)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char, uint32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__SetMemorizedSpellSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

void CNWSPlayerLastUpdateObject__SetNumberMemorizedSpellSlots(CNWSPlayerLastUpdateObject* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerLastUpdateObject*, unsigned char, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerLastUpdateObject__SetNumberMemorizedSpellSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
