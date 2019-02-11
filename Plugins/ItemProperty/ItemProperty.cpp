#include "ItemProperty.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSObject.hpp"
#include "Utils.hpp"
#include "ViewPtr.hpp"

#include <string>
#include <functional>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<ItemProperty::ItemProperty> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "ItemProperty",
        "Miscellaneous itemproperty functions",
        "sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new ItemProperty::ItemProperty(params);
    return g_plugin;
}


namespace ItemProperty {

ItemProperty::ItemProperty(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&ItemProperty::func, this, std::placeholders::_1))

    REGISTER(PackIP);
    REGISTER(UnpackIP);

#undef REGISTER

}

ItemProperty::~ItemProperty()
{
}

ArgumentStack ItemProperty::PackIP(ArgumentStack&& args)
{
    ArgumentStack stack;
    API::CGameEffect *ip = new API::CGameEffect();

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

    auto creator      = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    auto tag          = Services::Events::ExtractArgument<std::string>(args);

    ip->SetNumIntegersInitializeToNegativeOne(9);
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

    Services::Events::InsertArgument(stack, ip);
    return stack;
}
ArgumentStack ItemProperty::UnpackIP(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto ip = Services::Events::ExtractArgument<API::CGameEffect*>(args);

    Services::Events::InsertArgument(stack, ip->GetString(0).CStr());
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)ip->m_oidCreator);
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
