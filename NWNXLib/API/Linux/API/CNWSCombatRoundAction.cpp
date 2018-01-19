#include "CNWSCombatRoundAction.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSCombatRoundAction::CNWSCombatRoundAction()
{
    CNWSCombatRoundAction__CNWSCombatRoundActionCtor(this);
}

CNWSCombatRoundAction::~CNWSCombatRoundAction()
{
    CNWSCombatRoundAction__CNWSCombatRoundActionDtor(this);
}

int32_t CNWSCombatRoundAction::LoadData(CResGFF* a0, CResStruct* a1)
{
    return CNWSCombatRoundAction__LoadData(this, a0, a1);
}

int32_t CNWSCombatRoundAction::SaveData(CResGFF* a0, CResStruct* a1)
{
    return CNWSCombatRoundAction__SaveData(this, a0, a1);
}

void CNWSCombatRoundAction__CNWSCombatRoundActionCtor(CNWSCombatRoundAction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRoundAction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRoundAction__CNWSCombatRoundActionCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSCombatRoundAction__CNWSCombatRoundActionDtor(CNWSCombatRoundAction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSCombatRoundAction*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRoundAction__CNWSCombatRoundActionDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSCombatRoundAction__LoadData(CNWSCombatRoundAction* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRoundAction*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRoundAction__LoadData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSCombatRoundAction__SaveData(CNWSCombatRoundAction* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSCombatRoundAction*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSCombatRoundAction__SaveData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
