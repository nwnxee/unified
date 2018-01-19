#include "CExoArrayListTemplatedCNWVisibilityNodePtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWVisibilityNode.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWVisibilityNodePtr::Add(CNWVisibilityNode* a0)
{
    return CExoArrayListTemplatedCNWVisibilityNodePtr__Add(this, a0);
}

void CExoArrayListTemplatedCNWVisibilityNodePtr__Add(CExoArrayListTemplatedCNWVisibilityNodePtr* thisPtr, CNWVisibilityNode* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWVisibilityNodePtr*, CNWVisibilityNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWVisibilityNodePtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
