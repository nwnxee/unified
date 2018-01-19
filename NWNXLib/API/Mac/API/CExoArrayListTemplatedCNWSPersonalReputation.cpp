#include "CExoArrayListTemplatedCNWSPersonalReputation.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSPersonalReputation.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSPersonalReputation::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCNWSPersonalReputation__Allocate(this, a0);
}

void CExoArrayListTemplatedCNWSPersonalReputation__Allocate(CExoArrayListTemplatedCNWSPersonalReputation* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSPersonalReputation*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSPersonalReputation__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
