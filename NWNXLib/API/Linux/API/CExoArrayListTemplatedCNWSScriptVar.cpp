#include "CExoArrayListTemplatedCNWSScriptVar.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSScriptVar.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSScriptVar::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCNWSScriptVar__Allocate(this, a0);
}

void CExoArrayListTemplatedCNWSScriptVar__Allocate(CExoArrayListTemplatedCNWSScriptVar* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSScriptVar*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSScriptVar__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
