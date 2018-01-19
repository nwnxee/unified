#include "CExoLinkedListTemplatedunsignedlong.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedunsignedlong::~CExoLinkedListTemplatedunsignedlong()
{
    CExoLinkedListTemplatedunsignedlong__CExoLinkedListTemplatedunsignedlongDtor(this);
}

void CExoLinkedListTemplatedunsignedlong__CExoLinkedListTemplatedunsignedlongDtor(CExoLinkedListTemplatedunsignedlong* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedunsignedlong*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedunsignedlong__CExoLinkedListTemplatedunsignedlongDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
