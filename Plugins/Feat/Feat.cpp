#include "Feat.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWClass.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/CNWSEffectListHandler.hpp"
#include "API/CNWSPlayer.hpp"
#include "API/CNWSPlayerTURD.hpp"
#include "API/CTwoDimArrays.hpp"
#include "API/Constants.hpp"
#include "API/Constants/Effect.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include <cmath>

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants::EffectTrueType;

static Feat::Feat* g_plugin;

const auto MODULE_OID = 0;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Feat::Feat(services);
    return g_plugin;
}


namespace Feat {

static Hooks::Hook s_GetTotalEffectBonusHook;
static Hooks::Hook s_SavingThrowRollHook;
static Hooks::Hook s_GetWeaponPowerHook;
static Hooks::Hook s_AddFeatHook;
static Hooks::Hook s_RemoveFeatHook;
static Hooks::Hook s_OnApplyBonusFeatHook;
static Hooks::Hook s_OnRemoveBonusFeatHook;
static Hooks::Hook s_EatTURDHook;

Feat::Feat(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    ScriptAPI::RegisterEvent(PLUGIN_NAME, #func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetFeatModifier);

#undef REGISTER

    m_ShowEffectIcon = Config::Get<bool>("SHOW_EFFECT_ICON", false);
    m_nCustomSpellID = Config::Get<uint32_t>("CUSTOM_SPELL_ID", 0xFFFFFFFF);

    // We want the feat bonuses to not count toward limits
    s_GetTotalEffectBonusHook = Hooks::HookFunction(&CNWSCreature::GetTotalEffectBonus,
                                                             &GetTotalEffectBonusHook, Hooks::Order::Early);
    s_SavingThrowRollHook = Hooks::HookFunction(&CNWSCreature::SavingThrowRoll,
                                                         &SavingThrowRollHook, Hooks::Order::Early);
    s_GetWeaponPowerHook = Hooks::HookFunction(&CNWSCreature::GetWeaponPower,
                                                        &GetWeaponPowerHook, Hooks::Order::Early);

    s_AddFeatHook = Hooks::HookFunction(&CNWSCreatureStats::AddFeat, &AddFeatHook, Hooks::Order::Early);
    s_RemoveFeatHook = Hooks::HookFunction(&CNWSCreatureStats::RemoveFeat, &RemoveFeatHook, Hooks::Order::Early);
    s_OnApplyBonusFeatHook = Hooks::HookFunction(&CNWSEffectListHandler::OnApplyBonusFeat,
                                                          &OnApplyBonusFeatHook, Hooks::Order::Early);
    s_OnRemoveBonusFeatHook = Hooks::HookFunction(&CNWSEffectListHandler::OnRemoveBonusFeat,
                                                           &OnRemoveBonusFeatHook, Hooks::Order::Early);
    s_EatTURDHook = Hooks::HookFunction(&CNWSPlayer::EatTURD, &EatTURDHook, Hooks::Order::Early);
}

Feat::~Feat()
{
}

void Feat::DoEffect(CNWSCreature *pCreature,
                    uint16_t featId,
                    uint16_t nType,
                    int32_t param0,
                    int32_t param1,
                    int32_t param2,
                    int32_t param3,
                    int32_t param4,
                    int32_t param5)
{
    auto *eff = new CGameEffect(true);
    std::string sCustomTag = "NWNX_Feat_FeatMod_" + std::to_string(featId);
    eff->m_oidCreator         = MODULE_OID;
    eff->m_nType              = nType;
    eff->m_nSubType           = Constants::EffectSubType::Supernatural | Constants::EffectDurationType::Innate;
    eff->m_bShowIcon          = g_plugin->m_ShowEffectIcon;
    eff->m_nSpellId           = g_plugin->m_nCustomSpellID;
    eff->m_nParamInteger[0]   = param0;
    eff->m_nParamInteger[1]   = param1;
    eff->m_nParamInteger[2]   = param2;
    eff->m_nParamInteger[3]   = param3;
    eff->m_nParamInteger[4]   = param4;
    eff->m_nParamInteger[5]   = param5;
    eff->m_sCustomTag         = sCustomTag;
    pCreature->ApplyEffect(eff, true, true);
}

void Feat::ApplyFeatEffects(CNWSCreature *pCreature, uint16_t nFeat)
{
    // AB
    auto modAB = g_plugin->m_FeatAB[nFeat];
    if (modAB != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat,
                           modAB > 0 ? AttackIncrease : AttackDecrease,
                           abs(modAB), 0, Constants::RacialType::Invalid);
    }

    // ABILITY
    for (auto &abilityMod : g_plugin->m_FeatAbility[nFeat])
    {
        auto abilityType = abilityMod.first;
        auto mod = abilityMod.second;
        if (mod != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat,
                               mod > 0 ? AbilityIncrease : AbilityDecrease,
                               abilityType, abs(mod));
        }
    }

