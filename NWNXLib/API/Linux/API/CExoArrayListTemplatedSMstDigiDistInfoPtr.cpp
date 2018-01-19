#include "CExoArrayListTemplatedSMstDigiDistInfoPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "SMstDigiDistInfo.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedSMstDigiDistInfoPtr::Remove(SMstDigiDistInfo* a0)
{
    return CExoArrayListTemplatedSMstDigiDistInfoPtr__Remove(this, a0);
}

void CExoArrayListTemplatedSMstDigiDistInfoPtr__Remove(CExoArrayListTemplatedSMstDigiDistInfoPtr* thisPtr, SMstDigiDistInfo* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedSMstDigiDistInfoPtr*, SMstDigiDistInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedSMstDigiDistInfoPtr__Remove);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
