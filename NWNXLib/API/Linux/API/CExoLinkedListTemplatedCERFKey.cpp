#include "CExoLinkedListTemplatedCERFKey.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCERFKey::CExoLinkedListTemplatedCERFKey()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCERFKey::CExoLinkedListTemplatedCERFKey(const CExoLinkedListTemplatedCERFKey&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCERFKey& CExoLinkedListTemplatedCERFKey::operator=(const CExoLinkedListTemplatedCERFKey&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

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
