#include "CCallbackImplTemplated20.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CCallbackImplTemplated20::GetCallbackSizeBytes()
{
    return CCallbackImplTemplated20__GetCallbackSizeBytes(this);
}

void CCallbackImplTemplated20::Run(void* a0, int32_t a1, uint64_t a2)
{
    return CCallbackImplTemplated20__Run(this, a0, a1, a2);
}

void CCallbackImplTemplated20__GetCallbackSizeBytes(CCallbackImplTemplated20* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated20*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated20__GetCallbackSizeBytes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CCallbackImplTemplated20__Run(CCallbackImplTemplated20* thisPtr, void* a0, int32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated20*, void*, int32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated20__Run);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

}

}
