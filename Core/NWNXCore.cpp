#include "NWNXCore.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Constants.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "Platform/ASLR.hpp"
#include "Platform/Debug.hpp"
#include "Platform/FileSystem.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Patching/Patching.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Services/Commands/Commands.hpp"
#include "Utils.hpp"
#include "Encoding.hpp"

#include <csignal>

using namespace NWNXLib;
using namespace NWNXLib::Hooking;

static void (*nwn_crash_handler)(int);
extern "C" void nwnx_signal_handler(int sig)
{
    std::fflush(stdout);

    const char *err;
    switch (sig)
    {
        case SIGABRT:  err = "Program aborted";          break;
        case SIGFPE:   err = "Floating point exception"; break;
        case SIGSEGV:  err = "Segmentation fault";       break;
        default:       err = "Unknown error";            break;
    }

    std::fprintf(stderr, " NWNX Signal Handler:\n"
        "==============================================================\n"
        " NWNX has crashed. Fatal error: %s (%d).\n"
        " Please file a bug at https://github.com/nwnxee/unified/issues\n"
        "==============================================================\n",
        err, sig);

    std::fputs(NWNXLib::Platform::Debug::GetStackTrace(20).c_str(), stderr);

    std::fflush(stderr);

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

}

namespace Core {

NWNXCore* g_core = nullptr; // Used to access the core class in hook or event handlers.

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
    services->m_commands = std::make_unique<Commands>();

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
    proxyServices->m_commands = std::make_unique<Services::CommandsProxy>(*m_services->m_commands);

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
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWVirtualMachineCommands__ExecuteCommandSetVar>(&SetVarHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWVirtualMachineCommands__ExecuteCommandGetVar>(&GetVarHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWVirtualMachineCommands__ExecuteCommandTagEffect>(&TagEffectHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWVirtualMachineCommands__ExecuteCommandTagItemProperty>(&TagItemPropertyHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::CNWVirtualMachineCommands__ExecuteCommandPlaySound>(&PlaySoundHandler);

    m_services->m_hooks->RequestExclusiveHook<API::Functions::CAppManager__DestroyServer>(&DestroyServerHandler);
    m_services->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopInternalHandler);

    m_services->m_hooks->RequestSharedHook<API::Functions::CNWSObject__CNWSObjectDtor__0, void>(&Services::PerObjectStorage::CNWSObject__CNWSObjectDtor__0_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::CNWSArea__CNWSAreaDtor__0, void>(&Services::PerObjectStorage::CNWSArea__CNWSAreaDtor__0_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::CNWSPlayer__EatTURD, void>(&Services::PerObjectStorage::CNWSPlayer__EatTURD_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::CNWSPlayer__DropTURD, void>(&Services::PerObjectStorage::CNWSPlayer__DropTURD_hook);
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
    const bool skipAllPlugins = m_coreServices->m_config->Get<bool>("SKIP_ALL", false);

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

        if (pluginNameWithoutExtension == "NWNX_Experimental" && !m_coreServices->m_config->Get<bool>("LOAD_EXPERIMENTAL_PLUGIN", false))
        {
            continue;
        }

        std::unique_ptr<Services::ProxyServiceList> services = ConstructProxyServices(pluginNameWithoutExtension);

        Plugin::CreateParams params = { services };

        if (services->m_config->Get<bool>("SKIP", (bool)skipAllPlugins))
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

void NWNXCore::CreateServerHandler(API::CAppManager* app)
{
    g_core->InitialVersionCheck();

    g_core->m_services = g_core->ConstructCoreServices();
    g_core->m_coreServices = g_core->ConstructProxyServices(NWNX_CORE_PLUGIN_NAME);

    // We need to set the NWNXLib log level (separate from Core now) to match the core log level.
    Log::SetLogLevel("NWNXLib", Log::GetLogLevel(NWNX_CORE_PLUGIN_NAME));

    if (auto locale = g_core->m_coreServices->m_config->Get<std::string>("LOCALE"))
    {
        Encoding::SetDefaultLocale(*locale);
    }

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
    if (auto shutdownScript = g_core->m_coreServices->m_config->Get<std::string>("SHUTDOWN_SCRIPT"))
    {
        if (API::Globals::AppManager()->m_pServerExoApp->GetServerMode() == 2)
        {
            LOG_NOTICE("Running module shutdown script: %s", shutdownScript->c_str());
            Utils::ExecuteScript(*shutdownScript, 0);
        }
    }

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
    g_core->m_services->m_commands->RunScheduledCommands();
}

}
