#include "Effect.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSObject.hpp"

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
    Events::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(PackEffect);
    REGISTER(UnpackEffect);
    REGISTER(SetEffectExpiredScript);
    REGISTER(GetEffectExpiredData);
    REGISTER(GetEffectExpiredCreator);
    REGISTER(ReplaceEffect);

#undef REGISTER

}

Effect::~Effect()
{
}

ArgumentStack Effect::PackEffect(ArgumentStack&& args)
{
    CGameEffect *eff = new CGameEffect(true);

    eff->m_sCustomTag = Events::ExtractArgument<std::string>(args).c_str();

    auto vector1z = Events::ExtractArgument<float>(args);
    auto vector1y = Events::ExtractArgument<float>(args);
    auto vector1x = Events::ExtractArgument<float>(args);
    eff->m_vParamVector[1] = {vector1x, vector1y, vector1z};

    auto vector0z = Events::ExtractArgument<float>(args);
    auto vector0y = Events::ExtractArgument<float>(args);
    auto vector0x = Events::ExtractArgument<float>(args);
    eff->m_vParamVector[0] = {vector0x, vector0y, vector0z};

    eff->m_oidParamObjectID[3] = Events::ExtractArgument<ObjectID>(args);
    eff->m_oidParamObjectID[2] = Events::ExtractArgument<ObjectID>(args);
    eff->m_oidParamObjectID[1] = Events::ExtractArgument<ObjectID>(args);
    eff->m_oidParamObjectID[0] = Events::ExtractArgument<ObjectID>(args);

    eff->m_sParamString[5] = Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[4] = Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[3] = Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[2] = Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[1] = Events::ExtractArgument<std::string>(args).c_str();
    eff->m_sParamString[0] = Events::ExtractArgument<std::string>(args).c_str();

    eff->m_nParamFloat[3] = Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[2] = Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[1] = Events::ExtractArgument<float>(args);
    eff->m_nParamFloat[0] = Events::ExtractArgument<float>(args);

    eff->SetNumIntegers(8); // allocate array
    eff->m_nParamInteger[7] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[6] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[5] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[4] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[3] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[2] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[1] = Events::ExtractArgument<int32_t>(args);
    eff->m_nParamInteger[0] = Events::ExtractArgument<int32_t>(args);
    // Overwrite num integers from 8
    eff->m_nNumIntegers = Events::ExtractArgument<int32_t>(args);

    auto bRightLinkValid = Events::ExtractArgument<int32_t>(args);
    auto *pRightLink = Events::ExtractArgument<CGameEffect*>(args);
    eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

    auto bLeftLinkValid = Events::ExtractArgument<int32_t>(args);
    auto *pLeftLink = Events::ExtractArgument<CGameEffect*>(args);
    eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

    eff->m_nCasterLevel       = Events::ExtractArgument<int32_t>(args);
    eff->m_bShowIcon          = Events::ExtractArgument<int32_t>(args);
    eff->m_bExpose            = Events::ExtractArgument<int32_t>(args);
    eff->m_nSpellId           = Events::ExtractArgument<int32_t>(args);
    eff->m_oidCreator         = Events::ExtractArgument<ObjectID>(args);
    eff->m_nExpiryTimeOfDay   = Events::ExtractArgument<int32_t>(args);
    eff->m_nExpiryCalendarDay = Events::ExtractArgument<int32_t>(args);
    eff->m_fDuration          = Events::ExtractArgument<float>(args);
    eff->m_nSubType           = Events::ExtractArgument<int32_t>(args);
    eff->m_nType              = Events::ExtractArgument<int32_t>(args);

    if (bLeftLinkValid || bRightLinkValid)
        eff->UpdateLinked();

    return Events::Arguments(eff);
}
ArgumentStack Effect::UnpackEffect(ArgumentStack&& args)
{
    ArgumentStack stack;
    auto eff = Events::ExtractArgument<CGameEffect*>(args);

    Events::InsertArgument(stack, (int32_t)eff->m_nType);
    Events::InsertArgument(stack, (int32_t)eff->m_nSubType);
    Events::InsertArgument(stack, (float)eff->m_fDuration);
    Events::InsertArgument(stack, (int32_t)eff->m_nExpiryCalendarDay);
    Events::InsertArgument(stack, (int32_t)eff->m_nExpiryTimeOfDay);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidCreator);
    Events::InsertArgument(stack, (int32_t)eff->m_nSpellId);
    Events::InsertArgument(stack, (int32_t)eff->m_bExpose);
    Events::InsertArgument(stack, (int32_t)eff->m_bShowIcon);
    Events::InsertArgument(stack, (int32_t)eff->m_nCasterLevel);

    // The DestroyGameEffect at the end of this function will delete any linked effects
    // as well so we make a copy of the linked effects and send those for unpacking
    CGameEffect *leftLinkEff = nullptr;
    if (eff->m_pLinkLeft != nullptr)
    {
        leftLinkEff = new CGameEffect(true);
        leftLinkEff->CopyEffect(eff->m_pLinkLeft, 0);
    }
    Events::InsertArgument(stack, leftLinkEff);
    Events::InsertArgument(stack, eff->m_pLinkLeft != nullptr);

    CGameEffect *rightLinkEff = nullptr;
    if (eff->m_pLinkRight != nullptr)
    {
        rightLinkEff = new CGameEffect(true);
        rightLinkEff->CopyEffect(eff->m_pLinkRight, 0);
    }
    Events::InsertArgument(stack, rightLinkEff);
    Events::InsertArgument(stack, eff->m_pLinkRight != nullptr);

    Events::InsertArgument(stack, (int32_t)eff->m_nNumIntegers);
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 0 ? eff->m_nParamInteger[0] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 1 ? eff->m_nParamInteger[1] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 2 ? eff->m_nParamInteger[2] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 3 ? eff->m_nParamInteger[3] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 4 ? eff->m_nParamInteger[4] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 5 ? eff->m_nParamInteger[5] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 6 ? eff->m_nParamInteger[6] : -1));
    Events::InsertArgument(stack, (int32_t)(eff->m_nNumIntegers > 7 ? eff->m_nParamInteger[7] : -1));

    Events::InsertArgument(stack, (float)eff->m_nParamFloat[0]);
    Events::InsertArgument(stack, (float)eff->m_nParamFloat[1]);
    Events::InsertArgument(stack, (float)eff->m_nParamFloat[2]);
    Events::InsertArgument(stack, (float)eff->m_nParamFloat[3]);

    Events::InsertArgument(stack, std::string(eff->m_sParamString[0].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[1].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[2].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[3].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[4].CStr()));
    Events::InsertArgument(stack, std::string(eff->m_sParamString[5].CStr()));

    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[0]);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[1]);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[2]);
    Events::InsertArgument(stack, (ObjectID)eff->m_oidParamObjectID[3]);

    Events::InsertArgument(stack, (float)eff->m_vParamVector[0].x);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[0].y);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[0].z);

    Events::InsertArgument(stack, (float)eff->m_vParamVector[1].x);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[1].y);
    Events::InsertArgument(stack, (float)eff->m_vParamVector[1].z);

    Events::InsertArgument(stack, std::string(eff->m_sCustomTag.CStr()));

    Utils::DestroyGameEffect(eff);
    return stack;
}

