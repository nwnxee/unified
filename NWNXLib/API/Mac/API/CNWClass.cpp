#include "CNWClass.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWClass_Feat.hpp"
#include "CNWClass__CNWClass_Skill.hpp"
#include "CNWRules.hpp"

namespace NWNXLib {

namespace API {

CNWClass::CNWClass()
{
    CNWClass__CNWClassCtor__0(this);
}

CNWClass::~CNWClass()
{
    CNWClass__CNWClassDtor__0(this);
}

unsigned char CNWClass::GetAttackBonus(unsigned char a0)
{
    return CNWClass__GetAttackBonus(this, a0);
}

unsigned char CNWClass::GetBonusFeats(unsigned char a0)
{
    return CNWClass__GetBonusFeats(this, a0);
}

CNWClass_Feat* CNWClass::GetClassFeat(uint16_t a0)
{
    return CNWClass__GetClassFeat(this, a0);
}

CExoString CNWClass::GetDescriptionText()
{
    return CNWClass__GetDescriptionText(this);
}

unsigned char CNWClass::GetFortSaveBonus(unsigned char a0)
{
    return CNWClass__GetFortSaveBonus(this, a0);
}

int32_t CNWClass::GetIsAlignmentAllowed(unsigned char a0, unsigned char a1)
{
    return CNWClass__GetIsAlignmentAllowed(this, a0, a1);
}

unsigned char CNWClass::GetLevelFeatGranted(uint16_t a0)
{
    return CNWClass__GetLevelFeatGranted(this, a0);
}

unsigned char CNWClass::GetLevelGranted(uint16_t a0)
{
    return CNWClass__GetLevelGranted(this, a0);
}

CExoString CNWClass::GetNameLowerText()
{
    return CNWClass__GetNameLowerText(this);
}

CExoString CNWClass::GetNamePluralText()
{
    return CNWClass__GetNamePluralText(this);
}

CExoString CNWClass::GetNameText()
{
    return CNWClass__GetNameText(this);
}

unsigned char CNWClass::GetRefSaveBonus(unsigned char a0)
{
    return CNWClass__GetRefSaveBonus(this, a0);
}

unsigned char CNWClass::GetSpellGain(unsigned char a0, unsigned char a1)
{
    return CNWClass__GetSpellGain(this, a0, a1);
}

unsigned char CNWClass::GetSpellsKnownPerLevel(unsigned char a0, unsigned char a1, unsigned char a2, uint16_t a3, unsigned char a4)
{
    return CNWClass__GetSpellsKnownPerLevel(this, a0, a1, a2, a3, a4);
}

unsigned char CNWClass::GetWillSaveBonus(unsigned char a0)
{
    return CNWClass__GetWillSaveBonus(this, a0);
}

int32_t CNWClass::IsBonusFeat(uint16_t a0)
{
    return CNWClass__IsBonusFeat(this, a0);
}

int32_t CNWClass::IsFeatUseable(uint16_t a0)
{
    return CNWClass__IsFeatUseable(this, a0);
}

int32_t CNWClass::IsGrantedFeat(uint16_t a0, unsigned char& a1)
{
    return CNWClass__IsGrantedFeat(this, a0, a1);
}

int32_t CNWClass::IsNormalFeat(uint16_t a0)
{
    return CNWClass__IsNormalFeat(this, a0);
}

int32_t CNWClass::IsSkillClassSkill(uint16_t a0)
{
    return CNWClass__IsSkillClassSkill(this, a0);
}

int32_t CNWClass::IsSkillUseable(uint16_t a0)
{
    return CNWClass__IsSkillUseable(this, a0);
}

void CNWClass::LoadAttackBonusTable(CExoString a0)
{
    return CNWClass__LoadAttackBonusTable(this, a0);
}

void CNWClass::LoadBonusFeatsTable(CExoString a0)
{
    return CNWClass__LoadBonusFeatsTable(this, a0);
}

void CNWClass::LoadFeatsTable(CExoString a0, CNWRules* a1)
{
    return CNWClass__LoadFeatsTable(this, a0, a1);
}

void CNWClass::LoadSavingThrowTable(CExoString a0)
{
    return CNWClass__LoadSavingThrowTable(this, a0);
}

void CNWClass::LoadSkillsTable(CExoString a0)
{
    return CNWClass__LoadSkillsTable(this, a0);
}

void CNWClass::LoadSpellGainTable(CExoString a0)
{
    return CNWClass__LoadSpellGainTable(this, a0);
}

void CNWClass::LoadSpellKnownTable(CExoString a0)
{
    return CNWClass__LoadSpellKnownTable(this, a0);
}

void CNWClass__CNWClassCtor__0(CNWClass* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__CNWClassCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWClass__CNWClassDtor__0(CNWClass* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__CNWClassDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char CNWClass__GetAttackBonus(CNWClass* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetAttackBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWClass__GetBonusFeats(CNWClass* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetBonusFeats);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CNWClass_Feat* CNWClass__GetClassFeat(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = CNWClass_Feat*(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetClassFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWClass__GetDescriptionText(CNWClass* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWClass*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetDescriptionText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWClass__GetFortSaveBonus(CNWClass* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetFortSaveBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWClass__GetIsAlignmentAllowed(CNWClass* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetIsAlignmentAllowed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWClass__GetLevelFeatGranted(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetLevelFeatGranted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWClass__GetLevelGranted(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetLevelGranted);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoString CNWClass__GetNameLowerText(CNWClass* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWClass*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetNameLowerText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWClass__GetNamePluralText(CNWClass* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWClass*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetNamePluralText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CExoString CNWClass__GetNameText(CNWClass* thisPtr)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CNWClass*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetNameText);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CNWClass__GetRefSaveBonus(CNWClass* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetRefSaveBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

unsigned char CNWClass__GetSpellGain(CNWClass* thisPtr, unsigned char a0, unsigned char a1)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetSpellGain);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char CNWClass__GetSpellsKnownPerLevel(CNWClass* thisPtr, unsigned char a0, unsigned char a1, unsigned char a2, uint16_t a3, unsigned char a4)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char, unsigned char, unsigned char, uint16_t, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetSpellsKnownPerLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

unsigned char CNWClass__GetWillSaveBonus(CNWClass* thisPtr, unsigned char a0)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CNWClass*, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__GetWillSaveBonus);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWClass__IsBonusFeat(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__IsBonusFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWClass__IsFeatUseable(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__IsFeatUseable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWClass__IsGrantedFeat(CNWClass* thisPtr, uint16_t a0, unsigned char& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, uint16_t, unsigned char&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__IsGrantedFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWClass__IsNormalFeat(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__IsNormalFeat);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWClass__IsSkillClassSkill(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__IsSkillClassSkill);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWClass__IsSkillUseable(CNWClass* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWClass*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__IsSkillUseable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWClass__LoadAttackBonusTable(CNWClass* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadAttackBonusTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWClass__LoadBonusFeatsTable(CNWClass* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadBonusFeatsTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWClass__LoadFeatsTable(CNWClass* thisPtr, CExoString a0, CNWRules* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString, CNWRules*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadFeatsTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWClass__LoadSavingThrowTable(CNWClass* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadSavingThrowTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWClass__LoadSkillsTable(CNWClass* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadSkillsTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWClass__LoadSpellGainTable(CNWClass* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadSpellGainTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWClass__LoadSpellKnownTable(CNWClass* thisPtr, CExoString a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWClass*, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWClass__LoadSpellKnownTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
