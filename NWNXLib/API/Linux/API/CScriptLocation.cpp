#include "CScriptLocation.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CScriptLocation::CScriptLocation()
{
    CScriptLocation__CScriptLocationCtor(this);
}

CScriptLocation::~CScriptLocation()
{
    CScriptLocation__CScriptLocationDtor(this);
}

void CScriptLocation::CopyScriptLocation(CScriptLocation* a0)
{
    return CScriptLocation__CopyScriptLocation(this, a0);
}

int32_t CScriptLocation::LoadLocation(CResGFF* a0, CResStruct* a1)
{
    return CScriptLocation__LoadLocation(this, a0, a1);
}

int32_t CScriptLocation::SaveLocation(CResGFF* a0, CResStruct* a1)
{
    return CScriptLocation__SaveLocation(this, a0, a1);
}

void CScriptLocation__CScriptLocationCtor(CScriptLocation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptLocation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptLocation__CScriptLocationCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CScriptLocation__CScriptLocationDtor(CScriptLocation* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptLocation*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptLocation__CScriptLocationDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CScriptLocation__CopyScriptLocation(CScriptLocation* thisPtr, CScriptLocation* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptLocation*, CScriptLocation*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptLocation__CopyScriptLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CScriptLocation__LoadLocation(CScriptLocation* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptLocation*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptLocation__LoadLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CScriptLocation__SaveLocation(CScriptLocation* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CScriptLocation*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptLocation__SaveLocation);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
