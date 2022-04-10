#include "Events.hpp"

#include "API/CNWSArea.hpp"
#include "API/CNWSModule.hpp"
#include "API/CNWSObject.hpp"

namespace Events {

using namespace NWNXLib::API;
using namespace NWNXLib::API::Constants;

// BOOL CNWSArea::RunEventScript(int32_t nScript, CExoString* psOverrideScriptName)
static NWNXLib::Hooks::Hook s_runAreaEventScript;
// BOOL CNWSModule::RunEventScript(int32_t nScript, CExoString* psOverrideScriptName)
static NWNXLib::Hooks::Hook s_runModuleEventScript;
// BOOL CNWSObject::RunEventScript(int32_t nScript, CExoString* psOverrideScriptName)
static NWNXLib::Hooks::Hook s_runObjectEventScript;

static void AreaRunEventScript(CNWSArea*, int32_t, CExoString*);
static void ModuleRunEventScript(CNWSModule*, int32_t, CExoString*);
static void ObjectRunEventScript(CNWSObject*, int32_t, CExoString*);

void HookEvents() __attribute__((constructor));
void HookEvents()
{
    InitOnFirstSubscribe("NWNX_ON_RUN_EVENT_SCRIPT_(BEFORE|AFTER)", []() {
        ForceEnableWhitelist("NWNX_ON_RUN_EVENT_SCRIPT");

        s_runAreaEventScript = NWNXLib::Hooks::HookFunction(Functions::_ZN8CNWSArea14RunEventScriptEiP10CExoString,
                                             (void*)&AreaRunEventScript, NWNXLib::Hooks::Order::Earliest);

        s_runModuleEventScript = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSModule14RunEventScriptEiP10CExoString,
                                             (void*)&ModuleRunEventScript, NWNXLib::Hooks::Order::Earliest);

        s_runObjectEventScript = NWNXLib::Hooks::HookFunction(Functions::_ZN10CNWSObject14RunEventScriptEiP10CExoString,
                                             (void*)&ObjectRunEventScript, NWNXLib::Hooks::Order::Earliest);
    });
}

static void DoEH(uint32_t tySelf, ObjectID idSelf, 
    int32_t nScriptIdx, CExoString* psScript,
    std::function<void()> fnEv)
{
    const int32_t nType = tySelf * 1000 + nScriptIdx;
    
    if (!IsIDInWhitelist("NWNX_ON_RUN_EVENT_SCRIPT", nType))
    {
        fnEv();
        return;
    }

    auto PushAndSignal = [&](const std::string& ev) -> bool {
        PushEventData("EVENT_TYPE", std::to_string(nType));
        PushEventData("EVENT_SCRIPT", psScript->CStr());
        return SignalEvent(ev, idSelf);
    };

    if (!PushAndSignal("NWNX_ON_RUN_EVENT_SCRIPT_BEFORE"))
    {
        return;
    }

    fnEv();

    PushAndSignal("NWNX_ON_RUN_EVENT_SCRIPT_AFTER");
}

void AreaRunEventScript(CNWSArea* thisPtr, int32_t nScript, CExoString* psOverrideScriptName)
{
    ASSERT(nScript >= 0 && nScript < (int32_t)(sizeof(CNWSArea::m_sScripts) / sizeof(CExoString)));
    CExoString* psScript = psOverrideScriptName ? psOverrideScriptName : &(thisPtr->m_sScripts[nScript]);

    DoEH(thisPtr->m_nObjectType, thisPtr->m_idSelf, nScript, psScript, [&]() {
        s_runAreaEventScript->CallOriginal<void>(thisPtr, nScript, psOverrideScriptName);    
    });
}

void ModuleRunEventScript(CNWSModule* thisPtr, int32_t nScript, CExoString* psOverrideScriptName)
{
    ASSERT(nScript >= 0 && nScript < (int32_t)(sizeof(CNWSModule::m_sScripts) / sizeof(CExoString)));
    CExoString* psScript = psOverrideScriptName ? psOverrideScriptName : &(thisPtr->m_sScripts[nScript]);

    DoEH(thisPtr->m_nObjectType, thisPtr->m_idSelf, nScript, psScript, [&]() {
        s_runModuleEventScript->CallOriginal<void>(thisPtr, nScript, psOverrideScriptName);
    });
}

void ObjectRunEventScript(CNWSObject* thisPtr, int32_t nScript, CExoString* psOverrideScriptName)
{
    CExoString* psScript = psOverrideScriptName ? psOverrideScriptName : thisPtr->GetScriptName(nScript);

    DoEH(thisPtr->m_nObjectType, thisPtr->m_idSelf, nScript, psScript, [&]() {
        s_runObjectEventScript->CallOriginal<void>(thisPtr, nScript, psOverrideScriptName);
    });
}

}
