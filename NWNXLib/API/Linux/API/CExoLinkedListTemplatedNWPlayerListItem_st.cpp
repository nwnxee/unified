#include "CExoLinkedListTemplatedNWPlayerListItem_st.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedNWPlayerListItem_st::~CExoLinkedListTemplatedNWPlayerListItem_st()
{
    CExoLinkedListTemplatedNWPlayerListItem_st__CExoLinkedListTemplatedNWPlayerListItem_stDtor(this);
}

void CExoLinkedListTemplatedNWPlayerListItem_st__CExoLinkedListTemplatedNWPlayerListItem_stDtor(CExoLinkedListTemplatedNWPlayerListItem_st* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedNWPlayerListItem_st*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedNWPlayerListItem_st__CExoLinkedListTemplatedNWPlayerListItem_stDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
