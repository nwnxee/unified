#include "DotNET.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CVirtualMachineScript.hpp"
#include "API/Functions.hpp"

#include <algorithm>
#include <cstring>
#include <chrono>
#include <string>

#include "sdk/coreclr_delegates.h"
#include "sdk/hostfxr.h"
#include <dirent.h>
#include <dlfcn.h>
#include <limits.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    return new DotNET::DotNET(services);
}

using namespace NWNXLib::Services;

namespace DotNET {

static hostfxr_initialize_for_runtime_config_fn hostfxr_initialize_for_runtime_config;
static hostfxr_get_runtime_delegate_fn          hostfxr_get_runtime_delegate;
static hostfxr_close_fn                         hostfxr_close;

bool DotNET::InitThunks()
{
    void *nethost = nullptr;
    void *hostfxr = nullptr;

    if (auto nethost_path = Config::Get<std::string>("NETHOST_PATH"))
    {
        nethost = dlopen(nethost_path->c_str(), RTLD_LAZY);
        ASSERT_MSG(nethost, "NETHOST_PATH specified ('%s') but failed to open libnethost.so at that path", nethost_path->c_str());
    }

    if (!nethost)
    {
        const char *paths[] = {
            "libnethost.so",
            "./libnethost.so",
            "lib/libnethost.so"
        };
        for (size_t i = 0; i < std::size(paths); i++)
        {
            nethost = dlopen(paths[i], RTLD_LAZY);
            if (nethost)
            {
                LOG_INFO("Loaded libnethost.so from: %s (autodetected)", paths[i]);
                break;
            }
        }
    }

    if (!nethost)
    {
        const auto hostBaseDir = "/usr/share/dotnet/packs/Microsoft.NETCore.App.Host.linux-x64/";
        const auto hostLibSuffix = "/runtimes/linux-x64/native/libnethost.so";

        DIR* dir = opendir(hostBaseDir);

        if (dir != nullptr)
        {
            dirent* directoryEntry = readdir(dir);
            std::vector<std::string> paths;

            while (directoryEntry != nullptr)
            {
                if (directoryEntry->d_type == DT_DIR)
                {
                    const auto path = (std::string(hostBaseDir) + directoryEntry->d_name + hostLibSuffix);
                    paths.push_back(path);
                }

                directoryEntry = readdir(dir);
            }

            closedir(dir);

            if (!paths.empty())
            {
                std::sort(paths.begin(), paths.end(), std::greater<std::string>());
                for (std::string path : paths)
                {
                    nethost = dlopen(path.c_str(), RTLD_LAZY);

                    if (nethost)
                    {
                        LOG_INFO("Loaded libnethost.so from: %s (autodetected)", path);
                        break;
                    }
                }
            }
        }
    }

    if (!nethost)
    {
        LOG_ERROR("Unable to load libnethost.so. .NET plugin will be unavailable.");
        LOG_ERROR("If you're not using the .NET plugin, you can disable this message with 'NWNX_DOTNET_SKIP=y'");
        return false;
    }

    auto get_hostfxr_path = (int(*)(char*,size_t*,const void*))dlsym(nethost, "get_hostfxr_path");
    ASSERT_OR_RETURN(get_hostfxr_path != nullptr, false);

    char buffer[PATH_MAX];
    size_t buffer_size = PATH_MAX;
    ASSERT_OR_RETURN(get_hostfxr_path(buffer, &buffer_size, nullptr) == 0, false);
    dlclose(nethost);

    hostfxr = dlopen(buffer, RTLD_LAZY);
    ASSERT_OR_RETURN(hostfxr != nullptr, false);

    hostfxr_initialize_for_runtime_config = (hostfxr_initialize_for_runtime_config_fn)dlsym(hostfxr, "hostfxr_initialize_for_runtime_config");
    hostfxr_get_runtime_delegate          = (hostfxr_get_runtime_delegate_fn)         dlsym(hostfxr, "hostfxr_get_runtime_delegate");
    hostfxr_close                         = (hostfxr_close_fn)                        dlsym(hostfxr, "hostfxr_close");

    ASSERT_OR_RETURN(hostfxr_initialize_for_runtime_config != nullptr, false);
    ASSERT_OR_RETURN(hostfxr_get_runtime_delegate != nullptr, false);
    ASSERT_OR_RETURN(hostfxr_close != nullptr, false);

    return true;
}

DotNET::DotNET(Services::ProxyServiceList* services) : Plugin(services)
{
    ASSERT_OR_THROW(Instance == nullptr);
    Instance = this;

    // If the initial lib loads failed, we probably don't have .NET installed.
    if (!InitThunks())
        return;

    auto assembly   = Config::Get<std::string>("ASSEMBLY");
    auto entrypoint = Config::Get<std::string>("ENTRYPOINT", "NWN.Internal");

    if (!assembly.has_value())
    {
        LOG_ERROR("NWNX_DOTNET_ASSEMBLY not specified. DotNET plugin will not be loaded.");
        LOG_ERROR("If you're not using the .NET plugin, you can disable this message with 'NWNX_DOTNET_SKIP=y'");
        return;
    }

    // Load .NET Core
    hostfxr_handle cxt = nullptr;
    auto runtimeconfig = *assembly + ".runtimeconfig.json";
    int rc = hostfxr_initialize_for_runtime_config(runtimeconfig.c_str(), nullptr, &cxt);
    if (rc != 0 || cxt == nullptr)
        LOG_FATAL("Unable to load runtime config '%s'; rc=0x%x", runtimeconfig, rc);

    // Get the load assembly function pointer
    load_assembly_and_get_function_pointer_fn load_assembly_and_get_function_pointer = nullptr;
    rc = hostfxr_get_runtime_delegate(cxt, hdt_load_assembly_and_get_function_pointer, (void**)&load_assembly_and_get_function_pointer);
    if (rc != 0 || load_assembly_and_get_function_pointer == nullptr)
        LOG_FATAL("Unable to get load_assembly_and_get_function_pointer; rc=0x%x", rc);

    hostfxr_close(cxt);


    component_entry_point_fn bootstrap = nullptr;
    auto dll = *assembly + ".dll";
    auto full_ep = entrypoint + ", " + assembly->substr(assembly->find_last_of("/\\") + 1);
    rc = load_assembly_and_get_function_pointer(dll.c_str(), full_ep.c_str(),
                                                "Bootstrap", nullptr, nullptr, (void**)&bootstrap);
    if (rc != 0 || bootstrap == nullptr)
        LOG_FATAL("Unable to get %s.Bootstrap() function: dll='%s'; rc=0x%x", full_ep, dll, rc);

    //
    // Fill the function table to hand over to managed code
    // NOTE: Only add new entries to the end of this table, DO NOT RESHUFFLE.
    //
    std::vector<void*> args;
        args.push_back((void*)&GetFunctionPointer);
        args.push_back((void*)&RegisterHandlers);
        args.push_back((void*)&CallBuiltIn);
        args.push_back((void*)&StackPushInteger);
        args.push_back((void*)&StackPushFloat);
        args.push_back((void*)&StackPushString);
        args.push_back((void*)&StackPushString); // reserved utf8
        args.push_back((void*)&StackPushObject);
        args.push_back((void*)&StackPushVector);
        args.push_back((void*)&StackPushGameDefinedStructure);
        args.push_back((void*)&StackPopInteger);
        args.push_back((void*)&StackPopFloat);
        args.push_back((void*)&StackPopString);
        args.push_back((void*)&StackPopString); // reserved utf8
        args.push_back((void*)&StackPopObject);
        args.push_back((void*)&StackPopVector);
        args.push_back((void*)&StackPopGameDefinedStructure);
        args.push_back((void*)&FreeGameDefinedStructure);
        args.push_back((void*)&ClosureAssignCommand);
        args.push_back((void*)&ClosureDelayCommand);
        args.push_back((void*)&ClosureActionDoCommand);
        args.push_back((void*)&nwnxSetFunction);
        args.push_back((void*)&nwnxPushInt);
        args.push_back((void*)&nwnxPushFloat);
        args.push_back((void*)&nwnxPushObject);
        args.push_back((void*)&nwnxPushString);
        args.push_back((void*)&nwnxPushString); // reserved utf8
        args.push_back((void*)&nwnxPushEffect);
        args.push_back((void*)&nwnxPushItemProperty);
        args.push_back((void*)&nwnxPopInt);
        args.push_back((void*)&nwnxPopFloat);
        args.push_back((void*)&nwnxPopObject);
        args.push_back((void*)&nwnxPopString);
        args.push_back((void*)&nwnxPopString); // reserved utf8
        args.push_back((void*)&nwnxPopEffect);
        args.push_back((void*)&nwnxPopItemProperty);
        args.push_back((void*)&nwnxCallFunction);
        args.push_back((void*)&GetNWNXExportedGlobals);
        args.push_back((void*)&RequestHook);
        args.push_back((void*)&ReturnHook);
    rc = bootstrap(args.data(), args.size()*sizeof(void*));
    if (rc != 0)
        LOG_FATAL("Failed to execute bootstrap function; rc=0x%x", rc);

    LOG_INFO("Managed code bootstrapped.");
}

DotNET::~DotNET() { }


uintptr_t DotNET::GetFunctionPointer(const char *name)
{
    void *core = dlopen("NWNX_Core.so", RTLD_LAZY);
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


void DotNET::RegisterHandlers(AllHandlers *handlers, unsigned size)
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
    Handlers = *handlers;

    LOG_DEBUG("Registered main loop handler: %p", Handlers.MainLoop);
    static Hooks::Hook MainLoopHook;
    MainLoopHook = Hooks::HookFunction(Functions::_ZN21CServerExoAppInternal8MainLoopEv,
        (void*)+[](CServerExoAppInternal *pServerExoAppInternal) -> int32_t
        {
            static uint64_t frame = 0;
            if (Handlers.MainLoop)
            {
                int spBefore = Utils::PushScriptContext(Constants::OBJECT_INVALID, false);
                Handlers.MainLoop(frame);
                int spAfter = Utils::PopScriptContext();
                ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
            }
            ++frame;

            return MainLoopHook->CallOriginal<int32_t>(pServerExoAppInternal);
        },
        Hooks::Order::VeryEarly);


    LOG_DEBUG("Registered runscript handler: %p", Handlers.RunScript);
    static Hooks::Hook RunScriptHook;
    RunScriptHook = Hooks::HookFunction(Functions::_ZN15CVirtualMachine9RunScriptEP10CExoStringji,
        (void*)+[](CVirtualMachine* thisPtr, CExoString* script, ObjectID objId, int32_t valid) -> int32_t
        {
            if (!script || *script == "")
                return 1;

            LOG_DEBUG("Calling managed RunScriptHandler for script '%s' on Object 0x%08x", script->CStr(), objId);
            int spBefore = Utils::PushScriptContext(objId, !!valid);
            int32_t retval = Handlers.RunScript(script->CStr(), objId);
            int spAfter = Utils::PopScriptContext();
            ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);

            // ~0 is returned if runscript request is not handled and needs to be forwarded
            if (retval != ~0)
            {
                Globals::VirtualMachine()->m_nReturnValueParameterType = 0x03;
                Globals::VirtualMachine()->m_pReturnValue = reinterpret_cast<void*>(retval);
                return 1;
            }
            return RunScriptHook->CallOriginal<int32_t>(thisPtr, script, objId, valid);
        },
        Hooks::Order::Latest);

