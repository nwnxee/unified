#include "Mono.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CVirtualMachineScript.hpp"
#include "API/Functions.hpp"
#include "API/Version.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Metrics/Metrics.hpp"

#include <algorithm>
#include <cstring>
#include <chrono>
#include <string>

#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Mono::Mono> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Mono",
        "Allows users to see sharp.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        false
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Mono::Mono(params);
    return g_plugin;
}

using namespace NWNXLib::Services;

namespace Mono {

static Hooking::FunctionHook* s_RunScriptHook;
static Hooking::FunctionHook* s_RunScriptSituationHook;

Mono::Mono(const Plugin::CreateParams& params)
    : Plugin(params)
{
    Maybe<std::string> configPath = GetServices()->m_config->Get<std::string>("CONFIG_PATH");
    mono_config_parse(configPath ? configPath->c_str() : nullptr);

    g_Domain = mono_jit_init("nwnx");

    m_ScriptMetrics = GetServices()->m_config->Get<bool>("SCRIPT_METRICS", true);
    m_ClosureMetrics = GetServices()->m_config->Get<bool>("CLOSURE_METRICS", true);
    m_MainLoopMetrics = GetServices()->m_config->Get<bool>("MAIN_LOOP_METRICS", true);

    std::string assembly = GetServices()->m_config->Require<std::string>("ASSEMBLY");

    LOG_INFO("Loading assembly %s.", assembly.c_str());
    g_Assembly = mono_domain_assembly_open(g_Domain, assembly.c_str());

    if (!g_Assembly)
    {
        throw std::logic_error("Could not open the mono assembly.");
    }

    m_PushScriptContext = GetHandler("Internal", "PushScriptContext", 1);
    m_PopScriptContext = GetHandler("Internal", "PopScriptContext", 0);
    m_ExecuteClosure = GetHandler("Internal", "ExecuteClosure", 1);
    m_OnMainLoopTick = GetHandler("Events", "OnMainLoopTick", 1);

    mono_add_internal_call("NWN.Internal::CallBuiltIn", reinterpret_cast<const void*>(&CallBuiltIn));

    mono_add_internal_call("NWN.Internal::StackPushInteger", reinterpret_cast<const void*>(&StackPushInteger));
    mono_add_internal_call("NWN.Internal::StackPushFloat", reinterpret_cast<const void*>(&StackPushFloat));
    mono_add_internal_call("NWN.Internal::StackPushString", reinterpret_cast<const void*>(&StackPushString));
    mono_add_internal_call("NWN.Internal::StackPushObject_Native", reinterpret_cast<const void*>(&StackPushObject));
    mono_add_internal_call("NWN.Internal::StackPushVector_Native", reinterpret_cast<const void*>(&StackPushVector));
    mono_add_internal_call("NWN.Internal::StackPushEffect_Native", reinterpret_cast<const void*>(&StackPushEffect));
    mono_add_internal_call("NWN.Internal::StackPushEvent_Native", reinterpret_cast<const void*>(&StackPushEvent));
    mono_add_internal_call("NWN.Internal::StackPushLocation_Native", reinterpret_cast<const void*>(&StackPushLocation));
    mono_add_internal_call("NWN.Internal::StackPushTalent_Native", reinterpret_cast<const void*>(&StackPushTalent));
    mono_add_internal_call("NWN.Internal::StackPushItemProperty_Native", reinterpret_cast<const void*>(&StackPushItemProperty));

    mono_add_internal_call("NWN.Internal::StackPopInteger", reinterpret_cast<const void*>(&StackPopInteger));
    mono_add_internal_call("NWN.Internal::StackPopFloat", reinterpret_cast<const void*>(&StackPopFloat));
    mono_add_internal_call("NWN.Internal::StackPopString", reinterpret_cast<const void*>(&StackPopString));
    mono_add_internal_call("NWN.Internal::StackPopObject_Native", reinterpret_cast<const void*>(&StackPopObject));
    mono_add_internal_call("NWN.Internal::StackPopVector", reinterpret_cast<const void*>(&StackPopVector));
    mono_add_internal_call("NWN.Internal::StackPopEffect_Native", reinterpret_cast<const void*>(&StackPopEffect));
    mono_add_internal_call("NWN.Internal::StackPopEvent_Native", reinterpret_cast<const void*>(&StackPopEvent));
    mono_add_internal_call("NWN.Internal::StackPopLocation_Native", reinterpret_cast<const void*>(&StackPopLocation));
    mono_add_internal_call("NWN.Internal::StackPopTalent_Native", reinterpret_cast<const void*>(&StackPopTalent));
    mono_add_internal_call("NWN.Internal::StackPopItemProperty_Native", reinterpret_cast<const void*>(&StackPopItemProperty));

    mono_add_internal_call("NWN.Internal::FreeEffect", reinterpret_cast<const void*>(&FreeEffect));
    mono_add_internal_call("NWN.Internal::FreeEvent", reinterpret_cast<const void*>(&FreeEvent));
    mono_add_internal_call("NWN.Internal::FreeLocation", reinterpret_cast<const void*>(&FreeLocation));
    mono_add_internal_call("NWN.Internal::FreeTalent", reinterpret_cast<const void*>(&FreeTalent));
    mono_add_internal_call("NWN.Internal::FreeItemProperty", reinterpret_cast<const void*>(&FreeItemProperty));

    mono_add_internal_call("NWN.Internal::BeginClosure", reinterpret_cast<const void*>(&BeginClosure));
    mono_add_internal_call("NWN.Internal::ClosureAssignCommand_Native", reinterpret_cast<const void*>(&ClosureAssignCommand));
    mono_add_internal_call("NWN.Internal::ClosureDelayCommand_Native", reinterpret_cast<const void*>(&ClosureDelayCommand));
    mono_add_internal_call("NWN.Internal::ClosureActionDoCommand_Native", reinterpret_cast<const void*>(&ClosureActionDoCommand));

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CVirtualMachine__RunScript, void>(
        +[](CVirtualMachine* thisPtr, CExoString* script, Types::ObjectID objId, int32_t valid)
        {
            bool skip = script->m_sString && g_plugin->RunMonoScript(script->m_sString, objId, !!valid);
            if (!skip)
            {
                s_RunScriptHook->CallOriginal<void>(thisPtr, script, objId, valid);
            }
        }
    );

    s_RunScriptHook = GetServices()->m_hooks->FindHookByAddress(Functions::CVirtualMachine__RunScript);

    GetServices()->m_hooks->RequestExclusiveHook<Functions::CVirtualMachine__RunScriptSituation, int32_t>(
        +[](CVirtualMachine* thisPtr, CVirtualMachineScript* script, Types::ObjectID oid, int32_t oidValid)
        {
            if (strstr(script->m_sScriptName.m_sString, "NWNX_MONO_INTERNAL"))
            {
                // We can locate the eventId inside the string after the first space.
                char* eventIdStr = strstr(script->m_sScriptName.m_sString, " ");
                ASSERT(eventIdStr);
                if (eventIdStr)
                {
                    g_plugin->ExecuteClosure(strtoull(eventIdStr, nullptr, 10));

                    // We manually call the dtor then call free here, rather than using delete.
                    // This is necessary because the API will try to double free otherwise -
                    // it will call CExoString's dtor, as will the original dtor when we later jump to it.
                    CVirtualMachineScript__CVirtualMachineScriptDtor(script);
                    free(script);

                    return 1;
                }
            }

            return s_RunScriptSituationHook->CallOriginal<int32_t>(thisPtr, script, oid, oidValid);
        }
    );

    s_RunScriptSituationHook = GetServices()->m_hooks->FindHookByAddress(Functions::CVirtualMachine__RunScriptSituation);

    GetServices()->m_hooks->RequestSharedHook<Functions::CServerExoAppInternal__MainLoop, int32_t>(
        +[](Services::Hooks::CallType type, CServerExoAppInternal*)
        {
            if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
            {
                return;
            }

            static uint64_t s_Frame = 0;
            g_plugin->ExecuteMainLoopTick(s_Frame++);
        }
    );

    Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Sum<uint32_t>;
    GetServices()->m_metrics->SetResampler("Closure", resampler, std::chrono::seconds(1));
    GetServices()->m_metrics->SetResampler("MainLoop", resampler, std::chrono::seconds(1));
}

Mono::~Mono()
{
    if (g_Domain)
    {
        mono_jit_cleanup(g_Domain);
        g_Domain = nullptr;
    }
}

bool Mono::RunMonoScript(const char* scriptName, Types::ObjectID objId, bool valid)
{
    std::string scriptNameAsLower = scriptName;
    std::transform(std::begin(scriptNameAsLower), std::end(scriptNameAsLower), std::begin(scriptNameAsLower), ::tolower);

    auto iter = m_ScriptMap.find(scriptNameAsLower);
    if (iter == std::end(m_ScriptMap))
    {
        MonoMethod* method = GetScriptEntryFromClass(scriptNameAsLower.c_str());
        iter = m_ScriptMap.insert(std::make_pair(scriptNameAsLower, method)).first;
    }

    MonoMethod* method = iter->second;
    if (!method)
    {
        return false;
    }

    { // PREPARE VM
        GetVm()->m_nRecursionLevel += 1;
        GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel] = objId;
        GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel] = valid;
        GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
        GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];
    }

    { // RUN C# SCRIPT
        auto runScripts = [&]()
        {
            LOG_DEBUG("Invoking NWN.Scripts.%s::Main on OID 0x%x.", scriptNameAsLower.c_str(), objId);

            MonoObject* ex = nullptr;
            void* pushArgs[1] = { &objId };
            mono_runtime_invoke(m_PushScriptContext, nullptr, pushArgs, &ex);
            if (!ex)
            {
                // Even if we fail the actual method, we still need to pop.
                mono_runtime_invoke(method, nullptr, nullptr, &ex);

                // If we failed the actual method, we discard this exception and only report actual method.
                mono_runtime_invoke(m_PopScriptContext, nullptr, nullptr, ex ? nullptr : &ex);
            }

            if (ex)
            {
                char* exMsg = mono_string_to_utf8(mono_object_to_string(ex, nullptr));
                LOG_WARNING("Caught unhandled exception when invoking NWN.Scripts.%s::Main: %s", scriptNameAsLower.c_str(), exMsg);
                mono_free(exMsg);
            }
        };

        if (m_ScriptMetrics)
        {
            const auto timeBefore = std::chrono::high_resolution_clock::now();
            runScripts();
            const auto timeAfter = std::chrono::high_resolution_clock::now();

            using namespace std::chrono;
            nanoseconds dur = duration_cast<nanoseconds>(timeAfter - timeBefore);
            LOG_DEBUG("Run took %f ms.", dur.count() / 1000.0f / 1000.0f);

            GetServices()->m_metrics->Push(
                "Script",
                { { "ns", std::to_string(dur.count()) } },
                { { "Script", scriptNameAsLower.c_str() } });
        }
        else
        {
            runScripts();
        }
    }

    { // CLEANUP VM
        GetVm()->m_nRecursionLevel -= 1;

        if (GetVm()->m_nRecursionLevel != -1)
        {
            GetVmCommands()->m_oidObjectRunScript = GetVm()->m_oidObjectRunScript[GetVm()->m_nRecursionLevel];
            GetVmCommands()->m_bValidObjectRunScript = GetVm()->m_bValidObjectRunScript[GetVm()->m_nRecursionLevel];
        }
    }

    return true;
}

