#include "CNWSTransition.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSObject.hpp"
#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

void CNWSTransition::LoadFromGff(CResGFF* a0, CResStruct* a1)
{
    return CNWSTransition__LoadFromGff(this, a0, a1);
}

CNWSObject* CNWSTransition::LookupTarget()
{
    return CNWSTransition__LookupTarget(this);
}

void CNWSTransition::SaveToGff(CResGFF* a0, CResStruct* a1)
{
    return CNWSTransition__SaveToGff(this, a0, a1);
}

void CNWSTransition::SetTarget(const CExoString& a0)
{
    return CNWSTransition__SetTarget__0(this, a0);
}

void CNWSTransition::SetTarget(CNWSObject* a0)
{
    return CNWSTransition__SetTarget__1(this, a0);
}

void CNWSTransition::Unlink(int32_t a0)
{
    return CNWSTransition__Unlink(this, a0);
}

void CNWSTransition__LoadFromGff(CNWSTransition* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTransition*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTransition__LoadFromGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CNWSObject* CNWSTransition__LookupTarget(CNWSTransition* thisPtr)
{
    using FuncPtrType = CNWSObject*(__attribute__((cdecl)) *)(CNWSTransition*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTransition__LookupTarget);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CNWSTransition__SaveToGff(CNWSTransition* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTransition*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTransition__SaveToGff);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CNWSTransition__SetTarget__0(CNWSTransition* thisPtr, const CExoString& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTransition*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTransition__SetTarget__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSTransition__SetTarget__1(CNWSTransition* thisPtr, CNWSObject* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTransition*, CNWSObject*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTransition__SetTarget__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSTransition__Unlink(CNWSTransition* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSTransition*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSTransition__Unlink);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
