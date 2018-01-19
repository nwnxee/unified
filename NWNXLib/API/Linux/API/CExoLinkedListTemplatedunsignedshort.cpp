#include "CExoLinkedListTemplatedunsignedshort.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedunsignedshort::~CExoLinkedListTemplatedunsignedshort()
{
    CExoLinkedListTemplatedunsignedshort__CExoLinkedListTemplatedunsignedshortDtor(this);
}

void CExoLinkedListTemplatedunsignedshort__CExoLinkedListTemplatedunsignedshortDtor(CExoLinkedListTemplatedunsignedshort* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedunsignedshort*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedunsignedshort__CExoLinkedListTemplatedunsignedshortDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
