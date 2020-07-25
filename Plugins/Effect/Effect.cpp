#include "Effect.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSObject.hpp"
#include "Utils.hpp"

#include <string>

using namespace NWNXLib;
using namespace NWNXLib::API;

static Effect::Effect* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Effect::Effect(services);
    return g_plugin;
}


namespace Effect {

Effect::Effect(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(PackEffect);
    REGISTER(UnpackEffect);
    REGISTER(SetEffectExpiredScript);
    REGISTER(GetEffectExpiredData);
    REGISTER(GetEffectExpiredCreator);

#undef REGISTER

}

Effect::~Effect()
{
}

ArgumentStack Effect::PackEffect(ArgumentStack&& args)
{
    CGameEffect *eff = new CGameEffect(true);

    eff->m_sCustomTag = Services::Events::ExtractArgument<std::string>(args).c_str();

    eff->m_oidParamObjectID[3] = Services::Events::ExtractArgument<ObjectID>(args);
    eff->m_oidParamObjectID[2] = Services::Events::ExtractArgument<ObjectID>(args);
    eff->m_oidParamObjectID[1] = Services::Events::ExtractArgument<ObjectID>(args);
    eff->m_oidParamObjectID[0] = Services::Events::ExtractArgument<ObjectID>(args);

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
    CGameEffect *pRightLink = Services::Events::ExtractArgument<CGameEffect*>(args);
    eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

    int32_t bLeftLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    CGameEffect *pLeftLink = Services::Events::ExtractArgument<CGameEffect*>(args);
    eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

    eff->m_nCasterLevel       = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_bShowIcon          = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_bExpose            = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nSpellId           = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_oidCreator         = Services::Events::ExtractArgument<ObjectID>(args);
    eff->m_nExpiryTimeOfDay   = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nExpiryCalendarDay = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_fDuration          = Services::Events::ExtractArgument<float>(args);
    eff->m_nSubType           = Services::Events::ExtractArgument<int32_t>(args);
    eff->m_nType              = Services::Events::ExtractArgument<int32_t>(args);

    if (bLeftLinkValid || bRightLinkValid)
        eff->UpdateLinked();

    return Services::Events::Arguments(eff);
}
ArgumentStack Effect::UnpackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto eff = Services::Events::ExtractArgument<CGameEffect*>(args);

    Services::Events::InsertArgument(stack, (int32_t)eff->m_nType);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nSubType);
    Services::Events::InsertArgument(stack, (float)eff->m_fDuration);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nExpiryCalendarDay);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nExpiryTimeOfDay);
    Services::Events::InsertArgument(stack, (ObjectID)eff->m_oidCreator);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nSpellId);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_bExpose);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_bShowIcon);
    Services::Events::InsertArgument(stack, (int32_t)eff->m_nCasterLevel);

    // The DestroyGameEffect at the end of this function will delete any linked effects
    // as well so we make a copy of the linked effects and send those for unpacking
    CGameEffect *leftLinkEff = nullptr;
    if (eff->m_pLinkLeft != nullptr)
    {
        leftLinkEff = new CGameEffect(true);
        leftLinkEff->CopyEffect(eff->m_pLinkLeft, 0);
    }
    Services::Events::InsertArgument(stack, leftLinkEff);
    Services::Events::InsertArgument(stack, eff->m_pLinkLeft != nullptr);

    CGameEffect *rightLinkEff = nullptr;
    if (eff->m_pLinkRight != nullptr)
    {
        rightLinkEff = new CGameEffect(true);
        rightLinkEff->CopyEffect(eff->m_pLinkRight, 0);
    }
    Services::Events::InsertArgument(stack, rightLinkEff);
    Services::Events::InsertArgument(stack, eff->m_pLinkRight != nullptr);

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

    Services::Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[0]);
    Services::Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[1]);
    Services::Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[2]);
    Services::Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[3]);

    Services::Events::InsertArgument(stack, std::string(eff->m_sCustomTag.CStr()));

    Utils::DestroyGameEffect(eff);
    return stack;
}

ArgumentStack Effect::SetEffectExpiredScript(ArgumentStack&& args)
{
    static bool bOnEffectRemovedHook;

    if (!bOnEffectRemovedHook)
    {
        GetServices()->m_hooks->RequestSharedHook<API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect, int32_t>(
            +[](bool before, CNWSEffectListHandler*, CNWSObject* pObject, CGameEffect* pEffect) -> void
            {
                if (before)
                {
                    CExoString &sScriptName = pEffect->m_sParamString[4];
                    if (!sScriptName.IsEmpty())
                    {
                        g_plugin->m_effectExpiredData = std::string(pEffect->m_sParamString[5].CStr());
                        g_plugin->m_effectExpiredCreator = pEffect->m_oidCreator;

                        LOG_DEBUG("Running script '%s' on object '%x' with data '%s'",
                            sScriptName.CStr(), pObject->m_idSelf, g_plugin->m_effectExpiredData);

                        ++g_plugin->m_effectExpiredDepth;
                        Globals::VirtualMachine()->RunScript(&sScriptName, pObject->m_idSelf, 1);
                        --g_plugin->m_effectExpiredDepth;
                    }
                }
            });

        bOnEffectRemovedHook = true;
    }

    auto effect = Services::Events::ExtractArgument<CGameEffect*>(args);

    // Script name
    effect->m_sParamString[4] = Services::Events::ExtractArgument<std::string>(args).c_str();
    // Data
    effect->m_sParamString[5] = Services::Events::ExtractArgument<std::string>(args).c_str();

    return Services::Events::Arguments(effect);
}

ArgumentStack Effect::GetEffectExpiredData(ArgumentStack&&)
{
    if (g_plugin->m_effectExpiredDepth == 0)
    {
        throw std::runtime_error("Attempted to get effect expired data in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_effectExpiredData);
}

ArgumentStack Effect::GetEffectExpiredCreator(ArgumentStack&&)
{
    if (g_plugin->m_effectExpiredDepth == 0)
    {
        throw std::runtime_error("Attempted to get effect expired creator in an invalid context.");
    }

    return Services::Events::Arguments(g_plugin->m_effectExpiredCreator);
}

}
