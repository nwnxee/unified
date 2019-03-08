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

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Damage::Damage> g_plugin;

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
    GetServices()->m_events->RegisterEvent(#func, std::bind(&Damage::func, this, std::placeholders::_1))

    REGISTER(SetEventScript);
    REGISTER(GetDamageEventData);
    REGISTER(SetDamageEventData);
    REGISTER(GetAttackEventData);
    REGISTER(SetAttackEventData);

#undef REGISTER

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSEffectListHandler__OnApplyDamage>(&Damage::OnApplyDamage);
    GetServices()->m_hooks->RequestExclusiveHook<Functions::CNWSCombatRound__SetCurrentAttack>(&Damage::OnCombatAttack);

    m_EventHooks["DAMAGE"] = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSEffectListHandler__OnApplyDamage);
    m_EventHooks["ATTACK"] = GetServices()->m_hooks->FindHookByAddress(Functions::CNWSCombatRound__SetCurrentAttack);

    m_EventScripts["DAMAGE"] = "";
    m_EventScripts["ATTACK"] = "";
}

Damage::~Damage()
{
}

ArgumentStack Damage::SetEventScript(ArgumentStack&& args)
{
    ArgumentStack stack;
    const std::string event = Services::Events::ExtractArgument<std::string>(args);
    const std::string script = Services::Events::ExtractArgument<std::string>(args);
    Types::ObjectID oidOwner = Services::Events::ExtractArgument<Types::ObjectID>(args);

    if (oidOwner == Constants::OBJECT_INVALID)
    {
        m_EventScripts[event] = script;
        LOG_INFO("Set Global %s Event Script to %s", event.c_str(), script.c_str());
    }
    else
    {
        if (script != "")
        {
            g_plugin->GetServices()->m_perObjectStorage->Set(oidOwner, event + "_EVENT_SCRIPT", script);
            LOG_INFO("Set object 0x%08x %s Event Script to %s", oidOwner, event.c_str(), script.c_str());
        }
        else
        {
            g_plugin->GetServices()->m_perObjectStorage->Remove(oidOwner, event + "_EVENT_SCRIPT");
            LOG_INFO("Clearing %s Event Script for object 0x%08x", event.c_str(), oidOwner);
        }
    }

    return stack;
}

std::string Damage::GetEventScript(NWNXLib::API::CNWSObject *pObject, const std::string &event)
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

int32_t Damage::OnApplyDamage(NWNXLib::API::CNWSEffectListHandler *pThis, NWNXLib::API::CNWSObject *pObject, NWNXLib::API::CGameEffect *pEffect, bool bLoadingGame)
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

    return g_plugin->m_EventHooks["DAMAGE"]->CallOriginal<int32_t>(pThis, pObject, pEffect, bLoadingGame);
}

//--------------------------- Attack Event ------------------------------------

ArgumentStack Damage::GetAttackEventData(ArgumentStack&&)
{
    ArgumentStack stack;

    Services::Events::InsertArgument(stack, m_AttackData.bOffhand);
    Services::Events::InsertArgument(stack, m_AttackData.bSneakAttack);
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

    return stack;
}

void Damage::OnCombatAttack(NWNXLib::API::CNWSCombatRound *pThis, uint8_t attackNumber)
{
    std::string script = GetEventScript(pThis->m_pBaseCreature, "ATTACK");
    AttackDataStr& attackData = g_plugin->m_AttackData;
    // SetCurrentAttack is 1-based, GetAttack is 0-based
    CNWSCombatAttackData *combatAttackData = pThis->GetAttack(attackNumber - 1);

    if (!script.empty())
    {
        // Prepare the data for the nwscript
        attackData.oidTarget = pThis->m_pBaseCreature->m_oidAttackTarget;
        attackData.nAttackNumber = attackNumber;
        attackData.nAttackResult = combatAttackData->m_nAttackResult;
        attackData.bSneakAttack = combatAttackData->m_bSneakAttack || combatAttackData->m_bDeathAttack;
        attackData.bOffhand = combatAttackData->m_nWeaponAttackType == 2;

        std::memcpy(attackData.vDamage, combatAttackData->m_nDamage, sizeof(attackData.vDamage));
        Utils::ExecuteScript(script, pThis->m_pBaseCreature->m_idSelf);
        std::memcpy(combatAttackData->m_nDamage, attackData.vDamage, sizeof(attackData.vDamage));
    }

    g_plugin->m_EventHooks["ATTACK"]->CallOriginal<void>(pThis, attackNumber);
}

}
