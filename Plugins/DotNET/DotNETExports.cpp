#include "nwnx.hpp"
#include "DotNET.hpp"

#include "API/CNWSObject.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"
#include "API/CWorldTimer.hpp"

#include <csignal>
#include <dlfcn.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace DotNET {

// Bootstrap functions
std::vector<void*> GetExports();

AllHandlers s_handlers;
static uint64_t s_frame = 0;
static int32_t s_pushedCount;
static std::vector<std::unique_ptr<NWNXLib::Hooks::FunctionHook>> s_managedHooks;
static std::string s_nwnxActivePlugin;
static std::string s_nwnxActiveFunction;

static Hooks::Hook s_mainLoopHook;
static Hooks::Hook s_runScriptHook;
static Hooks::Hook s_runScriptSituationHook;

static bool s_assertSubscribed;
static bool s_crashSubscribed;

static void OnServerCrash(int sig)
{
    if (s_handlers.Crash)
    {
        auto stackTrace = NWNXLib::Platform::GetStackTrace(20);
        s_handlers.Crash(sig, stackTrace.c_str());
        std::signal(SIGABRT, NULL);
        std::abort();
    }
}

NWNX_EXPORT uintptr_t GetFunctionPointer(const char* name)
{
    LOG_WARNING("GetFunctionPointer is deprecated and will be removed in the next release. Function pointers can be resolved natively in .NET using the System.Runtime.InteropServices.NativeLibrary API.");

    void* core = dlopen("NWNX_Core.so", RTLD_LAZY);
    if (!core)
    {
        LOG_ERROR("Failed to open core handle: %s", dlerror());
        return 0;
    }
    auto ret = reinterpret_cast<uintptr_t>(dlsym(core, name));
    if (ret == 0)
        LOG_WARNING("Failed to get symbol name '%s': %s", name, dlerror());
    dlclose(core);
    return ret;
}

NWNX_EXPORT void RegisterMainLoopHandler(MainLoopHandler handler)
{
    s_handlers.MainLoop = handler;
    if (!handler)
    {
        if (s_mainLoopHook)
        {
            LOG_DEBUG("Removed main loop handler");
            s_mainLoopHook.reset();
        }

        return;
    }

    LOG_DEBUG("Registered main loop handler: %p", s_handlers.MainLoop);
    if (!s_mainLoopHook)
    {
        s_mainLoopHook = Hooks::HookFunction(&CServerExoAppInternal::MainLoop,
                                             +[](CServerExoAppInternal* pServerExoAppInternal) -> int32_t
            {
                int spBefore = Utils::PushScriptContext(Constants::OBJECT_INVALID, 0, false);
                s_handlers.MainLoop(s_frame);
                int spAfter = Utils::PopScriptContext();
                ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
                ++s_frame;

                return s_mainLoopHook->CallOriginal<int32_t>(pServerExoAppInternal);
            }, Hooks::Order::VeryEarly);
    }
}

NWNX_EXPORT void RegisterRunScriptHandler(RunScriptHandler handler)
{
    s_handlers.RunScript = handler;
    if (!handler)
    {
        if (s_runScriptHook)
        {
            LOG_DEBUG("Removed run script handler");
            s_runScriptHook.reset();
        }

        return;
    }

    LOG_DEBUG("Registered run script handler: %p", s_handlers.RunScript);
    if (!s_runScriptHook)
    {
        s_runScriptHook = Hooks::HookFunction(&CVirtualMachine::RunScript,
                                              +[](CVirtualMachine* thisPtr, CExoString* script, ObjectID objId, int32_t valid,
                                                      int32_t eventId) -> int32_t
            {
                if (!script || *script == "")
                    return 1;

                LOG_DEBUG("Calling managed RunScriptHandler for script '%s' on Object 0x%08x", script->CStr(), objId);
                int spBefore = Utils::PushScriptContext(objId, eventId, !!valid);
                int32_t retVal = s_handlers.RunScript(script->CStr(), objId);
                int spAfter = Utils::PopScriptContext();
                ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);

                // ~0 is returned if runscript request is not handled and needs to be forwarded
                if (retVal != ~0)
                {
                    Globals::VirtualMachine()->m_nReturnValueParameterType = 0x03;
                    Globals::VirtualMachine()->m_pReturnValue = reinterpret_cast<void*>(retVal);
                    return 1;
                }

                return s_runScriptHook->CallOriginal<int32_t>(thisPtr, script, objId, valid, eventId);
            },Hooks::Order::Latest);
    }
}

