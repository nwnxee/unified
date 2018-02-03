#include "CResHelperTemplatedCResWOK2016.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResWOK2016::~CResHelperTemplatedCResWOK2016()
{
    CResHelperTemplatedCResWOK2016__CResHelperTemplatedCResWOK2016Dtor__0(this);
}

void CResHelperTemplatedCResWOK2016::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResWOK2016__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResWOK2016__CResHelperTemplatedCResWOK2016Dtor__0(CResHelperTemplatedCResWOK2016* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResWOK2016*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResWOK2016__CResHelperTemplatedCResWOK2016Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResWOK2016__SetResRef(CResHelperTemplatedCResWOK2016* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResWOK2016*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResWOK2016__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
