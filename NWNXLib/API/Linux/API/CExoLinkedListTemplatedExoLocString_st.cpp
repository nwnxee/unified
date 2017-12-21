#include "CExoLinkedListTemplatedExoLocString_st.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedExoLocString_st::CExoLinkedListTemplatedExoLocString_st()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedExoLocString_st::CExoLinkedListTemplatedExoLocString_st(const CExoLinkedListTemplatedExoLocString_st&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedExoLocString_st& CExoLinkedListTemplatedExoLocString_st::operator=(const CExoLinkedListTemplatedExoLocString_st&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedExoLocString_st::~CExoLinkedListTemplatedExoLocString_st()
{
    CExoLinkedListTemplatedExoLocString_st__CExoLinkedListTemplatedExoLocString_stDtor(this);
}

void CExoLinkedListTemplatedExoLocString_st__CExoLinkedListTemplatedExoLocString_stDtor(CExoLinkedListTemplatedExoLocString_st* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedExoLocString_st*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedExoLocString_st__CExoLinkedListTemplatedExoLocString_stDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