NWNX_EXPORT void RegisterClosureHandler(ClosureHandler handler)
{
    s_handlers.Closure = handler;
    if (!handler)
    {
        LOG_DEBUG("Removed closure handler");
        if (s_runScriptSituationHook)
        {
            s_runScriptSituationHook.reset();
        }

        return;
    }

    LOG_DEBUG("Registered closure handler: %p", s_handlers.Closure);

    if (!s_runScriptSituationHook)
    {
        s_runScriptSituationHook = Hooks::HookFunction(&CVirtualMachine::RunScriptSituation,
                                                       +[](CVirtualMachine* thisPtr, CVirtualMachineScript* script, ObjectID objId,
                                                               int32_t valid) -> int32_t
            {
                uint64_t eventId;
                if (script && sscanf(script->m_sScriptName.m_sString, "NWNX_DOTNET_INTERNAL %lu", &eventId) == 1)
                {
                    LOG_DEBUG("Calling managed RunScriptSituationHandler for event '%lu' on Object 0x%08x", eventId,
                        objId);
                    int spBefore = Utils::PushScriptContext(objId, 0, !!valid);
                    s_handlers.Closure(eventId, objId);
                    int spAfter = Utils::PopScriptContext();
                    ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
                    delete script;

                    return 1;
                }

                return s_runScriptSituationHook->CallOriginal<int32_t>(thisPtr, script, objId, valid);
            }, Hooks::Order::Latest);
    }
}

NWNX_EXPORT void RegisterSignalHandler(SignalHandler handler)
{
    s_handlers.Signal = handler;
    if (handler)
    {
        LOG_DEBUG("Registered signal handler: %p", s_handlers.Closure);
    }
    else
    {
        LOG_DEBUG("Removed signal handler");
    }
}

NWNX_EXPORT void RegisterAssertHandler(AssertHandler handler)
{
    s_handlers.Assert = handler;
    if (!handler)
    {
        LOG_DEBUG("Removed assertion handler");
        return;
    }

    LOG_DEBUG("Registered native assertion handler: %p", s_handlers.Assert);
    if (!s_assertSubscribed)
    {
        s_assertSubscribed = true;
        MessageBus::Subscribe("NWNX_ASSERT_FAIL",
            [](const std::vector<std::string>& message)
            {
                if (!s_handlers.Assert)
                {
                    return;
                }

                if (API::Globals::VirtualMachine())
                {
                    Utils::PushScriptContext(Constants::OBJECT_INVALID, 0, false);
                    s_handlers.Assert(message[0].c_str(), message[1].c_str());
                    Utils::PopScriptContext();
                }
                else
                {
                    s_handlers.Assert(message[0].c_str(), message[1].c_str());
                }
            });
    }
}

NWNX_EXPORT void RegisterCrashHandler(CrashHandler handler)
{
    s_handlers.Crash = handler;
    if (!handler)
    {
        LOG_DEBUG("Removed managed crash handler");
        return;
    }

    LOG_DEBUG("Registered managed crash handler: %p", s_handlers.Crash);
    if (!s_crashSubscribed)
    {
        s_crashSubscribed = true;
        std::signal(SIGABRT, OnServerCrash);
        std::signal(SIGFPE, OnServerCrash);
        std::signal(SIGSEGV, OnServerCrash);
        std::signal(SIGILL, OnServerCrash);
    }
}

NWNX_EXPORT void RegisterHandlers(AllHandlers* handlers, unsigned size)
{
    LOG_WARNING("RegisterHandlers is deprecated and will be removed in the next release. Register handlers individually through the RegisterXXXHandler methods.");

    if (handlers == nullptr)
    {
        LOG_ERROR("RegisterHandlers argument is null pointer, aborting");
        return;
    }
    if (size != sizeof(*handlers))
    {
        LOG_ERROR("RegisterHandlers argument contains invalid number of entries, aborting");
        return;
    }

    LOG_INFO("Registering managed code handlers");
    RegisterMainLoopHandler(handlers->MainLoop);
    RegisterRunScriptHandler(handlers->RunScript);
    RegisterClosureHandler(handlers->Closure);
    RegisterSignalHandler(handlers->Signal);
    RegisterAssertHandler(handlers->Assert);
    RegisterCrashHandler(handlers->Crash);
}

