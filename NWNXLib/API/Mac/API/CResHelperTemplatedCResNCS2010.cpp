#include "CResHelperTemplatedCResNCS2010.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResNCS2010::~CResHelperTemplatedCResNCS2010()
{
    CResHelperTemplatedCResNCS2010__CResHelperTemplatedCResNCS2010Dtor__0(this);
}

void CResHelperTemplatedCResNCS2010::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResNCS2010__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResNCS2010__CResHelperTemplatedCResNCS2010Dtor__0(CResHelperTemplatedCResNCS2010* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResNCS2010*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResNCS2010__CResHelperTemplatedCResNCS2010Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResNCS2010__SetResRef(CResHelperTemplatedCResNCS2010* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResNCS2010*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResNCS2010__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
