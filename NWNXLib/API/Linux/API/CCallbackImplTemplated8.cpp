#include "CCallbackImplTemplated8.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

int32_t CCallbackImplTemplated8::GetCallbackSizeBytes()
{
    return CCallbackImplTemplated8__GetCallbackSizeBytes(this);
}

void CCallbackImplTemplated8::Run(void* a0, int32_t a1, uint64_t a2)
{
    return CCallbackImplTemplated8__Run(this, a0, a1, a2);
}

int32_t CCallbackImplTemplated8__GetCallbackSizeBytes(CCallbackImplTemplated8* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCallbackImplTemplated8*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated8__GetCallbackSizeBytes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CCallbackImplTemplated8__Run(CCallbackImplTemplated8* thisPtr, void* a0, int32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated8*, void*, int32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated8__Run);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
