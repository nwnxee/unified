#include "nwnx.hpp"

#include "API/CNWSObject.hpp"
#include "API/CAppManager.hpp"
#include "API/CServerAIMaster.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CWorldTimer.hpp"

#include <dlfcn.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace DotNET {

// Bootstrap functions
using MainLoopHandlerType  = void (*)(uint64_t);
using RunScriptHandlerType = int (*)(const char*, uint32_t);
using ClosureHandlerType = void (*)(uint64_t, uint32_t);
using SignalHandlerType = void (*)(const char*);
using AssertHandlerType = void (*)(const char*, const char*);

struct AllHandlers
{
    MainLoopHandlerType  MainLoop;
    RunScriptHandlerType RunScript;
    ClosureHandlerType   Closure;
    SignalHandlerType    SignalHandler;
    AssertHandlerType    AssertHandler;
};
static AllHandlers s_handlers;

static int32_t s_pushedCount = 0;

static std::vector<std::unique_ptr<NWNXLib::Hooks::FunctionHook>> s_managedHooks;

static std::string s_nwnxActivePlugin;
static std::string s_nwnxActiveFunction;

static uintptr_t GetFunctionPointer(const char* name)
{
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

static void RegisterHandlers(AllHandlers* handlers, unsigned size)
{
    if (size > sizeof(*handlers))
    {
        LOG_ERROR("RegisterHandlers argument contains too many entries, aborting");
        return;
    }
    if (size < sizeof(*handlers))
    {
        LOG_WARNING("RegisterHandlers argument missing some entries - Managed/Unmanaged mismatch, update managed code");
    }

    LOG_INFO("Registering managed code handlers.");
    s_handlers = *handlers;

    static Hooks::Hook MainLoopHook;
    if (s_handlers.MainLoop)
    {
        LOG_DEBUG("Registered main loop handler: %p", s_handlers.MainLoop);
        MainLoopHook = Hooks::HookFunction(&CServerExoAppInternal::MainLoop,
            +[](CServerExoAppInternal* pServerExoAppInternal) -> int32_t
            {
                static uint64_t frame = 0;
                if (s_handlers.MainLoop)
                {
                    int spBefore = Utils::PushScriptContext(Constants::OBJECT_INVALID, 0, false);
                    s_handlers.MainLoop(frame);
                    int spAfter = Utils::PopScriptContext();
                    ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
                }
                ++frame;

                return MainLoopHook->CallOriginal<int32_t>(pServerExoAppInternal);
            },
            Hooks::Order::VeryEarly);
    }


    static Hooks::Hook RunScriptHook;
    if (s_handlers.RunScript)
    {
        LOG_DEBUG("Registered runscript handler: %p", s_handlers.RunScript);
        RunScriptHook = Hooks::HookFunction(&CVirtualMachine::RunScript,
            +[](CVirtualMachine* thisPtr, CExoString* script, ObjectID objId, int32_t valid,
                       int32_t eventId) -> int32_t
            {
                if (!script || *script == "")
                    return 1;

                LOG_DEBUG("Calling managed RunScriptHandler for script '%s' on Object 0x%08x", script->CStr(), objId);
                int spBefore = Utils::PushScriptContext(objId, eventId, !!valid);
                int32_t retval = s_handlers.RunScript(script->CStr(), objId);
                int spAfter = Utils::PopScriptContext();
                ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);

                // ~0 is returned if runscript request is not handled and needs to be forwarded
                if (retval != ~0)
                {
                    Globals::VirtualMachine()->m_nReturnValueParameterType = 0x03;
                    Globals::VirtualMachine()->m_pReturnValue = reinterpret_cast<void*>(retval);
                    return 1;
                }
                return RunScriptHook->CallOriginal<int32_t>(thisPtr, script, objId, valid, eventId);
            },
            Hooks::Order::Latest);
    }


    static Hooks::Hook RunScriptSituationHook;
    if (s_handlers.Closure)
    {
        LOG_DEBUG("Registered closure handler: %p", s_handlers.Closure);
        RunScriptSituationHook = Hooks::HookFunction(&CVirtualMachine::RunScriptSituation,
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
                return RunScriptSituationHook->CallOriginal<int32_t>(thisPtr, script, objId, valid);
            },
            Hooks::Order::Latest);
    }

    if (s_handlers.SignalHandler)
    {
        LOG_DEBUG("Registered core signal handler: %p", s_handlers.SignalHandler);
        MessageBus::Subscribe("NWNX_CORE_SIGNAL",
            [](const std::vector<std::string>& message)
            {
                if (API::Globals::VirtualMachine())
                {
                    int spBefore = Utils::PushScriptContext(Constants::OBJECT_INVALID, 0, false);
                    s_handlers.SignalHandler(message[0].c_str());
                    int spAfter = Utils::PopScriptContext();
                    ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
                }
                else
                {
                    s_handlers.SignalHandler(message[0].c_str());
                }
            });
    }

    if (s_handlers.AssertHandler)
    {
        LOG_DEBUG("Registered native assertion handler: %p", s_handlers.AssertHandler);
        MessageBus::Subscribe("NWNX_ASSERT_FAIL",
            [](const std::vector<std::string>& message)
            {
                if (API::Globals::VirtualMachine())
                {
                    Utils::PushScriptContext(Constants::OBJECT_INVALID, 0, false);
                    s_handlers.AssertHandler(message[0].c_str(), message[1].c_str());
                    Utils::PopScriptContext();
                }
                else
                {
                    s_handlers.AssertHandler(message[0].c_str(), message[1].c_str());
                }
            });
    }
}