    // ABVSRACE
    for (auto &ABVsRaceMod : g_plugin->m_FeatABVsRace[nFeat])
    {
        auto vsRace = ABVsRaceMod.first;
        auto modVsRace = ABVsRaceMod.second;
        if (modVsRace != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat,
                               modVsRace > 0 ? AttackIncrease : AttackDecrease,
                               abs(modVsRace), 0, vsRace);
        }
    }

    // AC
    auto modAC = g_plugin->m_FeatAC[nFeat];
    if (modAC != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat,
                           modAC > 0 ? ACIncrease : ACDecrease, Constants::ACBonus::Dodge,
                           abs(modAC), Constants::RacialType::Invalid, 0, 0, 4103);
    }

    // ACVSRACE
    for (auto &ACVsRaceMod : g_plugin->m_FeatACVsRace[nFeat])
    {
        auto vsRace = ACVsRaceMod.first;
        auto modVsRace = ACVsRaceMod.second;
        if (modVsRace != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat,
                               modVsRace > 0 ? ACIncrease : ACDecrease, Constants::ACBonus::Dodge,
                               abs(modVsRace), vsRace, 0, 0, 4103);
        }
    }

    // ARCANESPELLFAILURE
    auto modArcaneSpellFailure = g_plugin->m_FeatArcaneSpellFailure[nFeat];
    if (modArcaneSpellFailure != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat, ArcaneSpellFailure, modArcaneSpellFailure);
    }

    // BONUSSPELL
    g_plugin->AddRemoveBonusSpell(pCreature->m_pStats, nFeat);

    // CONCEALMENT
    auto modConceal = g_plugin->m_FeatConcealment[nFeat];
    if (modConceal != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat,Concealment, modConceal, Constants::RacialType::Invalid);
    }

    // DMGIMMUNITY
    for (auto &dmgImmunityMod : g_plugin->m_FeatDmgImmunity[nFeat])
    {
        auto modDmgImmunityType = dmgImmunityMod.first;
        auto modDmgImmunityValue = dmgImmunityMod.second;
        if (modDmgImmunityValue != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat,
                               modDmgImmunityValue > 0 ? DamageImmunityIncrease : DamageImmunityDecrease,
                               modDmgImmunityType, abs(modDmgImmunityValue));
        }
    }

    // DMGREDUCTION
    for (auto &dmgResistMod : g_plugin->m_FeatDmgReduction[nFeat])
    {
        auto modDmgReductionType = dmgResistMod.first;
        auto modDmgReductionValue = dmgResistMod.second;
        if (modDmgReductionValue != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat, DamageReduction, modDmgReductionType, modDmgReductionValue);
        }
    }

    // DMGRESIST
    for (auto &dmgResistMod : g_plugin->m_FeatDmgResist[nFeat])
    {
        auto modDmgResistType = dmgResistMod.first;
        auto modDmgResistValue = dmgResistMod.second;
        if (modDmgResistValue != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat, DamageResistance, modDmgResistType, modDmgResistValue);
        }
    }

    // HASTE
    if (g_plugin->m_FeatHaste.find(nFeat) != g_plugin->m_FeatHaste.end())
    {
        g_plugin->DoEffect(pCreature, nFeat, Haste);
    }

    // IMMUNITY
    for (auto &immunity : g_plugin->m_FeatImmunities[nFeat])
    {
        g_plugin->DoEffect(pCreature, nFeat, Immunity, immunity,Constants::RacialType::Invalid);
    }

    // MOVEMENTSPEED
    auto modSpeed = g_plugin->m_FeatMovementSpeed[nFeat];
    if (modSpeed != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat, MovementSpeedIncrease, modSpeed);
    }

    // REGENERATION
    auto modRegenAmount = g_plugin->m_FeatRegeneration[nFeat].first;
    auto modRegenInterval = g_plugin->m_FeatRegeneration[nFeat].second;
    if (modRegenAmount != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat, Regenerate, modRegenAmount,
                modRegenInterval > 0 ? modRegenInterval * 1000 : 6000);
    }

    // SAVE
    for (auto &saveMod : g_plugin->m_FeatSave[nFeat])
    {
        auto saveType = saveMod.first;
        auto mod = saveMod.second;
        if (mod != 0)
        {
            g_plugin->DoEffect(pCreature, nFeat,
                               mod > 0 ? SavingThrowIncrease : SavingThrowDecrease, abs(mod),
                               saveType, Constants::SavingThrowType::All, Constants::RacialType::Invalid);
        }
    }

    // SAVEVSRACE
    for (auto &saveMod : g_plugin->m_FeatSaveVsRace[nFeat])
    {
        auto saveType = saveMod.first;
        for (auto &saveVsFeatMod : g_plugin->m_FeatSaveVsRace[nFeat][saveType])
        {
            auto saveVsRace = saveVsFeatMod.first;
            auto modVsRace = saveVsFeatMod.second;
            if (modVsRace != 0)
            {
                g_plugin->DoEffect(pCreature, nFeat,
                                   modVsRace > 0 ? SavingThrowIncrease : SavingThrowDecrease, abs(modVsRace),
                                   saveType, Constants::SavingThrowType::All, saveVsRace);
            }
        }
    }

    // SAVEVSTYPE
    for (auto &saveMod : g_plugin->m_FeatSaveVsType[nFeat])
    {
        auto saveType = saveMod.first;
        for (auto &saveVsTypeMod : g_plugin->m_FeatSaveVsType[nFeat][saveType])
        {
            auto saveVsType = saveVsTypeMod.first;
            auto modVsType = saveVsTypeMod.second;
            if (modVsType != 0)
            {
                g_plugin->DoEffect(pCreature, nFeat,
                                   modVsType > 0 ? SavingThrowIncrease : SavingThrowDecrease, abs(modVsType),
                                   saveType, saveVsType, Constants::RacialType::Invalid);
            }
        }
    }

    // SAVEVSTYPERACE
    for (auto &saveMod : g_plugin->m_FeatSaveVsTypeRace[nFeat])
    {
        auto saveType = saveMod.first;
        for (auto &saveVsTypeMod : g_plugin->m_FeatSaveVsTypeRace[nFeat][saveType])
        {
            auto saveVsType = saveVsTypeMod.first;
            for (auto &saveVsTypeRaceMod : g_plugin->m_FeatSaveVsTypeRace[nFeat][saveType][saveVsType])
            {
                auto saveVsRace = saveVsTypeRaceMod.first;
                auto modVsTypeRace = saveVsTypeRaceMod.second;
                if (modVsTypeRace != 0)
                {
                    g_plugin->DoEffect(pCreature, nFeat,
                                       modVsTypeRace > 0 ? SavingThrowIncrease : SavingThrowDecrease,
                                       abs(modVsTypeRace), saveType, saveVsType, saveVsRace);
                }
            }
        }
    }

    // SEEINVISIBLE
    if (g_plugin->m_FeatSeeInvisible.find(nFeat) != g_plugin->m_FeatSeeInvisible.end())
    {
        g_plugin->DoEffect(pCreature, nFeat, SeeInvisible);
    }

    // SPELLSAVEDC
    if (g_plugin->m_FeatSpellSaveDC[nFeat] != 0)
    {
        static NWNXLib::Hooks::Hook pCalculateSpellSaveDC_hook;
        if (!pCalculateSpellSaveDC_hook)
        {
            pCalculateSpellSaveDC_hook = Hooks::HookFunction(
                    &CNWSCreature::CalculateSpellSaveDC,
                    +[](CNWSCreature *pThis, int32_t nSpellID) -> int32_t
                    {
                        int iMods = 0;
                        for (auto &spellSaveDCMod : g_plugin->m_FeatSpellSaveDC)
                        {
                            if (pThis->m_pStats->HasFeat(spellSaveDCMod.first))
                            {
                                iMods += spellSaveDCMod.second;
                            }
                        }
                        return iMods + pCalculateSpellSaveDC_hook->CallOriginal<int32_t>(pThis, nSpellID);
                    }, Hooks::Order::Late);
        }
    }


    // SPELLIMMUNITY
    for (auto &spellImmunity : g_plugin->m_FeatSpellImmunities[nFeat])
    {
        g_plugin->DoEffect(pCreature, nFeat, SpellImmunity, spellImmunity);
    }

    // SR
    auto mod_SRCharGen = g_plugin->m_FeatSRCharGen[nFeat].first;
    auto mod_SRMax = g_plugin->m_FeatSRCharGen[nFeat].second;
    auto mod_SRInc = std::get<0>(g_plugin->m_FeatSR[nFeat]);
    auto mod_SRLevel = std::get<1>(g_plugin->m_FeatSR[nFeat]);
    auto mod_SRStart = std::get<2>(g_plugin->m_FeatSR[nFeat]);
    auto mod_SRPerLevelCalc = 0;
    if (mod_SRLevel > 0)
        mod_SRPerLevelCalc = int32_t(std::floor(((pCreature->m_pStats->GetLevel(true) - mod_SRStart + 1) / mod_SRLevel) * mod_SRInc));
    int32_t mod_SR = mod_SRCharGen + (mod_SRPerLevelCalc > 0 ? mod_SRPerLevelCalc : 0);
    mod_SR = (mod_SR > mod_SRMax && mod_SRMax > 0) ? mod_SRMax : mod_SR;
    if (mod_SR != 0)
    {
        g_plugin->DoEffect(pCreature, nFeat, SpellResistanceIncrease, mod_SR);
    }

    // TRUESEEING
    if (g_plugin->m_FeatTrueSeeing.find(nFeat) != g_plugin->m_FeatTrueSeeing.end())
    {
        g_plugin->DoEffect(pCreature, nFeat, Trueseeing);
    }

    // ULTRAVISION
    if (g_plugin->m_FeatUltravision.find(nFeat) != g_plugin->m_FeatUltravision.end())
    {
        g_plugin->DoEffect(pCreature, nFeat, Ultravision);
    }

    // VISUALEFFECT
    for (auto &vfx : g_plugin->m_FeatVFX[nFeat])
    {
        g_plugin->DoEffect(pCreature, nFeat, VisualEffect, vfx);
    }
}

