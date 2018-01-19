#include "CMemRecord.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CMemRecord::Clear()
{
    return CMemRecord__Clear(this);
}

void CMemRecord__Clear(CMemRecord* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CMemRecord*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CMemRecord__Clear);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