ArgumentStack Effect::SetEffectExpiredScript(ArgumentStack&& args)
{
    static Hooks::Hook pOnEffectRemovedHook =
            Hooks::HookFunction(API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect,
            (void*)+[](CNWSEffectListHandler *pEffectListHandler, CNWSObject* pObject, CGameEffect* pEffect) -> int32_t
            {
                CExoString &sScriptName = pEffect->m_sParamString[4];
                if (!sScriptName.IsEmpty())
                {
                    g_plugin->m_effectExpiredData = std::string(pEffect->m_sParamString[5].CStr());
                    g_plugin->m_effectExpiredCreator = pEffect->m_oidCreator;

                    LOG_DEBUG("(SetEffectExpiredScript) Running script '%s' on object '%x' with data '%s'",
                        sScriptName.CStr(), pObject->m_idSelf, g_plugin->m_effectExpiredData);

                    ++g_plugin->m_effectExpiredDepth;
                    Globals::VirtualMachine()->RunScript(&sScriptName, pObject->m_idSelf, 1);
                    --g_plugin->m_effectExpiredDepth;
                }
                return pOnEffectRemovedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect);
            }, Hooks::Order::Early);

    auto effect = Events::ExtractArgument<CGameEffect*>(args);

    // Script name
    effect->m_sParamString[4] = Events::ExtractArgument<std::string>(args).c_str();
    // Data
    effect->m_sParamString[5] = Events::ExtractArgument<std::string>(args).c_str();

    return Events::Arguments(effect);
}

ArgumentStack Effect::GetEffectExpiredData(ArgumentStack&&)
{
    if (g_plugin->m_effectExpiredDepth == 0)
    {
        throw std::runtime_error("Attempted to get effect expired data in an invalid context.");
    }

    return Events::Arguments(g_plugin->m_effectExpiredData);
}

ArgumentStack Effect::GetEffectExpiredCreator(ArgumentStack&&)
{
    if (g_plugin->m_effectExpiredDepth == 0)
    {
        throw std::runtime_error("Attempted to get effect expired creator in an invalid context.");
    }

    return Events::Arguments(g_plugin->m_effectExpiredCreator);
}

ArgumentStack Effect::ReplaceEffect(ArgumentStack&& args)
{
    int found = 0;
    auto objId = Events::ExtractArgument<ObjectID>(args);
    auto eOld  = Events::ExtractArgument<CGameEffect*>(args);
    auto eNew  = Events::ExtractArgument<CGameEffect*>(args);

    ASSERT_OR_THROW(eNew->m_nType == eOld->m_nType);

    if (auto* obj = Utils::AsNWSObject(Utils::GetGameObject(objId)))
    {
        for (auto* eff : obj->m_appliedEffects)
        {
            if (eff->m_nID == eOld->m_nID)
            {
                eff->m_nSubType              = eNew->m_nSubType;
                eff->m_fDuration             = eNew->m_fDuration;
                eff->m_nExpiryCalendarDay    = eNew->m_nExpiryCalendarDay;
                eff->m_nExpiryTimeOfDay      = eNew->m_nExpiryTimeOfDay;
                eff->m_oidCreator            = eNew->m_oidCreator;
                eff->m_nSpellId              = eNew->m_nSpellId;
                eff->m_nCasterLevel          = eNew->m_nCasterLevel;
                eff->m_nItemPropertySourceId = eNew->m_nItemPropertySourceId;
                eff->m_sCustomTag            = eNew->m_sCustomTag;
                eff->UpdateLinked();
                found++;
            }
        }
    }
    return found;
}

}
