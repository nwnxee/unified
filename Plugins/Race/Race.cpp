#include "Race.hpp"
#include "API/C2DA.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
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
#include "API/CNWSEffectListHandler.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "API/CNWSItem.hpp"
#include "API/Constants/Effect.hpp"
#include "API/CNWSCombatRound.hpp"
#include <cmath>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

static Race::Race* g_plugin;

const auto MODULE_OID = 0;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Race::Race(services);
    return g_plugin;
}


namespace Race {

static Hooks::Hook s_LoadCharacterFinishHook;
static Hooks::Hook s_GetTotalEffectBonusHook;
static Hooks::Hook s_SavingThrowRollHook;
static Hooks::Hook s_GetWeaponPowerHook;
static Hooks::Hook s_ResetFeatRemainingUsesHook;
static Hooks::Hook s_SendServerToPlayerLevelUp_ConfirmationHook;
static Hooks::Hook s_CreateDefaultQuickButtonsHook;
static Hooks::Hook s_LevelUpAutomaticHook;
static Hooks::Hook s_GetMeetsPrestigeClassRequirementsHook;
static Hooks::Hook s_LoadRaceInfoHook;
static Hooks::Hook s_ValidateCharacterHook;
static Hooks::Hook s_GetAttackModifierVersusHook;
static Hooks::Hook s_GetArmorClassVersusHook;

// Replaced completely
static Hooks::Hook s_ResolveInitiativeHook;
static Hooks::Hook s_CheckItemRaceRestrictionsHook;
static Hooks::Hook s_GetFavoredEnemyBonusHook;


Race::Race(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    ScriptAPI::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetRacialModifier);
    REGISTER(GetParentRace);
    REGISTER(SetFavoredEnemyFeat);
    REGISTER(SuppressCreatureRaceEffects);
    REGISTER(ReactivateCreatureRaceEffects);

#undef REGISTER

    m_ShowEffectIcon = Config::Get<bool>("SHOW_EFFECT_ICON", false);

    // Most racial adjustments are done here using effects only once per server reset or after a level up
    s_LoadCharacterFinishHook = Hooks::HookFunction(&CServerExoAppInternal::LoadCharacterFinish,
                                                             &LoadCharacterFinishHook, Hooks::Order::Early);

    // We want the racial bonuses to not count toward limits
    s_GetTotalEffectBonusHook = Hooks::HookFunction(&CNWSCreature::GetTotalEffectBonus,
                                                             &GetTotalEffectBonusHook, Hooks::Order::Early);
    s_SavingThrowRollHook = Hooks::HookFunction(&CNWSCreature::SavingThrowRoll,
                                                         &SavingThrowRollHook, Hooks::Order::Early);
    s_GetWeaponPowerHook = Hooks::HookFunction(&CNWSCreature::GetWeaponPower,
                                                        &GetWeaponPowerHook, Hooks::Order::Early);

    s_GetAttackModifierVersusHook = Hooks::HookFunction(
            &CNWSCreatureStats::GetAttackModifierVersus, &Race::GetAttackModifierVersusHook, Hooks::Order::Late);

    s_GetArmorClassVersusHook = Hooks::HookFunction(
            &CNWSCreatureStats::GetArmorClassVersus, &Race::GetArmorClassVersusHook, Hooks::Order::Late);

#define HOOK_APPLY_EFFECT(_address) \
    static Hooks::Hook CAT(pOnApplyHook, __LINE__) = Hooks::HookFunction(_address, \
    +[](CNWSEffectListHandler *thisPtr, CNWSObject *pObject, CGameEffect *pEffect, BOOL bLoadingGame) -> int32_t \
    { \
        ApplyEffectHook(pObject, pEffect);  \
        return CAT(pOnApplyHook, __LINE__)->CallOriginal<int32_t>(thisPtr, pObject, pEffect, bLoadingGame);  \
    }, Hooks::Order::Early)

    // Make effects applied to parent races effect every child race
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyAttackIncrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyAttackDecrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyConcealment);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyDamageIncrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyDamageDecrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyEffectImmunity);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyACDecrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyACIncrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplyInvisibility);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplySanctuary);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplySavingThrowDecrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplySavingThrowIncrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplySkillDecrease);
    HOOK_APPLY_EFFECT(&CNWSEffectListHandler::OnApplySkillIncrease);

