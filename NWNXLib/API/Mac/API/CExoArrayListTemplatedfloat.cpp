#include "CExoArrayListTemplatedfloat.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedfloat::CExoArrayListTemplatedfloat()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoArrayListTemplatedfloat::CExoArrayListTemplatedfloat(const CExoArrayListTemplatedfloat&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoArrayListTemplatedfloat& CExoArrayListTemplatedfloat::operator=(const CExoArrayListTemplatedfloat&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoArrayListTemplatedfloat::~CExoArrayListTemplatedfloat()
{
    CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor(this);
}

void CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor(CExoArrayListTemplatedfloat* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedfloat*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedfloat__CExoArrayListTemplatedfloatDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
