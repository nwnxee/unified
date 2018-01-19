#include "CNWSStats_Spell.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

namespace NWNXLib {

namespace API {

CNWSStats_Spell::CNWSStats_Spell()
{
    CNWSStats_Spell__CNWSStats_SpellCtor__0(this);
}

void CNWSStats_Spell__CNWSStats_SpellCtor__0(CNWSStats_Spell* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSStats_Spell*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSStats_Spell__CNWSStats_SpellCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

}

}