MonoMethod* Mono::GetScriptEntryFromClass(const char* className)
{
    MonoImage* image = mono_assembly_get_image(g_Assembly);
    ASSERT(image);

    MonoClass* cls = mono_class_from_name(image, "NWN.Scripts", className);

    if (!cls)
    {
        LOG_DEBUG("Failed to find class %s.", className);
        return nullptr;
    }

    MonoMethod* method = mono_class_get_method_from_name(cls, "Main", 0);

    if (method)
    {
        LOG_INFO("Resolved NWN.Scripts.%s::Main.", className);
    }
    else
    {
        LOG_WARNING("Failed to resolve NWN.Scripts.%s::Main - ill-formed script?", className);
    }

    return method;
}

MonoMethod* Mono::GetHandler(const char* clsName, const char* handler, int paramCount)
{
    MonoImage* image = mono_assembly_get_image(g_Assembly);
    ASSERT(image);

    MonoClass* cls = mono_class_from_name(image, "NWN", clsName);

    if (!cls)
    {
        LOG_FATAL("Failed to resolve NWN.%s", clsName);
    }

    MonoMethod* method = mono_class_get_method_from_name(cls, handler, paramCount);

    if (!method)
    {
        LOG_FATAL("Failed to resolve NWN.%s::%s", clsName, handler);
    }

    LOG_INFO("Resolved NWN.%s::%s.", clsName, handler);
    return method;
}

