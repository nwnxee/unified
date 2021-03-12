#include "nwnx.hpp"

#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#include "sdk/coreclr_delegates.h"
#include "sdk/hostfxr.h"
#include <dirent.h>
#include <dlfcn.h>
#include <limits.h>

using namespace NWNXLib;
using namespace NWNXLib::API;

namespace DotNET {

std::vector<void*> GetExports();
static void DotNET() __attribute__((constructor));

static hostfxr_initialize_for_runtime_config_fn hostfxr_initialize_for_runtime_config;
static hostfxr_get_runtime_delegate_fn          hostfxr_get_runtime_delegate;
static hostfxr_close_fn                         hostfxr_close;

static bool InitThunks()
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

static void DotNET()
{
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

    std::vector<void*> args = GetExports();
    rc = bootstrap(args.data(), args.size()*sizeof(void*));
    if (rc != 0)
        LOG_FATAL("Failed to execute bootstrap function; rc=0x%x", rc);

    LOG_INFO("Managed code bootstrapped.");
}

}
