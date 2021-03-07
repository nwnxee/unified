#include "nwnx.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSItem.hpp"

#include <string>

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_EXPORT ArgumentStack PackIP(ArgumentStack&& args)
{
    CGameEffect *ip = new CGameEffect(true);

    auto propname     = args.extract<int32_t>();
    auto subtype      = args.extract<int32_t>();
    auto costtable    = args.extract<int32_t>();
    auto costvalue    = args.extract<int32_t>();
    auto param1       = args.extract<int32_t>();
    auto param1value  = args.extract<int32_t>();
    auto usesperday   = args.extract<int32_t>();
    auto chance       = args.extract<int32_t>();
    auto usable       = args.extract<int32_t>();
    auto spellId      = args.extract<int32_t>();

    auto creator      = args.extract<ObjectID>();
    auto tag          = args.extract<std::string>();

    ip->SetNumIntegersInitializeToNegativeOne(9);
    ip->m_bExpose = 1;
    ip->m_nType = Constants::EffectTrueType::ItemProperty;
    ip->m_nSubType = Constants::EffectDurationType::Permanent;
    ip->m_oidCreator = creator;
    ip->m_nSpellId = spellId;

    ip->SetInteger(0, propname);
    ip->SetInteger(1, subtype);
    ip->SetInteger(2, costtable);
    ip->SetInteger(3, costvalue);
    ip->SetInteger(4, param1);
    ip->SetInteger(5, param1value);
    ip->SetInteger(6, usesperday);
    ip->SetInteger(7, chance);
    ip->SetInteger(8, usable);
    ip->SetString(0, tag.c_str());

    return Events::Arguments(ip);
}
NWNX_EXPORT ArgumentStack UnpackIP(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto ip = args.extract<CGameEffect*>();

    Events::InsertArgument(stack, ip->GetString(0).CStr());
    Events::InsertArgument(stack, (ObjectID)ip->m_oidCreator);
    Events::InsertArgument(stack, (int32_t)ip->m_nSpellId);
    Events::InsertArgument(stack, ip->GetInteger(8));
    Events::InsertArgument(stack, ip->GetInteger(7));
    Events::InsertArgument(stack, ip->GetInteger(6));
    Events::InsertArgument(stack, ip->GetInteger(5));
    Events::InsertArgument(stack, ip->GetInteger(4));
    Events::InsertArgument(stack, ip->GetInteger(3));
    Events::InsertArgument(stack, ip->GetInteger(2));
    Events::InsertArgument(stack, ip->GetInteger(1));
    Events::InsertArgument(stack, ip->GetInteger(0));

    Utils::DestroyGameEffect(ip);
    return stack;
}

NWNX_EXPORT ArgumentStack GetActiveProperty(ArgumentStack&& args)
{
    auto objectId = args.extract<ObjectID>();
      ASSERT_OR_THROW(objectId != Constants::OBJECT_INVALID);

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
      ASSERT_OR_THROW(pItem);

    auto index = args.extract<int32_t>();
    auto ip = pItem->GetActiveProperty(index);
      ASSERT_OR_THROW(ip);

    ArgumentStack stack;

    Events::InsertArgument(stack, ip->m_sCustomTag.CStr());
    Events::InsertArgument(stack, ip->m_bUseable);
    Events::InsertArgument(stack, ip->m_nChanceOfAppearing);
    Events::InsertArgument(stack, ip->m_nUsesPerDay);
    Events::InsertArgument(stack, ip->m_nParam1Value);
    Events::InsertArgument(stack, ip->m_nParam1);
    Events::InsertArgument(stack, ip->m_nCostTableValue);
    Events::InsertArgument(stack, ip->m_nCostTable);
    Events::InsertArgument(stack, ip->m_nSubType);
    Events::InsertArgument(stack, ip->m_nPropertyName);
    return stack;
}
