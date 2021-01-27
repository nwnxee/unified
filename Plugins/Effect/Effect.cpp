#include "Effect.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSObject.hpp"
#include "Utils.hpp"
#include "Services/Config/Config.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWItemProperty.hpp"
#include "API/CNWSCombatRound.hpp"
#include "API/CNWSItem.hpp"
#include "API/CNWSInventory.hpp"

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
    REGISTER(ReplaceEffect);
    REGISTER(GetTrueEffectCount);
    REGISTER(GetTrueEffect);
    REGISTER(ReplaceEffectByElement);
    REGISTER(RemoveEffectById);
    REGISTER(SetEffectImmunityBypass);
    REGISTER(SetDamageReductionBypass);

#undef REGISTER

    auto bDR = GetServices()->m_config->Get<bool>("EXTEND_DAMAGE_REDUCTION_ITEM_PROPERTIES", false);
    auto bSC = GetServices()->m_config->Get<bool>("EXTEND_SNEAK_CRIT_IMM_ITEM_PROPERTIES", false);

    if(bDR || bSC)
    {
        GetServices()->m_hooks->RequestSharedHook<Functions::_ZN15CServerAIMaster21OnItemPropertyAppliedEP8CNWSItemP15CNWItemPropertyP12CNWSCreatureji, bool, CServerAIMaster*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, BOOL>(&OnItemPropertyAppliedHook);
        if(bDR)
            GetServices()->m_hooks->RequestSharedHook<Functions::_ZN21CNWSEffectListHandler22OnApplyDamageReductionEP10CNWSObjectP11CGameEffecti, bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL>(&OnApplyDamageReductionHook);
        if(bSC)
        {
            GetServices()->m_hooks->RequestSharedHook<Functions::_ZN21CNWSEffectListHandler21OnApplyEffectImmunityEP10CNWSObjectP11CGameEffecti, bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL>(&OnApplyEffectImmunityHook);
            m_GetEffectImmunityHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats17GetEffectImmunityEhP12CNWSCreaturei>(&GetEffectImmunityHook);
        }
    }
}

Effect::~Effect()
{
}

ArgumentStack Effect::ResolveUnpack(CGameEffect *eff, bool bLink /*=true*/)
{
    ArgumentStack stack;

    Services::Events::InsertArgument(stack, std::to_string(eff->m_nID));
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

    if(bLink)
    {
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
    }

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

    Services::Events::InsertArgument(stack, (float)eff->m_vParamVector[0].x);
    Services::Events::InsertArgument(stack, (float)eff->m_vParamVector[0].y);
    Services::Events::InsertArgument(stack, (float)eff->m_vParamVector[0].z);

    Services::Events::InsertArgument(stack, (float)eff->m_vParamVector[1].x);
    Services::Events::InsertArgument(stack, (float)eff->m_vParamVector[1].y);
    Services::Events::InsertArgument(stack, (float)eff->m_vParamVector[1].z);

    Services::Events::InsertArgument(stack, std::string(eff->m_sCustomTag.CStr()));

    return stack;
}

ArgumentStack Effect::PackEffect(ArgumentStack&& args)
{
    CGameEffect *eff = new CGameEffect(true);

    eff->m_sCustomTag = Services::Events::ExtractArgument<std::string>(args).c_str();

    auto vector1z = Services::Events::ExtractArgument<float>(args);
    auto vector1y = Services::Events::ExtractArgument<float>(args);
    auto vector1x = Services::Events::ExtractArgument<float>(args);
    eff->m_vParamVector[1] = {vector1x, vector1y, vector1z};

    auto vector0z = Services::Events::ExtractArgument<float>(args);
    auto vector0y = Services::Events::ExtractArgument<float>(args);
    auto vector0x = Services::Events::ExtractArgument<float>(args);
    eff->m_vParamVector[0] = {vector0x, vector0y, vector0z};

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

    auto bRightLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    auto *pRightLink = Services::Events::ExtractArgument<CGameEffect*>(args);
    eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

    auto bLeftLinkValid = Services::Events::ExtractArgument<int32_t>(args);
    auto *pLeftLink = Services::Events::ExtractArgument<CGameEffect*>(args);
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

    stack = ResolveUnpack(eff, true);

    Utils::DestroyGameEffect(eff);
    return stack;
}

