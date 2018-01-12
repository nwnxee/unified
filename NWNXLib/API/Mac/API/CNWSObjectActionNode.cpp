#include "CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSObjectActionNode::CNWSObjectActionNode()
{
    CNWSObjectActionNode__CNWSObjectActionNodeCtor__0(this);
}

CNWSObjectActionNode::~CNWSObjectActionNode()
{
    CNWSObjectActionNode__CNWSObjectActionNodeDtor__0(this);
}

void CNWSObjectActionNode__CNWSObjectActionNodeCtor__0(CNWSObjectActionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObjectActionNode__CNWSObjectActionNodeCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSObjectActionNode__CNWSObjectActionNodeDtor__0(CNWSObjectActionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObjectActionNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObjectActionNode__CNWSObjectActionNodeDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
