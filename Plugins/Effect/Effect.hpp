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
    std::string m_effectExpiredData;
    uint32_t m_effectExpiredDepth;
    ObjectID m_effectExpiredCreator;
    bool m_bBypassImm = false;

    NWNXLib::Hooking::FunctionHook* m_GetEffectImmunityHook;

    ArgumentStack PackEffect(ArgumentStack&& args);
    ArgumentStack UnpackEffect(ArgumentStack&& args);
    ArgumentStack SetEffectExpiredScript(ArgumentStack&& args);
    ArgumentStack GetEffectExpiredData(ArgumentStack&& args);
    ArgumentStack GetEffectExpiredCreator(ArgumentStack&& args);
    ArgumentStack ReplaceEffect(ArgumentStack&& args);
    ArgumentStack GetTrueEffectCount(ArgumentStack&& args);
    ArgumentStack GetTrueEffect(ArgumentStack&& args);
    ArgumentStack ReplaceEffectByIndex(ArgumentStack&& args);
    ArgumentStack RemoveEffectById(ArgumentStack&& args);
    ArgumentStack SetEffectImmunityBypass(ArgumentStack&& args);
    static int32_t  GetEffectImmunityHook(CNWSCreatureStats *pStats, uint8_t nType, CNWSCreature * pVersus, BOOL bConsiderFeats=true);

    ArgumentStack ResolveUnpack(CGameEffect *eff, bool bLink=true);
    void ResolvePack(CGameEffect *eff, bool bReplace=false);
    void InitEffectImmHook();
};

}
