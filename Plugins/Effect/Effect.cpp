#include "nwnx.hpp"

#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include "API/CExoString.hpp"
#include "API/CGameEffect.hpp"
#include "API/Functions.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSObject.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWSEncounter.hpp"
#include "API/CNWSPlaceable.hpp"
#include "API/CNWSDoor.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSEffectListHandler.hpp"
#include "API/CScriptEvent.hpp"
#include "API/CNWSPlayerCharSheetGUI.hpp"
#include "API/CExoArrayList.hpp"

#include <string>

using namespace NWNXLib;
using namespace NWNXLib::API;

static std::string s_effectExpiredData;
static uint32_t s_effectExpiredDepth;
static ObjectID s_effectExpiredCreator;

ArgumentStack ResolveUnpack(CGameEffect *eff, bool bLink)
{
    ArgumentStack stack;

    stack.push(std::to_string(eff->m_nID));
    stack.push((int32_t)eff->m_nType);
    stack.push((int32_t)eff->m_nSubType);
    stack.push((float)eff->m_fDuration);
    stack.push((int32_t)eff->m_nExpiryCalendarDay);
    stack.push((int32_t)eff->m_nExpiryTimeOfDay);
    stack.push((ObjectID)eff->m_oidCreator);
    stack.push((int32_t)eff->m_nSpellId);
    stack.push((int32_t)eff->m_bExpose);
    stack.push((int32_t)eff->m_bShowIcon);
    stack.push((int32_t)eff->m_nCasterLevel);

    if (bLink)
    {
        CGameEffect *leftLinkEff = nullptr;
        if (eff->m_pLinkLeft != nullptr)
        {
            leftLinkEff = new CGameEffect(true);
            leftLinkEff->CopyEffect(eff->m_pLinkLeft, 0);
        }
        stack.push(leftLinkEff);
        stack.push(eff->m_pLinkLeft != nullptr);

        CGameEffect *rightLinkEff = nullptr;
        if (eff->m_pLinkRight != nullptr)
        {
            rightLinkEff = new CGameEffect(true);
            rightLinkEff->CopyEffect(eff->m_pLinkRight, 0);
        }
        stack.push(rightLinkEff);
        stack.push(eff->m_pLinkRight != nullptr);
    }

    stack.push((int32_t)eff->m_nNumIntegers);
    stack.push((int32_t)(eff->m_nNumIntegers > 0 ? eff->m_nParamInteger[0] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 1 ? eff->m_nParamInteger[1] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 2 ? eff->m_nParamInteger[2] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 3 ? eff->m_nParamInteger[3] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 4 ? eff->m_nParamInteger[4] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 5 ? eff->m_nParamInteger[5] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 6 ? eff->m_nParamInteger[6] : -1));
    stack.push((int32_t)(eff->m_nNumIntegers > 7 ? eff->m_nParamInteger[7] : -1));

    stack.push((float)eff->m_nParamFloat[0]);
    stack.push((float)eff->m_nParamFloat[1]);
    stack.push((float)eff->m_nParamFloat[2]);
    stack.push((float)eff->m_nParamFloat[3]);

    stack.push(std::string(eff->m_sParamString[0].CStr()));
    stack.push(std::string(eff->m_sParamString[1].CStr()));
    stack.push(std::string(eff->m_sParamString[2].CStr()));
    stack.push(std::string(eff->m_sParamString[3].CStr()));
    stack.push(std::string(eff->m_sParamString[4].CStr()));
    stack.push(std::string(eff->m_sParamString[5].CStr()));

    stack.push((ObjectID)eff->m_oidParamObjectID[0]);
    stack.push((ObjectID)eff->m_oidParamObjectID[1]);
    stack.push((ObjectID)eff->m_oidParamObjectID[2]);
    stack.push((ObjectID)eff->m_oidParamObjectID[3]);

    stack.push((float)eff->m_vParamVector[0].x);
    stack.push((float)eff->m_vParamVector[0].y);
    stack.push((float)eff->m_vParamVector[0].z);

    stack.push((float)eff->m_vParamVector[1].x);
    stack.push((float)eff->m_vParamVector[1].y);
    stack.push((float)eff->m_vParamVector[1].z);

    stack.push(std::string(eff->m_sCustomTag.CStr()));

    stack.push(std::to_string(eff->m_nItemPropertySourceId));

    return stack;
}

