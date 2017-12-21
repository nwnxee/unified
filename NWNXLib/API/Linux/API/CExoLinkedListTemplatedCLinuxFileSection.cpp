#include "CExoLinkedListTemplatedCLinuxFileSection.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCLinuxFileSection::~CExoLinkedListTemplatedCLinuxFileSection()
{
    CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionDtor(this);
}

void CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionDtor(CExoLinkedListTemplatedCLinuxFileSection* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCLinuxFileSection*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCLinuxFileSection__CExoLinkedListTemplatedCLinuxFileSectionDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