NWNX_EXPORT CVirtualMachineScript* CreateScriptForClosure(uint64_t eventId)
{
    auto* script = new CVirtualMachineScript();
    script->m_pCode = nullptr;
    script->m_nSecondaryInstructPtr = 0;
    script->m_nInstructPtr = 0;
    script->m_nStackSize = 0;
    script->m_pStack = new CVirtualMachineStack();

    char buff[128];
    sprintf(buff, "%s %lu", "NWNX_DOTNET_INTERNAL", eventId);
    script->m_sScriptName = CExoString(buff);

    return script;
}

NWNX_EXPORT void CallBuiltIn(int32_t id)
{
    auto vm = Globals::VirtualMachine();
    auto cmd = static_cast<CNWSVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);

    int pushedCount = s_pushedCount;
    s_pushedCount = 0;

    LOG_DEBUG("Calling BuiltIn %i.", id);
    ASSERT(vm->m_nRecursionLevel >= 0);
    cmd->ExecuteCommand(id, pushedCount);
}

NWNX_EXPORT void StackPushInteger(int32_t value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing integer %i.", value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushInteger(value))
    {
        ++s_pushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push integer %s - recursion level %i.",
            value, vm->m_nRecursionLevel);
    }
}

NWNX_EXPORT void StackPushFloat(float value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing float %f.", value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushFloat(value))
    {
        ++s_pushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push float %f - recursion level %i.",
            value, vm->m_nRecursionLevel);
    }
}

NWNX_EXPORT void StackPushString(const char* value)
{
    LOG_WARNING("StackPushString is deprecated and will be removed in the next release. Use StackPushRawString and convert encoding in managed code instead.");

    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    LOG_DEBUG("Pushing string '%s'.", value);
    CExoString str(String::FromUTF8(value).c_str());

    if (vm->StackPushString(str))
    {
        ++s_pushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push string '%s' - recursion level %i.",
            str.m_sString, vm->m_nRecursionLevel);
    }
}

NWNX_EXPORT void StackPushRawString(const char* value)
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    LOG_DEBUG("Pushing string '%s'.", value);
    CExoString str(value);

    if (vm->StackPushString(str))
    {
        ++s_pushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push string '%s' - recursion level %i.", str.m_sString, vm->m_nRecursionLevel);
    }
}

NWNX_EXPORT void StackPushObject(uint32_t value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing object 0x%x.", value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushObject(value))
    {
        ++s_pushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push object 0x%x - recursion level %i.",
            value, vm->m_nRecursionLevel);
    }
}

NWNX_EXPORT void StackPushVector(Vector value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing vector { %f, %f, %f }.", value.x, value.y, value.z);
    ASSERT(vm->m_nRecursionLevel >= 0);

    if (vm->StackPushVector(value))
    {
        ++s_pushedCount;
    }
    else
    {
        LOG_WARNING("Failed to push vector { %f, %f, %f } - recursion level %i.",
            value.x, value.y, value.z, vm->m_nRecursionLevel);
    }
}

NWNX_EXPORT void StackPushGameDefinedStructure(int32_t structId, void* value)
{
    auto vm = Globals::VirtualMachine();
    LOG_DEBUG("Pushing game defined structure %i at 0x%x.", structId, value);
    ASSERT(vm->m_nRecursionLevel >= 0);

    auto ret = vm->StackPushEngineStructure(structId, value);
    if (!ret)
    {
        LOG_WARNING("Failed to push game defined structure %i at 0x%x - recursion level %i.",
            structId, value, vm->m_nRecursionLevel);
    }

    s_pushedCount += ret;
}

NWNX_EXPORT int32_t StackPopInteger()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    int32_t value;
    if (!vm->StackPopInteger(&value))
    {
        LOG_WARNING("Failed to pop integer - recursion level %i.", vm->m_nRecursionLevel);
        return -1;
    }

    LOG_DEBUG("Popped integer %d.", value);
    return value;
}

NWNX_EXPORT float StackPopFloat()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    float value;
    if (!vm->StackPopFloat(&value))
    {
        LOG_WARNING("Failed to pop float - recursion level %i.", vm->m_nRecursionLevel);
        return 0.0f;
    }

    LOG_DEBUG("Popped float %f.", value);
    return value;
}