static CVirtualMachineScript* CreateScriptForClosure(uint64_t eventId)
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

static void CallBuiltIn(int32_t id)
{
    auto vm = Globals::VirtualMachine();
    auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
    LOG_DEBUG("Calling BuiltIn %i.", id);
    ASSERT(vm->m_nRecursionLevel >= 0);
    cmd->ExecuteCommand(id, s_pushedCount);
    s_pushedCount = 0;
}

static void StackPushInteger(int32_t value)
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

static void StackPushFloat(float value)
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

static void StackPushString(const char* value)
{
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

static void StackPushRawString(const char* value)
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

static void StackPushObject(uint32_t value)
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

static void StackPushVector(Vector value)
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

static void StackPushGameDefinedStructure(int32_t structId, void* value)
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

static int32_t StackPopInteger()
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

static float StackPopFloat()
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

static const char* StackPopString()
{
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

static const char* StackPopRawString()
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

static uint32_t StackPopObject()
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

static Vector StackPopVector()
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

static void* StackPopGameDefinedStructure(int32_t structId)
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

static void FreeGameDefinedStructure(int32_t structId, void* ptr)
{
    if (ptr)
    {
        auto cmd = static_cast<CNWVirtualMachineCommands*>(Globals::VirtualMachine()->m_pCmdImplementer);
        LOG_DEBUG("Freeing game structure at 0x%x", ptr);
        cmd->DestroyGameDefinedStructure(structId, ptr);
    }
}

static int32_t ClosureAssignCommand(uint32_t oid, uint64_t eventId)
{
    if (Utils::GetGameObject(oid))
    {
        auto* ai = Globals::AppManager()->m_pServerExoApp->GetServerAIMaster();
        ai->AddEventDeltaTime(0, 0, oid, oid, 1, CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

static int32_t ClosureDelayCommand(uint32_t oid, float duration, uint64_t eventId)
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

static int32_t ClosureActionDoCommand(uint32_t oid, uint64_t eventId)
{
    if (auto* obj = Utils::AsNWSObject(Utils::GetGameObject(oid)))
    {
        obj->AddDoCommandAction(CreateScriptForClosure(eventId));
        return 1;
    }

    return 0;
}

static void NWNXSetFunction(const char* plugin, const char* function)
{
    s_nwnxActivePlugin = plugin;
    s_nwnxActiveFunction = function;
}

static void NWNXPushInt(int32_t n)
{
    ScriptAPI::Push(n);
}

static void NWNXPushFloat(float f)
{
    ScriptAPI::Push(f);
}

static void NWNXPushObject(uint32_t o)
{
    ScriptAPI::Push((ObjectID)o);
}

static void NWNXPushString(const char* s)
{
    ScriptAPI::Push(String::FromUTF8(s));
}

static void NWNXPushRawString(const char* s)
{
    ScriptAPI::Push<std::string>(s);
}

static void NWNXPushEffect(CGameEffect* e)
{
    ScriptAPI::Push(e);
}

static void NWNXPushItemProperty(CGameEffect* ip)
{
    ScriptAPI::Push(ip);
}

static int32_t NWNXPopInt()
{
    return ScriptAPI::Pop<int32_t>().value_or(0);
}

static float NWNXPopFloat()
{
    return ScriptAPI::Pop<float>().value_or(0.0f);
}

static uint32_t NWNXPopObject()
{
    return ScriptAPI::Pop<ObjectID>().value_or(Constants::OBJECT_INVALID);
}

static const char* NWNXPopString()
{
    auto str = ScriptAPI::Pop<std::string>().value_or(std::string{""});
    return strdup(String::ToUTF8(str).c_str());
}

static const char* NWNXPopRawString()
{
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

static CGameEffect* NWNXPopEffect()
{
    return ScriptAPI::Pop<CGameEffect*>().value_or(nullptr);
}

static CGameEffect* NWNXPopItemProperty()
{
    return ScriptAPI::Pop<CGameEffect*>().value_or(nullptr);
}

static void NWNXCallFunction()
{
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
static NWNXExportedGlobals GetNWNXExportedGlobals()
{
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

static void* RequestHook(void* address, void* managedFuncPtr, int32_t order)
{
    auto funchook = s_managedHooks.emplace_back(Hooks::HookFunction(address, managedFuncPtr, order)).get();
    return funchook->GetOriginal();
}

static void ReturnHook(void* trampoline)
{
    for (auto it = s_managedHooks.begin(); it != s_managedHooks.end(); it++)
    {
        if (it->get()->GetOriginal() == trampoline)
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