ArgumentStack Effect::SetEffectExpiredScript(ArgumentStack&& args)
{
    static Hooking::FunctionHook *pOnEffectRemovedHook =
            GetServices()->m_hooks->Hook(API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect,
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
            }, Hooking::Order::Early);

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

ArgumentStack Effect::ReplaceEffect(ArgumentStack&& args)
{
    int found = 0;
    auto objId = Services::Events::ExtractArgument<ObjectID>(args);
    auto eOld  = Services::Events::ExtractArgument<CGameEffect*>(args);
    auto eNew  = Services::Events::ExtractArgument<CGameEffect*>(args);

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

ArgumentStack Effect::GetTrueEffectCount(ArgumentStack&& args)
{
    int32_t retVal = 0;
    auto objectId = Services::Events::ExtractArgument<ObjectID>(args);

    if(objectId != Constants::OBJECT_INVALID)
    {
        if (auto *pObject = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId)))
        {
            retVal = pObject->m_appliedEffects.num;
        }
    }

    return Services::Events::Arguments(retVal);
}

ArgumentStack Effect::GetTrueEffect(ArgumentStack&& args)
{
    auto objectId = Services::Events::ExtractArgument<ObjectID>(args);
      ASSERT_OR_THROW(objectId != Constants::OBJECT_INVALID);
    auto *pObject = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId));
      ASSERT_OR_THROW(pObject);
    auto it = Services::Events::ExtractArgument<int32_t>(args);
      ASSERT_OR_THROW(it >= 0);
      ASSERT_OR_THROW(it < pObject->m_appliedEffects.num);

    auto *eff = pObject->m_appliedEffects.element[it];

    ArgumentStack stack = ResolveUnpack(eff, false);

    return stack;
}

ArgumentStack Effect::ReplaceEffectByElement(ArgumentStack&& args)
{
    auto objectId = Services::Events::ExtractArgument<ObjectID>(args);
    if(objectId != Constants::OBJECT_INVALID)
    {
        if(auto *pObject = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId)))
        {
            auto element = Services::Events::ExtractArgument<int32_t>(args);
              ASSERT_OR_THROW(element >= 0);
              ASSERT_OR_THROW(element < pObject->m_appliedEffects.num);
            auto eff = pObject->m_appliedEffects.element[element];

            eff->m_sCustomTag = Services::Events::ExtractArgument<std::string>(args).c_str();

            auto vector1z = Services::Events::ExtractArgument<float>(args);
            auto vector1y = Services::Events::ExtractArgument<float>(args);
            auto vector1x = Services::Events::ExtractArgument<float>(args);
            eff->m_vParamVector[1] = {vector1x, vector1y, vector1z};

            auto vector0z = Services::Events::ExtractArgument<float>(args);
            auto vector0y = Services::Events::ExtractArgument<float>(args);
            auto vector0x = Services::Events::ExtractArgument<float>(args);
            eff->m_vParamVector[0] = {vector0x, vector0y, vector0z};

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

            eff->m_nParamInteger[7] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[6] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[5] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[4] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[3] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[2] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[1] = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nParamInteger[0] = Services::Events::ExtractArgument<int32_t>(args);

            eff->m_nCasterLevel       = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_bShowIcon          = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_bExpose            = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nSpellId           = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_oidCreator         = Services::Events::ExtractArgument<ObjectID>(args);
            eff->m_nExpiryTimeOfDay   = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_nExpiryCalendarDay = Services::Events::ExtractArgument<int32_t>(args);
            eff->m_fDuration          = Services::Events::ExtractArgument<float>(args);
            eff->m_nSubType           = Services::Events::ExtractArgument<int32_t>(args);
        }
    }

    return Services::Events::Arguments();
}

ArgumentStack Effect::RemoveEffectById(ArgumentStack&& args)
{
    int32_t ret = 0;
    auto objectId = Services::Events::ExtractArgument<ObjectID>(args);
    if(objectId != Constants::OBJECT_INVALID)
    {
        if (auto *pObject = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(objectId)))
        {
            auto id = Services::Events::ExtractArgument<std::string>(args);
            auto it = std::find_if(id.begin(), id.end(), [](unsigned char c) { return !std::isdigit(c); });
            if(!id.empty() && it == id.end())
                ret = pObject->RemoveEffectById(std::stoi(id));
        }
    }

    return Services::Events::Arguments(ret);
}

