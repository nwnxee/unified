#include "Damage.hpp"
#include "API/Functions.hpp"
#include "API/Constants.hpp"
#include "API/CGameEffect.hpp"
#include "API/CNWSObject.hpp"
#include "API/Globals.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSCreature.hpp"
#include "API/CNWSCombatRound.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Utils.hpp"

#include <cstring>
#include <bitset>

using namespace NWNXLib;
using namespace NWNXLib::API;

static Damage::Damage* g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Damage",
        "Damage related functions",
        "Bhaal (original nwnx2 plugin from Baaleos)",
        "marca.argentea at gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Damage::Damage(params);
    return g_plugin;
}

namespace Damage {

Damage::Damage(const Plugin::CreateParams& params)
  : Plugin(params)
{

#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(SetEventScript);
    REGISTER(GetDamageEventData);
    REGISTER(SetDamageEventData);
    REGISTER(GetAttackEventData);
    REGISTER(SetAttackEventData);
    REGISTER(DealDamage);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::_ZN21CNWSEffectListHandler13OnApplyDamageEP10CNWSObjectP11CGameEffecti>(&Damage::OnApplyDamage);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature17SignalMeleeDamageEP10CNWSObjecti, void>(&Damage::OnSignalDamage);
    GetServices()->m_hooks->RequestSharedHook<Functions::_ZN12CNWSCreature18SignalRangedDamageEP10CNWSObjecti, void>(&Damage::OnSignalDamage);

    m_OnApplyDamageHook = GetServices()->m_hooks->FindHookByAddress(Functions::_ZN21CNWSEffectListHandler13OnApplyDamageEP10CNWSObjectP11CGameEffecti);

    m_EventScripts["DAMAGE"] = "";
    m_EventScripts["ATTACK"] = "";
}

Damage::~Damage()
{
}

ArgumentStack Damage::SetEventScript(ArgumentStack&& args)
{
    const std::string event = Services::Events::ExtractArgument<std::string>(args);
    const std::string script = Services::Events::ExtractArgument<std::string>(args);
    Types::ObjectID oidOwner = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (oidOwner == Constants::OBJECT_INVALID)
    {
        m_EventScripts[event] = script;
        LOG_INFO("Set Global %s Event Script to %s", event, script);
    }
    else
    {
        if (script != "")
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(oidOwner, event + "_EVENT_SCRIPT", script, true);
            LOG_INFO("Set object 0x%08x %s Event Script to %s", oidOwner, event, script);
        }
        else
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(oidOwner, event + "_EVENT_SCRIPT");
            LOG_INFO("Clearing %s Event Script for object 0x%08x", event, oidOwner);
        }
    }

    return Services::Events::Arguments();
}

std::string Damage::GetEventScript(CNWSObject *pObject, const std::string &event)
{
    auto posScript = g_plugin->GetServices()->m_perObjectStorage->Get<std::string>(pObject, event + "_EVENT_SCRIPT");
    return posScript ? *posScript : g_plugin->m_EventScripts[event];
}

//--------------------------- Damage Event ------------------------------------

ArgumentStack Damage::GetDamageEventData(ArgumentStack&&)
{
    ArgumentStack stack;

    for (int k = 12; k >= 0; k--)
    {
        Services::Events::InsertArgument(stack, m_DamageData.vDamage[k]);
    }
    Services::Events::InsertArgument(stack, m_DamageData.oidDamager);

    return stack;
}

ArgumentStack Damage::SetDamageEventData(ArgumentStack&& args)
{
    ArgumentStack stack;

    for (int k = 0; k < 13; k++)
    {
        m_DamageData.vDamage[k] = Services::Events::ExtractArgument<int32_t>(args);
    }

    return stack;
}

int32_t Damage::OnApplyDamage(CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pEffect, bool bLoadingGame)
{
    std::string script = GetEventScript(pObject, "DAMAGE");

    if (!script.empty())
    {
        // We only run the OnDamage event for creatures.
        if (Utils::AsNWSCreature(pObject))
        {
            // Prepare the data for the nwscript
            g_plugin->m_DamageData.oidDamager = pEffect->m_oidCreator;

            std::memcpy(g_plugin->m_DamageData.vDamage, pEffect->m_nParamInteger, sizeof(g_plugin->m_DamageData.vDamage));
            Utils::ExecuteScript(script, pObject->m_idSelf);
            std::memcpy(pEffect->m_nParamInteger, g_plugin->m_DamageData.vDamage, sizeof(g_plugin->m_DamageData.vDamage));
        }
    }

    return g_plugin->m_OnApplyDamageHook->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);
}

//--------------------------- Attack Event ------------------------------------

ArgumentStack Damage::GetAttackEventData(ArgumentStack&&)
{
    ArgumentStack stack;

    Services::Events::InsertArgument(stack, m_AttackData.nSneakAttack);
    Services::Events::InsertArgument(stack, m_AttackData.nAttackType);
    Services::Events::InsertArgument(stack, m_AttackData.nAttackResult);
    Services::Events::InsertArgument(stack, m_AttackData.nAttackNumber);
    for (int k = 12; k >= 0; k--)
    {
        Services::Events::InsertArgument(stack, m_AttackData.vDamage[k]);
    }
    Services::Events::InsertArgument(stack, m_AttackData.oidTarget);

    return stack;
}

