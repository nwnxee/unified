#include "CExoArrayListTemplatedint.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedint::Add(int32_t a0)
{
    return CExoArrayListTemplatedint__Add(this, a0);
}

void CExoArrayListTemplatedint::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedint__Allocate(this, a0);
}

void CExoArrayListTemplatedint::SetSize(int32_t a0)
{
    return CExoArrayListTemplatedint__SetSize(this, a0);
}

void CExoArrayListTemplatedint__Add(CExoArrayListTemplatedint* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedint*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedint__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedint__Allocate(CExoArrayListTemplatedint* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedint*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedint__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoArrayListTemplatedint__SetSize(CExoArrayListTemplatedint* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedint*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedint__SetSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
