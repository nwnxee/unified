#include "CNWSStats_SpellLikeAbility.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSStats_SpellLikeAbility::CNWSStats_SpellLikeAbility()
{
    CNWSStats_SpellLikeAbility__CNWSStats_SpellLikeAbilityCtor__0(this);
}

void CNWSStats_SpellLikeAbility__CNWSStats_SpellLikeAbilityCtor__0(CNWSStats_SpellLikeAbility* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStats_SpellLikeAbility*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStats_SpellLikeAbility__CNWSStats_SpellLikeAbilityCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
