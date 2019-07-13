#include "Race.hpp"
#include "API/C2DA.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/CNWCCMessageData.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSkill.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/Config/Config.hpp"
#include "ViewPtr.hpp"
#include <cmath>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static ViewPtr<Race::Race> g_plugin;

const auto MODULE_OID = 0;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Race",
        "Define racial and subrace characteristics",
        "orth",
        "plenarius@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Race::Race(params);
    return g_plugin;
}


namespace Race {

Race::Race(const Plugin::CreateParams& params)
    : Plugin(params)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Race::func, this, std::placeholders::_1))

    REGISTER(SetRacialModifier);
    REGISTER(GetParentRace);

#undef REGISTER

    m_ShowEffectIcon = GetServices()->m_config->Get<bool>("SHOW_EFFECT_ICON", false);

    // Most racial adjustments are done here using effects only once per server reset or after a level up
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__PostProcess, void, CNWSCreature*>(&PostProcessHook);

    // We want the racial bonuses to not count toward limits
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__GetTotalEffectBonus, int32_t, CNWSCreature*, uint8_t, CNWSObject*, int32_t, int32_t, uint8_t, uint8_t, uint8_t, uint8_t, int32_t>(&GetTotalEffectBonusHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__SavingThrowRoll, int32_t, CNWSCreature*, uint8_t, uint16_t, uint8_t, uint32_t, int32_t, uint16_t, int32_t>(&SavingThrowRollHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__GetWeaponPower, int32_t, CNWSCreature*, CNWSObject*, int32_t>(&GetWeaponPowerHook);

    // Special hook for resetting the feat usages after rest etc.
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreatureStats__ResetFeatRemainingUses, void, CNWSCreatureStats*>(&ResetFeatRemainingUsesHook);

    // Completely rewritten in NWNX for Race plugin so we can add our Initiative changes
    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCreature__ResolveInitiative, void, CNWSCreature*>(&ResolveInitiativeHook);

    // We trick ValidateCharacter by removing racial feats before and adding them back after
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSPlayer__ValidateCharacter, int32_t, CNWSPlayer*, int32_t*>(&ValidateCharacterHook);

    // If a level up has been confirmed we rerun the racial applications in case of new feats, level based adjustments etc.
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSMessage__SendServerToPlayerLevelUp_Confirmation, int32_t, CNWSMessage*, Types::PlayerID, int32_t>(&SendServerToPlayerLevelUp_ConfirmationHook);

    // Swap race with parent race due to hardcoded checks here
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreatureStats__GetFavoredEnemyBonus, int32_t, CNWSCreatureStats*, CNWSCreature*>(&GetFavoredEnemyBonusHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreature__CreateDefaultQuickButtons, void, CNWSCreature*>(&CreateDefaultQuickButtonsHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreatureStats__LevelUpAutomatic, int32_t, CNWSCreatureStats*, uint8_t, int32_t, uint8_t>(&LevelUpAutomaticHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWSCreatureStats__GetMeetsPrestigeClassRequirements, int32_t, CNWSCreatureStats*, CNWClass*>(&GetMeetsPrestigeClassRequirementsHook);

    // Need to set up default parent race to invalid before the on module load sets up the parents
    GetServices()->m_hooks->RequestSharedHook<Functions::CNWRules__LoadRaceInfo, void, CNWRules *>(&LoadRaceInfoHook);
}

Race::~Race()
{
}

void Race::DoEffect(CNWSCreature *pCreature,
                    uint16_t nType,
                    int32_t param0,
                    int32_t param1,
                    int32_t param2,
                    int32_t param3,
                    int32_t param4,
                    int32_t param5)
{
    auto *eff = new API::CGameEffect(true);
    eff->m_oidCreator         = MODULE_OID;
    eff->m_nType              = nType;
    eff->m_nSubType           = EffectSubType::Supernatural | EffectDurationType::Innate;
    eff->m_bShowIcon          = g_plugin->m_ShowEffectIcon;
    eff->m_nParamInteger[0]   = param0;
    eff->m_nParamInteger[1]   = param1;
    eff->m_nParamInteger[2]   = param2;
    eff->m_nParamInteger[3]   = param3;
    eff->m_nParamInteger[4]   = param4;
    eff->m_nParamInteger[5]   = param5;
    eff->m_sCustomTag         = "NWNX_Race_RacialMod";
    pCreature->ApplyEffect(eff, true, true);
}

void Race::ApplyRaceEffects(CNWSCreature *pCreature)
{
    auto pPOS = g_plugin->GetServices()->m_perObjectStorage.get();
    auto effectsLevelAdded = *pPOS->Get<int>(pCreature->m_idSelf, "RACEMODS_ADDED_LEVEL");

    if (pCreature->m_pStats == nullptr || pCreature->m_pStats->GetLevel(true) == effectsLevelAdded)
        return;

    auto nLevel = pCreature->m_pStats->GetLevel(true);
    auto nRace = pCreature->m_pStats->m_nRace;

    // Remove any existing racial effects, this is done when the player levels up and we reapply
    // the racial modifiers.
    if (effectsLevelAdded)
    {
        for (int i = 0; i < pCreature->m_appliedEffects.num; i++)
        {
            auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
            if (eff->m_sCustomTag == "NWNX_Race_RacialMod")
            {
                pCreature->RemoveEffect(eff);
            }
        }
    }

    // AB
    auto modAB = g_plugin->m_RaceAB[nRace];
    if (modAB != 0)
    {
        g_plugin->DoEffect(pCreature,
                           modAB > 0 ? EffectTrueType::AttackIncrease : EffectTrueType::AttackDecrease,
                           abs(modAB), 0, RacialType::Invalid);
    }

    // ABVSRACE
    for (auto &ABVsRaceMod : g_plugin->m_RaceABVsRace[nRace])
    {
        auto vsRace = ABVsRaceMod.first;
        auto modVsRace = ABVsRaceMod.second;
        if (modVsRace != 0)
        {
            g_plugin->DoEffect(pCreature,
                               modVsRace > 0 ? EffectTrueType::AttackIncrease : EffectTrueType::AttackDecrease,
                               abs(modVsRace), 0, vsRace);
        }
    }

    // AC
    auto modAC = g_plugin->m_RaceAC[nRace];
    if (modAC != 0)
    {
        g_plugin->DoEffect(pCreature,
                           modAC > 0 ? EffectTrueType::ACIncrease : EffectTrueType::ACDecrease,
                           ACBonus::Dodge, abs(modAC), RacialType::Invalid, 0, 0, 4103);
    }

    // ACVSRACE
    for (auto &ACVsRaceMod : g_plugin->m_RaceACVsRace[nRace])
    {
        auto vsRace = ACVsRaceMod.first;
        auto modVsRace = ACVsRaceMod.second;
        if (modVsRace != 0)
        {
            g_plugin->DoEffect(pCreature,
                               modVsRace > 0 ? EffectTrueType::ACIncrease : EffectTrueType::ACDecrease,
                               ACBonus::Dodge, abs(modVsRace), vsRace, 0, 0, 4103);
        }
    }

    // CONCEALMENT
    auto modConceal = g_plugin->m_RaceConcealment[nRace];
    if (modConceal != 0)
    {
        g_plugin->DoEffect(pCreature, EffectTrueType::Concealment, modConceal, RacialType::Invalid);
    }

    // DMGIMMUNITY
    for (auto &dmgImmunityMod : g_plugin->m_RaceDmgImmunity[nRace])
    {
        auto modDmgImmunityType = dmgImmunityMod.first;
        auto modDmgImmunityValue = dmgImmunityMod.second;
        if (modDmgImmunityValue != 0)
        {
            g_plugin->DoEffect(pCreature, modDmgImmunityValue > 0 ? EffectTrueType::DamageImmunityIncrease
                                                                  : EffectTrueType::DamageImmunityDecrease,
                               modDmgImmunityType, abs(modDmgImmunityValue));
        }
    }

    // DMGREDUCTION
    for (auto &dmgResistMod : g_plugin->m_RaceDmgReduction[nRace])
    {
        auto modDmgReductionType = dmgResistMod.first;
        auto modDmgReductionValue = dmgResistMod.second;
        if (modDmgReductionValue != 0)
        {
            g_plugin->DoEffect(pCreature, EffectTrueType::DamageReduction, modDmgReductionType, modDmgReductionValue);
        }
    }

    // DMGRESIST
    for (auto &dmgResistMod : g_plugin->m_RaceDmgResist[nRace])
    {
        auto modDmgResistType = dmgResistMod.first;
        auto modDmgResistValue = dmgResistMod.second;
        if (modDmgResistValue != 0)
        {
            g_plugin->DoEffect(pCreature, EffectTrueType::DamageResistance, modDmgResistType, modDmgResistValue);
        }
    }

    // FEAT
    for (auto &featDetails : g_plugin->m_RaceFeat[nRace])
    {
        auto featId = featDetails.first;
        auto featLevel = featDetails.second;
        if (featLevel <= nLevel && !pCreature->m_pStats->HasFeat(featId))
        {
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[featLevel-1];
            pLevelStats->AddFeat(featId);
            pCreature->m_pStats->AddFeat(featId);
        }
    }

    // FEATUSAGE
    for (auto &raceFeatUsage : g_plugin->m_RaceFeatUsage[nRace])
    {
        auto featId = raceFeatUsage.first;
        auto fuChargen = raceFeatUsage.second.first;
        auto fuLevel = raceFeatUsage.second.second;
        auto levelMod = std::floor(pCreature->m_pStats->GetLevel(true) / fuLevel);
        auto totalMod = int32_t(fuChargen + levelMod);
        auto featRemainingUses = pCreature->m_pStats->GetFeatRemainingUses(featId);
        if (totalMod < featRemainingUses)
            pCreature->m_pStats->SetFeatRemainingUses(featId, totalMod);
    }

    // IMMUNITY
    for (auto &immunity : g_plugin->m_RaceImmunities[pCreature->m_pStats->m_nRace])
    {
        g_plugin->DoEffect(pCreature, EffectTrueType::Immunity, immunity, RacialType::Invalid);
    }

    // MOVEMENTSPEED
    auto modSpeed = g_plugin->m_RaceMovementSpeed[nRace];
    if (modSpeed != 0)
    {
        g_plugin->DoEffect(pCreature, EffectTrueType::MovementSpeedIncrease, modSpeed);
    }

    // REGENERATION
    auto modRegenAmount = g_plugin->m_RaceRegeneration[nRace].first;
    auto modRegenInterval = g_plugin->m_RaceRegeneration[nRace].second;
    if (modRegenAmount != 0)
    {
        g_plugin->DoEffect(pCreature, EffectTrueType::Regenerate, modRegenAmount,
                           modRegenInterval > 0 ? modRegenInterval * 1000 : 6000);
    }

    // SAVE
    for (auto &saveMod : g_plugin->m_RaceSave[nRace])
    {
        auto saveType = saveMod.first;
        auto mod = saveMod.second;
        if (mod != 0)
        {
            g_plugin->DoEffect(pCreature,
                               mod > 0 ? EffectTrueType::SavingThrowIncrease : EffectTrueType::SavingThrowDecrease,
                               abs(mod), saveType, SavingThrowType::All, RacialType::Invalid);
        }
    }

    // SAVEVSRACE
    for (auto &saveMod : g_plugin->m_RaceSaveVsRace[nRace])
    {
        auto saveType = saveMod.first;
        for (auto &saveVsRaceMod : g_plugin->m_RaceSaveVsRace[nRace][saveType])
        {
            auto saveVsRace = saveVsRaceMod.first;
            auto modVsRace = saveVsRaceMod.second;
            if (modVsRace != 0)
            {
                g_plugin->DoEffect(pCreature,
                                   modVsRace > 0 ? EffectTrueType::SavingThrowIncrease : EffectTrueType::SavingThrowDecrease,
                                   abs(modVsRace), saveType, SavingThrowType::All, saveVsRace);
            }
        }
    }

    // SAVEVSTYPE
    for (auto &saveMod : g_plugin->m_RaceSaveVsType[nRace])
    {
        auto saveType = saveMod.first;
        for (auto &saveVsTypeMod : g_plugin->m_RaceSaveVsType[nRace][saveType])
        {
            auto saveVsType = saveVsTypeMod.first;
            auto modVsType = saveVsTypeMod.second;
            if (modVsType != 0)
            {
                g_plugin->DoEffect(pCreature,
                                   modVsType > 0 ? EffectTrueType::SavingThrowIncrease : EffectTrueType::SavingThrowDecrease,
                                   abs(modVsType), saveType, saveVsType, RacialType::Invalid);
            }
        }
    }

    // SPELLIMMUNITY
    for (auto &spellImmunity : g_plugin->m_RaceSpellImmunities[pCreature->m_pStats->m_nRace])
    {
        g_plugin->DoEffect(pCreature, EffectTrueType::SpellImmunity, spellImmunity);
    }

    // SR
    auto mod_SRCharGen = g_plugin->m_RaceSRCharGen[nRace].first;
    auto mod_SRMax = g_plugin->m_RaceSRCharGen[nRace].second;
    auto mod_SRInc = std::get<0>(g_plugin->m_RaceSR[nRace]);
    auto mod_SRLevel = std::get<1>(g_plugin->m_RaceSR[nRace]);
    auto mod_SRStart = std::get<2>(g_plugin->m_RaceSR[nRace]);
    auto mod_SRPerLevelCalc = 0;
    if (mod_SRLevel > 0)
        mod_SRPerLevelCalc = int32_t(std::floor(((nLevel - mod_SRStart + 1) / mod_SRLevel) * mod_SRInc));
    int32_t mod_SR = mod_SRCharGen + (mod_SRPerLevelCalc > 0 ? mod_SRPerLevelCalc : 0);
    mod_SR = (mod_SR > mod_SRMax && mod_SRMax > 0) ? mod_SRMax : mod_SR;
    if (mod_SR != 0)
    {
        g_plugin->DoEffect(pCreature, EffectTrueType::SpellResistanceIncrease, mod_SR);
    }

    pPOS->Set(pCreature->m_idSelf, "RACEMODS_ADDED_LEVEL", nLevel);
}

void Race::PostProcessHook(
        Services::Hooks::CallType cType,
        CNWSCreature *pCreature)
{
    // We only want to do this in the AFTER
    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
        return;

    pCreature->m_bApplyingPostProcessEffects = true;
    g_plugin->ApplyRaceEffects(pCreature);
    pCreature->m_bApplyingPostProcessEffects = false;
}

void Race::SavingThrowRollHook(
        Services::Hooks::CallType cType,
        CNWSCreature *pCreature,
        uint8_t nSaveType,
        uint16_t,
        uint8_t nSpecificType,
        uint32_t oidSaveVersus,
        int32_t, uint16_t, int32_t)
{
    auto server = Globals::AppManager()->m_pServerExoApp;
    static uint16_t savingThrowBonusLimit;
    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        savingThrowBonusLimit = Globals::AppManager()->m_pServerExoApp->GetSavingThrowBonusLimit();
        auto nRace = pCreature->m_pStats->m_nRace;
        auto sRace = std::to_string(nRace);
        auto tgtCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(oidSaveVersus);
        auto modSaveBonus = g_plugin->m_RaceSave[nRace][nSaveType] + g_plugin->m_RaceSave[nRace][SavingThrow::All];
        uint8_t modSaveVSRaceBonus = 0;
        if (tgtCreature)
        {
            modSaveVSRaceBonus = g_plugin->m_RaceSaveVsRace[nRace][nSaveType][tgtCreature->m_pStats->m_nRace] +
                                 g_plugin->m_RaceSaveVsRace[nRace][SavingThrow::All][tgtCreature->m_pStats->m_nRace];
        }
        auto modSaveVSTypeBonus = g_plugin->m_RaceSaveVsType[nRace][nSaveType][nSpecificType] +
                                  g_plugin->m_RaceSaveVsType[nRace][SavingThrow::All][nSpecificType];
        server->SetSavingThrowBonusLimit(
                server->GetSavingThrowBonusLimit() + modSaveBonus + modSaveVSRaceBonus + modSaveVSTypeBonus);
    }
    else
    {
        server->SetSavingThrowBonusLimit(savingThrowBonusLimit);
    }
}

void Race::GetWeaponPowerHook(
    Services::Hooks::CallType cType,
    CNWSCreature *pCreature,
    CNWSObject *pObject, int32_t)
{
    auto server = Globals::AppManager()->m_pServerExoApp;
    static uint16_t attackBonusLimit;
    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        attackBonusLimit = Globals::AppManager()->m_pServerExoApp->GetAttackBonusLimit();
        auto nRace = pCreature->m_pStats->m_nRace;
        auto modABBonus = g_plugin->m_RaceAB[nRace];
        uint8_t modABVSRaceBonus = 0;
        auto tgtCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
        if (tgtCreature)
            modABVSRaceBonus = g_plugin->m_RaceABVsRace[nRace][tgtCreature->m_pStats->m_nRace];
        server->SetAttackBonusLimit(server->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);
    }
    else
    {
        server->SetAttackBonusLimit(attackBonusLimit);
    }
}

void Race::GetTotalEffectBonusHook(
        Services::Hooks::CallType cType,
        CNWSCreature *pCreature,
        uint8_t nEffectBonusType,
        CNWSObject *pObject,
        int32_t, int32_t, uint8_t, uint8_t, uint8_t nSkill, uint8_t, int32_t)
{
    auto server = Globals::AppManager()->m_pServerExoApp;
    static uint16_t attackBonusLimit;
    static uint16_t skillBonusLimit;

    // We only swap to the parent race for the target when using GetTotalEffectBonus
    CNWSCreature* tgtCreature = nullptr;
    if (pObject != nullptr)
    {
        tgtCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
        SetOrRestoreRace(cType, nullptr, tgtCreature->m_pStats);
    }

    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        auto nRace = pCreature->m_pStats->m_nRace;
        auto sRace = std::to_string(nRace);
        if (nEffectBonusType == 1)
        {
                attackBonusLimit = Globals::AppManager()->m_pServerExoApp->GetAttackBonusLimit();
                auto modABBonus = g_plugin->m_RaceAB[nRace];
                uint8_t modABVSRaceBonus = 0;
                if (tgtCreature)
                    modABVSRaceBonus = g_plugin->m_RaceABVsRace[nRace][tgtCreature->m_pStats->m_nRace];
                server->SetAttackBonusLimit(server->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);
        }
        else if (nEffectBonusType == 5)
        {
            skillBonusLimit = Globals::AppManager()->m_pServerExoApp->GetSkillBonusLimit();
            auto modSkillBonus = g_plugin->m_RaceSkill[nRace][nSkill];
            server->SetSkillBonusLimit(server->GetSkillBonusLimit() + modSkillBonus);
        }
    }
    else
    {
        if (nEffectBonusType == 1)
            server->SetAttackBonusLimit(attackBonusLimit);
        else if (nEffectBonusType == 5)
            server->SetSkillBonusLimit(skillBonusLimit);
    }
}

void Race::ResetFeatRemainingUsesHook(
        Services::Hooks::CallType type,
        CNWSCreatureStats *pCreatureStats)
{
    // Only need to do this in the after
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL)
        return;

    auto pCreature = pCreatureStats->m_pBaseCreature;
    auto nRace = pCreatureStats->m_nRace;

    // Check for any feat usage calcs
    for (auto &raceFeatUsage : g_plugin->m_RaceFeatUsage[nRace])
    {
        auto featId = raceFeatUsage.first;
        auto fuCharGen = raceFeatUsage.second.first;
        auto fuLevel = raceFeatUsage.second.second;
        auto levelMod = std::floor(pCreature->m_pStats->GetLevel(true) / fuLevel);
        auto totalMod = int32_t(fuCharGen + levelMod);
        auto featRemainingUses = pCreature->m_pStats->GetFeatRemainingUses(featId);
        if (totalMod < featRemainingUses)
            pCreature->m_pStats->SetFeatRemainingUses(featId, totalMod);
    }
}

