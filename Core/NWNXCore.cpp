#include "NWNXCore.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Platform/ASLR.hpp"
#include "Platform/FileSystem.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Patching/Patching.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Messaging/Messaging.hpp"

#include <cassert>
#include <cstring>

using namespace NWNXLib;
using namespace NWNXLib::Hooking;

namespace {

bool IsStringPrefixedWithNWNX(const API::CExoString* str)
{
    return str && str->m_sString && str->m_nBufferLength >= 5 && std::strncmp("NWNX!", str->m_sString, 5) == 0;
}

}

namespace Core {

static NWNXCore* g_core = nullptr; // Used to access the core class in hook or event handlers.
static Services::LogProxy* g_log = nullptr;

}

// If NWNX_LEGACY_SUPPORT is defined, we expose two additional symbols: NWNXLegacySetString and NWNXLegacyGetObject.
// The old NWNX core will call these if it decides not to handle an event.
// This allows us to run the new core for selective plugins while still using new functionality.
#if defined(NWNX_LEGACY_SUPPORT)
extern "C"
{
    void NWNXLegacySetString(NWNXLib::API::CExoString* index, NWNXLib::API::CExoString* value)
    {
        Core::g_core->SetStringHandler(nullptr, index, value);
    }

    NWNXLib::API::Types::ObjectID NWNXLegacyGetObject(NWNXLib::API::CExoString* index)
    {
        return Core::g_core->GetObjectHandler(nullptr, index);
    }
}
#endif

