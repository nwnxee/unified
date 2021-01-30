#pragma once

#include "nwnx.hpp"
#include "API/CServerExoAppInternal.hpp"
#include "API/CNWVirtualMachineCommands.hpp"

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

    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_posObjectDtorHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_posAreaDtorHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_posEatTURDHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_posDropTURDHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_posUUIDSaveToGffHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_posUUIDLoadFromGffHook;

private:
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_createServerHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_vmSetVarHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_vmGetVarHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_vmTagEffectHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_vmTagItemProperyHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_vmPlaySoundHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_destroyServerHook;
    std::unique_ptr<NWNXLib::Hooking::FunctionHook> m_mainLoopInternalHook;

    std::unique_ptr<NWNXLib::Services::ProxyServiceList> m_coreServices;

    std::unique_ptr<NWNXLib::Services::ServiceList> ConstructCoreServices();
    std::unique_ptr<NWNXLib::Services::ProxyServiceList> ConstructProxyServices(const std::string& plugin);

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
