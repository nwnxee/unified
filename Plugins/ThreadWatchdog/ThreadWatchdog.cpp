#include "ThreadWatchdog.hpp"
#include "API/Functions.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Tasks/Tasks.hpp"
#include "Services/Config/Config.hpp"

using namespace NWNXLib;

static ThreadWatchdog::ThreadWatchdog* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new ThreadWatchdog::ThreadWatchdog(services);
    return g_plugin;
}

namespace ThreadWatchdog {

static bool g_exit;
static uint64_t s_mainThreadCounter = 0;
static uint64_t s_watchdogLastObservedCounter = 0;
static uint32_t s_watchdogPeriod;
static uint32_t s_watchdogKillThreshold;

ThreadWatchdog::ThreadWatchdog(Services::ProxyServiceList* services)
    : Plugin(services)
{
    GetServices()->m_hooks->RequestSharedHook<API::Functions::_ZN21CServerExoAppInternal8MainLoopEv, int32_t>(&MainLoopUpdate);

    s_watchdogPeriod = GetServices()->m_config->Get<uint32_t>("PERIOD", 15);
    // Default to effectively infinite
    s_watchdogKillThreshold = GetServices()->m_config->Get<uint32_t>("KILL_THRESHOLD", ~0);

}

ThreadWatchdog::~ThreadWatchdog()
{
    g_exit = true;

    if (m_watchdog)
    {
        m_watchdog->join();
    }
}

void ThreadWatchdog::MainLoopUpdate(bool, CServerExoAppInternal*)
{
    ++s_mainThreadCounter;

    if (!g_plugin->m_watchdog)
    {
        g_exit = false;

        g_plugin->m_watchdog = std::make_unique<std::thread>([]()
        {
            static uint32_t killThreshold = s_watchdogKillThreshold;
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

                    if (--killThreshold == 0)
                    {
                        LOG_FATAL("ThreadWatchdog has detected %d successive LongStalls, and will kill the server, per configuration", s_watchdogKillThreshold);
                    }
                }
                else
                {
                    killThreshold = s_watchdogKillThreshold;
                }

                s_watchdogLastObservedCounter = s_mainThreadCounter;
                std::this_thread::sleep_for(std::chrono::seconds(s_watchdogPeriod));
            }
        });
    }
}

}
