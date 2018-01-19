#include "CExoLinkedListTemplatedCNWSClient.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCNWSClient::~CExoLinkedListTemplatedCNWSClient()
{
    CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientDtor(this);
}

void CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientDtor(CExoLinkedListTemplatedCNWSClient* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCNWSClient*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCNWSClient__CExoLinkedListTemplatedCNWSClientDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
