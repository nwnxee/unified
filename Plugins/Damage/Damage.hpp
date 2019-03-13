#pragma once

#include "Plugin.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Events/Events.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

struct DamageDataStr
{
    uint32_t oidDamager;
    int32_t  vDamage[13];
};

struct AttackDataStr
{
    uint32_t oidTarget;
    int16_t  vDamage[13];
    uint8_t  nAttackNumber;
    uint8_t  nAttackResult;
    uint8_t  bSneakAttack;
    uint8_t  bOffhand;
};

namespace Damage {

class Damage : public NWNXLib::Plugin
{
public:
    Damage(const Plugin::CreateParams& params);
    virtual ~Damage();

private:
    ArgumentStack SetEventScript(ArgumentStack&& args);
    ArgumentStack GetDamageEventData(ArgumentStack&& args);
    ArgumentStack SetDamageEventData(ArgumentStack&& args);
    ArgumentStack GetAttackEventData(ArgumentStack&& args);
    ArgumentStack SetAttackEventData(ArgumentStack&& args);

    NWNXLib::Hooking::FunctionHook* m_OnApplyDamageHook;
    NWNXLib::Hooking::FunctionHook* m_OnCombatAttackHook;

    static int32_t OnApplyDamage(NWNXLib::API::CNWSEffectListHandler *pThis, NWNXLib::API::CNWSObject *pObject, NWNXLib::API::CGameEffect *pEffect, bool bLoadingGame);
    static void OnCombatAttack(NWNXLib::API::CNWSCombatRound *pThis, uint8_t attackNumber);

    static std::string GetEventScript(NWNXLib::API::CNWSObject *pObject, const std::string &event);

    std::unordered_map<std::string,std::string> m_EventScripts;

    DamageDataStr m_DamageData;
    AttackDataStr m_AttackData;
};

}
