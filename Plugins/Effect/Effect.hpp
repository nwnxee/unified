#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Effect {

class Effect : public NWNXLib::Plugin
{
public:
    Effect(NWNXLib::Services::ProxyServiceList* services);
    virtual ~Effect();

private:
    struct m_bypassRed
    {
      uint16_t m_nPropertyName;
      int32_t m_nSubType;
      int32_t m_nCostTableValue;
      int32_t m_nParam1Value;
      bool bReverse;
    };
    std::string m_effectExpiredData;
    uint32_t m_effectExpiredDepth;
    ObjectID m_effectExpiredCreator;
    bool m_bBypassImm = false;
    bool m_bInitRed = false;
    uint8_t m_iMaterial;
    std::unordered_multimap<int32_t, m_bypassRed> m_bypass;

    NWNXLib::Hooking::FunctionHook* m_GetEffectImmunityHook;

    ArgumentStack PackEffect(ArgumentStack&& args);
    ArgumentStack UnpackEffect(ArgumentStack&& args);
    ArgumentStack SetEffectExpiredScript(ArgumentStack&& args);
    ArgumentStack GetEffectExpiredData(ArgumentStack&& args);
    ArgumentStack GetEffectExpiredCreator(ArgumentStack&& args);
    ArgumentStack ReplaceEffect(ArgumentStack&& args);
    ArgumentStack GetTrueEffectCount(ArgumentStack&& args);
    ArgumentStack GetTrueEffect(ArgumentStack&& args);
    ArgumentStack ReplaceEffectByElement(ArgumentStack&& args);
    ArgumentStack RemoveEffectById(ArgumentStack&& args);
    ArgumentStack SetEffectImmunityBypass(ArgumentStack&& args);
    ArgumentStack SetDamageReductionBypass(ArgumentStack&& args);

    static int32_t  GetEffectImmunityHook(CNWSCreatureStats *pStats, uint8_t nType, CNWSCreature * pVersus, BOOL bConsiderFeats=true);

    static void OnItemPropertyAppliedHook(bool, CServerAIMaster*, CNWSItem*, CNWItemProperty*, CNWSCreature*, uint32_t, BOOL);
    static void OnApplyDamageReductionHook(bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL);
    static void OnApplyEffectImmunityHook(bool, CNWSEffectListHandler*, CNWSObject*, CGameEffect*, BOOL);
    static void DoDamageReductionHook(bool, CNWSObject*, CNWSCreature*, int32_t, uint8_t, BOOL, BOOL);


    ArgumentStack ResolveUnpack(CGameEffect *eff, bool bLink=true);
    void InitEffectImmHook();
    void InitDamageReductionHooks();

};

}