#undef HOOK_APPLY_EFFECT

    // Special hook for resetting the feat usages after rest etc.
    s_ResetFeatRemainingUsesHook = Hooks::HookFunction(&CNWSCreatureStats::ResetFeatRemainingUses,
                                                                &ResetFeatRemainingUsesHook, Hooks::Order::Early);

    // Completely rewritten in NWNX for Race plugin so we can add our Initiative changes
    s_ResolveInitiativeHook = Hooks::HookFunction(&CNWSCreature::ResolveInitiative, &ResolveInitiativeHook, Hooks::Order::Final);

    // If a level up has been confirmed we rerun the racial applications in case of new feats, level based adjustments etc.
    s_SendServerToPlayerLevelUp_ConfirmationHook = Hooks::HookFunction(&CNWSMessage::SendServerToPlayerLevelUp_Confirmation,
                                                                                &SendServerToPlayerLevelUp_ConfirmationHook, Hooks::Order::Early);

    // Swap race with parent race due to hardcoded checks here
    s_CreateDefaultQuickButtonsHook = Hooks::HookFunction(&CNWSCreature::CreateDefaultQuickButtons,
                                                                   &CreateDefaultQuickButtonsHook, Hooks::Order::Early);
    s_LevelUpAutomaticHook = Hooks::HookFunction(&CNWSCreatureStats::LevelUpAutomatic,
                                                          &LevelUpAutomaticHook, Hooks::Order::Early);
    s_GetMeetsPrestigeClassRequirementsHook = Hooks::HookFunction(&CNWSCreatureStats::GetMeetsPrestigeClassRequirements,
                                                                           &GetMeetsPrestigeClassRequirementsHook, Hooks::Order::Early);

    //Don't swap, check as both parent and child race
    s_CheckItemRaceRestrictionsHook = Hooks::HookFunction(&CNWSCreature::CheckItemRaceRestrictions, &CheckItemRaceRestrictionsHook, Hooks::Order::Final);

    // Need to set up default parent race to invalid before the on module load sets up the parents
    s_LoadRaceInfoHook = Hooks::HookFunction(&CNWRules::LoadRaceInfo, &LoadRaceInfoHook, Hooks::Order::Early);

    // Check for favored enemy bonuses on either the race or parent race including custom set favored enemy feats for custom races
    s_GetFavoredEnemyBonusHook = Hooks::HookFunction(&CNWSCreatureStats::GetFavoredEnemyBonus, &GetFavoredEnemyBonusHook, Hooks::Order::Final);

    s_ValidateCharacterHook = Hooks::HookFunction(&CNWSPlayer::ValidateCharacter, &ValidateCharacterHook, Hooks::Order::Early);
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
    auto *eff = new CGameEffect(true);
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

void Race::RemoveRaceEffects(CNWSCreature *pCreature)
{
    auto effectsLevelAdded = *pCreature->nwnxGet<int>("RACEMODS_ADDED_LEVEL");
    if (pCreature->m_pStats == nullptr || effectsLevelAdded == 0)
        return;

    std::vector<uint64_t> remove(128);
    for (int32_t i = 0; i < pCreature->m_appliedEffects.num; i++)
    {
        auto eff = (CGameEffect*)pCreature->m_appliedEffects.element[i];
        if (eff->m_sCustomTag == "NWNX_Race_RacialMod")
        {
            remove.push_back(eff->m_nID);
        }
    }
    for (auto id: remove)
        pCreature->RemoveEffectById(id);

    pCreature->nwnxRemove("RACEMODS_ADDED_LEVEL");
}

