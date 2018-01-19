#include "CCallbackImplTemplated12.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CCallbackImplTemplated12::GetCallbackSizeBytes()
{
    return CCallbackImplTemplated12__GetCallbackSizeBytes(this);
}

void CCallbackImplTemplated12::Run(void* a0, int32_t a1, uint64_t a2)
{
    return CCallbackImplTemplated12__Run(this, a0, a1, a2);
}

void CCallbackImplTemplated12__GetCallbackSizeBytes(CCallbackImplTemplated12* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated12*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated12__GetCallbackSizeBytes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CCallbackImplTemplated12__Run(CCallbackImplTemplated12* thisPtr, void* a0, int32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated12*, void*, int32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated12__Run);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

}

}
