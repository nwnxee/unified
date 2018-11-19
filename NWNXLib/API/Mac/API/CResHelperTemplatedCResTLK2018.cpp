#include "CResHelperTemplatedCResTLK2018.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CResHelperTemplatedCResTLK2018::~CResHelperTemplatedCResTLK2018()
{
    CResHelperTemplatedCResTLK2018__CResHelperTemplatedCResTLK2018Dtor__0(this);
}

void CResHelperTemplatedCResTLK2018::SetResRef(const CResRef& a0, int32_t a1)
{
    return CResHelperTemplatedCResTLK2018__SetResRef(this, a0, a1);
}

void CResHelperTemplatedCResTLK2018__CResHelperTemplatedCResTLK2018Dtor__0(CResHelperTemplatedCResTLK2018* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResTLK2018*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResTLK2018__CResHelperTemplatedCResTLK2018Dtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CResHelperTemplatedCResTLK2018__SetResRef(CResHelperTemplatedCResTLK2018* thisPtr, const CResRef& a0, int32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResHelperTemplatedCResTLK2018*, const CResRef&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResHelperTemplatedCResTLK2018__SetResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
