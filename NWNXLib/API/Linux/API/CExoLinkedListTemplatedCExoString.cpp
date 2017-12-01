#include "CExoLinkedListTemplatedCExoString.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCExoString::CExoLinkedListTemplatedCExoString()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCExoString::CExoLinkedListTemplatedCExoString(const CExoLinkedListTemplatedCExoString&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCExoString& CExoLinkedListTemplatedCExoString::operator=(const CExoLinkedListTemplatedCExoString&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCExoString::~CExoLinkedListTemplatedCExoString()
{
    CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringDtor(this);
}

void CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringDtor(CExoLinkedListTemplatedCExoString* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCExoString*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCExoString__CExoLinkedListTemplatedCExoStringDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
