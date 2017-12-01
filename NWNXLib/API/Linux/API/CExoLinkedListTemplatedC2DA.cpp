#include "CExoLinkedListTemplatedC2DA.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedC2DA::CExoLinkedListTemplatedC2DA()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedC2DA::CExoLinkedListTemplatedC2DA(const CExoLinkedListTemplatedC2DA&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedC2DA& CExoLinkedListTemplatedC2DA::operator=(const CExoLinkedListTemplatedC2DA&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedC2DA::~CExoLinkedListTemplatedC2DA()
{
    CExoLinkedListTemplatedC2DA__CExoLinkedListTemplatedC2DADtor(this);
}

void CExoLinkedListTemplatedC2DA__CExoLinkedListTemplatedC2DADtor(CExoLinkedListTemplatedC2DA* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedC2DA*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedC2DA__CExoLinkedListTemplatedC2DADtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
