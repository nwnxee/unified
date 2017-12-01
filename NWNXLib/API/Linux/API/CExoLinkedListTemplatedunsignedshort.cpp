#include "CExoLinkedListTemplatedunsignedshort.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedunsignedshort::CExoLinkedListTemplatedunsignedshort()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedunsignedshort::CExoLinkedListTemplatedunsignedshort(const CExoLinkedListTemplatedunsignedshort&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedunsignedshort& CExoLinkedListTemplatedunsignedshort::operator=(const CExoLinkedListTemplatedunsignedshort&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

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
