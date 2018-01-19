#include "CNWSPlayerCharSheetGUI.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CNWCreatureStatsUpdate.hpp"
#include "CNWSPlayer.hpp"

namespace NWNXLib {

namespace API {

uint32_t CNWSPlayerCharSheetGUI::ComputeCharacterSheetUpdateRequired(CNWSPlayer* a0)
{
    return CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired(this, a0);
}

void CNWSPlayerCharSheetGUI::SetCreatureDisplayed(uint32_t a0)
{
    return CNWSPlayerCharSheetGUI__SetCreatureDisplayed(this, a0);
}

uint32_t CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired(CNWSPlayerCharSheetGUI* thisPtr, CNWSPlayer* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CNWSPlayerCharSheetGUI*, CNWSPlayer*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerCharSheetGUI__ComputeCharacterSheetUpdateRequired);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CNWSPlayerCharSheetGUI__SetCreatureDisplayed(CNWSPlayerCharSheetGUI* thisPtr, uint32_t a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CNWSPlayerCharSheetGUI*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CNWSPlayerCharSheetGUI__SetCreatureDisplayed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
