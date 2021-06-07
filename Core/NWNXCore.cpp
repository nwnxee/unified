#include "nwnx.hpp"
#include "NWNXCore.hpp"

#include "API/CAppManager.hpp"
#include "API/CExoString.hpp"
#include "API/CServerExoApp.hpp"
#include "API/CNWSModule.hpp"
#include "API/CExoLinkedListInternal.hpp"
#include "API/CExoLinkedListNode.hpp"
#include "API/CExoResMan.hpp"
#include "API/CExoBase.hpp"
#include "API/CExoAliasList.hpp"
#include "API/CVirtualMachine.hpp"
#include "API/CExoStringList.hpp"
#include "API/CScriptCompiler.hpp"

#include <csignal>
#include <regex>
#include <dirent.h>
#include <unistd.h>
#include <cstdio>
#include <sstream>

using namespace NWNXLib;
using namespace NWNXLib::API;

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
        case SIGILL:   err = "Illegal instruction";      break;
        default:       err = "Unknown error";            break;
    }

    std::fprintf(stderr, " NWNX Signal Handler:\n"
        "==============================================================\n"
        " NWNX %d.%d (%s) has crashed. Fatal error: %s (%d).\n"
        " Please file a bug at https://github.com/nwnxee/unified/issues\n"
        "==============================================================\n",
        NWNX_TARGET_NWN_BUILD, NWNX_TARGET_NWN_BUILD_REVISION, NWNX_BUILD_SHA, err, sig);

    std::fputs(NWNXLib::Platform::GetStackTrace(20).c_str(), stderr);

    std::fflush(stderr);

    nwn_crash_handler(sig);
}

namespace {

void InitCrashHandlers()
{
    nwn_crash_handler = std::signal(SIGABRT, nwnx_signal_handler);
    std::signal(SIGFPE,  nwnx_signal_handler);
    std::signal(SIGSEGV, nwnx_signal_handler);
    std::signal(SIGILL, nwnx_signal_handler);
}
void RestoreCrashHandlers()
{
    std::signal(SIGABRT, nwn_crash_handler);
    std::signal(SIGFPE,  nwn_crash_handler);
    std::signal(SIGSEGV, nwn_crash_handler);
    std::signal(SIGILL, nwn_crash_handler);
}

}

// TODO: Remove and allow auto-init post-load
namespace NWNXLib::POS { void InitializeHooks(); }
namespace NWNXLib::Tasks {
    void StartAsyncWorkers();
    void StopAsyncWorkers();
}


