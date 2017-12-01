#include "CExoLinkedListTemplatedCNWSPlayerTURD.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCNWSPlayerTURD::CExoLinkedListTemplatedCNWSPlayerTURD()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSPlayerTURD::CExoLinkedListTemplatedCNWSPlayerTURD(const CExoLinkedListTemplatedCNWSPlayerTURD&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSPlayerTURD& CExoLinkedListTemplatedCNWSPlayerTURD::operator=(const CExoLinkedListTemplatedCNWSPlayerTURD&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCNWSPlayerTURD::~CExoLinkedListTemplatedCNWSPlayerTURD()
{
    CExoLinkedListTemplatedCNWSPlayerTURD__CExoLinkedListTemplatedCNWSPlayerTURDDtor(this);
}

void CExoLinkedListTemplatedCNWSPlayerTURD__CExoLinkedListTemplatedCNWSPlayerTURDDtor(CExoLinkedListTemplatedCNWSPlayerTURD* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCNWSPlayerTURD*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCNWSPlayerTURD__CExoLinkedListTemplatedCNWSPlayerTURDDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