void Race::ApplyRaceEffects(CNWSCreature *pCreature)
{
    auto effectsLevelAdded = *pCreature->nwnxGet<int>("RACEMODS_ADDED_LEVEL");

    if (pCreature->m_pStats == nullptr || pCreature->m_pStats->GetLevel(true) == effectsLevelAdded)
        return;

    auto nLevel = pCreature->m_pStats->GetLevel(true);
    auto nRace = pCreature->m_pStats->m_nRace;

    // Remove any existing racial effects, this is done when the player levels up and we reapply
    // the racial modifiers.
    if (effectsLevelAdded)
    {
        RemoveRaceEffects(pCreature);
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
    auto modAC = g_plugin->m_RaceAC[nRace].first;
    auto typeAC = g_plugin->m_RaceAC[nRace].second;
    if (modAC != 0)
    {
        g_plugin->DoEffect(pCreature,
                           modAC > 0 ? EffectTrueType::ACIncrease : EffectTrueType::ACDecrease,
                           typeAC, abs(modAC), RacialType::Invalid, 0, 0, 4103);
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

    pCreature->nwnxSet("RACEMODS_ADDED_LEVEL", nLevel);
}

int32_t Race::LoadCharacterFinishHook(CServerExoAppInternal *pServerExoAppInternal, CNWSPlayer *pPlayer, int32_t bUseSaveGameCharacter, int32_t bUseStateDataInSaveGame)
{
    auto retVal = s_LoadCharacterFinishHook->CallOriginal<int32_t>(pServerExoAppInternal, pPlayer, bUseSaveGameCharacter, bUseStateDataInSaveGame);

    if (auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject))
        g_plugin->ApplyRaceEffects(pCreature);

    return retVal;
}

uint8_t Race::SavingThrowRollHook(CNWSCreature *pCreature, uint8_t nSaveType, uint16_t nDifficultyClass, uint8_t nSpecificType,
                                  ObjectID oidSaveVersus, int32_t bPrint, uint16_t nFeat, int32_t bQueueFeedback)
{
    auto *pServerExoApp= Globals::AppManager()->m_pServerExoApp;
    uint16_t savingThrowBonusLimit = pServerExoApp->GetSavingThrowBonusLimit();

    auto nRace = pCreature->m_pStats->m_nRace;
    auto *pTargetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(oidSaveVersus);
    auto modSaveBonus = g_plugin->m_RaceSave[nRace][nSaveType] + g_plugin->m_RaceSave[nRace][SavingThrow::All];
    uint8_t modSaveVSRaceBonus = 0;
    if (pTargetCreature)
    {
        modSaveVSRaceBonus = g_plugin->m_RaceSaveVsRace[nRace][nSaveType][pTargetCreature->m_pStats->m_nRace] +
                             g_plugin->m_RaceSaveVsRace[nRace][SavingThrow::All][pTargetCreature->m_pStats->m_nRace];
    }
    auto modSaveVSTypeBonus = g_plugin->m_RaceSaveVsType[nRace][nSaveType][nSpecificType] +
                              g_plugin->m_RaceSaveVsType[nRace][SavingThrow::All][nSpecificType];

    pServerExoApp->SetSavingThrowBonusLimit(pServerExoApp->GetSavingThrowBonusLimit() + modSaveBonus + modSaveVSRaceBonus + modSaveVSTypeBonus);

    auto retVal = s_SavingThrowRollHook->CallOriginal<uint8_t>(pCreature, nSaveType, nDifficultyClass, nSpecificType,
                                                               oidSaveVersus, bPrint, nFeat, bQueueFeedback);

    pServerExoApp->SetSavingThrowBonusLimit(savingThrowBonusLimit);

    return retVal;
}

int32_t Race::GetWeaponPowerHook(CNWSCreature *pCreature, CNWSObject *pObject, int32_t bOffHand)
{
    auto *pServerExoApp= Globals::AppManager()->m_pServerExoApp;
    uint16_t attackBonusLimit = pServerExoApp->GetAttackBonusLimit();

    auto nRace = pCreature->m_pStats->m_nRace;
    auto modABBonus = g_plugin->m_RaceAB[nRace];
    uint8_t modABVSRaceBonus = 0;
    auto *pTargetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
    if (pTargetCreature)
    {
        modABVSRaceBonus = g_plugin->m_RaceABVsRace[nRace][pTargetCreature->m_pStats->m_nRace];
        auto parRace = g_plugin->m_RaceParent[pTargetCreature->m_pStats->m_nRace];
        if(parRace != RacialType::Invalid)
            modABVSRaceBonus = g_plugin->m_RaceABVsRace[nRace][parRace];
    }


    pServerExoApp->SetAttackBonusLimit(pServerExoApp->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);

    auto retVal = s_GetWeaponPowerHook->CallOriginal<int32_t>(pCreature, pObject, bOffHand);

    pServerExoApp->SetAttackBonusLimit(attackBonusLimit);

    return retVal;
}

void Race::ApplyEffectHook(CNWSObject *pObject, CGameEffect *pEffect)
{
    CNWSCreature* tgtCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
    if (tgtCreature == nullptr)
        return;
    uint8_t nRaceParam;
    //get the proper parameter that contains race
    switch(pEffect->m_nType)
    {
        case EffectTrueType::SavingThrowIncrease:
        case EffectTrueType::SavingThrowDecrease: nRaceParam = 3; break;
        case EffectTrueType::Immunity:
        case EffectTrueType::Invisibility:
        case EffectTrueType::Sanctuary:
        case EffectTrueType::Concealment: nRaceParam = 1; break;
            //AC, AB, Skill, Dmg increases and decreases
        default: nRaceParam = 2; break;
    }
    std::vector<uint16_t> vChild = g_plugin->m_ChildRaces[pEffect->m_nParamInteger[nRaceParam]];
    CGameEffect *pEffectNew;
    int32_t i;
    for(uint16_t &nChild : vChild)
    {
        pEffectNew = new CGameEffect(false);
        pEffectNew->m_nNumIntegers = pEffect->m_nNumIntegers;
        for(i = 0; i < pEffect->m_nNumIntegers; i++)
            pEffectNew->m_nParamInteger[i] = pEffect->m_nParamInteger[i];
        pEffectNew->m_nID = pEffect->m_nID;
        pEffectNew->m_oidCreator = pEffect->m_oidCreator;
        pEffectNew->m_nType = pEffect->m_nType;
        pEffectNew->m_nSubType = pEffect->m_nSubType;
        pEffectNew->m_fDuration = pEffect->m_fDuration;
        pEffectNew->m_nExpiryCalendarDay = pEffect->m_nExpiryCalendarDay;
        pEffectNew->m_nExpiryTimeOfDay = pEffect->m_nExpiryTimeOfDay;
        pEffectNew->m_nParamInteger[nRaceParam] = nChild;
        pEffectNew->m_nItemPropertySourceId = pEffect->m_nItemPropertySourceId;
        pEffectNew->m_bExpose = pEffect->m_bExpose;
        pEffectNew->m_bShowIcon = pEffect->m_bShowIcon;
        pEffectNew->m_nCasterLevel = pEffect->m_nCasterLevel;
        pEffectNew->m_bSkipOnLoad = pEffect->m_bSkipOnLoad;
        pEffectNew->m_nSpellId = pEffect->m_nSpellId;
        pEffectNew->m_sCustomTag = pEffect->m_sCustomTag;
        for(i = 0; i < 4; i++)
        {
            pEffectNew->m_nParamFloat[i] = pEffect->m_nParamFloat[i];
            pEffectNew->m_oidParamObjectID[i] = pEffect->m_oidParamObjectID[i];
        }
        for(i = 0; i < 6; i++)
            pEffectNew->m_sParamString[i] = pEffect->m_sParamString[i];

        tgtCreature->ApplyEffect(pEffectNew, false, true);
    }
}
int32_t Race::GetTotalEffectBonusHook(CNWSCreature *pCreature, uint8_t nEffectBonusType, CNWSObject *pObject,
                                      int32_t bElementalDamage, int32_t bForceMax, uint8_t nSaveType, uint8_t nSpecificType,
                                      uint8_t nSkill, uint8_t nAbilityScore, int32_t bOffHand)
{
    auto *pServerExoApp = Globals::AppManager()->m_pServerExoApp;
    uint16_t attackBonusLimit = pServerExoApp->GetAttackBonusLimit();
    uint16_t skillBonusLimit = pServerExoApp->GetSkillBonusLimit();;

    // We only swap to the parent race for the target when using GetTotalEffectBonus
    CNWSCreature* pTargetCreature = nullptr;
    if (pObject != nullptr)
    {
        pTargetCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
    }

    auto nRace = pCreature->m_pStats->m_nRace;
    if (nEffectBonusType == 1)
    {
        auto modABBonus = g_plugin->m_RaceAB[nRace];
        uint8_t modABVSRaceBonus = 0;
        if (pTargetCreature)
        {
            modABVSRaceBonus = g_plugin->m_RaceABVsRace[nRace][pTargetCreature->m_pStats->m_nRace];
            auto parRace = g_plugin->m_RaceParent[pTargetCreature->m_pStats->m_nRace];
            if(parRace != RacialType::Invalid)
                modABVSRaceBonus = g_plugin->m_RaceABVsRace[nRace][parRace];
        }
        pServerExoApp->SetAttackBonusLimit(attackBonusLimit + modABBonus + modABVSRaceBonus);
    }
    else if (nEffectBonusType == 5)
    {
        auto modSkillBonus = g_plugin->m_RaceSkill[nRace][nSkill];
        pServerExoApp->SetSkillBonusLimit(skillBonusLimit + modSkillBonus);
    }

    auto retVal = s_GetTotalEffectBonusHook->CallOriginal<int32_t>(pCreature, nEffectBonusType, pObject, bElementalDamage,
                                                                   bForceMax, nSaveType, nSpecificType, nSkill, nAbilityScore, bOffHand);


    if (nEffectBonusType == 1)
        pServerExoApp->SetAttackBonusLimit(attackBonusLimit);
    else if (nEffectBonusType == 5)
        pServerExoApp->SetSkillBonusLimit(skillBonusLimit);

    return retVal;
}

void Race::ResetFeatRemainingUsesHook(CNWSCreatureStats *pCreatureStats)
{
    s_ResetFeatRemainingUsesHook->CallOriginal<void>(pCreatureStats);

    auto *pCreature = pCreatureStats->m_pBaseCreature;
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
            mod += Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("EPIC_SUPERIOR_INITIATIVE_BONUS"), 8);
        else if (pStats->HasFeat(Feat::ImprovedInitiative))
            mod += Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("IMPROVED_INITIATIVE_BONUS"), 4);
        if (pStats->HasFeat(Feat::Blooded))
            mod += Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("BLOODED_INITIATIVE_BONUS"), 2);
        if (pStats->HasFeat(Feat::Thug))
            mod += Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("THUG_INITIATIVE_BONUS"), 2);

        // Add racial bonus
        auto nRace = pCreature->m_pStats->m_nRace;
        auto sRace = std::to_string(nRace);
        mod += g_plugin->m_RaceInitiative[nRace];

        pCreature->m_nInitiativeRoll = diceRoll + mod;
        auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByObjectId(pCreature->m_idSelf);
        if (pPlayer)
        {
            CNWCCMessageData messageData;
            messageData.SetObjectID(0, pCreature->m_idSelf);
            messageData.SetInteger(0, diceRoll);
            messageData.SetInteger(1, mod);
            auto *pMessage = static_cast<CNWSMessage *>(Globals::AppManager()->m_pServerExoApp->GetNWSMessage());
            if (pMessage)
            {
                pMessage->SendServerToPlayerCCMessage(pPlayer->m_nPlayerID,
                                                      Constants::MessageClientSideMsgMinor::Initiative,
                                                      &messageData, nullptr);
            }
        }
        pCreature->m_bInitiativeExpired = 0;
    }
}

