#include "CServerAIEventNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CResGFF.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

int32_t CServerAIEventNode::LoadNode(CResGFF* a0, CResStruct* a1)
{
    return CServerAIEventNode__LoadNode(this, a0, a1);
}

int32_t CServerAIEventNode::SaveNode(CResGFF* a0, CResStruct* a1)
{
    return CServerAIEventNode__SaveNode(this, a0, a1);
}

int32_t CServerAIEventNode__LoadNode(CServerAIEventNode* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIEventNode*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIEventNode__LoadNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CServerAIEventNode__SaveNode(CServerAIEventNode* thisPtr, CResGFF* a0, CResStruct* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CServerAIEventNode*, CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CServerAIEventNode__SaveNode);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
