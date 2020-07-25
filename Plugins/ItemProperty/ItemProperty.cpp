#include "ItemProperty.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "Utils.hpp"

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
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(PackIP);
    REGISTER(UnpackIP);

#undef REGISTER

}

ItemProperty::~ItemProperty()
{
}

ArgumentStack ItemProperty::PackIP(ArgumentStack&& args)
{
    CGameEffect *ip = new CGameEffect(true);

    auto propname     = Services::Events::ExtractArgument<int32_t>(args);
    auto subtype      = Services::Events::ExtractArgument<int32_t>(args);
    auto costtable    = Services::Events::ExtractArgument<int32_t>(args);
    auto costvalue    = Services::Events::ExtractArgument<int32_t>(args);
    auto param1       = Services::Events::ExtractArgument<int32_t>(args);
    auto param1value  = Services::Events::ExtractArgument<int32_t>(args);
    auto usesperday   = Services::Events::ExtractArgument<int32_t>(args);
    auto chance       = Services::Events::ExtractArgument<int32_t>(args);
    auto usable       = Services::Events::ExtractArgument<int32_t>(args);
    auto spellId      = Services::Events::ExtractArgument<int32_t>(args);

    auto creator      = Services::Events::ExtractArgument<ObjectID>(args);
    auto tag          = Services::Events::ExtractArgument<std::string>(args);

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

    return Services::Events::Arguments(ip);
}
ArgumentStack ItemProperty::UnpackIP(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto ip = Services::Events::ExtractArgument<CGameEffect*>(args);

    Services::Events::InsertArgument(stack, ip->GetString(0).CStr());
    Services::Events::InsertArgument(stack, (ObjectID)ip->m_oidCreator);
    Services::Events::InsertArgument(stack, (int32_t)ip->m_nSpellId);
    Services::Events::InsertArgument(stack, ip->GetInteger(8));
    Services::Events::InsertArgument(stack, ip->GetInteger(7));
    Services::Events::InsertArgument(stack, ip->GetInteger(6));
    Services::Events::InsertArgument(stack, ip->GetInteger(5));
    Services::Events::InsertArgument(stack, ip->GetInteger(4));
    Services::Events::InsertArgument(stack, ip->GetInteger(3));
    Services::Events::InsertArgument(stack, ip->GetInteger(2));
    Services::Events::InsertArgument(stack, ip->GetInteger(1));
    Services::Events::InsertArgument(stack, ip->GetInteger(0));

    Utils::DestroyGameEffect(ip);
    return stack;
}

}
