#include "CCallbackImplTemplated4.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

int32_t CCallbackImplTemplated4::GetCallbackSizeBytes()
{
    return CCallbackImplTemplated4__GetCallbackSizeBytes(this);
}

void CCallbackImplTemplated4::Run(void* a0, int32_t a1, uint64_t a2)
{
    return CCallbackImplTemplated4__Run(this, a0, a1, a2);
}

int32_t CCallbackImplTemplated4__GetCallbackSizeBytes(CCallbackImplTemplated4* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCallbackImplTemplated4*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated4__GetCallbackSizeBytes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CCallbackImplTemplated4__Run(CCallbackImplTemplated4* thisPtr, void* a0, int32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated4*, void*, int32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated4__Run);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
