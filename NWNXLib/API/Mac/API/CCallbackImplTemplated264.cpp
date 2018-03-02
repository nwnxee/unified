#include "CCallbackImplTemplated264.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

int32_t CCallbackImplTemplated264::GetCallbackSizeBytes()
{
    return CCallbackImplTemplated264__GetCallbackSizeBytes(this);
}

void CCallbackImplTemplated264::Run(void* a0, int32_t a1, uint64_t a2)
{
    return CCallbackImplTemplated264__Run(this, a0, a1, a2);
}

int32_t CCallbackImplTemplated264__GetCallbackSizeBytes(CCallbackImplTemplated264* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CCallbackImplTemplated264*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated264__GetCallbackSizeBytes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CCallbackImplTemplated264__Run(CCallbackImplTemplated264* thisPtr, void* a0, int32_t a1, uint64_t a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CCallbackImplTemplated264*, void*, int32_t, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CCallbackImplTemplated264__Run);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

}

}
