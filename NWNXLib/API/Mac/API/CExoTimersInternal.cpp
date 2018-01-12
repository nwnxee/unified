#include "CExoTimersInternal.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoTimersInternal::CExoTimersInternal()
{
    CExoTimersInternal__CExoTimersInternalCtor__0(this);
}

CExoTimersInternal::~CExoTimersInternal()
{
    CExoTimersInternal__CExoTimersInternalDtor__0(this);
}

uint64_t CExoTimersInternal::GetHighResolutionTimer()
{
    return CExoTimersInternal__GetHighResolutionTimer(this);
}

uint32_t CExoTimersInternal::GetLowResolutionTimer()
{
    return CExoTimersInternal__GetLowResolutionTimer(this);
}

void CExoTimersInternal__CExoTimersInternalCtor__0(CExoTimersInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoTimersInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimersInternal__CExoTimersInternalCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoTimersInternal__CExoTimersInternalDtor__0(CExoTimersInternal* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoTimersInternal*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimersInternal__CExoTimersInternalDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

uint64_t CExoTimersInternal__GetHighResolutionTimer(CExoTimersInternal* thisPtr)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CExoTimersInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimersInternal__GetHighResolutionTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoTimersInternal__GetLowResolutionTimer(CExoTimersInternal* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoTimersInternal*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimersInternal__GetLowResolutionTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
