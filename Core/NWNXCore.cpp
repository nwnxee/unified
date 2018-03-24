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
#include "Services/Metrics/Metrics.hpp"
#include "Services/Patching/Patching.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Utils.hpp"

#include <cstring>
#include <csignal>

using namespace NWNXLib;
using namespace NWNXLib::Hooking;

static void (*nwn_crash_handler)(int);
extern "C" void nwnx_signal_handler(int sig)
{
    const char *err;
    switch (sig)
    {
        case SIGABRT:  err = "Program aborted";          break;
        case SIGFPE:   err = "Floating point exception"; break;
        case SIGSEGV:  err = "Segmentation fault";       break;
        default:       err = "Unknown error";            break;
    }

    ASSERT_FAIL_MSG(" NWNX Signal Handler:\n"
        "==============================================================\n"
        " NWNX has crashed. Fatal error: %s (%d).\n"
        " Please file a bug at https://github.com/nwnxee/unified/issues\n"
        "==============================================================\n",
        err, sig);
    nwn_crash_handler(sig);
}

namespace {

void InitCrashHandlers()
{
    nwn_crash_handler = std::signal(SIGABRT, nwnx_signal_handler);
    std::signal(SIGFPE,  nwnx_signal_handler);
    std::signal(SIGSEGV, nwnx_signal_handler);
}
void RestoreCrashHandlers()
{
    std::signal(SIGABRT, nwn_crash_handler);
    std::signal(SIGFPE,  nwn_crash_handler);
    std::signal(SIGSEGV, nwn_crash_handler);
}

static const char NWNX_PREFIX[]        = "NWNXEE!";
static const char NWNX_LEGACY_PREFIX[] = "NWNX!";

bool CompareStringPrefix(const API::CExoString* str, const char *prefix)
{
    auto len = std::strlen(prefix);
    return str && str->m_sString && str->m_nBufferLength >= len && std::strncmp(prefix, str->m_sString, len) == 0;
}

void NotifyLegacyCall(const char* str)
{
    LOG_NOTICE("Legacy NWNX call detected: \"%s\" from %s.nss - ignored", str, Utils::GetCurrentScript().c_str());
    const char *cmd = str + sizeof(NWNX_LEGACY_PREFIX) - 1;
    if (!std::strncmp(cmd, "PUSH_ARGUMENT",    std::strlen("PUSH_ARGUMENT")) ||
        !std::strncmp(cmd, "CALL_FUNCTION",    std::strlen("CALL_FUNCTION")) ||
        !std::strncmp(cmd, "GET_RETURN_VALUE", std::strlen("GET_RETURN_VALUE")))
    {
        LOG_NOTICE("  Please recompile all scripts that include \"nwnx.nss\"");
    }
    else
    {
        LOG_NOTICE("  This is a leftover from 1.69 nwnx2 scripts.");
    }
}

}

