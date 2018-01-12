#include "CResHelperTemplatedCResNSS2009.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResNSS2009::~CResHelperTemplatedCResNSS2009()
{
    CResHelperTemplatedCResNSS2009__CResHelperTemplatedCResNSS2009Dtor__0(this);
}

void CResHelperTemplatedCResNSS2009::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResNSS2009__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResNSS2009__CResHelperTemplatedCResNSS2009Dtor__0(CResHelperTemplatedCResNSS2009* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResNSS2009*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResNSS2009__CResHelperTemplatedCResNSS2009Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResNSS2009__SetResRef(CResHelperTemplatedCResNSS2009* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResNSS2009*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResNSS2009__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
