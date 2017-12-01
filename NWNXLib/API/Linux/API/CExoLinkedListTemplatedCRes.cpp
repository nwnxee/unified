#include "CExoLinkedListTemplatedCRes.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCRes::CExoLinkedListTemplatedCRes()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCRes::CExoLinkedListTemplatedCRes(const CExoLinkedListTemplatedCRes&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCRes& CExoLinkedListTemplatedCRes::operator=(const CExoLinkedListTemplatedCRes&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCRes::~CExoLinkedListTemplatedCRes()
{
    CExoLinkedListTemplatedCRes__CExoLinkedListTemplatedCResDtor(this);
}

void CExoLinkedListTemplatedCRes__CExoLinkedListTemplatedCResDtor(CExoLinkedListTemplatedCRes* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCRes*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCRes__CExoLinkedListTemplatedCResDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
