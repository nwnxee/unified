#include "CScriptParseTreeNodeBlock.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CScriptParseTreeNodeBlock::CScriptParseTreeNodeBlock()
{
    CScriptParseTreeNodeBlock__CScriptParseTreeNodeBlockCtor(this);
}

void CScriptParseTreeNodeBlock__CScriptParseTreeNodeBlockCtor(CScriptParseTreeNodeBlock* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CScriptParseTreeNodeBlock*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CScriptParseTreeNodeBlock__CScriptParseTreeNodeBlockCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
