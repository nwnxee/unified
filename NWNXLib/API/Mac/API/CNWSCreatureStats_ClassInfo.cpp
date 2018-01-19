#include "CNWSCreatureStats_ClassInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSStats_Spell.hpp"

namespace NWNXLib {

namespace API {

CNWSCreatureStats_ClassInfo::CNWSCreatureStats_ClassInfo()
{
    CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoCtor__0(this);
}

CNWSCreatureStats_ClassInfo::~CNWSCreatureStats_ClassInfo()
{
    CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoDtor__0(this);
}

void CNWSCreatureStats_ClassInfo::AddKnownSpell(unsigned char a0, uint32_t a1)
{
    return CNWSCreatureStats_ClassInfo__AddKnownSpell(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo::ClearMemorizedKnownSpells(uint32_t a0)
{
    return CNWSCreatureStats_ClassInfo__ClearMemorizedKnownSpells(this, a0);
}

void CNWSCreatureStats_ClassInfo::ClearMemorizedSpellSlot(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__ClearMemorizedSpellSlot(this, a0, a1);
}

int32_t CNWSCreatureStats_ClassInfo::ConfirmDomainSpell(unsigned char a0, uint32_t a1)
{
    return CNWSCreatureStats_ClassInfo__ConfirmDomainSpell(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo::DecrementSpellsPerDayLeft(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__DecrementSpellsPerDayLeft(this, a0);
}

int32_t CNWSCreatureStats_ClassInfo::GetIsDomainSpell(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetIsDomainSpell(this, a0, a1);
}

uint32_t CNWSCreatureStats_ClassInfo::GetKnownSpell(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetKnownSpell(this, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo::GetMaxSpellsPerDayLeft(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__GetMaxSpellsPerDayLeft(this, a0);
}

uint32_t CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlot(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlot(this, a0, a1);
}

CNWSStats_Spell* CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotDetails(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotDetails(this, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotMetaType(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotMetaType(this, a0, a1);
}

int32_t CNWSCreatureStats_ClassInfo::GetMemorizedSpellInSlotReady(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotReady(this, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellReadyCount(uint32_t a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__0(this, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo::GetMemorizedSpellReadyCount(uint32_t a0, unsigned char* a1, unsigned char* a2, unsigned char a3)
{
    return CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__1(this, a0, a1, a2, a3);
}

unsigned char CNWSCreatureStats_ClassInfo::GetNumberBonusSpells(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__GetNumberBonusSpells(this, a0);
}

uint16_t CNWSCreatureStats_ClassInfo::GetNumberKnownSpells(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__GetNumberKnownSpells(this, a0);
}

unsigned char CNWSCreatureStats_ClassInfo::GetNumberMemorizedSpellSlots(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__GetNumberMemorizedSpellSlots(this, a0);
}

unsigned char CNWSCreatureStats_ClassInfo::GetSpellsPerDayLeft(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__GetSpellsPerDayLeft(this, a0);
}

void CNWSCreatureStats_ClassInfo::IncrementSpellsPerDayLeft(unsigned char a0)
{
    return CNWSCreatureStats_ClassInfo__IncrementSpellsPerDayLeft(this, a0);
}

void CNWSCreatureStats_ClassInfo::ModifyNumberBonusSpells(unsigned char a0, int32_t a1)
{
    return CNWSCreatureStats_ClassInfo__ModifyNumberBonusSpells(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo::RemoveKnownSpell(unsigned char a0, uint32_t a1)
{
    return CNWSCreatureStats_ClassInfo__RemoveKnownSpell(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo::ResetSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__ResetSpellsPerDayLeft(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo::SetMaxSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__SetMaxSpellsPerDayLeft(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo::SetMemorizedSpellInSlotReady(unsigned char a0, unsigned char a1, int32_t a2)
{
    return CNWSCreatureStats_ClassInfo__SetMemorizedSpellInSlotReady(this, a0, a1, a2);
}

void CNWSCreatureStats_ClassInfo::SetMemorizedSpellSlot(unsigned char a0, unsigned char a1, uint32_t a2, int32_t a3, unsigned char a4)
{
    return CNWSCreatureStats_ClassInfo__SetMemorizedSpellSlot(this, a0, a1, a2, a3, a4);
}

void CNWSCreatureStats_ClassInfo::SetNumberMemorizedSpellSlots(unsigned char a0, unsigned char a1, int32_t a2)
{
    return CNWSCreatureStats_ClassInfo__SetNumberMemorizedSpellSlots(this, a0, a1, a2);
}

void CNWSCreatureStats_ClassInfo::SetSpellsPerDayLeft(unsigned char a0, unsigned char a1)
{
    return CNWSCreatureStats_ClassInfo__SetSpellsPerDayLeft(this, a0, a1);
}

void CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoCtor__0(CNWSCreatureStats_ClassInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoDtor__0(CNWSCreatureStats_ClassInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__CNWSCreatureStats_ClassInfoDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSCreatureStats_ClassInfo__AddKnownSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__AddKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats_ClassInfo__ClearMemorizedKnownSpells(CNWSCreatureStats_ClassInfo* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__ClearMemorizedKnownSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats_ClassInfo__ClearMemorizedSpellSlot(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__ClearMemorizedSpellSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats_ClassInfo__ConfirmDomainSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__ConfirmDomainSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats_ClassInfo__DecrementSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__DecrementSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCreatureStats_ClassInfo__GetIsDomainSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetIsDomainSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CNWSCreatureStats_ClassInfo__GetKnownSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo__GetMaxSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMaxSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlot(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSStats_Spell* CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotDetails(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = CNWSStats_Spell*(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotDetails);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotMetaType(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotMetaType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotReady(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMemorizedSpellInSlotReady);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__0(CNWSCreatureStats_ClassInfo* thisPtr, uint32_t a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, uint32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__1(CNWSCreatureStats_ClassInfo* thisPtr, uint32_t a0, unsigned char* a1, unsigned char* a2, unsigned char a3)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, uint32_t, unsigned char*, unsigned char*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetMemorizedSpellReadyCount__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

unsigned char CNWSCreatureStats_ClassInfo__GetNumberBonusSpells(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetNumberBonusSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint16_t CNWSCreatureStats_ClassInfo__GetNumberKnownSpells(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetNumberKnownSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats_ClassInfo__GetNumberMemorizedSpellSlots(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetNumberMemorizedSpellSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWSCreatureStats_ClassInfo__GetSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__GetSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats_ClassInfo__IncrementSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__IncrementSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCreatureStats_ClassInfo__ModifyNumberBonusSpells(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__ModifyNumberBonusSpells);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats_ClassInfo__RemoveKnownSpell(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__RemoveKnownSpell);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats_ClassInfo__ResetSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__ResetSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats_ClassInfo__SetMaxSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__SetMaxSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCreatureStats_ClassInfo__SetMemorizedSpellInSlotReady(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__SetMemorizedSpellInSlotReady);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats_ClassInfo__SetMemorizedSpellSlot(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1, uint32_t a2, int32_t a3, unsigned char a4)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char, uint32_t, int32_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__SetMemorizedSpellSlot);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CNWSCreatureStats_ClassInfo__SetNumberMemorizedSpellSlots(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1, int32_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__SetNumberMemorizedSpellSlots);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CNWSCreatureStats_ClassInfo__SetSpellsPerDayLeft(CNWSCreatureStats_ClassInfo* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCreatureStats_ClassInfo*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCreatureStats_ClassInfo__SetSpellsPerDayLeft);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
