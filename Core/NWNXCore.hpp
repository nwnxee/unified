#pragma once

#include "nwnx.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWSVirtualMachineCommands.hpp"

#include <functional>
#include <map>
#include <memory>

namespace Core {

class NWNXCore
{
public:
    NWNXCore();
    ~NWNXCore();

    static int32_t GetVarHandler(CNWSVirtualMachineCommands*, int32_t, int32_t);
    static int32_t SetVarHandler(CNWSVirtualMachineCommands*, int32_t, int32_t);
    static int32_t TagEffectHandler(CNWSVirtualMachineCommands*, int32_t, int32_t);
    static int32_t TagItemPropertyHandler(CNWSVirtualMachineCommands*, int32_t, int32_t);
    static int32_t PlaySoundHandler(CNWSVirtualMachineCommands*, int32_t, int32_t);

    std::unique_ptr<NWNXLib::Services::ServiceList> m_services;

    const std::vector<std::string>& GetCustomResourceDirectoryAliases() const { return m_CustomResourceDirectoryAliases; }

    NWNXLib::Hooks::Hook m_vmSetVarHook;
    NWNXLib::Hooks::Hook m_vmGetVarHook;

private:
    NWNXLib::Hooks::Hook m_createServerHook;
    NWNXLib::Hooks::Hook m_vmTagEffectHook;
    NWNXLib::Hooks::Hook m_vmTagItemProperyHook;
    NWNXLib::Hooks::Hook m_vmPlaySoundHook;
    NWNXLib::Hooks::Hook m_destroyServerHook;
    NWNXLib::Hooks::Hook m_mainLoopInternalHook;

    std::unique_ptr<NWNXLib::Services::ProxyServiceList> m_coreServices;

    std::unique_ptr<NWNXLib::Services::ServiceList> ConstructCoreServices();
    std::unique_ptr<NWNXLib::Services::ProxyServiceList> ConstructProxyServices(const std::string& plugin);

    void CleanupPreload();
    void ConfigureLogLevel(const std::string& plugin);

    void InitialSetupHooks();
    void InitialVersionCheck();
    void InitialSetupPlugins();
    void InitialSetupResourceDirectories();
    void InitialSetupCommands();

    void UnloadServices();
    void Shutdown();

    static void CreateServerHandler(CAppManager*);
    static void DestroyServerHandler(CAppManager*);
    static int32_t MainLoopInternalHandler(CServerExoAppInternal*);

    int m_ScriptChunkRecursion;
    std::vector<std::string> m_CustomResourceDirectoryAliases;
};

}