    LOG_DEBUG("Registered closure handler: %p", Handlers.Closure);
    static Hooks::Hook RunScriptSituationHook;
    RunScriptSituationHook = Hooks::HookFunction(Functions::_ZN15CVirtualMachine18RunScriptSituationEPvji,
        (void*)+[](CVirtualMachine* thisPtr, CVirtualMachineScript* script, ObjectID objId, int32_t valid) -> int32_t
        {
            uint64_t eventId;
            if (script && sscanf(script->m_sScriptName.m_sString, "NWNX_DOTNET_INTERNAL %lu", &eventId) == 1)
            {
                LOG_DEBUG("Calling managed RunScriptSituationHandler for event '%lu' on Object 0x%08x", eventId, objId);
                int spBefore = Utils::PushScriptContext(objId, !!valid);
                Handlers.Closure(eventId, objId);
                int spAfter = Utils::PopScriptContext();
                ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
                delete script;
                return 1;
            }
            return RunScriptSituationHook->CallOriginal<int32_t>(thisPtr, script, objId, valid);
        },
        Hooks::Order::Latest);

    LOG_DEBUG("Registered core signal handler: %p", Handlers.SignalHandler);
    MessageBus::Subscribe("NWNX_CORE_SIGNAL",
        [](const std::vector<std::string>& message)
        {
            int spBefore = Utils::PushScriptContext(Constants::OBJECT_INVALID, false);
            Handlers.SignalHandler(message[0].c_str());
            int spAfter = Utils::PopScriptContext();
            ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
        });
}

}
