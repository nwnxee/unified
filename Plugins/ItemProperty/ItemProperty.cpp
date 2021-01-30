#include "ItemProperty.hpp"

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

static ItemProperty::ItemProperty* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new ItemProperty::ItemProperty(services);
    return g_plugin;
}


namespace ItemProperty {

ItemProperty::ItemProperty(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(PackIP);
    REGISTER(UnpackIP);
    REGISTER(GetActiveProperty);

#undef REGISTER

}

ItemProperty::~ItemProperty()
{
}

ArgumentStack ItemProperty::PackIP(ArgumentStack&& args)
{
    CGameEffect *ip = new CGameEffect(true);

    auto propname     = Events::ExtractArgument<int32_t>(args);
    auto subtype      = Events::ExtractArgument<int32_t>(args);
    auto costtable    = Events::ExtractArgument<int32_t>(args);
    auto costvalue    = Events::ExtractArgument<int32_t>(args);
    auto param1       = Events::ExtractArgument<int32_t>(args);
    auto param1value  = Events::ExtractArgument<int32_t>(args);
    auto usesperday   = Events::ExtractArgument<int32_t>(args);
    auto chance       = Events::ExtractArgument<int32_t>(args);
    auto usable       = Events::ExtractArgument<int32_t>(args);
    auto spellId      = Events::ExtractArgument<int32_t>(args);

    auto creator      = Events::ExtractArgument<ObjectID>(args);
    auto tag          = Events::ExtractArgument<std::string>(args);

    ip->SetNumIntegersInitializeToNegativeOne(9);
    ip->m_bExpose = 1;
    ip->m_nType = API::Constants::EffectTrueType::ItemProperty;
    ip->m_nSubType = API::Constants::EffectDurationType::Permanent;
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
ArgumentStack ItemProperty::UnpackIP(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto ip = Events::ExtractArgument<CGameEffect*>(args);

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

ArgumentStack ItemProperty::GetActiveProperty(ArgumentStack&& args)
{
    auto objectId = Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(objectId != Constants::OBJECT_INVALID);

    auto *pGameObject = Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId);
    auto *pItem = Utils::AsNWSItem(pGameObject);
      ASSERT_OR_THROW(pItem);

    auto index = Events::ExtractArgument<int32_t>(args);
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

}
