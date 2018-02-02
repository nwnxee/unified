#include "CResHelperTemplatedCResNDB2064.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResNDB2064::~CResHelperTemplatedCResNDB2064()
{
    CResHelperTemplatedCResNDB2064__CResHelperTemplatedCResNDB2064Dtor__0(this);
}

void CResHelperTemplatedCResNDB2064::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResNDB2064__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResNDB2064__CResHelperTemplatedCResNDB2064Dtor__0(CResHelperTemplatedCResNDB2064* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResNDB2064*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResNDB2064__CResHelperTemplatedCResNDB2064Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResNDB2064__SetResRef(CResHelperTemplatedCResNDB2064* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResNDB2064*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResNDB2064__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