void ResolvePack(CGameEffect *eff, ArgumentStack& args, bool bReplace)
{
    eff->m_nItemPropertySourceId = std::stoull(args.extract<std::string>());

    eff->m_sCustomTag = args.extract<std::string>().c_str();

    auto vector1z = args.extract<float>();
    auto vector1y = args.extract<float>();
    auto vector1x = args.extract<float>();
    eff->m_vParamVector[1] = {vector1x, vector1y, vector1z};

    auto vector0z = args.extract<float>();
    auto vector0y = args.extract<float>();
    auto vector0x = args.extract<float>();
    eff->m_vParamVector[0] = {vector0x, vector0y, vector0z};

    eff->m_oidParamObjectID[3] = args.extract<ObjectID>();
    eff->m_oidParamObjectID[2] = args.extract<ObjectID>();
    eff->m_oidParamObjectID[1] = args.extract<ObjectID>();
    eff->m_oidParamObjectID[0] = args.extract<ObjectID>();

    eff->m_sParamString[5] = args.extract<std::string>().c_str();
    eff->m_sParamString[4] = args.extract<std::string>().c_str();
    eff->m_sParamString[3] = args.extract<std::string>().c_str();
    eff->m_sParamString[2] = args.extract<std::string>().c_str();
    eff->m_sParamString[1] = args.extract<std::string>().c_str();
    eff->m_sParamString[0] = args.extract<std::string>().c_str();

    eff->m_nParamFloat[3] = args.extract<float>();
    eff->m_nParamFloat[2] = args.extract<float>();
    eff->m_nParamFloat[1] = args.extract<float>();
    eff->m_nParamFloat[0] = args.extract<float>();

    eff->SetNumIntegers(8); // allocate array
    eff->m_nParamInteger[7] = args.extract<int32_t>();
    eff->m_nParamInteger[6] = args.extract<int32_t>();
    eff->m_nParamInteger[5] = args.extract<int32_t>();
    eff->m_nParamInteger[4] = args.extract<int32_t>();
    eff->m_nParamInteger[3] = args.extract<int32_t>();
    eff->m_nParamInteger[2] = args.extract<int32_t>();
    eff->m_nParamInteger[1] = args.extract<int32_t>();
    eff->m_nParamInteger[0] = args.extract<int32_t>();
    // Overwrite num integers from 8
    eff->m_nNumIntegers = args.extract<int32_t>();

    bool bUpdateLinks = false;
    if (!bReplace)
    {
        auto bRightLinkValid = args.extract<int32_t>();
        auto *pRightLink = args.extract<CGameEffect*>();
        eff->m_pLinkRight = (bRightLinkValid) ? pRightLink : nullptr;

        auto bLeftLinkValid = args.extract<int32_t>();
        auto *pLeftLink = args.extract<CGameEffect*>();
        eff->m_pLinkLeft = (bLeftLinkValid) ? pLeftLink : nullptr;

        if (bLeftLinkValid || bRightLinkValid)
            bUpdateLinks = true;
    }

    eff->m_nCasterLevel       = args.extract<int32_t>();
    eff->m_bShowIcon          = args.extract<int32_t>();
    eff->m_bExpose            = args.extract<int32_t>();
    eff->m_nSpellId           = args.extract<int32_t>();
    eff->m_oidCreator         = args.extract<ObjectID>();
    eff->m_nExpiryTimeOfDay   = args.extract<int32_t>();
    eff->m_nExpiryCalendarDay = args.extract<int32_t>();
    eff->m_fDuration          = args.extract<float>();
    eff->m_nSubType           = args.extract<int32_t>();

    if (!bReplace)
        eff->m_nType = args.extract<int32_t>();

    if (bUpdateLinks)
        eff->UpdateLinked();
}

