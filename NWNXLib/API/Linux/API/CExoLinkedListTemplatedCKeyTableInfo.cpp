#include "CExoLinkedListTemplatedCKeyTableInfo.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCKeyTableInfo::CExoLinkedListTemplatedCKeyTableInfo()
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCKeyTableInfo::CExoLinkedListTemplatedCKeyTableInfo(const CExoLinkedListTemplatedCKeyTableInfo&)
{
     // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCKeyTableInfo& CExoLinkedListTemplatedCKeyTableInfo::operator=(const CExoLinkedListTemplatedCKeyTableInfo&)
{
    return *this; // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCKeyTableInfo::~CExoLinkedListTemplatedCKeyTableInfo()
{
    CExoLinkedListTemplatedCKeyTableInfo__CExoLinkedListTemplatedCKeyTableInfoDtor(this);
}

void CExoLinkedListTemplatedCKeyTableInfo__CExoLinkedListTemplatedCKeyTableInfoDtor(CExoLinkedListTemplatedCKeyTableInfo* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCKeyTableInfo*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCKeyTableInfo__CExoLinkedListTemplatedCKeyTableInfoDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
