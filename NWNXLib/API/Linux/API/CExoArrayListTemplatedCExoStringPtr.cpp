#include "CExoArrayListTemplatedCExoStringPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCExoStringPtr::CExoArrayListTemplatedCExoStringPtr(const CExoArrayListTemplatedCExoStringPtr& a0)
{
    CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrCtor(this, a0);
}

void CExoArrayListTemplatedCExoStringPtr::Add(CExoString* a0)
{
    return CExoArrayListTemplatedCExoStringPtr__Add(this, a0);
}

void CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrCtor(CExoArrayListTemplatedCExoStringPtr* thisPtr, const CExoArrayListTemplatedCExoStringPtr& a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoStringPtr*, const CExoArrayListTemplatedCExoStringPtr&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0);
}

void CExoArrayListTemplatedCExoStringPtr__Add(CExoArrayListTemplatedCExoStringPtr* thisPtr, CExoString* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoStringPtr*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoStringPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