NWNX_EXPORT ArgumentStack PackEffect(ArgumentStack&& args)
{
    CGameEffect *eff = new CGameEffect(true);

    ResolvePack(eff, args, false);

    return eff;
}

NWNX_EXPORT ArgumentStack UnpackEffect(ArgumentStack&& args)
{
    auto eff = args.extract<CGameEffect*>();
    SCOPEGUARD(Utils::DestroyGameEffect(eff));

    return ResolveUnpack(eff, true);
}

NWNX_EXPORT ArgumentStack SetEffectExpiredScript(ArgumentStack&& args)
{
    static Hooks::Hook pOnEffectRemovedHook =
            Hooks::HookFunction(API::Functions::_ZN21CNWSEffectListHandler15OnEffectRemovedEP10CNWSObjectP11CGameEffect,
            (void*)+[](CNWSEffectListHandler *pEffectListHandler, CNWSObject* pObject, CGameEffect* pEffect) -> int32_t
            {
                CExoString& sScriptName = pEffect->m_sParamString[4];
                if (!sScriptName.IsEmpty())
                {
                    s_effectExpiredData = std::string(pEffect->m_sParamString[5].CStr());
                    s_effectExpiredCreator = pEffect->m_oidCreator;

                    LOG_DEBUG("(SetEffectExpiredScript) Running script '%s' on object '%x' with data '%s'",
                        sScriptName.CStr(), pObject->m_idSelf, s_effectExpiredData);

                    ++s_effectExpiredDepth;
                    Globals::VirtualMachine()->RunScript(&sScriptName, pObject->m_idSelf, 1);
                    --s_effectExpiredDepth;
                }
                return pOnEffectRemovedHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect);
            }, Hooks::Order::Early);

    auto effect = args.extract<CGameEffect*>();

    // Script name
    effect->m_sParamString[4] = args.extract<std::string>().c_str();
    // Data
    effect->m_sParamString[5] = args.extract<std::string>().c_str();

    return effect;
}

NWNX_EXPORT ArgumentStack GetEffectExpiredData(ArgumentStack&&)
{
    if (s_effectExpiredDepth == 0)
        throw std::runtime_error("Attempted to get effect expired data in an invalid context.");

    return s_effectExpiredData;
}

NWNX_EXPORT ArgumentStack GetEffectExpiredCreator(ArgumentStack&&)
{
    if (s_effectExpiredDepth == 0)
        throw std::runtime_error("Attempted to get effect expired creator in an invalid context.");

    return s_effectExpiredCreator;
}

NWNX_EXPORT ArgumentStack ReplaceEffect(ArgumentStack&& args)
{
    int found = 0;
    auto objId = args.extract<ObjectID>();
    auto eOld  = args.extract<CGameEffect*>();
    auto eNew  = args.extract<CGameEffect*>();

    SCOPEGUARD(Utils::DestroyGameEffect(eOld));
    SCOPEGUARD(Utils::DestroyGameEffect(eNew));

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

NWNX_EXPORT ArgumentStack GetTrueEffectCount(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
        return pObject->m_appliedEffects.num;

    return 0;
}

NWNX_EXPORT ArgumentStack GetTrueEffect(ArgumentStack&& args)
{
    auto *pObject = Utils::PopObject(args);
      ASSERT_OR_THROW(pObject);
    auto it = args.extract<int32_t>();
      ASSERT_OR_THROW(it >= 0);
      ASSERT_OR_THROW(it < pObject->m_appliedEffects.num);

    return ResolveUnpack(pObject->m_appliedEffects[it], false);
}

NWNX_EXPORT ArgumentStack ReplaceEffectByIndex(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        auto index = args.extract<int32_t>();
          ASSERT_OR_THROW(index >= 0);
          ASSERT_OR_THROW(index < pObject->m_appliedEffects.num);

        ResolvePack(pObject->m_appliedEffects[index], args, true);
    }

    return {};
}

