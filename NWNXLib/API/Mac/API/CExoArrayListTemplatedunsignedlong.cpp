#include "CExoArrayListTemplatedunsignedlong.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedunsignedlong::~CExoArrayListTemplatedunsignedlong()
{
    CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongDtor(this);
}

void CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongDtor(CExoArrayListTemplatedunsignedlong* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedunsignedlong*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedunsignedlong__CExoArrayListTemplatedunsignedlongDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
