#include "ThreadWatchdog.hpp"
#include "API/Functions.hpp"
#include "API/Version.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "ViewPtr.hpp"

using namespace NWNXLib;

static ViewPtr<ThreadWatchdog::ThreadWatchdog> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "ThreadWatchdog",
        "TODO",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new ThreadWatchdog::ThreadWatchdog(params);
    return g_plugin;
}

namespace ThreadWatchdog {

static bool g_exit;
static uint64_t s_mainThreadCounter = 0;
static uint64_t s_watchdogLastObservedCounter = 0;

ThreadWatchdog::ThreadWatchdog(const Plugin::CreateParams& params)
    : Plugin(params)
{
    GetServices()->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopUpdate);
}

ThreadWatchdog::~ThreadWatchdog()
{
    g_exit = true;

    if (m_watchdog)
    {
        m_watchdog->join();
    }
}

void ThreadWatchdog::MainLoopUpdate(Services::Hooks::CallType, API::CServerExoAppInternal*)
{
    ++s_mainThreadCounter;

    if (!g_plugin->m_watchdog)
    {
        g_exit = false;

        g_plugin->m_watchdog = std::make_unique<std::thread>([]()
        {
            while (!g_exit)
            {
                if (s_mainThreadCounter == s_watchdogLastObservedCounter)
                {
                    // At this point, BAD things have happened.
                    // We've been in a stall from anywhere between 15-30 seconds.
                    // On the bright side, the main thread is fucked, so we probably don't need to worry about that.
                    // We have to do a few things here.

                    // First, we write to the log.
                    LOG_WARNING("ThreadWatchdog detected a LongStall.");

                    // Next we push a metric indicating that a long stall has been detected.
                    g_plugin->GetServices()->m_metrics->Push("LongStall", { { "Count", "1" } });

                    // Now that metric is sitting in some big array, waiting for the main thread to process it.
                    // We're going to pretend to be the main thread.
                    Services::Metrics* metrics = g_plugin->GetServices()->m_metrics->GetProxyBase();
                    Services::Tasks* tasks = g_plugin->GetServices()->m_tasks->GetProxyBase();
                    metrics->Update(tasks);

                    // Finally, we're going to pump the main thread task queue, so we don't accumulate a gazillion
                    // tasks, and so we remain productive until somebody can come along and figure out why we've
                    // hit a long stall.
                    tasks->ProcessWorkOnMainThread();
                }

                s_watchdogLastObservedCounter = s_mainThreadCounter;
                std::this_thread::sleep_for(std::chrono::seconds(15));
            }
        });
    }
}

}