int32_t Race::ValidateCharacterHook(CNWSPlayer *pPlayer, int32_t *bFailedServerRestriction)
{
    auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);

    if (!pCreature)
        return s_ValidateCharacterHook->CallOriginal<int32_t>(pPlayer, bFailedServerRestriction);

    auto nRace = pCreature->m_pStats->m_nRace;

    // Need to store the feat usages and set them after we remove/add the feat back to bypass Char Validation
    std::unordered_map<uint16_t, uint8_t> featUses;

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
        if (Globals::Rules()->GetFeat(featId)->m_nUsesPerDay)
            featUses.emplace(featId, pCreature->m_pStats->GetFeatRemainingUses(featId));
        pCreature->m_pStats->RemoveFeat(featId);
    }

    auto retVal = s_ValidateCharacterHook->CallOriginal<int32_t>(pPlayer, bFailedServerRestriction);

    for (auto &featDetails : g_plugin->m_RaceFeat[nRace])
    {
        auto featId = featDetails.first;
        auto featLevel = featDetails.second;
        if (featLevel > pCreature->m_pStats->m_lstLevelStats.num)
            continue;
        auto *pLevelStats = pCreature->m_pStats->m_lstLevelStats.element[featLevel-1];
        pLevelStats->AddFeat(featId);
        pCreature->m_pStats->AddFeat(featId);
        if (Globals::Rules()->GetFeat(featId)->m_nUsesPerDay)
            pCreature->m_pStats->SetFeatRemainingUses(featId, featUses[featId]);
    }

    return retVal;
}

