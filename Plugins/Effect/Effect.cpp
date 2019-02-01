#include "Effect.hpp"

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

static ViewPtr<Effect::Effect> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Effect",
        "Miscellaneous Effectity functions",
        "sherincall",
        "sherincall@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Effect::Effect(params);
    return g_plugin;
}


namespace Effect {

Effect::Effect(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Effect::func, this, std::placeholders::_1))

    REGISTER(PackEffect);
    REGISTER(UnpackEffect);
    REGISTER(SetOnEffectRemovedScript);

#undef REGISTER

}

Effect::~Effect()
{
}

ArgumentStack Effect::PackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    API::CGameEffect *eff = new API::CGameEffect();

    eff->m_sCustomTag = Services::Events::ExtractArgument<std::string>(args).c_str();

    eff->m_oidParamObjectID[3] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_oidParamObjectID[2] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_oidParamObjectID[1] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_oidParamObjectID[0] = Services::Events::ExtractArgument<API::Types::ObjectID>(args);

    eff->m_sParamString[5] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[4] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[3] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[2] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[1] = Services::Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[0] = Services::Events::ExtractArgument<std::string>(args).c_str();

    eff->m_nParamFloat[3] = Services::Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[2] = Services::Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[1] = Services::Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[0] = Services::Events::ExtractArgument<float>(args);

    eff->SetNumIntegers(8); // allocate array
    eff->m_nParamInteger[7] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[6] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[5] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[4] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[3] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[2] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[1] = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[0] = Services::Events::ExtractArgument<int32_t>(args);
    // Overwrite num integers from 8
    eff->m_nNumIntegers = Services::Events::ExtractArgument<int32_t>(args);

    int32_t bRightLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    API::CGameEffect *pRightLink = Services::Events::ExtractArgument<API::CGameEffect*>(args);
    eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

    int32_t bLeftLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    API::CGameEffect *pLeftLink = Services::Events::ExtractArgument<API::CGameEffect*>(args);
    eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

    eff->m_nCasterLevel       = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_bShowIcon          = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_bExpose            = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nSpellId           = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_oidCreator         = Services::Events::ExtractArgument<API::Types::ObjectID>(args);
    eff->m_nExpiryTimeOfDay   = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nExpiryCalendarDay = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_fDuration          = Services::Events::ExtractArgument<float>(args);
    eff->m_nSubType           = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nType              = Services::Events::ExtractArgument<int32_t>(args);

    if (bLeftLinkValid || bRightLinkValid)
        eff->UpdateLinked();

    Services::Events::InsertArgument(stack, eff);
    return stack;
}
ArgumentStack Effect::UnpackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto eff = Services::Events::ExtractArgument<API::CGameEffect*>(args);

    Services::Events::InsertArgument(stack, (int32_t)eff->m_nType);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nSubType);
    Services::Events::InsertArgument(stack, (float)eff->m_fDuration);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nExpiryCalendarDay);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nExpiryTimeOfDay);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidCreator);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nSpellId);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_bExpose);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_bShowIcon);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nCasterLevel);
    Services::Events::InsertArgument(stack, (API::CGameEffect*)eff->m_pLinkLeft);
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_pLinkLeft != nullptr));
    Services::Events::InsertArgument(stack, (API::CGameEffect*)eff->m_pLinkRight);
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_pLinkRight != nullptr));

    Services::Events::InsertArgument(stack, (int32_t)eff->m_nNumIntegers);
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 0 ? eff->m_nParamInteger[0] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 1 ? eff->m_nParamInteger[1] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 2 ? eff->m_nParamInteger[2] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 3 ? eff->m_nParamInteger[3] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 4 ? eff->m_nParamInteger[4] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 5 ? eff->m_nParamInteger[5] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 6 ? eff->m_nParamInteger[6] : -1));
    Services::Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 7 ? eff->m_nParamInteger[7] : -1));

    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[0]);
    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[1]);
    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[2]);
    Services::Events::InsertArgument(stack, (float)eff->m_nParamFloat[3]);

    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[0].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[1].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[2].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[3].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[4].CStr()));
    Services::Events::InsertArgument(stack, std::string(eff->m_sParamString[5].CStr()));

    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[0]);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[1]);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[2]);
    Services::Events::InsertArgument(stack, (API::Types::ObjectID)eff->m_oidParamObjectID[3]);

    Services::Events::InsertArgument(stack, std::string(eff->m_sCustomTag.CStr()));
    //delete eff;
    Utils::DestroyGameEffect(eff);
    return stack;
}

ArgumentStack Effect::SetOnEffectRemovedScript(ArgumentStack&& args)
{
    static bool bOnEffectRemovedHook;

    if (!bOnEffectRemovedHook)
    {
        GetServices()->m_hooks->RequestSharedHook<API::Functions::CNWSEffectListHandler__OnEffectRemoved, int32_t>(
            +[](Services::Hooks::CallType type, CNWSEffectListHandler*, CNWSObject* pObject, CGameEffect* pEffect) -> void
            {
                if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
                {
                    CExoString &sScriptName = pEffect->m_sParamString[2];
                    if (!sScriptName.IsEmpty())
                    {
                        LOG_DEBUG("Running script '%s' on object '%x' for expired effect of type '%u'", sScriptName.CStr(), pObject->m_idSelf, pEffect->m_nType);

                        Globals::VirtualMachine()->RunScript(&sScriptName, pObject->m_idSelf, 1);
                    }
                }
            });

        bOnEffectRemovedHook = true;
    }

    ArgumentStack stack;

    auto effect = Services::Events::ExtractArgument<API::CGameEffect*>(args);

    effect->m_sParamString[2] = Services::Events::ExtractArgument<std::string>(args).c_str();

    Services::Events::InsertArgument(stack, effect);

    return stack;
}

}