ArgumentStack Damage::SetAttackEventData(ArgumentStack&& args)
{
    ArgumentStack stack;

    for (int k = 0; k < 13; k++)
    {
        m_AttackData.vDamage[k] = Services::Events::ExtractArgument<int32_t>(args);
    }
    m_AttackData.nAttackResult = Services::Events::ExtractArgument<int32_t>(args);

    return stack;
}

void Damage::OnSignalDamage(bool before, CNWSCreature *pThis, CNWSObject *pTarget, uint32_t nAttacks)
{
    // only call once, either before or after original
    if (before)
    {
        std::string script = GetEventScript(pThis, "ATTACK");
        if ( !script.empty() )
        {
            // m_nCurrentAttack points to the attack *after* this flurry
            uint8_t attackNumberOffset = pThis->m_pcCombatRound->m_nCurrentAttack - nAttacks;
            // trigger script once per attack in the flurry
            for ( uint8_t i = 0; i < nAttacks; i++ )
                OnCombatAttack(pThis, pTarget, script, attackNumberOffset + i);
        }
    }
}

void Damage::OnCombatAttack(CNWSCreature *pThis, CNWSObject *pTarget, std::string script, uint8_t attackNumber)
{
    AttackDataStr& attackData = g_plugin->m_AttackData;
    CNWSCombatRound *combatRound = pThis->m_pcCombatRound;
    CNWSCombatAttackData *combatAttackData = combatRound->GetAttack(attackNumber);
    // Prepare the data for the nwscript
    attackData.oidTarget = pTarget->m_idSelf;
    attackData.nAttackNumber = attackNumber + 1; // 1-based for backwards compatibility
    attackData.nAttackResult = combatAttackData->m_nAttackResult;
    attackData.nAttackType = combatAttackData->m_nWeaponAttackType;
    attackData.nSneakAttack = combatAttackData->m_bSneakAttack + (combatAttackData->m_bDeathAttack << 1);
    std::memcpy(attackData.vDamage, combatAttackData->m_nDamage, sizeof(attackData.vDamage));
    // run script, then copy back attack data
    Utils::ExecuteScript(script, pThis->m_idSelf);
    std::memcpy(combatAttackData->m_nDamage, attackData.vDamage, sizeof(attackData.vDamage));
    combatAttackData->m_nAttackResult = attackData.nAttackResult;
}

//--------------------------- Dealing Damage ----------------------------------

ArgumentStack Damage::DealDamage(ArgumentStack&& args)
{
    int vDamage[13];
    std::bitset<13> positive;

    // read input
    uint32_t oidSource = Services::Events::ExtractArgument<Types::ObjectID>(args);
    uint32_t oidTarget = Services::Events::ExtractArgument<Types::ObjectID>(args);

    for (int k = 0; k < 12; k++)
    {
        vDamage[k] = Services::Events::ExtractArgument<int32_t>(args);
        // need to distinguish between no damage dealt, and damage reduced to 0
        positive[k] = vDamage[k] > 0;
    }
    int damagePower = Services::Events::ExtractArgument<int32_t>(args);

    int range = 0;
    try
    {
        range = Services::Events::ExtractArgument<int>(args);
    }
    catch(const std::runtime_error& e)
    {
        LOG_WARNING("NWNX_Damage_DealDamage() called from NWScript without final parameter. Please download the latest versions of NWNX scripts.");
    }

    CNWSCreature *pSource = Globals::AppManager()->m_pServerExoApp->GetCreatureByGameObjectID(oidSource);
    CNWSObject *pTarget = Utils::AsNWSObject(Globals::AppManager()->m_pServerExoApp->GetGameObject(oidTarget));
    ASSERT_OR_THROW(pTarget != nullptr);

    // apply damage immunity and resistance
    for (int k = 0; k < 12; k++)
    {
        if ( vDamage[k] > 0 )
            vDamage[k] = pTarget->DoDamageImmunity(pSource, vDamage[k], 1 << k, false, false);
        if ( vDamage[k] > 0 )
            vDamage[k] = pTarget->DoDamageResistance(pSource, vDamage[k], 1 << k, false, false, false);
    }
    // apply DR (combine physical damage for this)
    vDamage[12] = vDamage[0] + vDamage[1] + vDamage[2];
    positive[12] = positive[0] || positive[1] || positive[2];
    if (vDamage[12] > 0)
        vDamage[12] = pTarget->DoDamageReduction(pSource, vDamage[12], damagePower, false, false);

    // create damage effect ...
    CGameEffect *pEffect = new CGameEffect(true);
    pEffect->m_nType = 38;
    pEffect->SetCreator(oidSource);
    pEffect->SetNumIntegers(19);
    for (int k = 0; k < 3; k++)
        pEffect->SetInteger(k, -1);
    for (int k = 3; k < 13; k++)
        pEffect->SetInteger(k, positive[k] ? vDamage[k] : -1);
    pEffect->SetInteger(17, true); // combat damage
    // ... and apply it

    //Check if ranged (this sets bRangedAttack internally)
    pEffect->SetInteger(18, !!range);

    pTarget->ApplyEffect(pEffect, false, true);

    return Services::Events::Arguments();
}

}