NWNX_EXPORT const char* StackPopString()
{
    LOG_WARNING("StackPopString is deprecated and will be removed in the next release. Use StackPopRawString and convert encoding in managed code instead.");

    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    CExoString value;
    if (!vm->StackPopString(&value))
    {
        LOG_WARNING("Failed to pop string - recursion level %i.", vm->m_nRecursionLevel);
        return "";
    }

    LOG_DEBUG("Popped string '%s'.", value.m_sString);

    // TODO: Less copies
    return strdup(String::ToUTF8(value.CStr()).c_str());
}

NWNX_EXPORT const char* StackPopRawString()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    static CExoString value;
    if (!vm->StackPopString(&value))
    {
        LOG_WARNING("Failed to pop string - recursion level %i.", vm->m_nRecursionLevel);
        return nullptr;
    }

    LOG_DEBUG("Popped string '%s'.", value.m_sString);

    return value.CStr();
}

NWNX_EXPORT uint32_t StackPopObject()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    uint32_t value;
    if (!vm->StackPopObject(&value))
    {
        LOG_WARNING("Failed to pop object - recursion level %i.", vm->m_nRecursionLevel);
        return Constants::OBJECT_INVALID;
    }

    LOG_DEBUG("Popped object 0x%x.", value);
    return value;
}

NWNX_EXPORT Vector StackPopVector()
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    Vector value;
    if (!vm->StackPopVector(&value))
    {
        LOG_WARNING("Failed to pop vector - recursion level %i.", vm->m_nRecursionLevel);
        return value;
    }

    LOG_DEBUG("Popping vector { %f, %f, %f }.", value.x, value.y, value.z);
    return value;
}

NWNX_EXPORT void* StackPopGameDefinedStructure(int32_t structId)
{
    auto vm = Globals::VirtualMachine();
    ASSERT(vm->m_nRecursionLevel >= 0);

    void* value;
    if (!vm->StackPopEngineStructure(structId, &value))
    {
        LOG_WARNING("Failed to pop game defined structure %i - recursion level %i.",
            structId, vm->m_nRecursionLevel);
        return nullptr;
    }

    LOG_DEBUG("Popped game defined structure %i at 0x%x.", structId, value);
    return value;
}

NWNX_EXPORT void FreeGameDefinedStructure(int32_t structId, void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWSVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing game structure at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(structId, ptr);
    }
}

