#include "CScriptParseTreeNodeBlock.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CScriptParseTreeNodeBlock::CScriptParseTreeNodeBlock(const CScriptParseTreeNodeBlock&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

CScriptParseTreeNodeBlock& CScriptParseTreeNodeBlock::operator=(const CScriptParseTreeNodeBlock&)
{
    __builtin_trap(); // This is an auto-generated stub. You probably shouldn't use it.
}

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
