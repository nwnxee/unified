// https://docs.microsoft.com/en-us/dotnet/core/tutorials/netcore-hosting
// https://github.com/dotnet/samples/blob/main/core/hosting/src/NativeHost/nativehost.cpp
#include "nwnx.hpp"
#include "DotNET.hpp"

#include <algorithm>
#include <string>
#include <vector>

#include "External/Microsoft.NETCore.App.Host.linux-x64/nethost.h"
#include "External/Microsoft.NETCore.App.Host.linux-x64/coreclr_delegates.h"
#include "External/Microsoft.NETCore.App.Host.linux-x64/hostfxr.h"

#include <dirent.h>
#include <dlfcn.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace DotNET {

extern std::vector<void*> GetExports();
extern AllHandlers s_handlers;

static bool LoadHostFxr();
static void LoadNetCore(const std::string& assembly);
static void CoreMessageHandler(const std::vector<std::string>& message);
static void Bootstrap();

static hostfxr_initialize_for_runtime_config_fn  hostfxr_initialize_for_runtime_config;
static hostfxr_get_runtime_delegate_fn           hostfxr_get_runtime_delegate;
static hostfxr_close_fn                          hostfxr_close;
static load_assembly_and_get_function_pointer_fn load_assembly_and_get_function_pointer;

static void DotNET() __attribute__((constructor));

static void DotNET()
{
    if (!LoadHostFxr())
    {
        LOG_ERROR("Unable to load hostfxr.so. .NET plugin will be unavailable.");
        LOG_ERROR("If you're not using the .NET plugin, you can disable this message with 'NWNX_DOTNET_SKIP=y'");
        return;
    }

    const auto assembly = Config::Get<std::string>("ASSEMBLY", "");
    if (assembly.empty())
    {
        LOG_ERROR("NWNX_DOTNET_ASSEMBLY not specified. DotNET plugin will not be loaded.");
        LOG_ERROR("If you're not using the .NET plugin, you can disable this message with 'NWNX_DOTNET_SKIP=y'");
        return;
    }

    LoadNetCore(assembly);
    MessageBus::Subscribe("NWNX_CORE_SIGNAL", CoreMessageHandler);
}

bool LoadHostFxr()
{
    char buffer[PATH_MAX];
    size_t buffer_size = PATH_MAX;

    if (get_hostfxr_path(buffer, &buffer_size, nullptr) != 0)
    {
        return false;
    }

    void *hostfxr = dlopen(buffer, RTLD_LAZY);
    ASSERT_OR_RETURN(hostfxr != nullptr, false);

    hostfxr_initialize_for_runtime_config = (hostfxr_initialize_for_runtime_config_fn)dlsym(hostfxr, "hostfxr_initialize_for_runtime_config");
    hostfxr_get_runtime_delegate          = (hostfxr_get_runtime_delegate_fn)         dlsym(hostfxr, "hostfxr_get_runtime_delegate");
    hostfxr_close                         = (hostfxr_close_fn)                        dlsym(hostfxr, "hostfxr_close");

    ASSERT_OR_RETURN(hostfxr_initialize_for_runtime_config != nullptr, false);
    ASSERT_OR_RETURN(hostfxr_get_runtime_delegate != nullptr, false);
    ASSERT_OR_RETURN(hostfxr_close != nullptr, false);

    return true;
}

void LoadNetCore(const std::string& assembly)
{
    hostfxr_handle cxt = nullptr;

    auto runtimeConfig = assembly + ".runtimeconfig.json";
    int returnCode = hostfxr_initialize_for_runtime_config(runtimeConfig.c_str(), nullptr, &cxt);
    if (returnCode != 0 || cxt == nullptr)
        LOG_FATAL("Unable to load runtime config '%s'; returnCode=0x%x", runtimeConfig, returnCode);

    // Get the load assembly function pointer
    load_assembly_and_get_function_pointer = nullptr;
    returnCode = hostfxr_get_runtime_delegate(cxt, hdt_load_assembly_and_get_function_pointer, (void**)&load_assembly_and_get_function_pointer);
    if (returnCode != 0 || load_assembly_and_get_function_pointer == nullptr)
        LOG_FATAL("Unable to get load_assembly_and_get_function_pointer; returnCode=0x%x", returnCode);

    hostfxr_close(cxt);
}

void CoreMessageHandler(const std::vector<std::string> &message)
{
    const std::string& messageType = message[0];

    if (messageType == "ON_NWNX_LOADED")
    {
        Bootstrap();
    }
    if (s_handlers.Signal)
    {
        if (API::Globals::VirtualMachine())
        {
            int spBefore = Utils::PushScriptContext(Constants::OBJECT_INVALID, 0, false);
            s_handlers.Signal(message[0].c_str());
            int spAfter = Utils::PopScriptContext();
            ASSERT_MSG(spBefore == spAfter, "spBefore=%x, spAfter=%x", spBefore, spAfter);
        }
        else
        {
            s_handlers.Signal(message[0].c_str());
        }
    }
}

void Bootstrap()
{
    const auto assembly = Config::Get<std::string>("ASSEMBLY", "");
    const auto entrypoint = Config::Get<std::string>("ENTRYPOINT", "NWN.Internal");
    const auto method = Config::Get<std::string>("METHOD", "Bootstrap");
    const auto newBootstrap = Config::Get<bool>("NEW_BOOTSTRAP", false);

    int returnCode = 0;
    auto assemblyPath = assembly + ".dll";
    auto fullTypeName = entrypoint + ", " + assembly.substr(assembly.find_last_of("/\\") + 1);

    if (newBootstrap)
    {
        void (*bootstrap)() = nullptr;
        returnCode = load_assembly_and_get_function_pointer(assemblyPath.c_str(), fullTypeName.c_str(),
                                                            method.c_str(), "System.Action, System.Runtime", nullptr, (void**)&bootstrap);
        if (returnCode != 0 || bootstrap == nullptr)
            LOG_FATAL("Unable to get %s.%s() function: assemblyPath='%s'; returnCode=0x%x", fullTypeName, method, assemblyPath, returnCode);

        bootstrap();
        if (returnCode != 0)
            LOG_FATAL("Failed to execute bootstrap function; returnCode=0x%x", returnCode);
    }
    else
    {
        LOG_WARNING("Using legacy bootstrap method for function exports. This will be removed in the next NWNX release. Set NWNX_DOTNET_NEW_BOOTSTRAP to use the new bootstrap method and hide this message.");
        component_entry_point_fn bootstrap = nullptr;
        returnCode = load_assembly_and_get_function_pointer(assemblyPath.c_str(), fullTypeName.c_str(),
                                                            method.c_str(), nullptr, nullptr, (void**)&bootstrap);
        if (returnCode != 0 || bootstrap == nullptr)
            LOG_FATAL("Unable to get %s.%s() function: assemblyPath='%s'; returnCode=0x%x", fullTypeName, method, assemblyPath, returnCode);

        std::vector<void*> args = GetExports();
        returnCode = bootstrap(args.data(), args.size() * sizeof(void*));
        if (returnCode != 0)
            LOG_FATAL("Failed to execute bootstrap function; returnCode=0x%x", returnCode);
    }

    LOG_INFO("Managed code bootstrapped.");
}

}
