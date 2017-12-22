#include "CResHelperTemplatedCResIFO2014.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResIFO2014::~CResHelperTemplatedCResIFO2014()
{
    CResHelperTemplatedCResIFO2014__CResHelperTemplatedCResIFO2014Dtor__0(this);
}

void CResHelperTemplatedCResIFO2014::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResIFO2014__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResIFO2014__CResHelperTemplatedCResIFO2014Dtor__0(CResHelperTemplatedCResIFO2014* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResIFO2014*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResIFO2014__CResHelperTemplatedCResIFO2014Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResIFO2014__SetResRef(CResHelperTemplatedCResIFO2014* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResIFO2014*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResIFO2014__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
