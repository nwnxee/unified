#include "CNWSCombatAttackData.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSCombatAttackData::CNWSCombatAttackData()
{
    CNWSCombatAttackData__CNWSCombatAttackDataCtor__0(this);
}

CNWSCombatAttackData::~CNWSCombatAttackData()
{
    CNWSCombatAttackData__CNWSCombatAttackDataDtor__0(this);
}

void CNWSCombatAttackData::AddDamage(uint16_t a0, int32_t a1)
{
    return CNWSCombatAttackData__AddDamage(this, a0, a1);
}

void CNWSCombatAttackData::ClearAttackData()
{
    return CNWSCombatAttackData__ClearAttackData(this);
}

void CNWSCombatAttackData::Copy(CNWSCombatAttackData* a0, int32_t a1)
{
    return CNWSCombatAttackData__Copy(this, a0, a1);
}

int32_t CNWSCombatAttackData::GetDamage(uint16_t a0)
{
    return CNWSCombatAttackData__GetDamage(this, a0);
}

int32_t CNWSCombatAttackData::GetTotalDamage(int32_t a0)
{
    return CNWSCombatAttackData__GetTotalDamage(this, a0);
}

int32_t CNWSCombatAttackData::LoadData(CResGFF* a0, CResStruct* a1)
{
    return CNWSCombatAttackData__LoadData(this, a0, a1);
}

int32_t CNWSCombatAttackData::SaveData(CResGFF* a0, CResStruct* a1)
{
    return CNWSCombatAttackData__SaveData(this, a0, a1);
}

void CNWSCombatAttackData::SetBaseDamage(int32_t a0)
{
    return CNWSCombatAttackData__SetBaseDamage(this, a0);
}

void CNWSCombatAttackData::SetDamage(uint16_t a0, int32_t a1)
{
    return CNWSCombatAttackData__SetDamage(this, a0, a1);
}

void CNWSCombatAttackData__CNWSCombatAttackDataCtor__0(CNWSCombatAttackData* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__CNWSCombatAttackDataCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSCombatAttackData__CNWSCombatAttackDataDtor__0(CNWSCombatAttackData* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__CNWSCombatAttackDataDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CNWSCombatAttackData__AddDamage(CNWSCombatAttackData* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__AddDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatAttackData__ClearAttackData(CNWSCombatAttackData* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__ClearAttackData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSCombatAttackData__Copy(CNWSCombatAttackData* thisPtr, CNWSCombatAttackData* a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*, CNWSCombatAttackData*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__Copy);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCombatAttackData__GetDamage(CNWSCombatAttackData* thisPtr, uint16_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatAttackData*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__GetDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCombatAttackData__GetTotalDamage(CNWSCombatAttackData* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatAttackData*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__GetTotalDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CNWSCombatAttackData__LoadData(CNWSCombatAttackData* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatAttackData*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__LoadData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCombatAttackData__SaveData(CNWSCombatAttackData* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatAttackData*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__SaveData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSCombatAttackData__SetBaseDamage(CNWSCombatAttackData* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__SetBaseDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSCombatAttackData__SetDamage(CNWSCombatAttackData* thisPtr, uint16_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatAttackData*, uint16_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatAttackData__SetDamage);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