void Mono::ExecuteClosure(uint64_t eventId)
{
    auto execClosures = [&]()
    {
        LOG_DEBUG("Executing closure %llu.", eventId);

        GetVm()->m_nRecursionLevel += 1;

        MonoObject* ex = nullptr;
        void* closureArgs[1] = { &eventId };
        mono_runtime_invoke(m_ExecuteClosure, nullptr, closureArgs, &ex);

        if (ex)
        {
            char* exMsg = mono_string_to_utf8(mono_object_to_string(ex, nullptr));
            LOG_WARNING("Caught unhandled exception when invoking closures: %s", exMsg);
            mono_free(exMsg);
        }

        GetVm()->m_nRecursionLevel -= 1;
    };

    if (m_ClosureMetrics)
    {
        const auto timeBefore = std::chrono::high_resolution_clock::now();
        execClosures();
        const auto timeAfter = std::chrono::high_resolution_clock::now();

        using namespace std::chrono;
        nanoseconds dur = duration_cast<nanoseconds>(timeAfter - timeBefore);

        GetServices()->m_metrics->Push("Closure", { { "ns", std::to_string(dur.count()) } });
    }
    else
    {
        execClosures();
    }
}

void Mono::ExecuteMainLoopTick(uint64_t frame)
{
    auto execMainLoop = [&]()
    {
        GetVm()->m_nRecursionLevel += 1;

        MonoObject* ex = nullptr;
        void* mainLoopArgs[1] = { &frame };
        mono_runtime_invoke(m_OnMainLoopTick, nullptr, mainLoopArgs, &ex);

        if (ex)
        {
            char* exMsg = mono_string_to_utf8(mono_object_to_string(ex, nullptr));
            LOG_WARNING("Caught unhandled exception when ticking the main loop: %s", exMsg);
            mono_free(exMsg);
        }

        GetVm()->m_nRecursionLevel -= 1;
    };

    if (m_MainLoopMetrics)
    {
        const auto timeBefore = std::chrono::high_resolution_clock::now();
        execMainLoop();
        const auto timeAfter = std::chrono::high_resolution_clock::now();

        using namespace std::chrono;
        nanoseconds dur = duration_cast<nanoseconds>(timeAfter - timeBefore);

        GetServices()->m_metrics->Push("MainLoop", { { "ns", std::to_string(dur.count()) } });
    }
    else
    {
        execMainLoop();
    }
}

}
