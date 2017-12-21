#include "CExoLinkedListTemplatedCERFRes.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCERFRes::CExoLinkedListTemplatedCERFRes()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCERFRes::CExoLinkedListTemplatedCERFRes(const CExoLinkedListTemplatedCERFRes&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCERFRes& CExoLinkedListTemplatedCERFRes::operator=(const CExoLinkedListTemplatedCERFRes&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCERFRes::~CExoLinkedListTemplatedCERFRes()
{
    CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResDtor(this);
}

void CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResDtor(CExoLinkedListTemplatedCERFRes* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCERFRes*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCERFRes__CExoLinkedListTemplatedCERFResDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