NWNX_EXPORT int32_t ClosureAssignCommand(uint32_t oid, uint64_t eventId)
{
    if (Utils::GetGameObject(oid))
    {
        auto* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(0, 0, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

NWNX_EXPORT int32_t ClosureDelayCommand(uint32_t oid, float duration, uint64_t eventId)
{
    if (Utils::GetGameObject(oid))
    {
        uint32_t days = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetCalendarDayFromSeconds(duration);
        uint32_t time = Globals::AppManager()->m_pServerExoApp->GetWorldTimer()->GetTimeOfDayFromSeconds(duration);

        auto* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(days, time, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

NWNX_EXPORT int32_t ClosureActionDoCommand(uint32_t oid, uint64_t eventId)
{
    if (auto* obj = Utils::AsNWSObject(Utils::GetGameObject(oid)))
    {
        obj->AddDoCommandAction(CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

NWNX_EXPORT void NWNXSetFunction(const char* plugin, const char* function)
{
    LOG_WARNING("NWNXSetFunction is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    s_nwnxActivePlugin = plugin;
    s_nwnxActiveFunction = function;
}

NWNX_EXPORT void NWNXPushInt(int32_t n)
{
    LOG_WARNING("NWNXPushInt is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push(n);
}

NWNX_EXPORT void NWNXPushFloat(float f)
{
    LOG_WARNING("NWNXPushFloat is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push(f);
}

NWNX_EXPORT void NWNXPushObject(uint32_t o)
{
    LOG_WARNING("NWNXPushObject is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push((ObjectID)o);
}

NWNX_EXPORT void NWNXPushString(const char* s)
{
    LOG_WARNING("NWNXPushString is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push(String::FromUTF8(s));
}

NWNX_EXPORT void NWNXPushRawString(const char* s)
{
    LOG_WARNING("NWNXPushRawString is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push<std::string>(s);
}

NWNX_EXPORT void NWNXPushEffect(CGameEffect* e)
{
    LOG_WARNING("NWNXPushEffect is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push(e);
}

NWNX_EXPORT void NWNXPushItemProperty(CGameEffect* ip)
{
    LOG_WARNING("NWNXPushItemProperty is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Push(ip);
}

NWNX_EXPORT int32_t NWNXPopInt()
{
    LOG_WARNING("NWNXPopInt is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    return ScriptAPI::Pop<int32_t>().value_or(0);
}

NWNX_EXPORT float NWNXPopFloat()
{
    LOG_WARNING("NWNXPopFloat is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    return ScriptAPI::Pop<float>().value_or(0.0f);
}

NWNX_EXPORT uint32_t NWNXPopObject()
{
    LOG_WARNING("NWNXPopObject is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    return ScriptAPI::Pop<ObjectID>().value_or(Constants::OBJECT_INVALID);
}

NWNX_EXPORT const char* NWNXPopString()
{
    LOG_WARNING("NWNXPopString is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    auto str = ScriptAPI::Pop<std::string>().value_or(std::string{""});
    return strdup(String::ToUTF8(str).c_str());
}

NWNX_EXPORT const char* NWNXPopRawString()
{
    LOG_WARNING("NWNXPopRawString is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    auto value = ScriptAPI::Pop<std::string>();

    static std::string retVal;
    if (value.has_value())
    {
        retVal = value.value();
        return retVal.c_str();
    }
    else
    {
        return nullptr;
    }
}

NWNX_EXPORT CGameEffect* NWNXPopEffect()
{
    LOG_WARNING("NWNXPopEffect is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    return ScriptAPI::Pop<CGameEffect*>().value_or(nullptr);
}

NWNX_EXPORT CGameEffect* NWNXPopItemProperty()
{
    LOG_WARNING("NWNXPopItemProperty is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    return ScriptAPI::Pop<CGameEffect*>().value_or(nullptr);
}

NWNX_EXPORT void NWNXCallFunction()
{
    LOG_WARNING("NWNXCallFunction is deprecated and will be removed in the next release. Use the built-in nwscript method instead.");
    ScriptAPI::Call(s_nwnxActivePlugin, s_nwnxActiveFunction);
}

static struct NWNXExportedGlobals
{
    CExoString            *psBuildNumber;
    CExoString            *psBuildRevision;
    CExoBase              *pExoBase;
    CExoResMan            *pExoResMan;
    CVirtualMachine       *pVirtualMachine;
    CScriptCompiler       *pScriptCompiler;
    CAppManager           *pAppManager;
    CTlkTable             *pTlkTable;
    CNWRules              *pRules;
    Task::CExoTaskManager *pExoTaskManager;
    int32_t                *pbEnableCombatDebugging;
    int32_t                *pbEnableSavingThrowDebugging;
    int32_t                *pbEnableMovementSpeedDebugging;
    int32_t                *pbEnableHitDieDebugging;
    int32_t                *pbExitProgram;
} ExportedGlobals;
NWNX_EXPORT NWNXExportedGlobals GetNWNXExportedGlobals()
{
    LOG_WARNING("GetNWNXExportedGlobals is deprecated and will be removed in the next release. Native globals can be accessed using SWIG_DotNET, or through the System.Runtime.InteropServices.NativeLibrary API.");

    if (ExportedGlobals.psBuildNumber == nullptr)
    {
        ExportedGlobals.psBuildNumber                  = Globals::BuildNumber();
        ExportedGlobals.psBuildRevision                = Globals::BuildRevision();
        ExportedGlobals.pExoBase                       = Globals::ExoBase();
        ExportedGlobals.pExoResMan                     = Globals::ExoResMan();
        ExportedGlobals.pVirtualMachine                = Globals::VirtualMachine();
        ExportedGlobals.pScriptCompiler                = Globals::ScriptCompiler();
        ExportedGlobals.pAppManager                    = Globals::AppManager();
        ExportedGlobals.pTlkTable                      = Globals::TlkTable();
        ExportedGlobals.pRules                         = Globals::Rules();
        ExportedGlobals.pExoTaskManager                = Globals::TaskManager();
        ExportedGlobals.pbEnableCombatDebugging        = Globals::EnableCombatDebugging();
        ExportedGlobals.pbEnableSavingThrowDebugging   = Globals::EnableSavingThrowDebugging();
        ExportedGlobals.pbEnableMovementSpeedDebugging = Globals::EnableMovementSpeedDebugging();
        ExportedGlobals.pbEnableHitDieDebugging        = Globals::EnableHitDieDebugging();
        ExportedGlobals.pbExitProgram                  = Globals::ExitProgram();
    }

    return ExportedGlobals;
}

NWNX_EXPORT void* RequestHook(void* address, void* managedFuncPtr, int32_t order)
{
    LOG_WARNING("RequestHook is deprecated and will be removed in the next release. Use RequestFunctionHook instead.");

    auto funchook = s_managedHooks.emplace_back(Hooks::HookFunction(address, managedFuncPtr, order)).get();
    return funchook->GetOriginal();
}

NWNX_EXPORT void ReturnHook(void* trampoline)
{
    LOG_WARNING("ReturnHook is deprecated and will be removed in the next release. Use ReturnFunctionHook instead.");

    for (auto it = s_managedHooks.begin(); it != s_managedHooks.end(); it++)
    {
        if (it->get()->GetOriginal() == trampoline)
        {
            s_managedHooks.erase(it);
            return;
        }
    }
}

NWNX_EXPORT Hooks::FunctionHook* RequestFunctionHook(void* address, void* managedFuncPtr, const int32_t order)
{
    const auto funcHook = s_managedHooks.emplace_back(Hooks::HookFunction(address, managedFuncPtr, order)).get();
    return funcHook;
}

NWNX_EXPORT void ReturnFunctionHook(const Hooks::FunctionHook* funcHook)
{
    for (auto it = s_managedHooks.begin(); it != s_managedHooks.end(); ++it)
    {
        if (it->get() == funcHook)
        {
            s_managedHooks.erase(it);
            return;
        }
    }
}

std::vector<void*> GetExports()
{
    //
    // Fill the function table to hand over to managed code
    // NOTE: Only add new entries to the end of this table, DO NOT RESHUFFLE.
    //
    std::vector<void*> exports;
    exports.push_back((void*)&GetFunctionPointer);
    exports.push_back((void*)&RegisterHandlers);
    exports.push_back((void*)&CallBuiltIn);
    exports.push_back((void*)&StackPushInteger);
    exports.push_back((void*)&StackPushFloat);
    exports.push_back((void*)&StackPushString);
    exports.push_back((void*)&StackPushString); // reserved utf8
    exports.push_back((void*)&StackPushObject);
    exports.push_back((void*)&StackPushVector);
    exports.push_back((void*)&StackPushGameDefinedStructure);
    exports.push_back((void*)&StackPopInteger);
    exports.push_back((void*)&StackPopFloat);
    exports.push_back((void*)&StackPopString);
    exports.push_back((void*)&StackPopString); // reserved utf8
    exports.push_back((void*)&StackPopObject);
    exports.push_back((void*)&StackPopVector);
    exports.push_back((void*)&StackPopGameDefinedStructure);
    exports.push_back((void*)&FreeGameDefinedStructure);
    exports.push_back((void*)&ClosureAssignCommand);
    exports.push_back((void*)&ClosureDelayCommand);
    exports.push_back((void*)&ClosureActionDoCommand);
    exports.push_back((void*)&NWNXSetFunction);
    exports.push_back((void*)&NWNXPushInt);
    exports.push_back((void*)&NWNXPushFloat);
    exports.push_back((void*)&NWNXPushObject);
    exports.push_back((void*)&NWNXPushString);
    exports.push_back((void*)&NWNXPushString); // reserved utf8
    exports.push_back((void*)&NWNXPushEffect);
    exports.push_back((void*)&NWNXPushItemProperty);
    exports.push_back((void*)&NWNXPopInt);
    exports.push_back((void*)&NWNXPopFloat);
    exports.push_back((void*)&NWNXPopObject);
    exports.push_back((void*)&NWNXPopString);
    exports.push_back((void*)&NWNXPopString); // reserved utf8
    exports.push_back((void*)&NWNXPopEffect);
    exports.push_back((void*)&NWNXPopItemProperty);
    exports.push_back((void*)&NWNXCallFunction);
    exports.push_back((void*)&GetNWNXExportedGlobals);
    exports.push_back((void*)&RequestHook);
    exports.push_back((void*)&ReturnHook);
    exports.push_back((void*)&StackPushRawString);
    exports.push_back((void*)&StackPopRawString);
    exports.push_back((void*)&NWNXPushRawString);
    exports.push_back((void*)&NWNXPopRawString);

    return exports;
}

}
