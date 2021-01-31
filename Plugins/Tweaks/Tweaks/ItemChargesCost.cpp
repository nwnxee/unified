#include "Tweaks/ItemChargesCost.hpp"


#include "API/CExoArrayList.hpp"
#include "API/CNWBaseItem.hpp"
#include "API/CNWBaseItemArray.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSItem.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Functions.hpp"

namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;

static int s_chargesCostBehavior;
static Hooks::Hook s_CalculateBaseCostsHook;

ItemChargesCost::ItemChargesCost(int mode)
{
    s_chargesCostBehavior = mode;
    if (mode < 1 || mode > 3)
    {
        LOG_INFO("Unknown value for NWNX_TWEAKS_ITEM_CHARGES_COST_MODE.");
        return;
    }
    s_CalculateBaseCostsHook = Hooks::HookFunction(Functions::_ZN8CNWSItem18CalculateBaseCostsEv,
                                            (void*)&CNWSItem__CalculateBaseCosts_sharedhook, Hooks::Order::Early);
}

void ItemChargesCost::CNWSItem__CalculateBaseCosts_sharedhook(CNWSItem* pThis)
{
    int32_t savedCharges = pThis->m_nNumCharges;

    switch (s_chargesCostBehavior)
    {
        case 1:
            pThis->m_nNumCharges = std::min(pThis->m_nNumCharges * 5, 250);
            break;
        case 2:
            pThis->m_nNumCharges = std::min(pThis->m_nNumCharges, 50) * 5 + std::max(pThis->m_nNumCharges - 50, 0) * 1.25;
            break;
        case 3:
            pThis->m_nNumCharges *= 5;
            break;
    }

    s_CalculateBaseCostsHook->CallOriginal<void>(pThis);

    pThis->m_nNumCharges = savedCharges;
}

}