int32_t Race::SendServerToPlayerLevelUp_ConfirmationHook(CNWSMessage *pMessage, PlayerID nPlayerId, int32_t bValidated)
{
    auto retVal = s_SendServerToPlayerLevelUp_ConfirmationHook->CallOriginal<int32_t>(pMessage, nPlayerId, bValidated);

    // Reapply the racial effects in case there are level specific ones
    if (bValidated)
    {
        auto *pPlayer = Globals::AppManager()->m_pServerExoApp->GetClientObjectByPlayerId(nPlayerId);
        auto *pCreature = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(pPlayer->m_oidNWSObject);
        ApplyRaceEffects(pCreature);
    }

    return retVal;
}

void Race::SetOrRestoreRace(bool before, CNWSCreatureStats *pCreatureStats, CNWSCreatureStats *pTgtCreatureStats)
{
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

int32_t Race::GetFavoredEnemyBonusHook(CNWSCreatureStats *pCreatureStats, CNWSCreature *pTgtCreature)
{
    static bool bFavoredEnemyRacesInitialized = false;
    if (!bFavoredEnemyRacesInitialized)
    {
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Aberration].push_back(Constants::Feat::FavoredEnemy_Aberration);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Animal].push_back(Constants::Feat::FavoredEnemy_Animal);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Beast].push_back(Constants::Feat::FavoredEnemy_Beast);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Construct].push_back(Constants::Feat::FavoredEnemy_Construct);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Dragon].push_back(Constants::Feat::FavoredEnemy_Dragon);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Dwarf].push_back(Constants::Feat::FavoredEnemy_Dwarf);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Elemental].push_back(Constants::Feat::FavoredEnemy_Elemental);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Elf].push_back(Constants::Feat::FavoredEnemy_Elf);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Fey].push_back(Constants::Feat::FavoredEnemy_Fey);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Giant].push_back(Constants::Feat::FavoredEnemy_Giant);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Gnome].push_back(Constants::Feat::FavoredEnemy_Gnome);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Halfelf].push_back(Constants::Feat::FavoredEnemy_Halfelf);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Halfling].push_back(Constants::Feat::FavoredEnemy_Halfling);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Halforc].push_back(Constants::Feat::FavoredEnemy_Halforc);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Human].push_back(Constants::Feat::FavoredEnemy_Human);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::HumanoidGoblinoid].push_back(Constants::Feat::FavoredEnemy_Goblinoid);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::HumanoidMonstrous].push_back(Constants::Feat::FavoredEnemy_Monstrous);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::HumanoidOrc].push_back(Constants::Feat::FavoredEnemy_Orc);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::HumanoidReptilian].push_back(Constants::Feat::FavoredEnemy_Reptilian);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::MagicalBeast].push_back(Constants::Feat::FavoredEnemy_MagicalBeast);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Outsider].push_back(Constants::Feat::FavoredEnemy_Outsider);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Shapechanger].push_back(Constants::Feat::FavoredEnemy_Shapechanger);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Undead].push_back(Constants::Feat::FavoredEnemy_Undead);
        g_plugin->m_RaceFavoredEnemyFeat[Constants::RacialType::Vermin].push_back(Constants::Feat::FavoredEnemy_Vermin);
        bFavoredEnemyRacesInitialized = true;
    }

    // If either the target's race or its parent race has a favored enemy feat associated with it we check the attacker for that feat
    std::vector<uint16_t> nFeatList;
    auto fi = g_plugin->m_RaceFavoredEnemyFeat.find(pTgtCreature->m_pStats->m_nRace);
    if (fi != g_plugin->m_RaceFavoredEnemyFeat.end())
        nFeatList = fi->second;

    auto pri = g_plugin->m_RaceParent.find(pTgtCreature->m_pStats->m_nRace);
    if ( pri != g_plugin->m_RaceParent.end())
    {
        auto pfi = g_plugin->m_RaceFavoredEnemyFeat.find(pri->second);
        if (pfi != g_plugin->m_RaceFavoredEnemyFeat.end())
        {
            nFeatList.insert(nFeatList.end(), pfi->second.begin(), pfi->second.end());
        }
    }

    if (nFeatList.empty())
        return 0;

    uint8_t nBonus = 0;
    if (pCreatureStats->m_bIsPC)
    {
        int32_t nMulticlass = -1;
        for (auto* levelStats : pCreatureStats->m_lstLevelStats)
        {
            for (auto feat : levelStats->m_lstFeats)
            {
                if (std::find(nFeatList.begin(), nFeatList.end(), feat) != nFeatList.end())
                {
                    for (int i = 0; i < pCreatureStats->m_nNumMultiClasses; i++)
                    {
                        if (pCreatureStats->m_ClassInfo[i].m_nClass == levelStats->m_nClass)
                        {
                            nMulticlass = i;
                            break;
                        }
                    }
                }
                if (nMulticlass != -1)
                    break;
            }
            if (nMulticlass != -1)
                break;
        }

        if (nMulticlass == -1)
            return 0;

        if (pCreatureStats->m_ClassInfo[nMulticlass].m_nClass == Constants::ClassType::Harper)
            nBonus = pCreatureStats->m_ClassInfo[nMulticlass].m_nLevel / 4 + 1;
        else
            nBonus= pCreatureStats->m_ClassInfo[nMulticlass].m_nLevel / 5 + 1;

        return nBonus;
    }
    for(const auto& nFeat : nFeatList)
    {
        if (pCreatureStats->HasFeat(nFeat))
            return pCreatureStats->GetLevel(0) / 5 + 1;
    }
    return 0;
}

