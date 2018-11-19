#include "CExoArrayListTemplatedunsignedshort.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedunsignedshort::~CExoArrayListTemplatedunsignedshort()
{
    CExoArrayListTemplatedunsignedshort__CExoArrayListTemplatedunsignedshortDtor(this);
}

void CExoArrayListTemplatedunsignedshort__CExoArrayListTemplatedunsignedshortDtor(CExoArrayListTemplatedunsignedshort* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedunsignedshort*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedunsignedshort__CExoArrayListTemplatedunsignedshortDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