namespace Core {

static Hooking::FunctionHook* g_setStringHook = nullptr;
static Hooking::FunctionHook* g_getStringHook = nullptr;
static Hooking::FunctionHook* g_getObjectHook = nullptr;

NWNXCore::NWNXCore()
    : m_pluginProxyServiceMap([](const auto& first, const auto& second) { return first.m_id < second.m_id; })
{
    g_core = this;

    m_services = ConstructCoreServices();
    m_coreServices = ConstructProxyServices(NWNX_CORE_PLUGIN_NAME);
    g_log = m_coreServices->m_log.get();

    // This sets up the base address for every hook and patch to follow.
    Platform::ASLR::CalculateBaseAddress();

    if (m_coreServices->m_config->Get<bool>("SKIP", false))
    {
        g_log->Info("Not loading NWNX due to configuration.");
        return;
    }

    m_services->m_hooks->RequestSharedHook<API::Functions::CAppManager__CreateServer, void>(&CreateServerHandler);
}

NWNXCore::~NWNXCore()
{
    Shutdown();
}

std::unique_ptr<Services::ServiceList> NWNXCore::ConstructCoreServices()
{
    using namespace NWNXLib::Services;
    std::unique_ptr<ServiceList> services = std::make_unique<ServiceList>();

    services->m_log = std::make_unique<Log>();

    // Make a log proxy for all the core services to use.
    auto logProxy = std::make_shared<LogProxy>(*services->m_log, NWNX_CORE_PLUGIN_NAME, LogSeverity::SEV_INFO);

    services->m_events = std::make_unique<Events>(logProxy);
    services->m_hooks = std::make_unique<Hooks>(logProxy);
    services->m_plugins = std::make_unique<Plugins>(logProxy);
    services->m_tasks = std::make_unique<Tasks>(logProxy);
    services->m_metrics = std::make_unique<Metrics>(logProxy);
    services->m_patching = std::make_unique<Patching>(logProxy);
    services->m_config = std::make_unique<Config>(logProxy);
    services->m_messaging = std::make_unique<Messaging>(logProxy);

    // Make a config proxy temporarily so we can configure the log proxy.
    ConfigureLogProxy(*logProxy, ConfigProxy(*services->m_config, NWNX_CORE_PLUGIN_NAME));

    return services;
}

std::unique_ptr<Services::ProxyServiceList> NWNXCore::ConstructProxyServices(const std::string plugin)
{
    std::unique_ptr<Services::ProxyServiceList> proxyServices = std::make_unique<Services::ProxyServiceList>();

    proxyServices->m_log = std::make_unique<Services::LogProxy>(*m_services->m_log, plugin, Services::LogSeverity::SEV_INFO);
    proxyServices->m_events = std::make_unique<Services::EventsProxy>(*m_services->m_events, plugin);
    proxyServices->m_hooks = std::make_unique<Services::HooksProxy>(*m_services->m_hooks);
    proxyServices->m_plugins = std::make_unique<Services::PluginsProxy>(*m_services->m_plugins);
    proxyServices->m_tasks = std::make_unique<Services::TasksProxy>(*m_services->m_tasks);
    proxyServices->m_metrics = std::make_unique<Services::MetricsProxy>(*m_services->m_metrics, plugin);
    proxyServices->m_patching = std::make_unique<Services::PatchingProxy>(*m_services->m_patching);
    proxyServices->m_config = std::make_unique<Services::ConfigProxy>(*m_services->m_config, plugin);
    proxyServices->m_messaging = std::make_unique<Services::MessagingProxy>(*m_services->m_messaging);

    ConfigureLogProxy(*proxyServices->m_log, *proxyServices->m_config);

    return proxyServices;
}

void NWNXCore::ConfigureLogProxy(NWNXLib::Services::LogProxy& proxy, const NWNXLib::Services::ConfigProxy& config)
{
    // Setup the log level. We do this first by checking if NWNX_<PLUGIN>_LOG_LEVEL is set.
    auto logLevel = config.Get<uint32_t>("LOG_LEVEL");

    if (!logLevel && m_coreServices)
    {
        // If it is not, then we check if NWNX_CORE_LOG_LEVEL is set.
        logLevel = m_coreServices->m_config->Get<uint32_t>("LOG_LEVEL");
    }

    if (logLevel)
    {
        // If neither of these are set, it will use the default (which is SEV_INFO, set above).
        proxy.SetLogLevel(static_cast<Services::LogSeverity>(*logLevel));
    }
}

void NWNXCore::InitialSetupHooks()
{
#if !defined(NWNX_LEGACY_SUPPORT)
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWSScriptVarTable__SetString>(&SetStringHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWSScriptVarTable__GetObject>(&GetObjectHandler);
#endif

    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWSScriptVarTable__GetString>(&GetStringHandler);

    m_services->m_hooks->RequestExclusiveHook<API::Functions::CAppManager__DestroyServer>(&DestroyServerHandler);
    m_services->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopInternalHandler);

    g_setStringHook = m_services->m_hooks->FindHookByAddress(API::Functions::CNWSScriptVarTable__SetString);
    g_getStringHook = m_services->m_hooks->FindHookByAddress(API::Functions::CNWSScriptVarTable__GetString);
    g_getObjectHook = m_services->m_hooks->FindHookByAddress(API::Functions::CNWSScriptVarTable__GetObject);
}

void NWNXCore::InitialVersionCheck()
{
    const uintptr_t buildNumberAddr = Platform::DynamicLibraries::GetLoadedFuncAddr("GetBuildNumber");
    if (buildNumberAddr)
    {
        API::CExoString* versionAsStr = reinterpret_cast<API::CExoString*(*)()>(buildNumberAddr)();
        g_log->Info("Server is running version %s.", versionAsStr->m_sString);

        const uint32_t version = std::stoi(versionAsStr->m_sString);

        if (version != NWNX_TARGET_NWN_BUILD)
        {
            throw std::runtime_error("Core version mismatch -- has the server updated?");
        }
    }
    else
    {
        throw std::runtime_error("Unable to resolve GetBuildNumber from the NWN binary. Old version?");
    }
}

void NWNXCore::InitialSetupPlugins()
{
    using namespace Platform::FileSystem;

    constexpr static const char* pluginPrefix = NWNX_PLUGIN_PREFIX;
    const std::string prefix = pluginPrefix;

    const std::string pluginDir = m_coreServices->m_config->Get<std::string>("LOAD_PATH", GetCurDirectory());

    g_log->Info("Loading plugins from: %s", pluginDir.c_str());

    std::vector<std::string> sortedDynamicLibraries;

    for (auto& dynamicLibrary : GetAllDynamicLibrariesInDirectory(pluginDir))
    {
        sortedDynamicLibraries.emplace_back(std::move(dynamicLibrary.first));
    }

    // Sort by file name, so at least plugins are loaded in deterministic order.
    std::sort(std::begin(sortedDynamicLibraries), std::end(sortedDynamicLibraries));

    for (auto& dynamicLibrary : sortedDynamicLibraries)
    {
        const std::string& pluginName = dynamicLibrary;
        const std::string pluginNameWithoutExtension = StripExtensionFromFileName(pluginName);

        if (pluginNameWithoutExtension == NWNX_CORE_PLUGIN_NAME || pluginNameWithoutExtension.compare(0, prefix.size(), prefix) != 0)
        {
            continue; // Not a plugin.
        }

        std::unique_ptr<Services::ProxyServiceList> services = ConstructProxyServices(pluginNameWithoutExtension);

        Plugin::CreateParams params = { services };

        if (services->m_config->Get<bool>("SKIP", false))
        {
            g_log->Info("Skipping plugin %s due to configuration.", pluginNameWithoutExtension.c_str());
            continue;
        }

        try
        {
            auto registrationToken = m_services->m_plugins->LoadPlugin(CombinePaths(pluginDir, pluginName), std::move(params));
            auto data = *m_services->m_plugins->FindPluginById(registrationToken.m_id);
            g_log->Info("Loaded plugin %u (%s) v%u by %s.", data.m_id, data.m_info->m_name.c_str(), data.m_info->m_version, data.m_info->m_author.c_str());
            m_pluginProxyServiceMap.insert(std::make_pair(std::move(registrationToken), std::move(services)));
        }
        catch (const std::runtime_error& err)
        {
            g_log->Error("Failed to load plugin (%s) because '%s'.", pluginName.c_str(), err.what());
            throw;
        }
    }
}

void NWNXCore::UnloadPlugins()
{
    using PairType = std::pair<Services::Plugins::RegistrationToken, std::unique_ptr<Services::ProxyServiceList>>;

    std::for_each(
        std::make_move_iterator(m_pluginProxyServiceMap.rbegin()),
        std::make_move_iterator(m_pluginProxyServiceMap.rend()),
        [this](PairType&& data)
        {
            UnloadPlugin(std::forward<PairType>(data));
        }
    );

    m_pluginProxyServiceMap.clear();
}

void NWNXCore::UnloadPlugin(std::pair<Services::Plugins::RegistrationToken,
    std::unique_ptr<Services::ProxyServiceList>>&& plugin)
{
    using namespace NWNXLib::Services;

    auto data = *m_services->m_plugins->FindPluginById(plugin.first.m_id);

    const Plugins::PluginID pluginId = data.m_id;
    const std::string pluginName = data.m_info->m_name;

    try
    {
        m_services->m_plugins->UnloadPlugin(std::forward<Plugins::RegistrationToken>(plugin.first), Plugin::UnloadReason::SHUTTING_DOWN);
        g_log->Info("Unloaded plugin %d (%s).", pluginId, pluginName.c_str());
    }
    catch (const std::runtime_error& err)
    {
        g_log->Error("Received error '%s' when unloading plugin %d (%s).", err.what(), pluginId, pluginName.c_str());
    }
}

void NWNXCore::UnloadServices()
{
    m_coreServices.reset();
    m_services.reset();
    g_log = nullptr;
}

void NWNXCore::Shutdown()
{
    UnloadPlugins();
    UnloadServices();
    g_core = nullptr;
}

void NWNXCore::SetStringHandler(API::CNWSScriptVarTable* thisPtr, API::CExoString* index, API::CExoString* value)
{
    if (IsStringPrefixedWithNWNX(index))
    {
        std::string keyAsStr = std::string(index->m_sString + 5);
        std::string valueAsStr = value->m_sString ? std::string(value->m_sString) : std::string("");
        return g_core->m_services->m_events->OnSetLocalString(std::move(keyAsStr), std::move(valueAsStr));
    }

#if defined(NWNX_LEGACY_SUPPORT)
    (void)thisPtr; // Suppress unused variable warning.
#else
    g_setStringHook->CallOriginal<void>(thisPtr, index, value);
#endif
}

API::Types::ObjectID NWNXCore::GetObjectHandler(API::CNWSScriptVarTable* thisPtr, API::CExoString* index)
{
    if (IsStringPrefixedWithNWNX(index))
    {
        Maybe<API::Types::ObjectID> eventRet = g_core->m_services->m_events->OnGetLocalObject(std::string(index->m_sString + 5));
        return eventRet ? eventRet.Extract() : API::Constants::OBJECT_INVALID;
    }

#if defined(NWNX_LEGACY_SUPPORT)
    (void)thisPtr; // Suppress unused variable warning.
    return API::Constants::OBJECT_INVALID;
#else
    return g_getObjectHook->CallOriginal<API::Types::ObjectID>(thisPtr, index);
#endif
}

API::CExoString NWNXCore::GetStringHandler(API::CNWSScriptVarTable* thisPtr, API::CExoString* index)
{
    if (IsStringPrefixedWithNWNX(index))
    {
        Maybe<std::string> eventRet = g_core->m_services->m_events->OnGetLocalString(std::string(index->m_sString + 5));

#if defined(NWNX_LEGACY_SUPPORT)
        if (eventRet) return eventRet.Extract().c_str();
#else
        return eventRet ? eventRet.Extract().c_str() : "";
#endif
    }

    return g_getStringHook->CallOriginal<API::CExoString>(thisPtr, index);
}

void NWNXCore::CreateServerHandler(Services::Hooks::CallType type, API::CAppManager*)
{
    if (type != Services::Hooks::CallType::AFTER_ORIGINAL)
    {
        return;
    }

    try
    {
        g_core->InitialSetupHooks();
        g_core->InitialVersionCheck();
        g_core->InitialSetupPlugins();
    }
    catch (const std::runtime_error& ex)
    {
        g_log->Fatal("The server encountered a fatal error '%s' during setup and must now terminate.", ex.what());
    }
}

void NWNXCore::DestroyServerHandler(API::CAppManager* app)
{
    g_core->Shutdown();

    // At this point, the hook has been reset. We should call the original again to let NWN carry on.
    app->DestroyServer();
}

void NWNXCore::MainLoopInternalHandler(Services::Hooks::CallType type, API::CServerExoAppInternal*)
{
    if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    g_core->m_services->m_metrics->Update(g_core->m_services->m_tasks);
    g_core->m_services->m_tasks->ProcessWorkOnMainThread();
}

}
