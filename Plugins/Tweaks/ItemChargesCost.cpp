#include "nwnx.hpp"

#include "API/CNWItemProperty.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSItem.hpp"


namespace Tweaks {

using namespace NWNXLib;
using namespace NWNXLib::API;


static int s_ChargesCostBehavior;

void ItemChargesCost() __attribute__((constructor));
void ItemChargesCost()
{
    s_ChargesCostBehavior = Config::Get<int>("ITEM_CHARGES_COST_MODE", 0);

    if (s_ChargesCostBehavior == 0)
        return;
    else if (s_ChargesCostBehavior < 0 || s_ChargesCostBehavior > 3)
    {
        LOG_INFO("Unknown value for NWNX_TWEAKS_ITEM_CHARGES_COST_MODE.");
        return;
    }

    LOG_INFO("Changing cost for items with charges.");

    static Hooks::Hook s_CalculateBaseCostsHook = Hooks::HookFunction(&CNWSItem::CalculateBaseCosts,
        +[](CNWSItem* pThis) -> void
        {
            int32_t savedCharges = pThis->m_nNumCharges;

            switch (s_ChargesCostBehavior)
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

                default:
                    break;
            }

            s_CalculateBaseCostsHook->CallOriginal<void>(pThis);

            pThis->m_nNumCharges = savedCharges;
        }, Hooks::Order::Early);
}

}