void Race::ResolveInitiativeHook(CNWSCreature *pCreature)
{
    if (pCreature->m_bInitiativeExpired == 1)
    {
        auto pStats = pCreature->m_pStats;
        auto diceRoll = Globals::Rules()->RollDice(1, 20);
        auto mod = pStats->GetDEXMod(0);
        if (pStats->HasFeat(Feat::EpicSuperiorInitiative))
            mod += 8;
        else if (pStats->HasFeat(Feat::ImprovedInitiative))
            mod += 4;
        if (pStats->HasFeat(Feat::Blooded))
            mod += 2;
        if (pStats->HasFeat(Feat::Thug))
            mod += 2;

        // Add racial bonus
        auto nRace = pCreature->m_pStats->m_nRace;
        auto sRace = std::to_string(nRace);
        mod += g_plugin->m_RaceInitiative[nRace];

        pCreature->m_nInitiativeRoll = diceRoll + mod;
        auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreature->m_idSelf);
        if (pPlayer)
        {
            auto *pData = new CNWCCMessageData;
            pData->SetInteger(0, diceRoll);
            pData->SetInteger(1, mod);
            pData->SetObjectID(0, pCreature->m_idSelf);
            auto *pMessage = static_cast<CNWSMessage*>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
            if (pMessage)
            {
                pMessage->SendServerToPlayerCCMessage(pPlayer->m_nPlayerID, MessageClientSideMsgMinor::Initiative, pData, nullptr);
            }
        }
        pCreature->m_bInitiativeExpired = 0;
    }
}

