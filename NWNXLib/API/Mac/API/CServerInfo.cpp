#include "CServerInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CServerInfo::CServerInfo()
{
    CServerInfo__CServerInfoCtor__0(this);
}

CServerInfo::~CServerInfo()
{
    CServerInfo__CServerInfoDtor(this);
}

int32_t CServerInfo::FindOptionIndex(CExoString a0, CExoString a1)
{
    return CServerInfo__FindOptionIndex(this, a0, a1);
}

void CServerInfo::SetDifficultyLevel(int32_t a0, int32_t a1)
{
    return CServerInfo__SetDifficultyLevel(this, a0, a1);
}

void CServerInfo__CServerInfoCtor__0(CServerInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerInfo__CServerInfoCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CServerInfo__CServerInfoDtor(CServerInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerInfo__CServerInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CServerInfo__FindOptionIndex(CServerInfo* thisPtr, CExoString a0, CExoString a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerInfo*, CExoString, CExoString);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerInfo__FindOptionIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

void CServerInfo__SetDifficultyLevel(CServerInfo* thisPtr, int32_t a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CServerInfo*, int32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerInfo__SetDifficultyLevel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