namespace Core {

static NWNXCore s_core;
NWNXCore* g_core = nullptr; // Used to access the core class in hook or event handlers.
bool g_CoreShuttingDown = false;

NWNXCore::NWNXCore()
    : m_ScriptChunkRecursion(0)
{
    g_core = this;

    // NOTE: We should do the version check here, but the global in the binary hasn't been initialised yet at this point.
    // This will be fixed in a future release of NWNX:EE. For now, the version check will happen *too late* - we may
    // crash before the version check happens.
    std::printf("Starting NWNX %d.%d [%s]\n", NWNX_TARGET_NWN_BUILD, NWNX_TARGET_NWN_BUILD_REVISION, NWNX_BUILD_SHA);
    // This sets up the base address for every hook and patch to follow.
    Platform::CalculateBaseAddress();

    m_createServerHook = Hooks::HookFunction(API::Functions::_ZN11CAppManager12CreateServerEv, (void*)&CreateServerHandler);
}

NWNXCore::~NWNXCore()
{
    Shutdown();
}

std::unique_ptr<Services::ServiceList> NWNXCore::ConstructCoreServices()
{
    using namespace NWNXLib::Services;
    std::unique_ptr<ServiceList> services = std::make_unique<ServiceList>();

    services->m_metrics = std::make_unique<Services::Metrics>();

    return services;
}

std::unique_ptr<Services::ProxyServiceList> NWNXCore::ConstructProxyServices(const std::string& plugin)
{
    std::unique_ptr<Services::ProxyServiceList> proxyServices = std::make_unique<Services::ProxyServiceList>();

    proxyServices->m_metrics = std::make_unique<Services::MetricsProxy>(*m_services->m_metrics, plugin);

    ConfigureLogLevel(plugin);

    return proxyServices;
}

void NWNXCore::ConfigureLogLevel(const std::string& plugin)
{
    // Setup the log level. We do this first by checking if NWNX_<PLUGIN>_LOG_LEVEL is set.
    auto logLevel = Config::Get<uint32_t>("LOG_LEVEL", plugin);

    if (!logLevel)
    {
        // If it is not, then we check if NWNX_CORE_LOG_LEVEL is set.
        logLevel = Config::Get<uint32_t>("LOG_LEVEL");
    }

    if (logLevel)
    {
        Log::SetLogLevel(plugin.c_str(), static_cast<Log::Channel::Enum>(*logLevel));
    }
}


void NWNXCore::InitialSetupHooks()
{
    m_vmSetVarHook         = Hooks::HookFunction(API::Functions::_ZN25CNWVirtualMachineCommands20ExecuteCommandSetVarEii, (void*)&SetVarHandler, Hooks::Order::Final);
    m_vmGetVarHook         = Hooks::HookFunction(API::Functions::_ZN25CNWVirtualMachineCommands20ExecuteCommandGetVarEii, (void*)&GetVarHandler, Hooks::Order::Final);
    m_vmTagEffectHook      = Hooks::HookFunction(API::Functions::_ZN25CNWVirtualMachineCommands23ExecuteCommandTagEffectEii, (void*)&TagEffectHandler, Hooks::Order::Final);
    m_vmTagItemProperyHook = Hooks::HookFunction(API::Functions::_ZN25CNWVirtualMachineCommands29ExecuteCommandTagItemPropertyEii, (void*)&TagItemPropertyHandler, Hooks::Order::Final);
    m_vmPlaySoundHook      = Hooks::HookFunction(API::Functions::_ZN25CNWVirtualMachineCommands23ExecuteCommandPlaySoundEii, (void*)&PlaySoundHandler, Hooks::Order::Final);

    m_destroyServerHook    = Hooks::HookFunction(API::Functions::_ZN11CAppManager13DestroyServerEv, (void*)&DestroyServerHandler, Hooks::Order::Final);
    m_mainLoopInternalHook = Hooks::HookFunction(API::Functions::_ZN21CServerExoAppInternal8MainLoopEv, (void*)&MainLoopInternalHandler, Hooks::Order::Final);

    POS::InitializeHooks();

    static Hooks::Hook loadModuleInProgressHook = Hooks::HookFunction(API::Functions::_ZN10CNWSModule20LoadModuleInProgressEii,
            (void*)+[](CNWSModule *pModule, int32_t nAreasLoaded, int32_t nAreasToLoad) -> uint32_t
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

                return loadModuleInProgressHook->CallOriginal<uint32_t>(pModule, nAreasLoaded, nAreasToLoad);
            }, Hooks::Order::Earliest);

    static Hooks::Hook loadModuleFinishHook = Hooks::HookFunction(
            API::Functions::_ZN10CNWSModule16LoadModuleFinishEv,
            (void*)+[](CNWSModule *pModule) -> uint32_t
            {
                MessageBus::Broadcast("NWNX_CORE_SIGNAL", { "ON_MODULE_LOAD_FINISH" });
                return loadModuleFinishHook->CallOriginal<uint32_t>(pModule);
            }, Hooks::Order::Earliest);

    if (!Config::Get<bool>("ALLOW_NWNX_FUNCTIONS_IN_EXECUTE_SCRIPT_CHUNK", false))
    {
        static Hooks::Hook runScriptChunkHook = Hooks::HookFunction(
                API::Functions::_ZN15CVirtualMachine14RunScriptChunkERK10CExoStringjii,
                (void*)+[](CVirtualMachine *pVirtualMachine, const CExoString& sScriptChunk, ObjectID oid, int32_t bOidValid, int32_t bWrapIntoMain) -> int32_t
                {
                    g_core->m_ScriptChunkRecursion += 1;
                    auto retVal = runScriptChunkHook->CallOriginal<int32_t>(pVirtualMachine, sScriptChunk, oid, bOidValid, bWrapIntoMain);
                    g_core->m_ScriptChunkRecursion -= 1;
                    return retVal;
                }, Hooks::Order::VeryEarly);
    }
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