uint8_t Feat::SavingThrowRollHook(CNWSCreature *pCreature, uint8_t nSaveType, uint16_t nDifficultyClass, uint8_t nSpecificType,
                               ObjectID oidSaveVersus, int32_t bPrint, uint16_t nFeat, int32_t bQueueFeedback)
{
    auto *pServerExoApp = Globals::AppManager()->m_pServerExoApp;
    uint16_t savingThrowBonusLimit = pServerExoApp->GetSavingThrowBonusLimit();

    auto *pTargetCreature = pServerExoApp->GetCreatureByGameObjectID(oidSaveVersus);
    for (int32_t j = 0; j < pCreature->m_pStats->m_lstFeats.num; j++)
    {
        auto nListFeat = pCreature->m_pStats->m_lstFeats.element[j];
        auto modSaveBonus = g_plugin->m_FeatSave[nFeat][nSaveType] + g_plugin->m_FeatSave[nListFeat][Constants::SavingThrow::All];
        uint8_t modSaveVSRaceBonus = 0;
        if (pTargetCreature)
        {
            std::list<uint8_t> saveBonuses = {};
            for (int32_t k = 0; k <= Constants::SavingThrow::MAX; k++)
            {
                saveBonuses.push_front(g_plugin->m_FeatSaveVsRace[nListFeat][k][pTargetCreature->m_pStats->m_nRace]);
                saveBonuses.push_front(g_plugin->m_FeatSaveVsTypeRace[nListFeat][k][nSpecificType][pTargetCreature->m_pStats->m_nRace]);
            }
            modSaveVSRaceBonus = *std::max_element(saveBonuses.begin(), saveBonuses.end());
        }
        auto modSaveVSTypeBonus = g_plugin->m_FeatSaveVsType[nListFeat][nSaveType][nSpecificType] +
                                  g_plugin->m_FeatSaveVsType[nListFeat][Constants::SavingThrow::All][nSpecificType];
        pServerExoApp->SetSavingThrowBonusLimit(
                pServerExoApp->GetSavingThrowBonusLimit() + modSaveBonus + modSaveVSRaceBonus + modSaveVSTypeBonus);
    }

    auto retVal = s_SavingThrowRollHook->CallOriginal<uint8_t>(pCreature, nSaveType, nDifficultyClass, nSpecificType,
                                                               oidSaveVersus, bPrint, nFeat, bQueueFeedback);

    pServerExoApp->SetSavingThrowBonusLimit(savingThrowBonusLimit);

    return retVal;
}

