#include "CResHelperTemplatedCResLTR2036.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResLTR2036::~CResHelperTemplatedCResLTR2036()
{
    CResHelperTemplatedCResLTR2036__CResHelperTemplatedCResLTR2036Dtor__0(this);
}

void CResHelperTemplatedCResLTR2036::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResLTR2036__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResLTR2036__CResHelperTemplatedCResLTR2036Dtor__0(CResHelperTemplatedCResLTR2036* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResLTR2036*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResLTR2036__CResHelperTemplatedCResLTR2036Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResLTR2036__SetResRef(CResHelperTemplatedCResLTR2036* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResLTR2036*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResLTR2036__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
