#include "CExoLinkedListTemplatedCLinuxFileKey.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCLinuxFileKey::~CExoLinkedListTemplatedCLinuxFileKey()
{
    CExoLinkedListTemplatedCLinuxFileKey__CExoLinkedListTemplatedCLinuxFileKeyDtor(this);
}

void CExoLinkedListTemplatedCLinuxFileKey__CExoLinkedListTemplatedCLinuxFileKeyDtor(CExoLinkedListTemplatedCLinuxFileKey* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCLinuxFileKey*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCLinuxFileKey__CExoLinkedListTemplatedCLinuxFileKeyDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
