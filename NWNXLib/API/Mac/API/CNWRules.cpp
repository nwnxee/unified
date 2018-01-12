#include "CNWRules.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWBaseItemArray.hpp"
#include "CNWClass.hpp"
#include "CNWDomain.hpp"
#include "CNWFeat.hpp"
#include "CNWRace.hpp"
#include "CNWSkill.hpp"
#include "CNWSpellArray.hpp"
#include "CTwoDimArrays.hpp"

namespace NWNXLib {

namespace API {

CNWRules::CNWRules()
{
    CNWRules__CNWRulesCtor__0(this);
}

CNWRules::~CNWRules()
{
    CNWRules__CNWRulesDtor__0(this);
}

int32_t CNWRules::CompareFeatName(const void* a0, const void* a1)
{
    return CNWRules__CompareFeatName(a0, a1);
}

unsigned char CNWRules::GetClassExpansionLevel(unsigned char a0)
{
    return CNWRules__GetClassExpansionLevel(this, a0);
}

int32_t CNWRules::GetDamageIndexFromFlags(uint32_t a0)
{
    return CNWRules__GetDamageIndexFromFlags(this, a0);
}

int32_t CNWRules::GetDifficultyOption(int32_t a0, int32_t a1)
{
    return CNWRules__GetDifficultyOption(this, a0, a1);
}

CNWDomain* CNWRules::GetDomain(uint16_t a0)
{
    return CNWRules__GetDomain(this, a0);
}

unsigned char CNWRules::GetFamiliarExpansionLevel(unsigned char a0, int32_t a1)
{
    return CNWRules__GetFamiliarExpansionLevel(this, a0, a1);
}

CNWFeat* CNWRules::GetFeat(uint16_t a0)
{
    return CNWRules__GetFeat(this, a0);
}

unsigned char CNWRules::GetFeatExpansionLevel(uint16_t a0)
{
    return CNWRules__GetFeatExpansionLevel(this, a0);
}

CExoString CNWRules::GetMasterFeatDescriptionText(char a0)
{
    return CNWRules__GetMasterFeatDescriptionText(this, a0);
}

CResRef CNWRules::GetMasterFeatIcon(char a0)
{
    return CNWRules__GetMasterFeatIcon(this, a0);
}

CExoString CNWRules::GetMasterFeatNameText(char a0)
{
    return CNWRules__GetMasterFeatNameText(this, a0);
}

unsigned char CNWRules::GetMetaMagicLevelCost(unsigned char a0)
{
    return CNWRules__GetMetaMagicLevelCost(this, a0);
}

unsigned char CNWRules::GetSkillExpansionLevel(uint16_t a0)
{
    return CNWRules__GetSkillExpansionLevel(this, a0);
}

unsigned char CNWRules::GetSpellExpansionLevel(uint32_t a0)
{
    return CNWRules__GetSpellExpansionLevel(this, a0);
}

int32_t CNWRules::GetWeightedDamageAmount(int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    return CNWRules__GetWeightedDamageAmount(this, a0, a1, a2, a3, a4);
}

int32_t CNWRules::IsArcaneClass(unsigned char a0)
{
    return CNWRules__IsArcaneClass(this, a0);
}

int32_t CNWRules::IsFeatUseable(unsigned char a0, uint16_t a1)
{
    return CNWRules__IsFeatUseable(this, a0, a1);
}

void CNWRules::LoadClassInfo()
{
    return CNWRules__LoadClassInfo(this);
}

void CNWRules::LoadDifficultyInfo()
{
    return CNWRules__LoadDifficultyInfo(this);
}

void CNWRules::LoadDomainInfo()
{
    return CNWRules__LoadDomainInfo(this);
}

void CNWRules::LoadFeatInfo()
{
    return CNWRules__LoadFeatInfo(this);
}

void CNWRules::LoadRaceInfo()
{
    return CNWRules__LoadRaceInfo(this);
}

void CNWRules::LoadSkillInfo()
{
    return CNWRules__LoadSkillInfo(this);
}

void CNWRules::ReloadAll()
{
    return CNWRules__ReloadAll(this);
}

uint16_t CNWRules::RollDice(unsigned char a0, unsigned char a1)
{
    return CNWRules__RollDice(this, a0, a1);
}

void CNWRules::SortFeats()
{
    return CNWRules__SortFeats(this);
}

void CNWRules::UnloadAll()
{
    return CNWRules__UnloadAll(this);
}

void CNWRules__CNWRulesCtor__0(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__CNWRulesCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWRules__CNWRulesDtor__0(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__CNWRulesDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWRules__CompareFeatName(const void* a0, const void* a1)
{
    using FuncPtrType = int32_t(*)(const void*, const void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__CompareFeatName);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(a0, a1);
}

unsigned char CNWRules__GetClassExpansionLevel(CNWRules* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWRules*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetClassExpansionLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWRules__GetDamageIndexFromFlags(CNWRules* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWRules*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetDamageIndexFromFlags);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWRules__GetDifficultyOption(CNWRules* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWRules*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetDifficultyOption);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWDomain* CNWRules__GetDomain(CNWRules* thisPtr, uint16_t a0)
{
    using FuncPtrType = CNWDomain*(__attribute__((cdecl)) *)(CNWRules*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetDomain);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWRules__GetFamiliarExpansionLevel(CNWRules* thisPtr, unsigned char a0, int32_t a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWRules*, unsigned char, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetFamiliarExpansionLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWFeat* CNWRules__GetFeat(CNWRules* thisPtr, uint16_t a0)
{
    using FuncPtrType = CNWFeat*(__attribute__((cdecl)) *)(CNWRules*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWRules__GetFeatExpansionLevel(CNWRules* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWRules*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetFeatExpansionLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWRules__GetMasterFeatDescriptionText(CNWRules* thisPtr, char a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRules*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetMasterFeatDescriptionText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CResRef CNWRules__GetMasterFeatIcon(CNWRules* thisPtr, char a0)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CNWRules*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetMasterFeatIcon);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWRules__GetMasterFeatNameText(CNWRules* thisPtr, char a0)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWRules*, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetMasterFeatNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWRules__GetMetaMagicLevelCost(CNWRules* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWRules*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetMetaMagicLevelCost);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWRules__GetSkillExpansionLevel(CNWRules* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWRules*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetSkillExpansionLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWRules__GetSpellExpansionLevel(CNWRules* thisPtr, uint32_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWRules*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetSpellExpansionLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWRules__GetWeightedDamageAmount(CNWRules* thisPtr, int32_t a0, int32_t a1, int32_t a2, int32_t a3, int32_t a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWRules*, int32_t, int32_t, int32_t, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__GetWeightedDamageAmount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

int32_t CNWRules__IsArcaneClass(CNWRules* thisPtr, unsigned char a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWRules*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__IsArcaneClass);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWRules__IsFeatUseable(CNWRules* thisPtr, unsigned char a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWRules*, unsigned char, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__IsFeatUseable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWRules__LoadClassInfo(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__LoadClassInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__LoadDifficultyInfo(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__LoadDifficultyInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__LoadDomainInfo(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__LoadDomainInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__LoadFeatInfo(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__LoadFeatInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__LoadRaceInfo(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__LoadRaceInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__LoadSkillInfo(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__LoadSkillInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__ReloadAll(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__ReloadAll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint16_t CNWRules__RollDice(CNWRules* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CNWRules*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__RollDice);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWRules__SortFeats(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__SortFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWRules__UnloadAll(CNWRules* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWRules__UnloadAll);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
