#include "CExoLinkedListTemplatedCNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCNWSObjectActionNode::~CExoLinkedListTemplatedCNWSObjectActionNode()
{
    CExoLinkedListTemplatedCNWSObjectActionNode__CExoLinkedListTemplatedCNWSObjectActionNodeDtor(this);
}

void CExoLinkedListTemplatedCNWSObjectActionNode__CExoLinkedListTemplatedCNWSObjectActionNodeDtor(CExoLinkedListTemplatedCNWSObjectActionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCNWSObjectActionNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCNWSObjectActionNode__CExoLinkedListTemplatedCNWSObjectActionNodeDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
