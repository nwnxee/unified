#include "CExoLinkedListTemplatedNWAreaExpansion_st.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedNWAreaExpansion_st::CExoLinkedListTemplatedNWAreaExpansion_st()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedNWAreaExpansion_st::CExoLinkedListTemplatedNWAreaExpansion_st(const CExoLinkedListTemplatedNWAreaExpansion_st&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedNWAreaExpansion_st& CExoLinkedListTemplatedNWAreaExpansion_st::operator=(const CExoLinkedListTemplatedNWAreaExpansion_st&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedNWAreaExpansion_st::~CExoLinkedListTemplatedNWAreaExpansion_st()
{
    CExoLinkedListTemplatedNWAreaExpansion_st__CExoLinkedListTemplatedNWAreaExpansion_stDtor(this);
}

void CExoLinkedListTemplatedNWAreaExpansion_st__CExoLinkedListTemplatedNWAreaExpansion_stDtor(CExoLinkedListTemplatedNWAreaExpansion_st* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedNWAreaExpansion_st*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedNWAreaExpansion_st__CExoLinkedListTemplatedNWAreaExpansion_stDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