void Race::CreateDefaultQuickButtonsHook(CNWSCreature *pCreature)
{
    SetOrRestoreRace(true, pCreature->m_pStats);
    s_CreateDefaultQuickButtonsHook->CallOriginal<void>(pCreature);
    SetOrRestoreRace(false, pCreature->m_pStats);
}

int32_t Race::LevelUpAutomaticHook(CNWSCreatureStats *pCreatureStats, uint8_t nClass, int32_t bReadyAllSpells, uint32_t nPackage)
{
    SetOrRestoreRace(true, pCreatureStats);
    auto retVal = s_LevelUpAutomaticHook->CallOriginal<int32_t>(pCreatureStats, nClass, bReadyAllSpells, nPackage);
    SetOrRestoreRace(false, pCreatureStats);
    return retVal;
}

int32_t Race::GetMeetsPrestigeClassRequirementsHook(CNWSCreatureStats *pCreatureStats, CNWClass *pClass)
{
    SetOrRestoreRace(true, pCreatureStats);
    auto retVal = s_GetMeetsPrestigeClassRequirementsHook->CallOriginal<int32_t>(pCreatureStats, pClass);
    SetOrRestoreRace(false, pCreatureStats);
    return retVal;
}

int32_t Race::CheckItemRaceRestrictionsHook(CNWSCreature *pCreature, CNWSItem *pItem)
{
    // Checks if there are any racial use limitations on the item or if they passed their UMD check
    if (!pItem->GetPropertyByTypeExists(Constants::ItemProperty::UseLimitationRacialType, 0) ||
         pCreature->CheckUseMagicDeviceSkill(pItem, 1) == 1)
        return 1;

    int32_t nRace = pCreature->m_pStats->m_nRace;

    for (int i = 0; i < pItem->m_lstPassiveProperties.num; i++)
    {
        if (pItem->GetPassiveProperty(i)->m_nPropertyName == Constants::ItemProperty::UseLimitationRacialType)
        {
            auto raceToCheck = pItem->GetPassiveProperty(i)->m_nSubType;
            if (nRace == raceToCheck || g_plugin->m_RaceParent[nRace] == raceToCheck)
            {
                return 1;
            }
        }
    }
    return 0;

}

