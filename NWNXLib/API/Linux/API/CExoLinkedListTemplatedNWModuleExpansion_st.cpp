#include "CExoLinkedListTemplatedNWModuleExpansion_st.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedNWModuleExpansion_st::CExoLinkedListTemplatedNWModuleExpansion_st()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedNWModuleExpansion_st::CExoLinkedListTemplatedNWModuleExpansion_st(const CExoLinkedListTemplatedNWModuleExpansion_st&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedNWModuleExpansion_st& CExoLinkedListTemplatedNWModuleExpansion_st::operator=(const CExoLinkedListTemplatedNWModuleExpansion_st&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedNWModuleExpansion_st::~CExoLinkedListTemplatedNWModuleExpansion_st()
{
    CExoLinkedListTemplatedNWModuleExpansion_st__CExoLinkedListTemplatedNWModuleExpansion_stDtor(this);
}

void CExoLinkedListTemplatedNWModuleExpansion_st__CExoLinkedListTemplatedNWModuleExpansion_stDtor(CExoLinkedListTemplatedNWModuleExpansion_st* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedNWModuleExpansion_st*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedNWModuleExpansion_st__CExoLinkedListTemplatedNWModuleExpansion_stDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
