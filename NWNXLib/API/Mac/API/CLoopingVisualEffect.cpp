#include "CLoopingVisualEffect.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

int32_t CLoopingVisualEffect::GetIsBeam()
{
    return CLoopingVisualEffect__GetIsBeam(this);
}

int32_t CLoopingVisualEffect__GetIsBeam(CLoopingVisualEffect* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CLoopingVisualEffect*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CLoopingVisualEffect__GetIsBeam);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
