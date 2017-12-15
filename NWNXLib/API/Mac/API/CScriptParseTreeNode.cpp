#include "CScriptParseTreeNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CScriptParseTreeNode::CScriptParseTreeNode()
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptParseTreeNode::CScriptParseTreeNode(const CScriptParseTreeNode&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptParseTreeNode& CScriptParseTreeNode::operator=(const CScriptParseTreeNode&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptParseTreeNode::~CScriptParseTreeNode()
{
    CScriptParseTreeNode__CScriptParseTreeNodeDtor(this);
}

void CScriptParseTreeNode::Clean()
{
    return CScriptParseTreeNode__Clean(this);
}

void CScriptParseTreeNode__CScriptParseTreeNodeDtor(CScriptParseTreeNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptParseTreeNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptParseTreeNode__CScriptParseTreeNodeDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

void CScriptParseTreeNode__Clean(CScriptParseTreeNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptParseTreeNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptParseTreeNode__Clean);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

}

}