int32_t Feat::GetTotalEffectBonusHook(CNWSCreature *pCreature, uint8_t nEffectBonusType, CNWSObject *pObject,
                                      int32_t bElementalDamage, int32_t bForceMax, uint8_t nSaveType, uint8_t nSpecificType,
                                      uint8_t nSkill, uint8_t nAbilityScore, int32_t bOffHand)
{
    auto *pServerExoApp = Globals::AppManager()->m_pServerExoApp;
    uint16_t attackBonusLimit = pServerExoApp->GetAttackBonusLimit();
    uint16_t abilityBonusLimit = pServerExoApp->GetAbilityBonusLimit();
    uint16_t saveBonusLimit = pServerExoApp->GetSavingThrowBonusLimit();

    CNWSCreature* pTargetCreature = nullptr;
    if (pObject != nullptr)
    {
        pTargetCreature = pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
    }

    for (int32_t j = 0; j < pCreature->m_pStats->m_lstFeats.num; j++)
    {
        auto nFeat = pCreature->m_pStats->m_lstFeats.element[j];
        if (nEffectBonusType == 1)
        {
            auto modABBonus = g_plugin->m_FeatAB[nFeat];
            uint8_t modABVSRaceBonus = 0;
            if (pTargetCreature)
                modABVSRaceBonus = g_plugin->m_FeatABVsRace[nFeat][pTargetCreature->m_pStats->m_nRace];
            pServerExoApp->SetAttackBonusLimit(pServerExoApp->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);
        }
        else if (nEffectBonusType == 3)
        {
            auto modSaveBonus = g_plugin->m_FeatAbility[nFeat][nSkill];
            uint8_t modSaveVSRaceBonus = 0;
            if (pTargetCreature)
            {
                std::list<uint8_t> saveBonuses = {};
                auto featRace = g_plugin->m_FeatSaveVsRace[nFeat][pTargetCreature->m_pStats->m_nRace];
                saveBonuses.push_front(featRace[Constants::SavingThrow::All]);
                saveBonuses.push_front(featRace[Constants::SavingThrow::Fortitude]);
                saveBonuses.push_front(featRace[Constants::SavingThrow::Reflex]);
                saveBonuses.push_front(featRace[Constants::SavingThrow::Will]);
                modSaveVSRaceBonus = *std::max_element(saveBonuses.begin(), saveBonuses.end());
            }
            pServerExoApp->SetSavingThrowBonusLimit(
                    pServerExoApp->GetSavingThrowBonusLimit() + modSaveBonus + modSaveVSRaceBonus);
        }
        else if (nEffectBonusType == 4)
        {
            auto modAbilityBonus = g_plugin->m_FeatAbility[nFeat][nAbilityScore];
            pServerExoApp->SetAbilityBonusLimit(pServerExoApp->GetAbilityBonusLimit() + modAbilityBonus);
        }
    }

    auto retVal = s_GetTotalEffectBonusHook->CallOriginal<int32_t>(pCreature, nEffectBonusType, pObject, bElementalDamage,
                                                                   bForceMax, nSaveType, nSpecificType, nSkill, nAbilityScore, bOffHand);

    if (nEffectBonusType == 1)
        pServerExoApp->SetAttackBonusLimit(attackBonusLimit);
    else if (nEffectBonusType == 3)
        pServerExoApp->SetSavingThrowBonusLimit(saveBonusLimit);
    else if (nEffectBonusType == 4)
        pServerExoApp->SetAbilityBonusLimit(abilityBonusLimit);

    return retVal;
}

