#include "CExoArrayListTemplatedCNWSExpressionNodePtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSExpressionNode.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSExpressionNodePtr::Add(CNWSExpressionNode* a0)
{
    return CExoArrayListTemplatedCNWSExpressionNodePtr__Add(this, a0);
}

void CExoArrayListTemplatedCNWSExpressionNodePtr__Add(CExoArrayListTemplatedCNWSExpressionNodePtr* thisPtr, CNWSExpressionNode* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSExpressionNodePtr*, CNWSExpressionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSExpressionNodePtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