int32_t Effect::GetEffectImmunityHook(CNWSCreatureStats *pStats, uint8_t nType, CNWSCreature * pVersus, BOOL bConsiderFeats)
{
    if(g_plugin->m_bBypassImm)
        return false;

    if(nType == Constants::ImmunityType::CriticalHit || nType == Constants::ImmunityType::SneakAttack)
    {
        if(bConsiderFeats && pStats->HasFeat(Constants::Feat::DeathlessMastery))
            return true;

        auto effectList = pStats->m_pBaseCreature->m_appliedEffects;
        uint8_t highest = 0;
        for (int32_t i = 0; i < effectList.num; i++)
        {
            auto *eff = effectList.element[i];

            if(eff->m_nType==Constants::EffectTrueType::Immunity && eff->m_nParamInteger[0]==nType)
            {
                if((eff->m_nParamInteger[1] == Constants::RacialType::All || (pVersus != nullptr && eff->m_nParamInteger[1] == pVersus->m_pStats->m_nRace)) && //race check
                   (eff->m_nParamInteger[2] == Constants::Alignment::All || (pVersus != nullptr && eff->m_nParamInteger[2] == pVersus->m_pStats->m_nAlignmentLawChaos)) &&
                   (eff->m_nParamInteger[3] == Constants::Alignment::All || (pVersus != nullptr && eff->m_nParamInteger[3] == pVersus->m_pStats->m_nAlignmentGoodEvil)))
                {
                    if(eff->m_nParamInteger[4] == 0 || eff->m_nParamInteger[4] == 100)
                        return true;

                    if(eff->m_nParamInteger[4] > highest)
                        highest = eff->m_nParamInteger[4];
                }

            }

        }

        if(highest > 0 && Globals::Rules()->RollDice(1, 100) <= highest)
            return true;

        return false;
    }

    return g_plugin->m_GetEffectImmunityHook->CallOriginal<BOOL>(pStats, nType, pVersus, bConsiderFeats);
}

void Effect::InitEffectImmHook()
{
    g_plugin->m_GetEffectImmunityHook = GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN17CNWSCreatureStats17GetEffectImmunityEhP12CNWSCreaturei>(&GetEffectImmunityHook);
}

ArgumentStack Effect::SetEffectImmunityBypass(ArgumentStack&& args)
{
    if(!g_plugin->m_GetEffectImmunityHook)
        InitEffectImmHook();

    g_plugin->m_bBypassImm = Services::Events::ExtractArgument<int32_t>(args);
    return Services::Events::Arguments();
}

void Effect::InitDamageReductionHooks()
{
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN10CNWSObject17DoDamageReductionEP12CNWSCreatureihii, bool, CNWSObject*, CNWSCreature*, int32_t, uint8_t, BOOL, BOOL>(&DoDamageReductionHook);
    g_plugin->m_bInitRed = true;
}

void Effect::OnItemPropertyAppliedHook(bool before, CServerAIMaster*, CNWSItem*, CNWItemProperty *pItemProperty, CNWSCreature*, uint32_t, BOOL)
{
    if(before)
    {
        if(pItemProperty->m_nParam1Value > 0)
        {
            if(pItemProperty->m_nPropertyName==Constants::ItemProperty::DamageReduction || pItemProperty->m_nPropertyName==Constants::ItemProperty::ImmunityMiscellaneous)
            {
                g_plugin->m_iMaterial=pItemProperty->m_nParam1Value;
            }
        }
    }
}

void Effect::OnApplyDamageReductionHook(bool before, CNWSEffectListHandler*, CNWSObject*, CGameEffect* pEffect, BOOL)
{
    if(before && g_plugin->m_iMaterial > 0)
    {
        pEffect->SetInteger(3, g_plugin->m_iMaterial);
        g_plugin->m_iMaterial=0;
    }
}