void Race::LoadRaceInfoHook(CNWRules *pRules)
{
    s_LoadRaceInfoHook->CallOriginal<void>(pRules);

    // Initialize the parent race to Invalid
    auto twoda = pRules->m_p2DArrays->GetCached2DA("RACIALTYPES", true);
    for (int raceId = 0; raceId < twoda->m_nNumRows; raceId++)
    {
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
            LOG_INFO("%s: Setting Natural AB modifier vs %s to %d.", raceName, versusRaceName, param2);
            break;
        }
        case AC:
        {
            if (param2 < ACBonus::MIN || param2 > ACBonus::MAX)
            {
                LOG_WARNING("%s: The specified AC Bonus type is invalid, falling back to Dodge.", raceName);
                param2 = ACBonus::Dodge;
            }
            g_plugin->m_RaceAC[raceId] = std::make_pair(param1, param2);
            LOG_INFO("%s: Setting %s AC modifier to %d.", raceName, ACBonus::ToString(param2), param1);
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
            LOG_INFO("%s: Setting Natural AC modifier vs %s to %d.", raceName, versusRaceName, param2);
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
            if (param2 <= 0)
            {
                LOG_ERROR("%s: Feat modifier improperly set.", raceName);
                break;
            }
            auto featName = Globals::Rules()->GetFeat(param1)->GetNameText();
            g_plugin->m_RaceFeat[raceId][param1] = param2;
            LOG_INFO("%s: Granting %s Feat at level %d.", raceName, featName, param2);
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
            LOG_INFO("%s: Setting %s Feat Usage Per Day to %d + 1 for every %d level(s).", raceName, featName, param2, param3);
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
                std::vector<uint32_t> immunities;
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
            g_plugin->m_ChildRaces[param1].push_back(raceId);
            auto parentRaceName = Globals::Rules()->m_lstRaces[param1].GetNameText();
            LOG_INFO("%s: Setting parent race to %s.", raceName, parentRaceName);
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
            MessageBus::Broadcast("NWNX_SKILLRANK_SIGNAL",
                                         {std::to_string(param1), sRace, std::to_string(param2)});

            g_plugin->m_RaceSkill[raceId][param1] = param2;
            auto skillName = Globals::Rules()->m_lstSkills[param1].GetNameText();
            LOG_INFO("%s: Setting Skill modifier of %d for %s.", raceName, param2, skillName);
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
                std::vector<uint32_t> immunities;
                immunities.push_back(param1);
                g_plugin->m_RaceSpellImmunities[raceId] = immunities;
            }
            auto spellName = Globals::Rules()->m_pSpellArray[0].GetSpell(param1)->GetSpellNameText();
            LOG_INFO("%s: Setting %s Spell Immunity.", raceName, spellName);
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
    auto raceId = ScriptAPI::ExtractArgument<int>(args);
    auto raceMod = static_cast<RaceModifier>(ScriptAPI::ExtractArgument<int>(args));
    auto param1 = ScriptAPI::ExtractArgument<int>(args);
    auto param2 = ScriptAPI::ExtractArgument<int>(args);
    auto param3 = ScriptAPI::ExtractArgument<int>(args);

    SetRaceModifier(raceId, raceMod, param1, param2, param3);

    return ScriptAPI::Arguments();
}

