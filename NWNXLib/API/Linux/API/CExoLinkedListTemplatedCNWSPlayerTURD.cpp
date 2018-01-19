#include "CExoLinkedListTemplatedCNWSPlayerTURD.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

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
