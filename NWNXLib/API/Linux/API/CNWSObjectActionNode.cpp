#include "CNWSObjectActionNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSObjectActionNode::CNWSObjectActionNode()
{
    CNWSObjectActionNode__CNWSObjectActionNodeCtor(this);
}

CNWSObjectActionNode::~CNWSObjectActionNode()
{
    CNWSObjectActionNode__CNWSObjectActionNodeDtor(this);
}

void CNWSObjectActionNode__CNWSObjectActionNodeCtor(CNWSObjectActionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObjectActionNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObjectActionNode__CNWSObjectActionNodeCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CNWSObjectActionNode__CNWSObjectActionNodeDtor(CNWSObjectActionNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSObjectActionNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSObjectActionNode__CNWSObjectActionNodeDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