ArgumentStack Race::GetParentRace(ArgumentStack&& args)
{
    auto raceId = ScriptAPI::ExtractArgument<int>(args);
    auto parentRace = g_plugin->m_RaceParent[raceId] == RacialType::Invalid ? raceId : g_plugin->m_RaceParent[raceId];
    return ScriptAPI::Arguments(parentRace);
}

ArgumentStack Race::SetFavoredEnemyFeat(ArgumentStack&& args)
{
    auto raceId = ScriptAPI::ExtractArgument<int>(args);
    auto featId = ScriptAPI::ExtractArgument<int>(args);

    CNWFeat *pFeat = Globals::Rules()->GetFeat(featId);
    ASSERT_OR_THROW(pFeat);

    g_plugin->m_RaceFavoredEnemyFeat[raceId].push_back(featId);

    LOG_INFO("%s: Setting Favored Enemy Feat to %s.", Globals::Rules()->m_lstRaces[raceId].GetNameText().CStr(), pFeat->GetNameText().CStr());

    return ScriptAPI::Arguments();
}

ArgumentStack Race::SuppressCreatureRaceEffects(ArgumentStack&& args)
{
    if(auto* pCreature = Utils::PopCreature(args))
    {
        RemoveRaceEffects(pCreature);
    }
    return {};
}

ArgumentStack Race::ReactivateCreatureRaceEffects(ArgumentStack&& args)
{
    if(auto* pCreature = Utils::PopCreature(args))
    {
        ApplyRaceEffects(pCreature);
    }
    return {};
}

int32_t Race::GetAttackModifierVersusHook(CNWSCreatureStats* pStats, CNWSCreature* pCreature)
{
    int32_t modABVSRaceBonus = 0;
    if(pCreature)
    {
        auto parRace = g_plugin->m_RaceParent[pCreature->m_pStats->m_nRace];

        if((parRace == RacialType::HumanoidOrc && pStats->HasFeat(Feat::BattleTrainingVersusOrcs)) ||
            (parRace == RacialType::HumanoidGoblinoid && pStats->HasFeat(Feat::BattleTrainingVersusGoblins)) ||
            (parRace == RacialType::HumanoidReptilian && pStats->HasFeat(Feat::BattleTrainingVersusReptilians)))
        {
            modABVSRaceBonus = Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("OFFENSIVE_TRAINING_MODIFIER"), 1);

            if (*Globals::EnableCombatDebugging() && pStats->m_bIsPC)
            {
                auto sDebugMsg = CExoString(" + ") +
                                 CExoString(std::to_string(Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("OFFENSIVE_TRAINING_MODIFIER"), 1))) +
                                 CExoString(" (Offensive training/battle training)") ;
                auto *pCurrentAttack = pStats->m_pBaseCreature->m_pcCombatRound->GetAttack(pStats->m_pBaseCreature->m_pcCombatRound->m_nCurrentAttack);
                pCurrentAttack->m_sAttackDebugText = pCurrentAttack->m_sAttackDebugText + sDebugMsg;
            }
        }

    }

    return s_GetAttackModifierVersusHook->CallOriginal<int32_t>(pStats, pCreature) + modABVSRaceBonus;

}

int16_t Race::GetArmorClassVersusHook(CNWSCreatureStats* pStats, CNWSCreature* pCreature = nullptr, BOOL bVsTouchAttack = false)
{
    int32_t modACVSRaceBonus = 0;
    if(pCreature)
    {
        auto parRace = g_plugin->m_RaceParent[pCreature->m_pStats->m_nRace];

        if(parRace == RacialType::Giant && pStats->HasFeat(Feat::BattleTrainingVersusGiants))
            modACVSRaceBonus = Globals::Rules()->GetRulesetIntEntry(CRULES_HASHEDSTR("DEFENSIVE_TRAINING_MODIFIER"), 4);

    }

    return s_GetArmorClassVersusHook->CallOriginal<int16_t>(pStats, pCreature, bVsTouchAttack) + modACVSRaceBonus;

}

}
