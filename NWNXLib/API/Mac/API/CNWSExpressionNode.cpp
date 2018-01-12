#include "CNWSExpressionNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSExpressionNode::CNWSExpressionNode()
{
    CNWSExpressionNode__CNWSExpressionNodeCtor__0(this);
}

CNWSExpressionNode::~CNWSExpressionNode()
{
    CNWSExpressionNode__CNWSExpressionNodeDtor__0(this);
}

void CNWSExpressionNode__CNWSExpressionNodeCtor__0(CNWSExpressionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSExpressionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpressionNode__CNWSExpressionNodeCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSExpressionNode__CNWSExpressionNodeDtor__0(CNWSExpressionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSExpressionNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSExpressionNode__CNWSExpressionNodeDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
