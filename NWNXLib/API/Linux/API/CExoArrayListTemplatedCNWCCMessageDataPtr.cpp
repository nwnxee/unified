#include "CExoArrayListTemplatedCNWCCMessageDataPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWCCMessageData.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWCCMessageDataPtr::Add(CNWCCMessageData* a0)
{
    return CExoArrayListTemplatedCNWCCMessageDataPtr__Add(this, a0);
}

void CExoArrayListTemplatedCNWCCMessageDataPtr__Add(CExoArrayListTemplatedCNWCCMessageDataPtr* thisPtr, CNWCCMessageData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWCCMessageDataPtr*, CNWCCMessageData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWCCMessageDataPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