void Race::ValidateCharacterHook(
        Services::Hooks::CallType cType,
        CNWSPlayer *pPlayer,
        int32_t*)
{
    auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
    auto nRace = pCreature->m_pStats->m_nRace;
    if (cType == Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        for (auto &featDetails : g_plugin->m_RaceFeat[nRace])
        {
            auto featId = featDetails.first;
            auto featLevel = featDetails.second;
            if (featLevel > pCreature->m_pStats->m_lstLevelStats.num)
                continue;
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[featLevel-1];
            std::list<uint16_t> levelFeats;
            for (int i = 0; i < pLevelStats->m_lstFeats.num; i++)
            {
                if (pLevelStats->m_lstFeats.element[i] != featId)
                {
                    levelFeats.push_back(pLevelStats->m_lstFeats.element[i]);
                }
            }
            pLevelStats->ClearFeats();
            for (auto &feat : levelFeats)
            {
                pLevelStats->AddFeat(feat);
            }
            pCreature->m_pStats->RemoveFeat(featId);
        }
    }
    else
    {
        for (auto &featDetails : g_plugin->m_RaceFeat[nRace])
        {
            auto featId = featDetails.first;
            auto featLevel = featDetails.second;
            if (featLevel > pCreature->m_pStats->m_lstLevelStats.num)
                continue;
            auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[featLevel-1];
            pLevelStats->AddFeat(featId);
            pCreature->m_pStats->AddFeat(featId);
        }
    }

}

