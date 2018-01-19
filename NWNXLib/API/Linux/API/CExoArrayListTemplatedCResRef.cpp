#include "CExoArrayListTemplatedCResRef.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCResRef::Add(CResRef a0)
{
    return CExoArrayListTemplatedCResRef__Add(this, a0);
}

void CExoArrayListTemplatedCResRef::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCResRef__Allocate(this, a0);
}

void CExoArrayListTemplatedCResRef__Add(CExoArrayListTemplatedCResRef* thisPtr, CResRef a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCResRef*, CResRef);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCResRef__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedCResRef__Allocate(CExoArrayListTemplatedCResRef* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCResRef*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCResRef__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
