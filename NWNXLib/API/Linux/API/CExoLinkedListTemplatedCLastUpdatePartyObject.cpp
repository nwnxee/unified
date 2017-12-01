#include "CExoLinkedListTemplatedCLastUpdatePartyObject.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCLastUpdatePartyObject::CExoLinkedListTemplatedCLastUpdatePartyObject()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCLastUpdatePartyObject::CExoLinkedListTemplatedCLastUpdatePartyObject(const CExoLinkedListTemplatedCLastUpdatePartyObject&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCLastUpdatePartyObject& CExoLinkedListTemplatedCLastUpdatePartyObject::operator=(const CExoLinkedListTemplatedCLastUpdatePartyObject&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCLastUpdatePartyObject::~CExoLinkedListTemplatedCLastUpdatePartyObject()
{
    CExoLinkedListTemplatedCLastUpdatePartyObject__CExoLinkedListTemplatedCLastUpdatePartyObjectDtor(this);
}

void CExoLinkedListTemplatedCLastUpdatePartyObject__CExoLinkedListTemplatedCLastUpdatePartyObjectDtor(CExoLinkedListTemplatedCLastUpdatePartyObject* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCLastUpdatePartyObject*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCLastUpdatePartyObject__CExoLinkedListTemplatedCLastUpdatePartyObjectDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