int32_t Feat::GetWeaponPowerHook(CNWSCreature *pCreature, CNWSObject *pObject, int32_t bOffHand)
{
    auto *pServerExoApp = Globals::AppManager()->m_pServerExoApp;
    uint16_t attackBonusLimit = pServerExoApp->GetAttackBonusLimit();

    for (int32_t j = 0; j < pCreature->m_pStats->m_lstFeats.num; j++)
    {
        auto nFeat = pCreature->m_pStats->m_lstFeats.element[j];
        auto modABBonus = g_plugin->m_FeatAB[nFeat];
        uint8_t modABVSRaceBonus = 0;
        auto *pTargetCreature = pServerExoApp->GetCreatureByGameObjectID(pObject->m_idSelf);
        if (pTargetCreature)
            modABVSRaceBonus = g_plugin->m_FeatABVsRace[nFeat][pTargetCreature->m_pStats->m_nRace];
        pServerExoApp->SetAttackBonusLimit(pServerExoApp->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);
    }

    auto retVal = s_GetWeaponPowerHook->CallOriginal<int32_t>(pCreature, pObject, bOffHand);

    pServerExoApp->SetAttackBonusLimit(attackBonusLimit);

    return retVal;
}

void Feat::AddFeatEffects(CNWSCreatureStats *pCreatureStats, uint16_t featId)
{
    if (g_plugin->m_Feats.find(featId) != g_plugin->m_Feats.end())
    {
        if (!pCreatureStats->HasFeat(featId))
        {
            g_plugin->ApplyFeatEffects(pCreatureStats->m_pBaseCreature, featId);
        }
    }
}

