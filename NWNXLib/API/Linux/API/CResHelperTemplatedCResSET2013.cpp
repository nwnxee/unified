#include "CResHelperTemplatedCResSET2013.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResSET2013::~CResHelperTemplatedCResSET2013()
{
    CResHelperTemplatedCResSET2013__CResHelperTemplatedCResSET2013Dtor__0(this);
}

void CResHelperTemplatedCResSET2013::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResSET2013__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResSET2013__CResHelperTemplatedCResSET2013Dtor__0(CResHelperTemplatedCResSET2013* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResSET2013*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResSET2013__CResHelperTemplatedCResSET2013Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResSET2013__SetResRef(CResHelperTemplatedCResSET2013* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResSET2013*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResSET2013__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