namespace Core {

static NWNXCore* g_core = nullptr; // Used to access the core class in hook or event handlers.

static Hooking::FunctionHook* g_setStringHook = nullptr;
static Hooking::FunctionHook* g_getStringHook = nullptr;
static Hooking::FunctionHook* g_getObjectHook = nullptr;

NWNXCore::NWNXCore()
    : m_pluginProxyServiceMap([](const auto& first, const auto& second) { return first.m_id < second.m_id; })
{
    g_core = this;

    // NOTE: We should do the version check here, but the global in the binary hasn't been initialised yet at this point.
    // This will be fixed in a future release of NWNX:EE. For now, the version check will happen *too late* - we may
    // crash before the version check happens.

    // This sets up the base address for every hook and patch to follow.
    Platform::ASLR::CalculateBaseAddress();

    m_createServerHook = std::make_unique<FunctionHook>("CreateServer",
        Platform::ASLR::GetRelocatedAddress(API::Functions::CAppManager__CreateServer),
        reinterpret_cast<uintptr_t>(&CreateServerHandler));
}

NWNXCore::~NWNXCore()
{
    Shutdown();
}

std::unique_ptr<Services::ServiceList> NWNXCore::ConstructCoreServices()
{
    using namespace NWNXLib::Services;
    std::unique_ptr<ServiceList> services = std::make_unique<ServiceList>();

    services->m_events = std::make_unique<Events>();
    services->m_hooks = std::make_unique<Hooks>();
    services->m_plugins = std::make_unique<Plugins>();
    services->m_tasks = std::make_unique<Tasks>();
    services->m_metrics = std::make_unique<Metrics>();
    services->m_patching = std::make_unique<Patching>();
    services->m_config = std::make_unique<Config>();
    services->m_messaging = std::make_unique<Messaging>();
    services->m_perObjectStorage = std::make_unique<PerObjectStorage>();

    return services;
}

std::unique_ptr<Services::ProxyServiceList> NWNXCore::ConstructProxyServices(const std::string& plugin)
{
    std::unique_ptr<Services::ProxyServiceList> proxyServices = std::make_unique<Services::ProxyServiceList>();

    proxyServices->m_events = std::make_unique<Services::EventsProxy>(*m_services->m_events, plugin);
    proxyServices->m_hooks = std::make_unique<Services::HooksProxy>(*m_services->m_hooks);
    proxyServices->m_plugins = std::make_unique<Services::PluginsProxy>(*m_services->m_plugins);
    proxyServices->m_tasks = std::make_unique<Services::TasksProxy>(*m_services->m_tasks);
    proxyServices->m_metrics = std::make_unique<Services::MetricsProxy>(*m_services->m_metrics, plugin);
    proxyServices->m_patching = std::make_unique<Services::PatchingProxy>(*m_services->m_patching);
    proxyServices->m_config = std::make_unique<Services::ConfigProxy>(*m_services->m_config, plugin);
    proxyServices->m_messaging = std::make_unique<Services::MessagingProxy>(*m_services->m_messaging);
    proxyServices->m_perObjectStorage = std::make_unique<Services::PerObjectStorageProxy>(*m_services->m_perObjectStorage, plugin);

    ConfigureLogLevel(plugin, *proxyServices->m_config);

    return proxyServices;
}

void NWNXCore::ConfigureLogLevel(const std::string& plugin, const NWNXLib::Services::ConfigProxy& config)
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
        Log::SetLogLevel(plugin.c_str(), static_cast<Log::Channel::Enum>(*logLevel));
    }
}

void NWNXCore::InitialSetupHooks()
{
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWSScriptVarTable__SetString>(&SetStringHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWSScriptVarTable__GetObject>(&GetObjectHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWSScriptVarTable__GetString>(&GetStringHandler);

    m_services->m_hooks->RequestExclusiveHook<API::Functions::CAppManager__DestroyServer>(&DestroyServerHandler);
    m_services->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopInternalHandler);

    m_services->m_hooks->RequestSharedHook<API::Functions::CGameObjectArray__Delete__1, void>(&Services::PerObjectStorage::CGameObjectArray__Delete__1_hook);

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
        const uint32_t version = std::stoul(versionAsStr->m_sString);

        if (version != NWNX_TARGET_NWN_BUILD)
        {
            std::fprintf(stderr, "NWNX: Expected build version %u, got build version %u", NWNX_TARGET_NWN_BUILD, version);
            std::fflush(stderr);
            std::abort();
        }
    }
    else
    {
        std::fprintf(stderr, "NWNX: Could not determine build version.");
        std::fflush(stderr);
        std::abort();
    }
}

void NWNXCore::InitialSetupPlugins()
{
    using namespace Platform::FileSystem;

    constexpr static const char* pluginPrefix = NWNX_PLUGIN_PREFIX;
    const std::string prefix = pluginPrefix;

    const std::string pluginDir = m_coreServices->m_config->Get<std::string>("LOAD_PATH", GetCurDirectory());

    LOG_INFO("Loading plugins from: %s", pluginDir.c_str());

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
            LOG_INFO("Skipping plugin %s due to configuration.", pluginNameWithoutExtension.c_str());
            continue;
        }

        try
        {
            LOG_DEBUG("Loading plugin %s", pluginName.c_str());
            auto registrationToken = m_services->m_plugins->LoadPlugin(CombinePaths(pluginDir, pluginName), std::move(params));
            auto data = *m_services->m_plugins->FindPluginById(registrationToken.m_id);
            LOG_INFO("Loaded plugin %u (%s) v%u by %s.", data.m_id, data.m_info->m_name.c_str(), data.m_info->m_version, data.m_info->m_author.c_str());
            m_pluginProxyServiceMap.insert(std::make_pair(std::move(registrationToken), std::move(services)));
        }
        catch (const std::runtime_error& err)
        {
            LOG_ERROR("Failed to load plugin (%s) because '%s'.", pluginName.c_str(), err.what());
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
        LOG_INFO("Unloaded plugin %d (%s).", pluginId, pluginName.c_str());
    }
    catch (const std::runtime_error& err)
    {
        LOG_ERROR("Received error '%s' when unloading plugin %d (%s).", err.what(), pluginId, pluginName.c_str());
    }
}