    const auto pluginDir = Config::Get<std::string>("LOAD_PATH", cwd);
    const bool skipAllPlugins = Config::Get<bool>("SKIP_ALL", false);

    LOG_INFO("Loading plugins from: %s", pluginDir);

    std::vector<std::string> files;
    if (auto dir = opendir(pluginDir.c_str()))
    {
        while (auto entry = readdir(dir))
        {
            if (entry->d_type == DT_UNKNOWN || entry->d_type == DT_REG || entry->d_type == DT_LNK)
            {
                files.emplace_back(entry->d_name);
            }
        }
        closedir(dir);
    }
    // Sort by file name, so at least plugins are loaded in deterministic order.
    std::sort(std::begin(files), std::end(files));

    for (auto& dynamicLibrary : files)
    {
        const std::string& pluginName = dynamicLibrary;
        const std::string pluginNameWithoutExtension = String::Basename(pluginName);

        if (pluginNameWithoutExtension == NWNX_CORE_PLUGIN_NAME || pluginNameWithoutExtension.compare(0, prefix.size(), prefix) != 0)
        {
            continue; // Not a plugin.
        }

        if (pluginNameWithoutExtension == "NWNX_Experimental" && !Config::Get<bool>("LOAD_EXPERIMENTAL_PLUGIN", false))
        {
            continue;
        }

        auto services = ConstructProxyServices(pluginNameWithoutExtension);
        if (Config::Get<bool>("SKIP", (bool)skipAllPlugins, pluginNameWithoutExtension))
        {
            LOG_INFO("Skipping plugin %s due to configuration.", pluginNameWithoutExtension);
            continue;
        }
        Plugin::Load(pluginDir + "/" + pluginName, std::move(services));
    }
}

