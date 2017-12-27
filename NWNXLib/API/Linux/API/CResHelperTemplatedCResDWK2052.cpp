#include "CResHelperTemplatedCResDWK2052.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResDWK2052::~CResHelperTemplatedCResDWK2052()
{
    CResHelperTemplatedCResDWK2052__CResHelperTemplatedCResDWK2052Dtor__0(this);
}

void CResHelperTemplatedCResDWK2052::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResDWK2052__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResDWK2052__CResHelperTemplatedCResDWK2052Dtor__0(CResHelperTemplatedCResDWK2052* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResDWK2052*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResDWK2052__CResHelperTemplatedCResDWK2052Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResDWK2052__SetResRef(CResHelperTemplatedCResDWK2052* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResDWK2052*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResDWK2052__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