void Feat::RemoveFeatEffects(CNWSCreatureStats *pCreatureStats, uint16_t featId)
{
    if (g_plugin->m_Feats.find(featId) != g_plugin->m_Feats.end())
    {
        if (pCreatureStats->HasFeat(featId))
        {
            if (g_plugin->m_FeatBonusSpell.find(featId) != g_plugin->m_FeatBonusSpell.end())
            {
                g_plugin->AddRemoveBonusSpell(pCreatureStats, featId, false);
            }
            std::vector<uint64_t> remove(128);
            for (int i = 0; i < pCreatureStats->m_pBaseCreature->m_appliedEffects.num; i++)
            {
                auto eff = (CGameEffect *) pCreatureStats->m_pBaseCreature->m_appliedEffects.element[i];
                std::string featTag = "NWNX_Feat_FeatMod_" + std::to_string(featId);
                if (eff->m_sCustomTag == featTag)
                {
                    remove.push_back(eff->m_nID);
                }
            }
            for (auto id: remove)
                pCreatureStats->m_pBaseCreature->RemoveEffectById(id);
        }
    }
}

void Feat::AddRemoveBonusSpell(CNWSCreatureStats *pCreatureStats, uint16_t featId, bool bAdd)
{
    for (auto &bonusSpellMod : g_plugin->m_FeatBonusSpell[featId])
    {
        auto classType = bonusSpellMod.first;
        for (auto &bonusSpellModClass : g_plugin->m_FeatBonusSpell[featId][classType])
        {
            uint8_t classLevel = bonusSpellModClass.first;
            int32_t classLevelBonus = bonusSpellModClass.second;
            if (classLevelBonus != 0)
            {
                int nMultiClass = -1;
                for (int i = 0; i < pCreatureStats->m_nNumMultiClasses; i++)
                {
                    if (pCreatureStats->m_ClassInfo[i].m_nClass == classType)
                    {
                        nMultiClass = i;
                        break;
                    }
                }
                if (nMultiClass >= 0)
                {
                    pCreatureStats->ModifyNumberBonusSpells(nMultiClass, classLevel, (bAdd ? 1 : -1) * classLevelBonus);
                }
            }
        }
    }
}

void Feat::AddFeatHook(CNWSCreatureStats *pCreatureStats, uint16_t nFeat)
{
    AddFeatEffects(pCreatureStats, nFeat);
    s_AddFeatHook->CallOriginal<void>(pCreatureStats, nFeat);
}

int32_t Feat::OnApplyBonusFeatHook(CNWSEffectListHandler *pEffectListHandler, CNWSObject *pObject, CGameEffect *pEffect, int32_t bLoadingGame)
{
    if (auto *pCreature = Utils::AsNWSCreature(pObject))
        AddFeatEffects(pCreature->m_pStats, pEffect->GetInteger(0));

    return s_OnApplyBonusFeatHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect, bLoadingGame);
}

void Feat::RemoveFeatHook(CNWSCreatureStats *pCreatureStats, uint16_t nFeat)
{
    RemoveFeatEffects(pCreatureStats, nFeat);
    s_RemoveFeatHook->CallOriginal<void>(pCreatureStats, nFeat);
}

int32_t Feat::OnRemoveBonusFeatHook(CNWSEffectListHandler *pEffectListHandler, CNWSObject *pObject, CGameEffect *pEffect)
{
    if (auto *pCreature = Utils::AsNWSCreature(pObject))
        RemoveFeatEffects(pCreature->m_pStats, pEffect->GetInteger(0));

    return s_OnRemoveBonusFeatHook->CallOriginal<int32_t>(pEffectListHandler, pObject, pEffect);
}

void Feat::EatTURDHook(CNWSPlayer *pPlayer, CNWSPlayerTURD *pTURD)
{
    if (pTURD)
    {
        std::vector<uint64_t> remove(128);
        for (int i = 0; i < pTURD->m_appliedEffects.num; i++)
        {
            auto *eff = pTURD->m_appliedEffects.element[i];

            std::string sCustomTag = eff->m_sCustomTag.CStr();
            if (sCustomTag.find("NWNX_Feat_FeatMod_", 0) == 0)
            {
                remove.push_back(eff->m_nID);
            }
        }
        for (auto id: remove)
            pTURD->RemoveEffectById(id);
    }

    s_EatTURDHook->CallOriginal<void>(pPlayer, pTURD);
}

