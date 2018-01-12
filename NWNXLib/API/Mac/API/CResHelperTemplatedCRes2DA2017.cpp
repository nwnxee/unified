#include "CResHelperTemplatedCRes2DA2017.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCRes2DA2017::~CResHelperTemplatedCRes2DA2017()
{
    CResHelperTemplatedCRes2DA2017__CResHelperTemplatedCRes2DA2017Dtor__0(this);
}

void CResHelperTemplatedCRes2DA2017::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCRes2DA2017__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCRes2DA2017__CResHelperTemplatedCRes2DA2017Dtor__0(CResHelperTemplatedCRes2DA2017* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCRes2DA2017*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCRes2DA2017__CResHelperTemplatedCRes2DA2017Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCRes2DA2017__SetResRef(CResHelperTemplatedCRes2DA2017* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCRes2DA2017*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCRes2DA2017__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