void Race::SendServerToPlayerLevelUp_ConfirmationHook(
        Services::Hooks::CallType cType,
        CNWSMessage *,
        Types::PlayerID playerId,
        int32_t bValidated)
{
    // Reapply the racial effects in case there are level specific ones
    if (cType == Services::Hooks::CallType::AFTER_ORIGINAL)
    {
        if (bValidated)
        {
            auto *client = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(playerId, 0);
            auto *pPlayer = static_cast<API::CNWSPlayer *>(client);
            auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
            ApplyRaceEffects(pCreature);
        }
    }
}

void Race::SetOrRestoreRace(
        Services::Hooks::CallType cType,
        CNWSCreatureStats *pCreatureStats,
        CNWSCreatureStats *pTgtCreatureStats)
{
    bool before = cType == Services::Hooks::CallType::BEFORE_ORIGINAL;
    static uint16_t originalRace;
    static uint16_t originalTgtRace;
    if (before)
    {
        if (pCreatureStats != nullptr)
        {
	    auto parentRace = g_plugin->m_RaceParent[pCreatureStats->m_nRace];
            originalRace = pCreatureStats->m_nRace;
            if (parentRace != RacialType::Invalid)
                pCreatureStats->m_nRace = parentRace;
        }
        if (pTgtCreatureStats != nullptr)
        {
            auto versusParentRace = g_plugin->m_RaceParent[pTgtCreatureStats->m_nRace];
            originalTgtRace = pTgtCreatureStats->m_nRace;
            if (versusParentRace != RacialType::Invalid)
                pTgtCreatureStats->m_nRace = versusParentRace;
        }
    }
    if (!before && pCreatureStats != nullptr && originalRace != pCreatureStats->m_nRace)
    {
        pCreatureStats->m_nRace = originalRace;
    }
    if (!before && pTgtCreatureStats != nullptr && originalTgtRace != pTgtCreatureStats->m_nRace)
    {
        pTgtCreatureStats->m_nRace = originalTgtRace;
    }
}

