#include "NWNXCore.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CServerExoApp.hpp"
#include "API/Functions.hpp"
#include "API/Globals.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CExoStringList.hpp"
#include "API/CScriptCompiler.hpp"
#include "Platform/ASLR.hpp"
#include "Platform/Debug.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Events/Events.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/PerObjectStorage/PerObjectStorage.hpp"
#include "Services/Commands/Commands.hpp"
#include "Utils.hpp"
#include "Encoding.hpp"

#include <csignal>
#include <regex>
#include <dirent.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

using namespace NWNXLib;
using namespace NWNXLib::API;
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

static NWNXCore s_core;
NWNXCore* g_core = nullptr; // Used to access the core class in hook or event handlers.
bool g_CoreShuttingDown = false;

NWNXCore::NWNXCore()
    : m_pluginProxyServiceMap([](const auto& first, const auto& second) { return first.m_id < second.m_id; }),
      m_ScriptChunkRecursion(0)
{
    g_core = this;

    // NOTE: We should do the version check here, but the global in the binary hasn't been initialised yet at this point.
    // This will be fixed in a future release of NWNX:EE. For now, the version check will happen *too late* - we may
    // crash before the version check happens.
    std::printf("Starting NWNX...\n");
    // This sets up the base address for every hook and patch to follow.
    Platform::ASLR::CalculateBaseAddress();

    m_createServerHook = std::make_unique<FunctionHook>(
        Platform::ASLR::GetRelocatedAddress(API::Functions::_ZN11CAppManager12CreateServerEv),
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
    m_services->m_hooks->RequestExclusiveHook<API::Functions::_ZN25CNWVirtualMachineCommands20ExecuteCommandSetVarEii>(&SetVarHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::_ZN25CNWVirtualMachineCommands20ExecuteCommandGetVarEii>(&GetVarHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::_ZN25CNWVirtualMachineCommands23ExecuteCommandTagEffectEii>(&TagEffectHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::_ZN25CNWVirtualMachineCommands29ExecuteCommandTagItemPropertyEii>(&TagItemPropertyHandler);
    m_services->m_hooks->RequestExclusiveHook<API::Functions::_ZN25CNWVirtualMachineCommands23ExecuteCommandPlaySoundEii>(&PlaySoundHandler);

    m_services->m_hooks->RequestExclusiveHook<API::Functions::_ZN11CAppManager13DestroyServerEv>(&DestroyServerHandler);
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN21CServerExoAppInternal8MainLoopEv, int32_t>(&MainLoopInternalHandler);

    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSObjectD0Ev, void>(&Services::PerObjectStorage::CNWSObject__CNWSObjectDtor__0_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN8CNWSAreaD0Ev, void>(&Services::PerObjectStorage::CNWSArea__CNWSAreaDtor__0_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSPlayer7EatTURDEP14CNWSPlayerTURD, void>(&Services::PerObjectStorage::CNWSPlayer__EatTURD_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSPlayer8DropTURDEv, void>(&Services::PerObjectStorage::CNWSPlayer__DropTURD_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN8CNWSUUID9SaveToGffEP7CResGFFP10CResStruct, void>(&Services::PerObjectStorage::CNWSUUID__SaveToGff_hook);
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN8CNWSUUID11LoadFromGffEP7CResGFFP10CResStruct, void>(&Services::PerObjectStorage::CNWSUUID__LoadFromGff_hook);

    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSModule20LoadModuleInProgressEii, uint32_t>(
            +[](bool before, CNWSModule *pModule, int32_t nAreasLoaded, int32_t nAreasToLoad)
            {
                if (before)
                {
                    int index = nAreasLoaded;
                    auto *node = pModule->m_lstModuleArea.m_pcExoLinkedListInternal->pHead;
                    while (node && index)
                    {
                        node = node->pNext;
                        index--;
                    }

                    if (node)
                    {
                        auto *resref = (CResRef*)node->pObject;
                        LOG_DEBUG("(%i/%i) Trying to load area with resref: %s", nAreasLoaded + 1,  nAreasToLoad, *resref);
                    }
                }
            });

    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN10CNWSModule16LoadModuleFinishEv, uint32_t>(
        +[](bool before, CNWSModule*)
        {
            if (before)
            {
                g_core->m_services->m_messaging->BroadcastMessage("NWNX_CORE_SIGNAL", { "ON_MODULE_LOAD_FINISH" });
            }
        });

    if (!m_coreServices->m_config->Get<bool>("ALLOW_NWNX_FUNCTIONS_IN_EXECUTE_SCRIPT_CHUNK", false))
    {
        m_services->m_hooks->RequestSharedHook<API::Functions::_ZN25CNWVirtualMachineCommands32ExecuteCommandExecuteScriptChunkEii, int32_t>(
                +[](bool before, CNWVirtualMachineCommands*, int32_t, int32_t)
                {
                    g_core->m_ScriptChunkRecursion += before ? +1 : -1;
                });
    }

    // TODO-64Bit: Temp fix for POS
    m_services->m_hooks->RequestSharedHook<API::Functions::_ZN11CGameObjectC2Ehj, void>(
            +[](bool before, CGameObject* pThis, uint8_t, uint32_t)
            {
                if (!before)
                    pThis->m_pNwnxData = nullptr;
            });
}

void NWNXCore::InitialVersionCheck()
{
    CExoString *pBuildNumber = Globals::BuildNumber();
    CExoString *pBuildRevision = Globals::BuildRevision();

    if (pBuildNumber && pBuildRevision)
    {
        const uint32_t version = std::stoul(pBuildNumber->m_sString);
        const uint32_t revision = std::stoul(pBuildRevision->m_sString);

        if (version != NWNX_TARGET_NWN_BUILD || revision != NWNX_TARGET_NWN_BUILD_REVISION)
        {
            std::fprintf(stderr, "NWNX: Expected build version %u revision %u, got build version %u revision %u.\n",
                                      NWNX_TARGET_NWN_BUILD, NWNX_TARGET_NWN_BUILD_REVISION, version, revision);
            std::fprintf(stderr, "NWNX: Will terminate. Please use the correct NWNX build for your game version.\n");
            std::fflush(stderr);
            std::exit(1);
        }
    }
    else
    {
        std::fprintf(stderr, "NWNX: Could not determine build version.\n");
        std::fflush(stderr);
        std::abort();
    }
}

void NWNXCore::InitialSetupPlugins()
{
    constexpr static const char* pluginPrefix = NWNX_PLUGIN_PREFIX;
    const std::string prefix = pluginPrefix;

    char cwd[PATH_MAX];
    ASSERT(getcwd(cwd, sizeof(cwd)) != nullptr);

    const auto pluginDir = m_coreServices->m_config->Get<std::string>("LOAD_PATH", cwd);
    const bool skipAllPlugins = m_coreServices->m_config->Get<bool>("SKIP_ALL", false);

    LOG_INFO("Loading plugins from: %s", pluginDir);

    std::vector<std::string> files;
    DIR* dir = opendir(pluginDir.c_str());

    if (dir != nullptr)
    {
        dirent* directoryEntry = readdir(dir);

        while (directoryEntry != nullptr)
        {
            if (directoryEntry->d_type == DT_UNKNOWN || directoryEntry->d_type == DT_REG || directoryEntry->d_type == DT_LNK)
            {
                files.emplace_back(directoryEntry->d_name);
            }
            directoryEntry = readdir(dir);
        }
        closedir(dir);
    }

    // Sort by file name, so at least plugins are loaded in deterministic order.
    std::sort(std::begin(files), std::end(files));

    for (auto& dynamicLibrary : files)
    {
        const std::string& pluginName = dynamicLibrary;
        const std::string pluginNameWithoutExtension = Utils::basename(pluginName);

        if (pluginNameWithoutExtension == NWNX_CORE_PLUGIN_NAME || pluginNameWithoutExtension.compare(0, prefix.size(), prefix) != 0)
        {
            continue; // Not a plugin.
        }

        if (pluginNameWithoutExtension == "NWNX_Experimental" && !m_coreServices->m_config->Get<bool>("LOAD_EXPERIMENTAL_PLUGIN", false))
        {
            continue;
        }

        std::unique_ptr<Services::ProxyServiceList> services = ConstructProxyServices(pluginNameWithoutExtension);

        if (services->m_config->Get<bool>("SKIP", (bool)skipAllPlugins))
        {
            LOG_INFO("Skipping plugin %s due to configuration.", pluginNameWithoutExtension);
            continue;
        }

        try
        {
            LOG_DEBUG("Loading plugin %s", pluginName);
            std::stringstream ss;
            ss << pluginDir << "/" << pluginName;
            auto registrationToken = m_services->m_plugins->LoadPlugin(ss.str(), services.get());
            auto data = *m_services->m_plugins->FindPluginById(registrationToken.m_id);
            LOG_INFO("Loaded plugin %u (%s).", data.m_id, pluginNameWithoutExtension);
            m_pluginProxyServiceMap.insert(std::make_pair(std::move(registrationToken), std::move(services)));
        }
        catch (const std::runtime_error& err)
        {
            LOG_ERROR("Failed to load plugin (%s) because '%s'.", pluginName, err.what());
            throw;
        }
    }
}

void NWNXCore::InitialSetupResourceDirectories()
{
    auto nwnxResDirPath = m_coreServices->m_config->Get<std::string>("NWNX_RESOURCE_DIRECTORY_PATH", Globals::ExoBase()->m_sUserDirectory.CStr() + std::string("/nwnx"));
    auto nwnxResDirPriority = m_coreServices->m_config->Get<int32_t>("NWNX_RESOURCE_DIRECTORY_PRIORITY", 70000000);

    std::unordered_map<std::string, std::pair<std::string, int32_t>> resourceDirectories;
    resourceDirectories.emplace("NWNX", std::make_pair(nwnxResDirPath, nwnxResDirPriority));

    if (auto customResmanDefinition = m_coreServices->m_config->Get<std::string>("CUSTOM_RESMAN_DEFINITION"))
    {
        std::string crdPath = *customResmanDefinition;
        FILE* file = std::fopen(crdPath.c_str(), "r");

        if (file)
        {
            LOG_INFO("Custom Resman Definition File: %s", crdPath);

            char line[640];
            char alias[64];
            char path[512];
            int32_t priority;

            while (std::fgets(line, 640, file))
            {
                if (sscanf(line, "%s %s %i", alias, path, &priority) == 3)
                {
                    resourceDirectories.try_emplace(alias, std::make_pair(path, priority));
                }
                else
                {
                    std::string errorLine = std::string(line);
                    LOG_WARNING("Invalid Custom Resman Definition Line: %s", Utils::trim(errorLine));
                }
            }

            std::fclose(file);
        }
        else
            LOG_ERROR("Failed to open Custom Resman Definition File: %s", crdPath);
    }

    m_services->m_tasks->QueueOnMainThread([resourceDirectories]
        {
            if (g_CoreShuttingDown)
                return;

            for (const auto& resDir : resourceDirectories)
            {
                CExoString alias = CExoString(resDir.first + ":");
                CExoString path = CExoString(resDir.second.first);

                if (Globals::ExoBase()->m_pcExoAliasList->GetAliasPath(alias).IsEmpty())
                {
                    LOG_INFO("Setting up Resource Directory: %s%s (Priority: %i)", alias, path, resDir.second.second);

                    g_core->m_CustomResourceDirectoryAliases.emplace_back(resDir.first);

                    Globals::ExoBase()->m_pcExoAliasList->Add(alias, path);
                    Globals::ExoResMan()->CreateDirectory(alias);
                    Globals::ExoResMan()->AddResourceDirectory(alias, resDir.second.second, true);
                }
                else
                    LOG_WARNING("Resource Directory with alias '%s' already exists. Please use nwn.ini to redefine base game resource directories.", alias);
            }
        });
}

void NWNXCore::InitialSetupCommands()
{
    m_services->m_commands->RegisterCommand("runscript", [](std::string&, std::string& args)
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2)
            return;

        if (!args.empty())
        {
            LOG_INFO("Executing console command: 'runscript' with args: %s", args);
            Utils::ExecuteScript(args, 0);
        }
    });

    m_services->m_commands->RegisterCommand("eval", [](std::string&, std::string& args)
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2)
            return;

        if (!args.empty())
        {
            LOG_INFO("Executing console command: 'eval' with args: %s", args);
            bool bWrapIntoMain = args.find("void main()") == std::string::npos;
            if (Globals::VirtualMachine()->RunScriptChunk(args, 0, true, bWrapIntoMain))
            {
                LOG_ERROR("Failed to run console command 'eval' with error: %s", Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
            }
        }
    });

    m_services->m_commands->RegisterCommand("evalx", [](std::string&, std::string& args)
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2)
            return;

        static std::string nwnxHeaders;
        if (nwnxHeaders.empty())
        {
            if (auto *pList = Globals::ExoResMan()->GetResOfType(Constants::ResRefType::NSS, false))
            {
                std::regex rgx("nwnx_[a-z]*");
                for (int i = 0; i < pList->m_nCount; i++)
                {
                    if (std::regex_match(pList->m_pStrings[i]->CStr(), rgx))
                        nwnxHeaders += "#include \"" + std::string(pList->m_pStrings[i]->CStr()) + "\" ";
                }
            }
        }

        if (!args.empty())
        {
            LOG_INFO("Executing console command: 'evalx' with args: %s", args);
            std::string script = nwnxHeaders + (args.find("void main()") == std::string::npos ? "void main() { " + args + " }" : args);
            if (Globals::VirtualMachine()->RunScriptChunk(script, 0, true, false))
            {
                LOG_ERROR("Failed to run console command 'evalx' with error: %s", Globals::VirtualMachine()->m_pJitCompiler->m_sCapturedError.CStr());
            }
        }
    });

    m_services->m_commands->RegisterCommand("loglevel", [](std::string&, std::string& args)
    {
        if (!args.empty())
        {
            size_t space = args.find_first_of(' ');
            std::string plugin = args.substr(0, space);
            std::string level = args.substr(space + 1);

            std::string pluginName = g_core->m_services->m_plugins->GetCanonicalPluginName("NWNX_" + plugin);

            if (!pluginName.empty())
            {
                if (auto logLevel = Utils::from_string<uint32_t>(level))
                {
                    LOG_INFO("Setting log level of plugin '%s' to '%u'", pluginName, *logLevel);
                    Log::SetLogLevel(pluginName.c_str(), static_cast<Log::Channel::Enum>(*logLevel));
                }
                else if (level == plugin) // no level given.
                {
                    LOG_INFO("Log level for %s is %u", pluginName, Log::GetLogLevel(pluginName.c_str()));
                }
                else
                {
                    LOG_INFO("'%s' is not a valid log level", level);
                }
            }
            else
            {
                LOG_INFO("Plugin '%s' is not loaded", plugin);
            }
        }
    });

    m_services->m_commands->RegisterCommand("logformat", [](std::string&, std::string& args)
    {
        if (args.find("timestamp") != std::string::npos)
            Log::SetPrintTimestamp(args.find("notimestamp") == std::string::npos);
        if (args.find("date") != std::string::npos)
            Log::SetPrintDate(args.find("nodate") == std::string::npos);
        if (args.find("plugin") != std::string::npos)
            Log::SetPrintPlugin(args.find("noplugin") == std::string::npos);
        if (args.find("source") != std::string::npos)
            Log::SetPrintSource(args.find("nosource") == std::string::npos);
        if (args.find("color") != std::string::npos)
            Log::SetColorOutput(args.find("nocolor") == std::string::npos);
        if (args.find("force") != std::string::npos)
            Log::SetForceColor(args.find("noforce") == std::string::npos);
        LOG_INFO("Log format updated: Timestamp:%s Date:%s Plugin:%s Source:%s Color:%s Force:%s.",
                 Log::GetPrintTimestamp(), Log::GetPrintDate(), Log::GetPrintPlugin(),
                 Log::GetPrintSource(), Log::GetColorOutput(), Log::GetForceColor());
    });

    m_services->m_commands->RegisterCommand("resolve", [](std::string&, std::string& args)
    {
        auto addr = Utils::from_string<uint64_t>(args);
        if (addr)
            LOG_NOTICE("%s", NWNXLib::Platform::Debug::ResolveAddress(*addr));
    });

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
    const std::string pluginName = Utils::basename(data.m_path);
    try
    {
        m_services->m_plugins->UnloadPlugin(std::forward<Plugins::RegistrationToken>(plugin.first));
        LOG_INFO("Unloaded plugin %d (%s).", pluginId, pluginName);
    }
    catch (const std::runtime_error& err)
    {
        LOG_ERROR("Received error '%s' when unloading plugin %d (%s).", err.what(), pluginId, pluginName);
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

void NWNXCore::CreateServerHandler(CAppManager* app)
{
    InitCrashHandlers();
    g_core->InitialVersionCheck();

    g_core->m_services = g_core->ConstructCoreServices();
    g_core->m_coreServices = g_core->ConstructProxyServices(NWNX_CORE_PLUGIN_NAME);

    // We need to set the NWNXLib log level (separate from Core now) to match the core log level.
    Log::SetLogLevel("NWNXLib", Log::GetLogLevel(NWNX_CORE_PLUGIN_NAME));
    Log::SetPrintTimestamp(g_core->m_coreServices->m_config->Get<bool>("LOG_TIMESTAMP", true));
    Log::SetPrintDate(g_core->m_coreServices->m_config->Get<bool>("LOG_DATE", false));
    Log::SetPrintPlugin(g_core->m_coreServices->m_config->Get<bool>("LOG_PLUGIN", true));
    Log::SetPrintSource(g_core->m_coreServices->m_config->Get<bool>("LOG_SOURCE", true));
    Log::SetColorOutput(g_core->m_coreServices->m_config->Get<bool>("LOG_COLOR", true));
    Log::SetForceColor(g_core->m_coreServices->m_config->Get<bool>("LOG_FORCE_COLOR", false));
    if (g_core->m_coreServices->m_config->Get<bool>("LOG_ASYNC", false))
        Log::SetAsync(g_core->m_services->m_tasks.get());

    if (auto locale = g_core->m_coreServices->m_config->Get<std::string>("LOCALE"))
    {
        Encoding::SetDefaultLocale(*locale);
    }

    auto crashOnAssertFailure = g_core->m_coreServices->m_config->Get<bool>("CRASH_ON_ASSERT_FAILURE");
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
            g_core->InitialSetupResourceDirectories();
            g_core->InitialSetupCommands();
        }
        catch (const std::runtime_error& ex)
        {
            LOG_FATAL("The server encountered a fatal error '%s' during setup and must now terminate.", ex.what());
        }
    }

    g_core->m_createServerHook.reset();
    app->CreateServer();
}

void NWNXCore::DestroyServerHandler(CAppManager* app)
{
    g_CoreShuttingDown = true;

    g_core->m_services->m_messaging->BroadcastMessage("NWNX_CORE_SIGNAL", { "ON_DESTROY_SERVER" });

    if (auto shutdownScript = g_core->m_coreServices->m_config->Get<std::string>("SHUTDOWN_SCRIPT"))
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() == 2)
        {
            LOG_NOTICE("Running module shutdown script: %s", *shutdownScript);
            Utils::ExecuteScript(*shutdownScript, 0);
        }
    }

    auto hook = g_core->m_services->m_hooks->FindHookByAddress(Functions::_ZN11CAppManager13DestroyServerEv);
    hook->CallOriginal<void>(app);

    LOG_NOTICE("Shutting down NWNX.");
    g_core->Shutdown();

    RestoreCrashHandlers();
}

void NWNXCore::MainLoopInternalHandler(bool before, CServerExoAppInternal*)
{
    if (!before)
    {
        return;
    }

    g_core->m_services->m_metrics->Update(g_core->m_services->m_tasks.get());
    g_core->m_services->m_tasks->ProcessWorkOnMainThread();
    g_core->m_services->m_commands->RunScheduledCommands();
}

}
