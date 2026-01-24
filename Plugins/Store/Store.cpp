#include "nwnx.hpp"

#include "API/CNWSStore.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_EXPORT ArgumentStack GetIsRestrictedBuyItem(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nBaseItemID = args.extract<int32_t>();
        return pStore->GetIsRestrictedBuyItem(nBaseItemID);
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetBlackMarketMarkDown(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_nBlackMarketMarkDown;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetBlackMarketMarkDown(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
          ASSERT_OR_THROW(nValue >= 0);
          ASSERT_OR_THROW(nValue <= 100);
        pStore->m_nBlackMarketMarkDown = nValue;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMarkDown(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_nMarkDown;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetMarkDown(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
          ASSERT_OR_THROW(nValue >= 0);
          ASSERT_OR_THROW(nValue <= 100);
        pStore->m_nMarkDown = nValue;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMarkUp(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_nMarkUp;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetMarkUp(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
          ASSERT_OR_THROW(nValue >= 1);
          ASSERT_OR_THROW(nValue <= 1000);
        pStore->m_nMarkUp = nValue;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetCurrentCustomersCount(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_aCurrentCustomers.num;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack GetBlackMarket(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_bBlackMarket;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetBlackMarket(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
        pStore->m_bBlackMarket = nValue;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetGold(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_iGold;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetGold(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
        pStore->m_iGold = nValue;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetIdentifyCost(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_iIdentifyCost;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetIdentifyCost(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
        pStore->m_iIdentifyCost = nValue;
    }
    return {};
}

NWNX_EXPORT ArgumentStack GetMaxBuyPrice(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        return pStore->m_iMaxBuyPrice;
    }
    return -1;
}

NWNX_EXPORT ArgumentStack SetMaxBuyPrice(ArgumentStack&& args)
{
    if (auto *pStore = Utils::PopStore(args))
    {
        const auto nValue = args.extract<int32_t>();
        pStore->m_iMaxBuyPrice = nValue;
    }
    return {};
}
