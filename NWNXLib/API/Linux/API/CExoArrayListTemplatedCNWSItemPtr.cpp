#include "CExoArrayListTemplatedCNWSItemPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSItem.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSItemPtr::Add(CNWSItem* a0)
{
    return CExoArrayListTemplatedCNWSItemPtr__Add(this, a0);
}

void CExoArrayListTemplatedCNWSItemPtr__Add(CExoArrayListTemplatedCNWSItemPtr* thisPtr, CNWSItem* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSItemPtr*, CNWSItem*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSItemPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
