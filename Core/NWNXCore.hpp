#pragma once

#include "API/CServerExoAppInternal.hpp"
#include "API/CNWVirtualMachineCommands.hpp"
#include "Common.hpp"
#include "Plugin.hpp"
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

    static int32_t GetVarHandler(CNWVirtualMachineCommands*, int32_t, int32_t);
    static int32_t SetVarHandler(CNWVirtualMachineCommands*, int32_t, int32_t);
    static int32_t TagEffectHandler(CNWVirtualMachineCommands*, int32_t, int32_t);
    static int32_t TagItemPropertyHandler(CNWVirtualMachineCommands*, int32_t, int32_t);
    static int32_t PlaySoundHandler(CNWVirtualMachineCommands*, int32_t, int32_t);

    std::unique_ptr<NWNXLib::Services::ServiceList> m_services;

    const std::vector<std::string>& GetCustomResourceDirectoryAliases() const { return m_CustomResourceDirectoryAliases; }

private: // Structures
    using PluginProxyServiceMap = std::map<
        NWNXLib::Services::Plugins::RegistrationToken,
        std::unique_ptr<NWNXLib::Services::ProxyServiceList>,
        std::function<bool(
            const NWNXLib::Services::Plugins::RegistrationToken&,
            const NWNXLib::Services::Plugins::RegistrationToken&)>>;

private:
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_createServerHook;
    std::unique_ptr<NWNXLib::Services::ProxyServiceList> m_coreServices;
    PluginProxyServiceMap m_pluginProxyServiceMap;

    std::unique_ptr<NWNXLib::Services::ServiceList> ConstructCoreServices();
    std::unique_ptr<NWNXLib::Services::ProxyServiceList> ConstructProxyServices(const std::string& plugin);

    void ConfigureLogLevel(const std::string& plugin, const NWNXLib::Services::ConfigProxy& config);

    void InitialSetupHooks();
    void InitialVersionCheck();
    void InitialSetupPlugins();
    void InitialSetupResourceDirectories();
    void InitialSetupCommands();

    void UnloadPlugins();
    void UnloadPlugin(std::pair<NWNXLib::Services::Plugins::RegistrationToken,
        std::unique_ptr<NWNXLib::Services::ProxyServiceList>>&& plugin);

    void UnloadServices();
    void Shutdown();

    static void CreateServerHandler(CAppManager*);
    static void DestroyServerHandler(CAppManager*);
    static void MainLoopInternalHandler(bool, CServerExoAppInternal*);

    int m_ScriptChunkRecursion;
    std::vector<std::string> m_CustomResourceDirectoryAliases;
};

}
