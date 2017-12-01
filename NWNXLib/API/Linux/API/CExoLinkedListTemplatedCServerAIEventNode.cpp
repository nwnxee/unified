#include "CExoLinkedListTemplatedCServerAIEventNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListInternal.hpp"

namespace NWNXLib {

namespace API {

CExoLinkedListTemplatedCServerAIEventNode::CExoLinkedListTemplatedCServerAIEventNode()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCServerAIEventNode::CExoLinkedListTemplatedCServerAIEventNode(const CExoLinkedListTemplatedCServerAIEventNode&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCServerAIEventNode& CExoLinkedListTemplatedCServerAIEventNode::operator=(const CExoLinkedListTemplatedCServerAIEventNode&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CExoLinkedListTemplatedCServerAIEventNode::~CExoLinkedListTemplatedCServerAIEventNode()
{
    CExoLinkedListTemplatedCServerAIEventNode__CExoLinkedListTemplatedCServerAIEventNodeDtor(this);
}

void CExoLinkedListTemplatedCServerAIEventNode__CExoLinkedListTemplatedCServerAIEventNodeDtor(CExoLinkedListTemplatedCServerAIEventNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoLinkedListTemplatedCServerAIEventNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoLinkedListTemplatedCServerAIEventNode__CExoLinkedListTemplatedCServerAIEventNodeDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
