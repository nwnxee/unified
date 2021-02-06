#include "nwnx.hpp"

#include "API/CNWRules.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSInventory.hpp"
#include "API/CNWSItem.hpp"
#include "API/CTwoDimArrays.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


void FixArmorDexBonusUnderOne() __attribute__((constructor));
void FixArmorDexBonusUnderOne()
{
    if (!Config::Get<bool>("FIX_ARMOR_DEX_BONUS_UNDER_ONE", false))
        return;

    LOG_INFO("Allowing armors with max DEX bonus under 1.");

    static Hooks::Hook s_ReplacedFunc = Hooks::HookFunction(Functions::_ZN17CNWSCreatureStats9GetDEXModEi,
    (void*)+[](CNWSCreatureStats *pThis, int32_t bArmorDexCap) -> uint8_t
    {
        auto nDexAC = pThis->m_nDexterityModifier;

        if (bArmorDexCap)
        {
            auto pArmor = pThis->m_pBaseCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Chest);
            int nTempValue = 0;
            if (pArmor && (nTempValue = pArmor->ComputeArmorClass()) > 0)
            {
                Globals::Rules()->m_p2DArrays->m_pArmorTable->GetINTEntry(nTempValue, CExoString("DEXBONUS"), &nTempValue);
                if (nTempValue < nDexAC)
                    nDexAC = static_cast<char>(nTempValue);
            }
        }

        return nDexAC;
    }, Hooks::Order::Final);
}

}
