#include "CScriptParseTreeNode.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

CScriptParseTreeNode::~CScriptParseTreeNode()
{
    CScriptParseTreeNode__CScriptParseTreeNodeDtor(this);
}

void CScriptParseTreeNode__CScriptParseTreeNodeDtor(CScriptParseTreeNode* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptParseTreeNode*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptParseTreeNode__CScriptParseTreeNodeDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

}

}