void NWNXCore::UnloadServices()
{
    m_coreServices.reset();
    m_services.reset();
}

void NWNXCore::Shutdown()
{
    UnloadPlugins();
    UnloadServices();
    g_core = nullptr;
}

void NWNXCore::SetStringHandler(API::CNWSScriptVarTable* thisPtr, API::CExoString* index, API::CExoString* value)
{
    if (CompareStringPrefix(index, NWNX_PREFIX))
    {
        std::string keyAsStr = std::string(index->m_sString + sizeof(NWNX_PREFIX) - 1);
        std::string valueAsStr = value->m_sString ? std::string(value->m_sString) : std::string("");
        return g_core->m_services->m_events->OnSetLocalString(std::move(keyAsStr), std::move(valueAsStr));
    }
    else if (CompareStringPrefix(index, NWNX_LEGACY_PREFIX))
    {
        NotifyLegacyCall(index->CStr());
    }

    g_setStringHook->CallOriginal<void>(thisPtr, index, value);
}

API::Types::ObjectID NWNXCore::GetObjectHandler(API::CNWSScriptVarTable* thisPtr, API::CExoString* index)
{
    if (CompareStringPrefix(index, NWNX_PREFIX))
    {
        Maybe<API::Types::ObjectID> eventRet = g_core->m_services->m_events->OnGetLocalObject(std::string(index->m_sString + sizeof(NWNX_PREFIX) - 1));
        return eventRet ? eventRet.Extract() : API::Constants::OBJECT_INVALID;
    }
    else if (CompareStringPrefix(index, NWNX_LEGACY_PREFIX))
    {
        NotifyLegacyCall(index->CStr());
    }

    return g_getObjectHook->CallOriginal<API::Types::ObjectID>(thisPtr, index);
}

API::CExoString NWNXCore::GetStringHandler(API::CNWSScriptVarTable* thisPtr, API::CExoString* index)
{
    if (CompareStringPrefix(index, NWNX_PREFIX))
    {
        Maybe<std::string> eventRet = g_core->m_services->m_events->OnGetLocalString(std::string(index->m_sString + sizeof(NWNX_PREFIX) - 1));

        return eventRet ? eventRet.Extract().c_str() : "";
    }
    else if (CompareStringPrefix(index, NWNX_LEGACY_PREFIX))
    {
        NotifyLegacyCall(index->CStr());
    }

    return g_getStringHook->CallOriginal<API::CExoString>(thisPtr, index);
}

void NWNXCore::CreateServerHandler(API::CAppManager* app)
{
    g_core->InitialVersionCheck();

    g_core->m_services = g_core->ConstructCoreServices();
    g_core->m_coreServices = g_core->ConstructProxyServices(NWNX_CORE_PLUGIN_NAME);

    // We need to set the NWNXLib log level (separate from Core now) to match the core log level.
    Log::SetLogLevel("NWNXLib", Log::GetLogLevel(NWNX_CORE_PLUGIN_NAME));

    Maybe<bool> crashOnAssertFailure = g_core->m_coreServices->m_config->Get<bool>("CRASH_ON_ASSERT_FAILURE");
    if (crashOnAssertFailure)
    {
        Assert::SetCrashOnFailure(*crashOnAssertFailure);
    }

    if (g_core->m_coreServices->m_config->Get<bool>("SKIP", false))
    {
        LOG_NOTICE("Not loading NWNX due to configuration.");
    }
    else
    {
        LOG_NOTICE("Loading NWNX.");

        try
        {
            g_core->InitialSetupHooks();
            g_core->InitialSetupPlugins();
        }
        catch (const std::runtime_error& ex)
        {
            LOG_FATAL("The server encountered a fatal error '%s' during setup and must now terminate.", ex.what());
        }
    }

    InitCrashHandlers();
    g_core->m_createServerHook.reset();
    app->CreateServer();
}

void NWNXCore::DestroyServerHandler(API::CAppManager* app)
{
    LOG_NOTICE("Shutting down NWNX.");
    g_core->Shutdown();

    // At this point, the hook has been reset. We should call the original again to let NWN carry on.
    app->DestroyServer();
    RestoreCrashHandlers();
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
