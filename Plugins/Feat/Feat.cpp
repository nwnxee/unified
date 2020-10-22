#include "Feat.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWFeat.hpp"
#include "API/CNWRace.hpp"
#include "API/CNWLevelStats.hpp"
#include "API/CNWRules.hpp"
#include "API/CNWSpellArray.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCreatureStats.hpp"
#include "API/Constants.hpp"
#include "API/Constants/Effect.hpp"
#include "API/Globals.hpp"
#include "API/Functions.hpp"
#include "Services/Config/Config.hpp"
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

Feat::Feat(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetFeatModifier);

#undef REGISTER

    m_ShowEffectIcon = GetServices()->m_config->Get<bool>("SHOW_EFFECT_ICON", false);

    // We want the feat bonuses to not count toward limits
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature19GetTotalEffectBonusEhP10CNWSObjectiihhhhi, int32_t, CNWSCreature*, uint8_t, CNWSObject*, int32_t, int32_t, uint8_t, uint8_t, uint8_t, uint8_t, int32_t>(&GetTotalEffectBonusHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature15SavingThrowRollEhthjiti, int32_t, CNWSCreature*, uint8_t, uint16_t, uint8_t, uint32_t, int32_t, uint16_t, int32_t>(&SavingThrowRollHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature14GetWeaponPowerEP10CNWSObjecti, int32_t, CNWSCreature*, CNWSObject*, int32_t>(&GetWeaponPowerHook);

    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN17CNWSCreatureStats7AddFeatEt, int32_t, CNWSCreatureStats*, uint16_t>(&AddFeatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN17CNWSCreatureStats10RemoveFeatEt, int32_t, CNWSCreatureStats*, uint16_t>(&RemoveFeatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN21CNWSEffectListHandler16OnApplyBonusFeatEP10CNWSObjectP11CGameEffecti, int32_t, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, int32_t>(&OnApplyBonusFeatHook);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN21CNWSEffectListHandler17OnRemoveBonusFeatEP10CNWSObjectP11CGameEffect, int32_t, CNWSEffectListHandler*, CNWSObject*, CGameEffect*>(&OnRemoveBonusFeatHook);
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
}

void Feat::SavingThrowRollHook(
        bool before,
        CNWSCreature *pCreature,
        uint8_t nSaveType,
        uint16_t,
        uint8_t nSpecificType,
        uint32_t oidSaveVersus,
        int32_t, uint16_t, int32_t)
{
    auto server = Globals::AppManager()->m_pServerExoApp;
    static uint16_t savingThrowBonusLimit;
    if (before)
    {
        savingThrowBonusLimit = server->GetSavingThrowBonusLimit();

        auto tgtCreature = server->GetCreatureByGameObjectID(oidSaveVersus);
        for (int32_t j = 0; j < pCreature->m_pStats->m_lstFeats.num; j++)
        {
            auto nFeat = pCreature->m_pStats->m_lstFeats.element[j];
            auto modSaveBonus = g_plugin->m_FeatSave[nFeat][nSaveType] + g_plugin->m_FeatSave[nFeat][Constants::SavingThrow::All];
            uint8_t modSaveVSRaceBonus = 0;
            if (tgtCreature)
            {
                std::list<uint8_t> saveBonuses = {};
                for (int32_t k = 0; k <= Constants::SavingThrow::MAX; k++)
                {
                    saveBonuses.push_front(g_plugin->m_FeatSaveVsRace[nFeat][k][tgtCreature->m_pStats->m_nRace]);
                    saveBonuses.push_front(g_plugin->m_FeatSaveVsTypeRace[nFeat][k][nSpecificType][tgtCreature->m_pStats->m_nRace]);
                }
                modSaveVSRaceBonus = *std::max_element(saveBonuses.begin(), saveBonuses.end());
            }
            auto modSaveVSTypeBonus = g_plugin->m_FeatSaveVsType[nFeat][nSaveType][nSpecificType] +
                                      g_plugin->m_FeatSaveVsType[nFeat][Constants::SavingThrow::All][nSpecificType];
            server->SetSavingThrowBonusLimit(
                    server->GetSavingThrowBonusLimit() + modSaveBonus + modSaveVSRaceBonus + modSaveVSTypeBonus);
        }
    }
    else
    {
        server->SetSavingThrowBonusLimit(savingThrowBonusLimit);
    }
}

void Feat::GetTotalEffectBonusHook(
        bool before,
        CNWSCreature *pCreature,
        uint8_t nEffectBonusType,
        CNWSObject *pObject,
        int32_t, int32_t, uint8_t, uint8_t, uint8_t nSkill, uint8_t, int32_t)
{
    auto server = Globals::AppManager()->m_pServerExoApp;
    static uint16_t attackBonusLimit;
    static uint16_t abilityBonusLimit;
    static uint16_t saveBonusLimit;

    if (before)
    {
        if (nEffectBonusType == 1)
            attackBonusLimit = server->GetAttackBonusLimit();
        else if (nEffectBonusType == 3)
            saveBonusLimit = server->GetSavingThrowBonusLimit();
        else if (nEffectBonusType == 4)
            abilityBonusLimit = server->GetAbilityBonusLimit();
        CNWSCreature* tgtCreature = nullptr;
        if (pObject != nullptr)
        {
            tgtCreature = server->GetCreatureByGameObjectID(pObject->m_idSelf);
        }
        for (int32_t j = 0; j < pCreature->m_pStats->m_lstFeats.num; j++)
        {
            auto nFeat = pCreature->m_pStats->m_lstFeats.element[j];
            if (nEffectBonusType == 1)
            {
                auto modABBonus = g_plugin->m_FeatAB[nFeat];
                uint8_t modABVSRaceBonus = 0;
                if (tgtCreature)
                    modABVSRaceBonus = g_plugin->m_FeatABVsRace[nFeat][tgtCreature->m_pStats->m_nRace];
                server->SetAttackBonusLimit(server->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);
            }
            else if (nEffectBonusType == 3)
            {
                auto modSaveBonus = g_plugin->m_FeatAbility[nFeat][nSkill];
                uint8_t modSaveVSRaceBonus = 0;
                if (tgtCreature)
                {
                    std::list<uint8_t> saveBonuses = {};
                    auto featRace = g_plugin->m_FeatSaveVsRace[nFeat][tgtCreature->m_pStats->m_nRace];
                    saveBonuses.push_front(featRace[Constants::SavingThrow::All]);
                    saveBonuses.push_front(featRace[Constants::SavingThrow::Fortitude]);
                    saveBonuses.push_front(featRace[Constants::SavingThrow::Reflex]);
                    saveBonuses.push_front(featRace[Constants::SavingThrow::Will]);
                    modSaveVSRaceBonus = *std::max_element(saveBonuses.begin(), saveBonuses.end());
                }
                server->SetSavingThrowBonusLimit(server->GetSavingThrowBonusLimit() + modSaveBonus + modSaveVSRaceBonus);
            }
            else if (nEffectBonusType == 4)
            {
                auto modAbilityBonus = g_plugin->m_FeatAbility[nFeat][nSkill];
                server->SetAbilityBonusLimit(server->GetAbilityBonusLimit() + modAbilityBonus);
            }
        }
    }
    else
    {
        if (nEffectBonusType == 1)
            server->SetAttackBonusLimit(attackBonusLimit);
        else if (nEffectBonusType == 3)
            server->SetSavingThrowBonusLimit(saveBonusLimit);
        else if (nEffectBonusType == 4)
            server->SetAbilityBonusLimit(abilityBonusLimit);
    }
}

void Feat::GetWeaponPowerHook(bool before, CNWSCreature *pCreature, CNWSObject *pObject, int32_t)
{
    auto server = Globals::AppManager()->m_pServerExoApp;
    static uint16_t attackBonusLimit;
    if (before)
    {
        attackBonusLimit = server->GetAttackBonusLimit();
        for (int32_t j = 0; j < pCreature->m_pStats->m_lstFeats.num; j++)
        {
            auto nFeat = pCreature->m_pStats->m_lstFeats.element[j];
            auto modABBonus = g_plugin->m_FeatAB[nFeat];
            uint8_t modABVSRaceBonus = 0;
            auto tgtCreature = server->GetCreatureByGameObjectID(pObject->m_idSelf);
            if (tgtCreature)
                modABVSRaceBonus = g_plugin->m_FeatABVsRace[nFeat][tgtCreature->m_pStats->m_nRace];
            server->SetAttackBonusLimit(server->GetAttackBonusLimit() + modABBonus + modABVSRaceBonus);
        }
    }
    else
    {
        server->SetAttackBonusLimit(attackBonusLimit);
    }
}

void Feat::AddFeatEffects(CNWSCreatureStats *pCreatureStats, uint16_t featId)
{
    if(g_plugin->m_Feats.find(featId) != g_plugin->m_Feats.end())
    {
        if (!pCreatureStats->HasFeat(featId))
        {
            g_plugin->ApplyFeatEffects(pCreatureStats->m_pBaseCreature, featId);
        }
    }
}

void Feat::RemoveFeatEffects(CNWSCreatureStats *pCreatureStats, uint16_t featId)
{
    if(g_plugin->m_Feats.find(featId) != g_plugin->m_Feats.end())
    {
        if (pCreatureStats->HasFeat(featId))
        {
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

void Feat::AddFeatHook(bool before, CNWSCreatureStats *pCreatureStats, uint16_t featId)
{
    if (before)
        AddFeatEffects(pCreatureStats, featId);
}

void Feat::OnApplyBonusFeatHook(bool before, CNWSEffectListHandler*, CNWSObject *pObject, CGameEffect*, int32_t featId)
{
    auto pCreatureStats = Utils::AsNWSCreature(pObject)->m_pStats;
    if (pCreatureStats && before)
        AddFeatEffects(pCreatureStats, featId);
}

void Feat::RemoveFeatHook(bool before, CNWSCreatureStats *pCreatureStats, uint16_t featId)
{
    if (before)
        RemoveFeatEffects(pCreatureStats, featId);
}

void Feat::OnRemoveBonusFeatHook(bool before, CNWSEffectListHandler *, CNWSObject *pObject, CGameEffect *pEffect)
{
    auto pCreatureStats = Utils::AsNWSCreature(pObject)->m_pStats;
    auto featId = pEffect->GetInteger(0);
    if (pCreatureStats && before)
        RemoveFeatEffects(pCreatureStats, featId);
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
        case IMMUNITY:
        {
            if (g_plugin->m_FeatImmunities.count(featId))
            {
                g_plugin->m_FeatImmunities[featId].push_back(param1);
            }
            else
            {
                std::list<uint32_t> immunities;
                immunities.push_back(param1);
                g_plugin->m_FeatImmunities[featId] = immunities;
            }
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
        case SPELLIMMUNITY:
        {
            if (g_plugin->m_FeatSpellImmunities.count(featId))
            {
                g_plugin->m_FeatSpellImmunities[featId].push_back(param1);
            }
            else
            {
                std::list<uint32_t> immunities;
                immunities.push_back(param1);
                g_plugin->m_FeatSpellImmunities[featId] = immunities;
            }
            auto spellName = Globals::Rules()->m_pSpellArray[0].GetSpell(param1)->GetSpellNameText();
            LOG_INFO("%s: Setting %s Spell Immunity.", featName, spellName);
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
    auto featId = Services::Events::ExtractArgument<int>(args);
    auto featMod = static_cast<FeatModifier>(Services::Events::ExtractArgument<int>(args));
    auto param1 = Services::Events::ExtractArgument<int>(args);
    auto param2 = Services::Events::ExtractArgument<int>(args);
    auto param3 = Services::Events::ExtractArgument<int>(args);
    auto param4 = Services::Events::ExtractArgument<int>(args);

    if (DoFeatModifier(featId, featMod, param1, param2, param3, param4) && !g_plugin->m_Feats.count(featId))
        g_plugin->m_Feats.insert(featId);

    return Services::Events::Arguments();
}

}