bool Feat::DoFeatModifier(int32_t featId, FeatModifier featMod, int32_t param1, int32_t param2, int32_t param3, int32_t param4)
{
    bool retVal = true;
    auto featNameText = Globals::Rules()->m_lstFeats[featId].GetNameText();
    auto featName = featNameText.CStr();
    std::string sFeat = std::to_string(featId);
    switch (featMod)
    {
        case AB:
        {
            g_plugin->m_FeatAB[featId] = param1;
            LOG_INFO("%s: Setting AB modifier to %d.", featName, param1);
            break;
        }
        case ABILITY:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Ability modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatAbility[featId][param1] = param2;
            LOG_INFO("%s: Setting %s Ability modifier to %d.", featName, Constants::Ability::ToString(param1), param2);
            break;
        }
        case ABVSRACE:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: AB modifier vs Race modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatABVsRace[featId][param1] = param2;
            auto versusRaceName = Globals::Rules()->m_lstRaces[param1].GetNamePluralText();
            LOG_INFO("%s: Setting AB modifier vs %s to %d.", featName, versusRaceName, param2);
            break;
        }
        case AC:
        {
            g_plugin->m_FeatAC[featId] = param1;
            LOG_INFO("%s: Setting AC modifier to %d.", featName, param1);
            break;
        }
        case ACVSRACE:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: AC modifier vs Race modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatACVsRace[featId][param1] = param2;
            auto versusRaceName = Globals::Rules()->m_lstRaces[param1].GetNamePluralText();
            LOG_INFO("%s: Setting AC modifier vs %s to %d.", featName, versusRaceName, param2);
            break;
        }
        case ARCANESPELLFAILURE:
        {
            g_plugin->m_FeatArcaneSpellFailure[featId] = param1;
            LOG_INFO("%s: Adjusting Arcane Spell Failure by %d%%.", featName, param1);
            break;
        }
        case BONUSSPELL:
        {
            CNWClass *pClass = param1 < Globals::Rules()->m_nNumClasses ? &Globals::Rules()->m_lstClasses[param1] : nullptr;
            if (!pClass || !pClass->m_bIsSpellCasterClass || param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF || param2 < 0 || param2 > 9)
            {
                LOG_ERROR("%s: Bonus Spell modifier improperly set. Arguments should be class, level, bonus spell amount where class is a spellcasting class.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatBonusSpell[featId][param1][param2] = param3;
            LOG_INFO("%s: Setting %s Bonus Spells at Level %d to %d.", featName, Constants::ClassType::ToString(param1), param2, param3);
            break;
        }
        case CONCEALMENT:
        {
            if (param1 < 1 || param1 > 100)
            {
                LOG_ERROR("%s: Natural Concealment modifier improperly set, value must be between 1 and 100.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatConcealment[featId] = param1;
            LOG_INFO("%s: Setting Natural Concealment modifier to %d.", featName, param1);
            break;
        }
        case DMGIMMUNITY:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Damage Immunity modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatDmgImmunity[featId][param1] = param2;
            if (param2 > 0)
                LOG_INFO("%s: Setting Damage Immunity vs %s to %d%%.", featName, Constants::DamageType::ToString(param1), param2);
            else
                LOG_INFO("%s: Setting Damage Vulnerability vs %s to %d%%.", featName, Constants::DamageType::ToString(param1), param2);
            break;
        }
        case DMGREDUCTION:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Damage Reduction modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatDmgReduction[featId][param1] = param2;
            LOG_INFO("%s: Setting Damage Reduction to %d/+%d.", featName, param1, param2);
            break;
        }
        case DMGRESIST:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Damage Resist modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatDmgResist[featId][param1] = param2;
            LOG_INFO("%s: Setting Damage Resist vs %s to %d point(s).", featName, Constants::DamageType::ToString(param1), param2);
            break;
        }
        case HASTE:
        {
            g_plugin->m_FeatHaste.insert(featId);;
            LOG_INFO("%s: Grants Haste", featName);
            break;
        }
        case IMMUNITY:
        {
            g_plugin->m_FeatImmunities[featId].insert(param1);
            LOG_INFO("%s: Setting %s Immunity.", featName, Constants::ImmunityType::ToString(param1));
            break;
        }
        case MOVEMENTSPEED:
        {
            g_plugin->m_FeatMovementSpeed[featId] = param1;
            LOG_INFO("%s: Setting Movement Speed to %d%%.", featName, param1);
            break;
        }
        case REGENERATION:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Regeneration modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatRegeneration[featId] = std::make_pair(param1, param2);
            LOG_INFO("%s: Setting Regeneration to %d hit point(s) every %d second(s).", featName, param1, param2);
            break;
        }
        case SAVE:
        {
            if (param2 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatSave[featId][param1] = param2;
            LOG_INFO("%s: Setting %s Save modifier to %d.", featName, Constants::SavingThrow::ToString(param1), param2);
            break;
        }
        case SAVEVSRACE:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save vs Race modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatSaveVsRace[featId][param1][param2] = param3;
            LOG_INFO("%s: Setting %s Saves vs Race: %s modifier to %d.", featName,
                     Constants::SavingThrow::ToString(param1), Globals::Rules()->m_lstRaces[param2].GetNameText().CStr(),
                     param3);
            break;
        }
        case SAVEVSTYPE:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save vs Type modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatSaveVsType[featId][param1][param2] = param3;
            LOG_INFO("%s: Setting %s Saves vs Type: %s modifier to %d.", featName,
                     Constants::SavingThrow::ToString(param1), Constants::SavingThrowType::ToString(param2),
                     param3);
            break;
        }
        case SAVEVSTYPERACE:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF || param4 == (int32_t)0xDEADBEEF)
            {
                LOG_ERROR("%s: Save vs Type and Race modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatSaveVsTypeRace[featId][param1][param2][param3] = param4;
            LOG_INFO("%s: Setting %s Saves vs Type: %s and Race: %s modifier to %d.", featName,
                     Constants::SavingThrow::ToString(param1),
                     Constants::SavingThrowType::ToString(param2),
                     Globals::Rules()->m_lstRaces[param3].GetNameText().CStr(), param4);
            break;
        }
        case SEEINVISIBLE:
        {
            g_plugin->m_FeatSeeInvisible.insert(featId);;
            LOG_INFO("%s: Grants See Invisible", featName);
            break;
        }
        case SPELLIMMUNITY:
        {
            g_plugin->m_FeatSpellImmunities[featId].insert(param1);
            auto spellName = Globals::Rules()->m_pSpellArray[0].GetSpell(param1)->GetSpellNameText();
            LOG_INFO("%s: Setting %s Spell Immunity.", featName, spellName);
            break;
        }
        case SPELLSAVEDC:
        {
            g_plugin->m_FeatSpellSaveDC[featId] = param1;
            LOG_INFO("%s: Caster's Spell Save DC will be modified by %d.", featName, param1);
            break;
        }
        case SRCHARGEN:
        {
            g_plugin->m_FeatSRCharGen[featId] = std::make_pair(param1, param2);
            LOG_INFO("%s: Setting Spell Resistance on character creation to %d.", featName, param1);
            if (param2 > 0)
                LOG_INFO("%s: Setting Maximum Racial Spell Resistance to %d.", featName, param2);
            break;
        }
        case SRINCLEVEL:
        {
            if (param2 == (int32_t)0xDEADBEEF || param3 == (int32_t)0xDEADBEEF || param2 <= 0 || param3 <= 0)
            {
                LOG_ERROR("%s: Incremental Spell Resistance modifier improperly set.", featName);
                retVal = false;
                break;
            }
            g_plugin->m_FeatSR[featId] = {param1, param2, param3};
            LOG_INFO("%s: Setting Spell Resistance increment %d point(s) every %d level(s) beginning at level %d.", featName, param1, param2, param3);
            break;
        }
        case TRUESEEING:
        {
            g_plugin->m_FeatTrueSeeing.insert(featId);;
            LOG_INFO("%s: Grants True Seeing", featName);
            break;
        }
        case ULTRAVISION:
        {
            g_plugin->m_FeatUltravision.insert(featId);;
            LOG_INFO("%s: Grants Ultravision", featName);
            break;
        }
        case VISUALEFFECT:
        {
            g_plugin->m_FeatVFX[featId].insert(param1);
            auto *twoda = Globals::Rules()->m_p2DArrays->GetCached2DA("visualeffects", true);
            twoda->Load2DArray();
            CExoString label;
            twoda->GetCExoStringEntry(param1, 0, &label);
            LOG_INFO("%s: Will apply %s VFX.", featName, label.CStr());
            break;
        }
        case INVALID:
        {
            LOG_ERROR("Feat modifier not recognized.");
            retVal = false;
            break;
        }
    }
    return retVal;
}

ArgumentStack Feat::SetFeatModifier(ArgumentStack&& args)
{
    auto featId = ScriptAPI::ExtractArgument<int>(args);
    auto featMod = static_cast<FeatModifier>(ScriptAPI::ExtractArgument<int>(args));
    auto param1 = ScriptAPI::ExtractArgument<int>(args);
    auto param2 = ScriptAPI::ExtractArgument<int>(args);
    auto param3 = ScriptAPI::ExtractArgument<int>(args);
    auto param4 = ScriptAPI::ExtractArgument<int>(args);

    if (DoFeatModifier(featId, featMod, param1, param2, param3, param4) && !g_plugin->m_Feats.count(featId))
        g_plugin->m_Feats.insert(featId);

    return ScriptAPI::Arguments();
}

}
