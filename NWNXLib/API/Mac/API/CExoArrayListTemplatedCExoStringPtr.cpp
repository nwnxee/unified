#include "CExoArrayListTemplatedCExoStringPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CExoArrayListTemplatedCExoStringPtr::~CExoArrayListTemplatedCExoStringPtr()
{
    CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrDtor(this);
}

void CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrDtor(CExoArrayListTemplatedCExoStringPtr* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCExoStringPtr*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCExoStringPtr__CExoArrayListTemplatedCExoStringPtrDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