void Race::GetFavoredEnemyBonusHook(
        Services::Hooks::CallType cType,
        CNWSCreatureStats *pCreatureStats,
        CNWSCreature *pTgtCreature)
{
    SetOrRestoreRace(cType, pCreatureStats, pTgtCreature->m_pStats);
}

void Race::CreateDefaultQuickButtonsHook(
        Services::Hooks::CallType cType,
        CNWSCreature *pCreature)
{
    SetOrRestoreRace(cType, pCreature->m_pStats);
}

void Race::LevelUpAutomaticHook(
        Services::Hooks::CallType cType,
        CNWSCreatureStats *pCreatureStats,
        uint8_t,
        int32_t,
        uint8_t)
{
    SetOrRestoreRace(cType, pCreatureStats);
}

void Race::GetMeetsPrestigeClassRequirementsHook(
        Services::Hooks::CallType cType,
        CNWSCreatureStats *pCreatureStats,
        CNWClass *)
{
    SetOrRestoreRace(cType, pCreatureStats);
}

void Race::LoadRaceInfoHook(Services::Hooks::CallType type, CNWRules*)
{
    // We only want to do this in the AFTER
    if (type == Services::Hooks::CallType::BEFORE_ORIGINAL || !Globals::Rules())
        return;

    // Initialize the parent race to Invalid
    auto twoda = Globals::Rules()->m_p2DArrays->GetCached2DA("RACIALTYPES", true);
    for (int raceId = 0; raceId < twoda->m_nNumRows; raceId++)
    {
        std::string sRace = std::to_string(raceId);
        g_plugin->m_RaceParent[raceId] = RacialType::Invalid;
    }
}

