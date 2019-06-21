#include "CExoLinkedListTemplatedCERFKey.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCERFKey::~CExoLinkedListTemplatedCERFKey()
{
    CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyDtor(this);
}

void CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyDtor(CExoLinkedListTemplatedCERFKey* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCERFKey*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCERFKey__CExoLinkedListTemplatedCERFKeyDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