void NWNXCore::InitialSetupResourceDirectories()
{
    auto nwnxResDirPath = Config::Get<std::string>("NWNX_RESOURCE_DIRECTORY_PATH", Globals::ExoBase()->m_sUserDirectory.CStr() + std::string("/nwnx"));
    auto nwnxResDirPriority = Config::Get<int32_t>("NWNX_RESOURCE_DIRECTORY_PRIORITY", 70000000);

    std::unordered_map<std::string, std::pair<std::string, int32_t>> resourceDirectories;
    resourceDirectories.emplace("NWNX", std::make_pair(nwnxResDirPath, nwnxResDirPriority));

    if (auto customResmanDefinition = Config::Get<std::string>("CUSTOM_RESMAN_DEFINITION"))
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
                    LOG_WARNING("Invalid Custom Resman Definition Line: %s", String::Trim(errorLine));
                }
            }

            std::fclose(file);
        }
        else
            LOG_ERROR("Failed to open Custom Resman Definition File: %s", crdPath);
    }

    Tasks::QueueOnMainThread([resourceDirectories]
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
    Commands::Register("runscript", [](std::string&, std::string& args)
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() != 2)
            return;

        if (!args.empty())
        {
            LOG_INFO("Executing console command: 'runscript' with args: %s", args);
            Utils::ExecuteScript(args, 0);
        }
    });

    Commands::Register("eval", [](std::string&, std::string& args)
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

    Commands::Register("evalx", [](std::string&, std::string& args)
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

    Commands::Register("loglevel", [](std::string&, std::string& args)
    {
        if (!args.empty())
        {
            size_t space = args.find_first_of(' ');
            std::string pluginName = args.substr(0, space);
            std::string level = args.substr(space + 1);

            auto* plugin = Plugin::Find("NWNX_" + pluginName);

            if (plugin)
            {
                if (auto logLevel = String::FromString<uint32_t>(level))
                {
                    LOG_INFO("Setting log level of plugin '%s' to '%u'", plugin->GetName(), *logLevel);
                    Log::SetLogLevel(plugin->GetName().c_str(), static_cast<Log::Channel::Enum>(*logLevel));
                }
                else if (level == pluginName) // no level given.
                {
                    LOG_INFO("Log level for %s is %u", plugin->GetName(), Log::GetLogLevel(plugin->GetName().c_str()));
                }
                else
                {
                    LOG_INFO("'%s' is not a valid log level", level);
                }
            }
            else
            {
                LOG_INFO("Plugin '%s' is not loaded", pluginName);
            }
        }
    });

    Commands::Register("logformat", [](std::string&, std::string& args)
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

    Commands::Register("resolve", [](std::string&, std::string& args)
    {
        auto addr = String::FromString<uint64_t>(args);
        if (addr)
            LOG_NOTICE("%s", NWNXLib::Platform::ResolveAddress(*addr));
    });

}


void NWNXCore::UnloadServices()
{
    m_coreServices.reset();
    m_services.reset();
}

void NWNXCore::Shutdown()
{
    if (g_core)
    {
        Plugin::UnloadAll();
        UnloadServices();
        Tasks::StopAsyncWorkers();
        g_core = nullptr;
        if (Config::Get<bool>("HARD_EXIT", false))
            exit(0);
    }
}

void NWNXCore::CreateServerHandler(CAppManager* app)
{
    InitCrashHandlers();
    g_core->InitialVersionCheck();

    g_core->m_services = g_core->ConstructCoreServices();
    g_core->m_coreServices = g_core->ConstructProxyServices(NWNX_CORE_PLUGIN_NAME);

    // We need to set the NWNXLib log level (separate from Core now) to match the core log level.
    Log::SetLogLevel("NWNXLib", Log::GetLogLevel(NWNX_CORE_PLUGIN_NAME));
    Log::SetPrintTimestamp(Config::Get<bool>("LOG_TIMESTAMP", true));
    Log::SetPrintDate(Config::Get<bool>("LOG_DATE", false));
    Log::SetPrintPlugin(Config::Get<bool>("LOG_PLUGIN", true));
    Log::SetPrintSource(Config::Get<bool>("LOG_SOURCE", true));
    Log::SetColorOutput(Config::Get<bool>("LOG_COLOR", true));
    Log::SetForceColor(Config::Get<bool>("LOG_FORCE_COLOR", false));
    //if (Config::Get<bool>("LOG_ASYNC", false))
    //    Log::SetAsync(g_core->m_services->m_tasks.get());

    if (auto locale = Config::Get<std::string>("LOCALE"))
    {
        String::SetDefaultLocale(*locale);
    }

    if (Config::Get<bool>("SKIP", false))
    {
        LOG_NOTICE("Not loading NWNX due to configuration.");
    }
    else
    {
        LOG_NOTICE("Loading NWNX.");

        try
        {
            Tasks::StartAsyncWorkers();
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

    MessageBus::Broadcast("NWNX_CORE_SIGNAL", { "ON_DESTROY_SERVER" });

    if (auto shutdownScript = Config::Get<std::string>("SHUTDOWN_SCRIPT"))
    {
        if (Globals::AppManager()->m_pServerExoApp->GetServerMode() == 2)
        {
            LOG_NOTICE("Running module shutdown script: %s", *shutdownScript);
            Utils::ExecuteScript(*shutdownScript, 0);
        }
    }

    g_core->m_destroyServerHook.reset();
    app->DestroyServer();
    g_core->Shutdown();

    RestoreCrashHandlers();
}

int32_t NWNXCore::MainLoopInternalHandler(CServerExoAppInternal *pServerExoAppInternal)
{
    g_core->m_services->m_metrics->Update();
    Tasks::ProcessMainThreadWork();
    Commands::RunScheduled();

    return g_core->m_mainLoopInternalHook->CallOriginal<int32_t>(pServerExoAppInternal);
}

}
