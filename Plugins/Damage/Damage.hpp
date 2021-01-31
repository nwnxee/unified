#pragma once

#include "nwnx.hpp"
using ArgumentStack = NWNXLib::Events::ArgumentStack;

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
    uint8_t  nAttackType;
    uint8_t  nSneakAttack;
    uint8_t  bRanged;
};

namespace Damage {

class Damage : public NWNXLib::Plugin
{
public:
    Damage(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Damage();

private:
    ArgumentStack SetEventScript(ArgumentStack&& args);
    ArgumentStack GetDamageEventData(ArgumentStack&& args);
    ArgumentStack SetDamageEventData(ArgumentStack&& args);
    ArgumentStack GetAttackEventData(ArgumentStack&& args);
    ArgumentStack SetAttackEventData(ArgumentStack&& args);
    ArgumentStack DealDamage(ArgumentStack&& args);

    NWNXLib::Hooks::Hook m_OnApplyDamageHook;
    NWNXLib::Hooks::Hook m_SignalMeleeDamageHook;
    NWNXLib::Hooks::Hook m_SignalRangedDamageHook;

    static int32_t OnApplyDamage(CNWSEffectListHandler *pThis, CNWSObject *pObject, CGameEffect *pEffect, BOOL bLoadingGame);
    static void HandleSignalDamage(CNWSCreature *pThis, CNWSObject *pTarget, int32_t nAttacks);
    static void SignalMeleeDamageHook(CNWSCreature *pThis, CNWSObject *pTarget, int32_t nAttacks);
    static void SignalRangedDamageHook(CNWSCreature *pThis, CNWSObject *pTarget, int32_t nAttacks);
    static void OnCombatAttack(CNWSCreature *pThis, CNWSObject *pTarget, std::string script, uint8_t attackNumber);

    static std::string GetEventScript(CNWSObject *pObject, const std::string &event);

    std::unordered_map<std::string,std::string> m_EventScripts;

    DamageDataStr m_DamageData;
    AttackDataStr m_AttackData;
};

}