void Race::SetRaceModifier(int32_t raceId, RaceModifier raceMod, int32_t param1, int32_t param2, int32_t param3)
{
    auto raceNameText = Globals::Rules()->m_lstRaces[raceId].GetNameText();
    auto raceName = raceNameText.CStr();
    std::string sRace = std::to_string(raceId);
    switch (raceMod)
    {
        case AB:
        {
            g_plugin->m_RaceAB[raceId] = param1;
            LOG_INFO("%s: Setting Natural AB modifier to %d.", raceName, param1);
            break;
        }
        case ABVSRACE:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Natural AB modifier vs Race modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceABVsRace[raceId][param1] = param2;
            auto versusRaceName = Globals::Rules()->m_lstRaces[param1].GetNamePluralText();
            LOG_INFO("%s: Setting Natural AB modifier vs %s to %d.", raceName, versusRaceName.CStr(), param2);
            break;
        }
        case AC:
        {
            g_plugin->m_RaceAC[raceId] = param1;
            LOG_INFO("%s: Setting Natural AC modifier to %d.", raceName, param1);
            break;
        }
        case ACVSRACE:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Natural AC modifier vs Race modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceACVsRace[raceId][param1] = param2;
            auto versusRaceName = Globals::Rules()->m_lstRaces[param1].GetNamePluralText();
            LOG_INFO("%s: Setting Natural AC modifier vs %s to %d.", raceName, versusRaceName.CStr(), param2);
            break;
        }
        case CONCEALMENT:
        {
            if (param1 < 1 || param1 > 100)
            {
                LOG_ERROR("%s: Natural Concealment modifier improperly set, value must be between 1 and 100.", raceName);
                break;
            }
            g_plugin->m_RaceConcealment[raceId] = param1;
            LOG_INFO("%s: Setting Natural Concealment modifier to %d.", raceName, param1);
            break;
        }
        case DMGIMMUNITY:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Damage Immunity modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceDmgImmunity[raceId][param1] = param2;
            if (param2 > 0)
                LOG_INFO("%s: Setting Damage Immunity vs %s to %d%%.", raceName, Constants::DamageType::ToString(param1), param2);
            else
                LOG_INFO("%s: Setting Damage Vulnerability vs %s to %d%%.", raceName, Constants::DamageType::ToString(param1), param2);
            break;
        }
        case DMGREDUCTION:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Damage Reduction modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceDmgReduction[raceId][param1] = param2;
            LOG_INFO("%s: Setting Damage Reduction to %d/+%d.", raceName, param1, param2);
            break;
        }
        case DMGRESIST:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Damage Resist modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceDmgResist[raceId][param1] = param2;
            LOG_INFO("%s: Setting Damage Resist vs %s to %d point(s).", raceName, Constants::DamageType::ToString(param1), param2);
            break;
        }
        case FEAT:
        {
            if (param2 == (int32_t)0xDEADBEEF || param2 <= 0)
            {
                LOG_ERROR("%s: Feat modifier improperly set.", raceName);
                break;
            }
            auto featName = Globals::Rules()->GetFeat(param1)->GetNameText();
            g_plugin->m_RaceFeat[raceId][param1] = param2;
            LOG_INFO("%s: Granting %s Feat at level %d.", raceName, featName.CStr(), param2);
            break;
        }
        case FEATUSAGE:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Feat Usage modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceFeatUsage[raceId][param1]= std::make_pair(param2, param3);
            auto featName = Globals::Rules()->GetFeat(param1)->GetNameText();
            LOG_INFO("%s: Setting %s Feat Usage Per Day to %d + 1 for every %d level(s).", raceName, featName.CStr(), param2, param3);
            break;
        }
        case IMMUNITY:
        {
            if (g_plugin->m_RaceImmunities.count(raceId))
            {
                g_plugin->m_RaceImmunities[raceId].push_back(param1);
            }
            else
            {
                std::list<uint32_t> immunities;
                immunities.push_back(param1);
                g_plugin->m_RaceImmunities[raceId] = immunities;
            }
            LOG_INFO("%s: Setting %s Immunity.", raceName, Constants::ImmunityType::ToString(param1));
            break;
        }
        case INITIATIVE:
        {
            g_plugin->m_RaceInitiative[raceId] = param1;
            LOG_INFO("%s: Setting Initiative modifier to %d.", raceName, param1);
            break;
        }
        case MOVEMENTSPEED:
        {
            g_plugin->m_RaceMovementSpeed[raceId] = param1;
            LOG_INFO("%s: Setting Movement Speed to %d%%.", raceName, param1);
            break;
        }
        case RACE:
        {
            g_plugin->m_RaceParent[raceId] = param1;
            auto parentRaceName = Globals::Rules()->m_lstRaces[param1].GetNameText();
            LOG_INFO("%s: Setting parent race to %s.", raceName, parentRaceName.CStr());
            break;
        }
        case REGENERATION:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Regeneration modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceRegeneration[raceId] = std::make_pair(param1, param2);
            LOG_INFO("%s: Setting Regeneration to %d hit point(s) every %d second(s).", raceName, param1, param2);
            break;
        }
        case SAVE:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceSave[raceId][param1] = param2;
            LOG_INFO("%s: Setting %s Save modifier to %d.", raceName, Constants::SavingThrow::ToString(param1), param2);
            break;
        }
        case SAVEVSRACE:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save vs Race modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceSaveVsRace[raceId][param1][param2] = param3;
            LOG_INFO("%s: Setting %s Saves vs Race: %s modifier to %d.", raceName,
                     Constants::SavingThrow::ToString(param1), Globals::Rules()->m_lstRaces[param2].GetNameText().CStr(),
                     param3);
            break;
        }
        case SAVEVSTYPE:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save vs Type modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceSaveVsType[raceId][param1][param2] = param3;
            LOG_INFO("%s: Setting %s Saves vs Type: %s modifier to %d.", raceName,
                     Constants::SavingThrow::ToString(param1), Constants::SavingThrowType::ToString(param2),
                     param3);
            break;
        }
        case SKILL:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Skill modifier improperly set.", raceName);
                break;
            }
            g_plugin->GetServices()->m_messaging->BroadcastMessage("NWNX_SKILLRANK_SIGNAL",
                                                                   {std::to_string(param1), sRace,
                                                                    std::to_string(param2)});

            g_plugin->m_RaceSkill[raceId][param1] = param2;
            auto skillName = Globals::Rules()->m_lstSkills[param1].GetNameText();
            LOG_INFO("%s: Setting Skill modifier of %d for %s.", raceName, param2, skillName.CStr());
            break;
        }
        case SPELLIMMUNITY:
        {
            if (g_plugin->m_RaceSpellImmunities.count(raceId))
            {
                g_plugin->m_RaceSpellImmunities[raceId].push_back(param1);
            }
            else
            {
                std::list<uint32_t> immunities;
                immunities.push_back(param1);
                g_plugin->m_RaceSpellImmunities[raceId] = immunities;
            }
            auto spellName = Globals::Rules()->m_pSpellArray[0].GetSpell(param1)->GetSpellNameText();
            LOG_INFO("%s: Setting %s Spell Immunity.", raceName, spellName.CStr());
            break;
        }
        case SRCHARGEN:
        {
            g_plugin->m_RaceSRCharGen[raceId] = std::make_pair(param1, param2);
            LOG_INFO("%s: Setting Spell Resistance on character creation to %d.", raceName, param1);
            if (param2 > 0)
                LOG_INFO("%s: Setting Maximum Racial Spell Resistance to %d.", raceName, param2);
            break;
        }
        case SRINCLEVEL:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF || param2 <= 0 || param3 <= 0)
            {
                LOG_ERROR("%s: Incremental Spell Resistance modifier improperly set.", raceName);
                break;
            }
            g_plugin->m_RaceSR[raceId] = {param1, param2, param3};
            LOG_INFO("%s: Setting Spell Resistance increment %d point(s) every %d level(s) beginning at level %d.", raceName, param1, param2, param3);
            break;
        }
        case INVALID:
        {
            LOG_ERROR("Race modifier not recognized.");
            break;
        }
    }
}

ArgumentStack Race::SetRacialModifier(ArgumentStack&& args)
{
    ArgumentStack stack;

    auto raceId = Services::Events::ExtractArgument<int>(args);
    auto raceMod = static_cast<RaceModifier>(Services::Events::ExtractArgument<int>(args));
    auto param1 = Services::Events::ExtractArgument<int>(args);
    auto param2 = Services::Events::ExtractArgument<int>(args);
    auto param3 = Services::Events::ExtractArgument<int>(args);

    SetRaceModifier(raceId, raceMod, param1, param2, param3);

    return stack;
}

ArgumentStack Race::GetParentRace(ArgumentStack&& args)
{
    ArgumentStack stack;

    auto raceId = Services::Events::ExtractArgument<int>(args);
    auto parentRace = g_plugin->m_RaceParent[raceId] == RacialType::Invalid ? raceId : g_plugin->m_RaceParent[raceId];
    Services::Events::InsertArgument(stack, parentRace);
    return stack;
}

}
