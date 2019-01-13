#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Plugin.hpp"
#include "Platform/Hooking.hpp"
#include "Services/Services.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Plugins/Plugins.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"

#include <functional>
#include <map>
#include <memory>

namespace Core {

class NWNXCore
{
public:
    NWNXCore();
    ~NWNXCore();

    static int32_t GetVarHandler(NWNXLib::API::CNWVirtualMachineCommands*, int32_t, int32_t);
    static int32_t SetVarHandler(NWNXLib::API::CNWVirtualMachineCommands*, int32_t, int32_t);

private: // Structures
    using PluginProxyServiceMap = std::map<
        NWNXLib::Services::Plugins::RegistrationToken,
        std::unique_ptr<NWNXLib::Services::ProxyServiceList>,
        std::function<bool(
            const NWNXLib::Services::Plugins::RegistrationToken&,
            const NWNXLib::Services::Plugins::RegistrationToken&)>>;

private:
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_createServerHook;
    std::unique_ptr<NWNXLib::Services::ServiceList> m_services;
    std::unique_ptr<NWNXLib::Services::ProxyServiceList> m_coreServices;
    PluginProxyServiceMap m_pluginProxyServiceMap;

    std::unique_ptr<NWNXLib::Services::ServiceList> ConstructCoreServices();
    std::unique_ptr<NWNXLib::Services::ProxyServiceList> ConstructProxyServices(const std::string& plugin);

    void ConfigureLogLevel(const std::string& plugin, const NWNXLib::Services::ConfigProxy& config);

    void InitialSetupHooks();
    void InitialVersionCheck();
    void InitialSetupPlugins();

    void UnloadPlugins();
    void UnloadPlugin(std::pair<NWNXLib::Services::Plugins::RegistrationToken,
        std::unique_ptr<NWNXLib::Services::ProxyServiceList>>&& plugin);

    void UnloadServices();
    void Shutdown();

    static void CreateServerHandler(NWNXLib::API::CAppManager*);
    static void DestroyServerHandler(NWNXLib::API::CAppManager*);
    static void MainLoopInternalHandler(NWNXLib::Services::Hooks::CallType type, NWNXLib::API::CServerExoAppInternal*);
};

}
