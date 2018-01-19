#include "CExoArrayListTemplatedCNWSSpellScriptDataPtr.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSSpellScriptData.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSSpellScriptDataPtr::Add(CNWSSpellScriptData* a0)
{
    return CExoArrayListTemplatedCNWSSpellScriptDataPtr__Add(this, a0);
}

void CExoArrayListTemplatedCNWSSpellScriptDataPtr__Add(CExoArrayListTemplatedCNWSSpellScriptDataPtr* thisPtr, CNWSSpellScriptData* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSSpellScriptDataPtr*, CNWSSpellScriptData*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSSpellScriptDataPtr__Add);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
