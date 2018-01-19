#include "CExoArrayListTemplatedCNWSStats_SpellLikeAbility.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWSStats_SpellLikeAbility.hpp"

namespace NWNXLib {

namespace API {

void CExoArrayListTemplatedCNWSStats_SpellLikeAbility::Allocate(int32_t a0)
{
    return CExoArrayListTemplatedCNWSStats_SpellLikeAbility__Allocate(this, a0);
}

void CExoArrayListTemplatedCNWSStats_SpellLikeAbility__Allocate(CExoArrayListTemplatedCNWSStats_SpellLikeAbility* thisPtr, int32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoArrayListTemplatedCNWSStats_SpellLikeAbility*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoArrayListTemplatedCNWSStats_SpellLikeAbility__Allocate);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
