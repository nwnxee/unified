#include "CExoArrayListTemplatedCCombatInformationNodePtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CCombatInformationNode.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCCombatInformationNodePtr::Add(CCombatInformationNode* a0)
{
    return CExoArrayListTemplatedCCombatInformationNodePtr__Add(this, a0);
}

void CExoArrayListTemplatedCCombatInformationNodePtr__Add(CExoArrayListTemplatedCCombatInformationNodePtr* thisPtr, CCombatInformationNode* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCCombatInformationNodePtr*, CCombatInformationNode*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCCombatInformationNodePtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