NWNX_EXPORT ArgumentStack RemoveEffectById(ArgumentStack&& args)
{
    if (auto *pObject = Utils::PopObject(args))
    {
        uint64_t id = std::stoull(args.extract<std::string>());
        return pObject->RemoveEffectById(id);
    }

    return false;
}

NWNX_EXPORT ArgumentStack Apply(ArgumentStack&& args)
{
    auto *pEffect = args.extract<CGameEffect*>();
    auto *pObject = Utils::PopObject(args);

    if(pObject && pEffect)
    {
        pObject->ApplyEffect(pEffect, false, true);
    }

    return {};
}

NWNX_EXPORT ArgumentStack AccessorizeVisualEffect(ArgumentStack&& args)
{
    static Hooks::Hook s_RemoveBadEffects = Hooks::HookFunction(Functions::_ZN12CNWSCreature16RemoveBadEffectsEv,
    (void*)+[](CNWSCreature *pCreature) -> void
    {
        CExoArrayList<CGameEffect*> *pAppliedEffects = &pCreature->m_appliedEffects;
        int32_t nIndex = 0;

        while (nIndex < pAppliedEffects->num)
        {
            auto *pEffect = (*pAppliedEffects)[nIndex];
            int32_t nDurationType = pEffect->GetDurationType();

            if ((nDurationType == Constants::EffectDurationType::Temporary ||
                (nDurationType == Constants::EffectDurationType::Permanent && (pEffect->GetSubType_Extraordinary() || pEffect->GetSubType_Magical()))) &&
                (pEffect->m_nType != Constants::EffectTrueType::VisualEffect || (pEffect->m_nType == Constants::EffectTrueType::VisualEffect && pEffect->GetInteger(7) != 1)))
            {
                pCreature->RemoveEffectById(pEffect->m_nID);
                nIndex = 0;
                continue;
            }

            nIndex++;
        }
    }, Hooks::Order::Final);

    static Hooks::Hook s_OnApplyDeathHook = Hooks::HookFunction(Functions::_ZN21CNWSEffectListHandler12OnApplyDeathEP10CNWSObjectP11CGameEffecti,
    (void*)+[](CNWSEffectListHandler*, CNWSObject *pObject, CGameEffect *pEffect, BOOL bLoadingGame)-> int32_t
    {
        auto *pServerAIMaster = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();

        ObjectID nCallerObjectId = pEffect->m_oidCreator;

        if (pObject->m_bPlotObject)
            return 1;// DELETE_EFFECT

        if (auto *pCreature = Utils::AsNWSCreature(pObject))
        {
            if (pCreature->m_bIsImmortal)
            {
                if (pCreature->GetCurrentHitPoints() < 1)
                    pCreature->m_nCurrentHitPoints = 1;

                return 1;// DELETE_EFFECT
            }
        }

        if (pObject->m_nObjectType != Constants::ObjectType::Creature)
            pObject->ClearAllActions();

        auto *pKiller = Utils::AsNWSCreature(Utils::GetGameObject(nCallerObjectId));

        if (nCallerObjectId == pObject->m_idSelf)
            nCallerObjectId = pObject->m_oidLastDamager;

        if (auto *pCreature = Utils::AsNWSCreature(pObject))
        {
            if (pCreature->m_nAIState != Constants::AIState::IsDead)
            {
                if (pEffect->GetSubType_Magical())
                {
                    if (pCreature->m_pStats->GetEffectImmunity(Constants::ImmunityType::Death, pKiller) && pEffect->m_nSpellId != 0xFFFFFFFF)
                    {
                        auto *pData = new CNWCCMessageData;
                        pData->SetObjectID(0, pObject->m_idSelf);

                        if (pKiller)
                        {
                            auto *pDataForKiller = new CNWCCMessageData;
                            pData->CopyTo(pDataForKiller);

                            pKiller->SendFeedbackMessage(127, pDataForKiller);
                        }

                        pCreature->SendFeedbackMessage(127, pData);

                        return 1;// DELETE_EFFECT
                    }
                }

                pCreature->ClearAllActions();
                pServerAIMaster->AdjustTargetAndWitnessReputations(pCreature->m_idSelf, nCallerObjectId, 2/*ACTION_KILL*/);

                int32_t nSpectacularDeath = pEffect->GetInteger(0);
                int32_t nDisplayFeedback = pEffect->GetInteger(1);

                if (pCreature->m_nState == 15/*Petrified*/)
                    nSpectacularDeath = true;
                if (!pCreature->m_bDestroyable || pCreature->m_bNoPermDeath)
                    nSpectacularDeath = false;

                if (pCreature->m_nAssociateType == Constants::AssociateType::DominatedByPC ||
                    pCreature->m_nAssociateType == Constants::AssociateType::DominatedByNPC)
                    pCreature->RemoveDomination();

                pCreature->SetActivity(0x00000001/*ActiveStealth*/, false);
                pCreature->RemoveCombatInvisibilityEffects();

                pCreature->m_oidKiller = nCallerObjectId;
                pCreature->RunEventScript(Constants::ScriptEvent::OnDeath);

                pCreature->ApplyDeathExperience();

                if (!pCreature->GetIsPossessedFamiliar())
                {
                    if (pCreature->m_nAssociateType == Constants::AssociateType::DMPossess ||
                        pCreature->m_nAssociateType == Constants::AssociateType::DMImpersonate)
                    {
                        if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreature->m_idSelf))
                        {
                            if (pPlayer->GetIsDM())
                            {
                                pPlayer->PossessCreature(Constants::OBJECT_INVALID, Constants::AssociateType::None);
                            }
                        }
                    }
                    else if (pCreature->m_bPlayerCharacter)
                    {
                        pCreature->StopGuiTimingBar();
                    }
                }
                else
                {
                    pCreature->StopGuiTimingBar();
                    pCreature->ReceiveAssociateCommand(-13/*UnpossessFamiliar*/);
                }

                ObjectID oidFamiliar = pCreature->GetAssociateId(Constants::AssociateType::Familiar);
                if (oidFamiliar != Constants::OBJECT_INVALID)
                {
                    auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(oidFamiliar);

                    if (pPlayer)
                    {
                        pCreature->UnpossessFamiliar();
                    }
                }

                if (pCreature->m_oidMaster != Constants::OBJECT_INVALID)
                {
                    if (pCreature->m_nNumCharSheetViewers > 0)
                    {
                        if (auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreature->m_oidMaster))
                        {
                            if (pPlayer->m_pCharSheetGUI)
                            {
                                pPlayer->m_pCharSheetGUI->SetCreatureDisplayed(Constants::OBJECT_INVALID);
                                Globals::AppManager()->m_pServerExoApp->GetNWSMessage()->SendServerToPlayerGUICharacterSheet_NotPermitted(
                                        pPlayer->m_nPlayerID, pCreature->m_idSelf);
                            }
                        }
                    }

                    if (auto *pMaster = Utils::AsNWSCreature(Utils::GetGameObject(pCreature->m_oidMaster)))
                    {
                        pMaster->RemoveAssociate(pCreature->m_idSelf);
                    }
                }

                if (pCreature->m_nAmbientAnimationState != 3/*AmbientAnimationStateDeadButt*/ &&
                        pCreature->m_nAmbientAnimationState != 4/*AmbientAnimationStateDeadFront*/)
                {
                    if (pKiller)
                    {
                        Vector vDeltaPos = VectorMath::Normalize(VectorMath::Subtract(pKiller->m_vPosition, pCreature->m_vPosition));
                        float fAngle = VectorMath::Dot(VectorMath::Normalize(pCreature->m_vOrientation), vDeltaPos);

                        if (fAngle >= 0.707f)
                        {
                            pCreature->m_nAmbientAnimationState = 3;// AmbientAnimationStateDeadButt
                            pCreature->SetAnimation(Constants::Animation::DeadButt);
                        }
                        else
                        {
                            pCreature->m_nAmbientAnimationState = 4;// AmbientAnimationStateDeadFront;
                            pCreature->SetAnimation(Constants::Animation::DeadFront);
                        }
                    }
                    else
                    {
                        pCreature->m_nAmbientAnimationState = 3;// AmbientAnimationStateDeadButt
                        pCreature->SetAnimation(Constants::Animation::DeadButt);
                    }
                }

                if (nDisplayFeedback)
                {
                    auto pMessageData = new CNWCCMessageData;
                    pMessageData->SetObjectID(0, nCallerObjectId);
                    pMessageData->SetObjectID(1, pCreature->m_idSelf);

                    if (auto *pOpponent = Utils::AsNWSCreature(Utils::GetGameObject(nCallerObjectId)))
                        pCreature->BroadcastDeathDataToParty(pMessageData, pOpponent);
                    else
                        pCreature->BroadcastDeathDataToParty(pMessageData);

                    delete pMessageData;
                    pMessageData = nullptr;
                }

                pCreature->m_bListening = false;
                pCreature->m_nAIState = Constants::AIState::IsDead;

                if (pCreature->GetCurrentHitPoints(true) > -11)
                    pCreature->m_nCurrentHitPoints = -11;

                pCreature->AutoCloseGUIPanels(false);
                pCreature->SetCombatMode(Constants::CombatMode::None, true);
                pCreature->UpdateActionQueue();

                CExoArrayList<CGameEffect*> *pAppliedEffects = &pCreature->m_appliedEffects;
                int32_t nIndex = 0;
                while (nIndex < pAppliedEffects->num)
                {
                    auto *pAppliedEffect = (*pAppliedEffects)[nIndex];
                    int32_t nDurationType = pAppliedEffect->GetDurationType();

                    if (nDurationType != Constants::EffectDurationType::Innate &&
                        nDurationType != Constants::EffectDurationType::Equipped)
                    {
                        if (pAppliedEffect->m_nType != Constants::EffectTrueType::VisualEffect ||
                            (pAppliedEffect->m_nType == Constants::EffectTrueType::VisualEffect && pAppliedEffect->GetInteger(7) != 1))
                        {
                            pCreature->RemoveEffectById(pAppliedEffect->m_nID);
                            nIndex = 0;
                            continue;
                        }
                    }

                    nIndex++;
                }

                if (!pCreature->m_bPlayerCharacter)
                {
                    if (!nSpectacularDeath || pCreature->m_bLootable)
                    {
                        if (!pCreature->m_bLootable)
                        {
                            pServerAIMaster->AddEventDeltaTime(
                                    0, pCreature->m_nDecayTime, pEffect->m_oidCreator,
                                    pObject->m_idSelf, Constants::AIMasterEvent::DestroyObject);
                        }
                        else
                        {
                            pCreature->SpawnBodyBag();
                        }

                        if (pCreature->m_oidEncounter != Constants::OBJECT_INVALID)
                        {
                            if (auto *pEncounter = Globals::AppManager()->m_pServerExoApp->GetEncounterByGameObjectID(pCreature->m_oidEncounter))
                            {
                                pEncounter->RemoveFromActiveCreatureCount(pCreature->m_pStats->m_fChallengeRating, 0/*EncounterCreatureDeath*/);
                                pCreature->m_bAlreadyRemovedFromEncounter = true;
                            }
                        }
                    }
                    else
                    {
                        auto *pGibEffect = new CGameEffect;
                        pGibEffect->m_nType = Constants::EffectTrueType::VisualEffect;
                        pGibEffect->SetDurationType(Constants::EffectDurationType::Instant);
                        pGibEffect->SetInteger(0, 119/*VisualEffectGib*/);
                        pCreature->ApplyEffect(pGibEffect, bLoadingGame);

                        pServerAIMaster->AddEventDeltaTime(
                                0, 3000, pEffect->m_oidCreator,
                                pObject->m_idSelf, Constants::AIMasterEvent::DestroyObject);

                        if (pCreature->m_oidEncounter != Constants::OBJECT_INVALID)
                        {
                            if (auto *pEncounter = Globals::AppManager()->m_pServerExoApp->GetEncounterByGameObjectID(pCreature->m_oidEncounter))
                            {
                                pEncounter->RemoveFromActiveCreatureCount(pCreature->m_pStats->m_fChallengeRating, 0/*EncounterCreatureDeath*/);
                                pCreature->m_bAlreadyRemovedFromEncounter = true;
                            }
                        }
                    }
                }
                else
                {
                    auto *pScriptEvent = new CScriptEvent;
                    pScriptEvent->m_nType = Constants::ScriptEvent::OnDeath;
                    pServerAIMaster->AddEventDeltaTime(
                            0, 0, pCreature->m_idSelf, Utils::GetModule()->m_idSelf,
                            Constants::AIMasterEvent::SignalEvent, pScriptEvent);
                }

                pCreature->ProcessMasterDeathForAssociates();
                pCreature->BroadcastVoiceChat(18/*VoiceChatDeath*/);
            }
        }
        else if (pObject->m_nObjectType == Constants::ObjectType::Placeable || pObject->m_nObjectType == Constants::ObjectType::Door)
        {
            if (auto *pPlaceable = Utils::AsNWSPlaceable(pObject))
            {
                pPlaceable->ClosePlaceableForAllPlayers();
                pPlaceable->SetAnimation(Constants::Animation::Destroyed);
            }
            else if (auto *pDoor = Utils::AsNWSDoor(pObject))
            {
                pDoor->SetOpenState(3/*OpenStateDestroyed*/);

                if (auto *pLinkedDoor = Utils::AsNWSDoor(pDoor->m_pTransition.LookupTarget()))
                {
                    if (pLinkedDoor->m_nAnimation != Constants::Animation::Destroyed)
                    {
                        auto *pDeathEffect = new CGameEffect;
                        pDeathEffect->m_nType = Constants::EffectTrueType::Death;
                        pDeathEffect->SetInteger(0, false);
                        pDeathEffect->SetInteger(1, true);
                        pCreature->ApplyEffect(pDeathEffect, bLoadingGame);
                    }
                }
            }

            auto *pScriptEvent = new CScriptEvent;
            pScriptEvent->m_nType = Constants::ScriptEvent::OnDeath;
            pServerAIMaster->AddEventDeltaTime(
                    0, 0, pEffect->m_oidCreator, pObject->m_idSelf,
                    Constants::AIMasterEvent::SignalEvent, pScriptEvent);

            pServerAIMaster->AddEventDeltaTime(
                    0, 2000, pEffect->m_oidCreator, pObject->m_idSelf,
                    Constants::AIMasterEvent::DestroyObject);
        }

        return 1;// DELETE_EFFECT
    }, Hooks::Order::Final);

    auto *pEffect = args.extract<CGameEffect*>();

    if (pEffect->m_nType == Constants::EffectTrueType::VisualEffect)
    {
        pEffect->SetSubType_Extraordinary();
        pEffect->SetInteger(7, true);
    }

    return pEffect;
}
