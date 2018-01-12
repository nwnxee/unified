#include "CExoTimers.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoTimersInternal.hpp"

namespace NWNXLib {

namespace API {

CExoTimers::CExoTimers()
{
    CExoTimers__CExoTimersCtor__0(this);
}

CExoTimers::~CExoTimers()
{
    CExoTimers__CExoTimersDtor__0(this);
}

uint64_t CExoTimers::GetHighResolutionTimer()
{
    return CExoTimers__GetHighResolutionTimer(this);
}

uint32_t CExoTimers::GetLowResolutionTimer()
{
    return CExoTimers__GetLowResolutionTimer(this);
}

void CExoTimers__CExoTimersCtor__0(CExoTimers* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoTimers*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimers__CExoTimersCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoTimers__CExoTimersDtor__0(CExoTimers* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoTimers*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimers__CExoTimersDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

uint64_t CExoTimers__GetHighResolutionTimer(CExoTimers* thisPtr)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CExoTimers*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimers__GetHighResolutionTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

uint32_t CExoTimers__GetLowResolutionTimer(CExoTimers* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoTimers*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoTimers__GetLowResolutionTimer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
