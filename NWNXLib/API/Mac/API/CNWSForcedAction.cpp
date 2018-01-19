#include "CNWSForcedAction.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CNWSForcedAction::CNWSForcedAction()
{
    CNWSForcedAction__CNWSForcedActionCtor__0(this);
}

CNWSForcedAction::~CNWSForcedAction()
{
    CNWSForcedAction__CNWSForcedActionDtor__0(this);
}

int32_t CNWSForcedAction::LoadForcedAction(CResGFF* a0, CResStruct* a1)
{
    return CNWSForcedAction__LoadForcedAction(this, a0, a1);
}

int32_t CNWSForcedAction::SaveForcedAction(CResGFF* a0, CResStruct* a1)
{
    return CNWSForcedAction__SaveForcedAction(this, a0, a1);
}

void CNWSForcedAction__CNWSForcedActionCtor__0(CNWSForcedAction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSForcedAction*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSForcedAction__CNWSForcedActionCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSForcedAction__CNWSForcedActionDtor__0(CNWSForcedAction* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSForcedAction*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSForcedAction__CNWSForcedActionDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CNWSForcedAction__LoadForcedAction(CNWSForcedAction* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSForcedAction*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSForcedAction__LoadForcedAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CNWSForcedAction__SaveForcedAction(CNWSForcedAction* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CNWSForcedAction*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSForcedAction__SaveForcedAction);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