void Effect::DoDamageReductionHook(bool before, CNWSObject *pObject, CNWSCreature *pCreature, int32_t, uint8_t, BOOL, BOOL)
{
    static std::unordered_map<uint64_t, int32_t> sEffects;
    if(before)
    {
        CNWSItem* pWeapon = nullptr;
        pWeapon = pCreature->m_pcCombatRound->GetCurrentAttackWeapon();
        if(pWeapon == nullptr)
            return; //no need to continue as there is no material type

        if(pWeapon->m_nBaseItem == Constants::BaseItem::HeavyCrossbow || pWeapon->m_nBaseItem == Constants::BaseItem::LightCrossbow)
            pWeapon = pCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Bolts);
        else if(pWeapon->m_nBaseItem == Constants::BaseItem::Longbow || pWeapon->m_nBaseItem == Constants::BaseItem::Shortbow)
            pWeapon = pCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Arrows);
        else if(pWeapon->m_nBaseItem == Constants::BaseItem::Sling)
            pWeapon = pCreature->m_pInventory->GetItemInSlot(Constants::EquipmentSlot::Bullets);
        if(pWeapon == nullptr)
            return;
        bool bRemoveDR;
        for (int i = 0; i < pObject->m_appliedEffects.num; i++)
        {
                auto *eff = pObject->m_appliedEffects.element[i];
                bRemoveDR=false;
                if(eff->m_nType==Constants::EffectTrueType::DamageReduction && eff->m_nParamInteger[3] > 0)
                {
                    auto redType = eff->m_nParamInteger[3];
                    auto range = g_plugin->m_bypass.equal_range(redType);
                    for (auto it= range.first; it != range.second; ++it)
                    {
                        auto bypass = it->second;
                        for (int i = 0; i < pWeapon->m_lstPassiveProperties.num; i++)
                        {
                            auto property = pWeapon->GetPassiveProperty(i);
                            if (property->m_nPropertyName == bypass.m_nPropertyName &&
                                (property->m_nCostTableValue == bypass.m_nCostTableValue || bypass.m_nCostTableValue==-1) &&
                                (property->m_nSubType == bypass.m_nSubType || bypass.m_nSubType==-1)  &&
                                (property->m_nParam1Value == bypass.m_nParam1Value || bypass.m_nParam1Value==-1))
                            {
                                if(!bypass.bReverse)
                                {
                                   bRemoveDR=true;
                                }
                                break; //as long as we found a property, break
                            }
                            if(bypass.bReverse && i==pWeapon->m_lstPassiveProperties.num-1) //last property and we still didn't find it, so remove DR
                                bRemoveDR=true;
                        }
                        if(bRemoveDR) break; // no reason to kep checking
                    }

                }

                if(bRemoveDR)
                {
                    sEffects[eff->m_nID] = eff->m_nParamInteger[1];
                    eff->m_nParamInteger[1]=0;
                }
        }
    }
    else
    {
        for (int i = 0; i < pObject->m_appliedEffects.num; i++)
        {
                auto *eff = pObject->m_appliedEffects.element[i];

                if(eff->m_nType==Constants::EffectTrueType::DamageReduction)
                {
                    auto original = sEffects.find(eff->m_nID);
                    if (original != std::end(sEffects))
                    {
                        eff->m_nParamInteger[1]=original->second;
                        sEffects.erase(eff->m_nID);
                    }
                }
        }
    }
}

ArgumentStack Effect::SetDamageReductionBypass(ArgumentStack&& args)
{
    if(!g_plugin->m_bInitRed)
        InitDamageReductionHooks();

    auto material = Services::Events::ExtractArgument<int32_t>(args);
    auto propType = Services::Events::ExtractArgument<int32_t>(args);
    auto subType =  Services::Events::ExtractArgument<int32_t>(args);
    auto costValue = Services::Events::ExtractArgument<int32_t>(args);
    auto param1Value =  Services::Events::ExtractArgument<int32_t>(args);
    auto reverse =  Services::Events::ExtractArgument<int32_t>(args);
    m_bypassRed ip;
    ip.m_nPropertyName=propType;
    ip.m_nSubType=subType;
    ip.m_nParam1Value=param1Value;
    ip.m_nCostTableValue=costValue;
    ip.bReverse=reverse;
    g_plugin->m_bypass.insert(std::make_pair(material, ip));
    return Services::Events::Arguments();
}

void Effect::OnApplyEffectImmunityHook(bool before, CNWSEffectListHandler*, CNWSObject *, CGameEffect * pEffect, BOOL)
{
    if(before && g_plugin->m_iMaterial > 0)
    {
        pEffect->SetInteger(4, g_plugin->m_iMaterial);
        g_plugin->m_iMaterial=0;
    }
}

}
