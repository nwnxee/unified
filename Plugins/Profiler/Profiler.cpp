#include "Profiler.hpp"

#include "API/Functions.hpp"
#include "Common.hpp"
#include "ProfilerMacros.hpp"
#include "Services/Config/Config.hpp"
#include "Services/Hooks/Hooks.hpp"
#include "Services/Messaging/Messaging.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Metrics/Resamplers.hpp"
#include "Targets/AIMasterUpdates.hpp"
#include "Targets/MainLoop.hpp"
#include "Targets/NetLayer.hpp"
#include "Targets/NetMessages.hpp"
#include "Targets/ObjectAIUpdates.hpp"
#include "Targets/ObjectEventHandlers.hpp"
#include "Targets/Pathing.hpp"
#include "Targets/Scripts.hpp"
#include "Timing.hpp"
#include "ViewPtr.hpp"

#include <queue>

using namespace NWNXLib;

static ViewPtr<Profiler::Profiler> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Profiler",
        "Acquires shared hooks to expose various useful metrics.",
        "Liareth",
        "liarethnwn@gmail.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Profiler::Profiler(params);
    return g_plugin;
}

namespace Profiler {

static ViewPtr<Services::HooksProxy> g_hooks;
static ViewPtr<Services::MetricsProxy> g_metrics;

static size_t g_calibrationRuns;
static std::chrono::milliseconds g_recalibrationPeriod;

static bool g_recalibrate = false;
static bool g_tickrate = false;

Profiler::Profiler(const Plugin::CreateParams& params)
    : Plugin(params)
{
    g_hooks = GetServices()->m_hooks.get();
    g_metrics = GetServices()->m_metrics.get();

    auto config = GetServices()->m_config.get();

    if (config->Get<bool>("ENABLE_OVERHEAD_COMPENSATION", true))
    {
        auto forcedOverhead = GetServices()->m_config->Get<int64_t>("OVERHEAD_COMPENSTION_FORCE");

        if (forcedOverhead)
        {
            FastTimer::PrepareForCalibration(std::chrono::nanoseconds(forcedOverhead.Extract()));
        }
        else
        {
            FastTimer::PrepareForCalibration();
            g_calibrationRuns = GetServices()->m_config->Get<size_t>("OVERHEAD_COMPENSATION_RUNS", 500);
            FastTimer::Calibrate(g_calibrationRuns, GetServices()->m_hooks.get(), GetServices()->m_metrics.get());
        }

        g_recalibrate = config->Get<bool>("OVERHEAD_COMPENSATION_RECALIBRATE", false);

        if (g_recalibrate)
        {
            g_recalibrationPeriod = std::chrono::milliseconds(config->Get<uint32_t>("OVERHEAD_COMPENSATION_RECALIBRATION_PERIOD", 1000));
        }
    }

    if (config->Get<bool>("ENABLE_AI_MASTER_UPDATES", true))
    {
        const bool overkillMode = config->Get<bool>("AI_MASTER_UPDATES_OVERKILL", false);
        m_aiMasterUpdates = std::make_unique<AIMasterUpdates>(overkillMode, GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_MAIN_LOOP", true))
    {
        m_mainLoop = std::make_unique<MainLoop>(GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_NET_LAYER", true))
    {
        m_netLayer = std::make_unique<NetLayer>(GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_NET_MESSAGES", true))
    {
        m_netMessages = std::make_unique<NetMessages>(GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_OBJECT_AI_UPDATES", false))
    {
        m_objectAIUpdates = std::make_unique<ObjectAIUpdates>(GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_OBJECT_EVENT_HANDLERS", false))
    {
        m_objectEventHandlers = std::make_unique<ObjectEventHandlers>(GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_PATHING", true))
    {
        m_pathing = std::make_unique<Pathing>(GetServices()->m_hooks, g_metrics);
    }

    if (config->Get<bool>("ENABLE_SCRIPTS", true))
    {
        const bool areaTimings = config->Get<bool>("SCRIPTS_AREA_TIMINGS", true);
        const bool typeTimings = config->Get<bool>("SCRIPTS_TYPE_TIMINGS", true);
        m_scripts = std::make_unique<Scripts>(areaTimings, typeTimings, GetServices()->m_hooks, g_metrics);
    }

    g_tickrate = config->Get<bool>("ENABLE_TICKRATE", true);

    if (g_tickrate)
    {
        Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Mean<uint32_t>;
        GetServices()->m_metrics->SetResampler("GameTickRate", resampler, std::chrono::seconds(1));
    }

    if (g_recalibrate || g_tickrate)
    {
        GetServices()->m_hooks->RequestSharedHook<API::Functions::CServerExoAppInternal__MainLoop, int32_t>(&MainLoopUpdate);
    }

    // Resamples all of the automated timing data.
    Services::Resamplers::ResamplerFuncPtr sum = &Services::Resamplers::template Sum<int64_t>;
    GetServices()->m_metrics->SetResampler("TimingEvent", sum, std::chrono::seconds(1));

    {
        GetServices()->m_messaging->SubscribeMessage("NWNX_PROFILER_SET_PERF_SCOPE_RESAMPLER",
            [this, sum](const std::vector<std::string> message)
            {
                ASSERT(message.size() == 1);
                GetServices()->m_metrics->SetResampler(message[0], sum, std::chrono::seconds(1));
            });

        static FastTimerScope* s_timerScope;

        GetServices()->m_messaging->SubscribeMessage("NWNX_PROFILER_PUSH_PERF_SCOPE",
            [this](const std::vector<std::string> message)
            {
                ASSERT(!s_timerScope);
                ASSERT(message.size() >= 1);
                ASSERT(message.size() % 2 == 1);

                std::string name = message[0];
                NWNXLib::Services::MetricData::Tags tags;

                for (size_t i = 1; i < message.size(); i += 2)
                {
                    tags.push_back(std::make_pair(message[i], message[i+1]));
                }

                s_timerScope = new FastTimerScope(*GetServices()->m_metrics, std::move(name), std::move(tags));
            });

        GetServices()->m_messaging->SubscribeMessage("NWNX_PROFILER_POP_PERF_SCOPE",
            [](const std::vector<std::string>)
            {
                ASSERT(s_timerScope);
                delete s_timerScope;
                s_timerScope = nullptr;
            });
    }
}

Profiler::~Profiler()
{
}

void Profiler::HandleTickrateReporting(const std::chrono::time_point<std::chrono::high_resolution_clock>& now)
{
    using namespace std::chrono;
    static std::queue<time_point<high_resolution_clock>> s_frameTimes;

    while (!s_frameTimes.empty() && duration_cast<seconds>(now - s_frameTimes.front()) >= seconds(1))
    {
        s_frameTimes.pop();
    }

    s_frameTimes.push(now);
    g_metrics->Push("GameTickRate", { { "Count", std::to_string(s_frameTimes.size()) } });
}

void Profiler::HandleRecalibration(const std::chrono::time_point<std::chrono::high_resolution_clock>& now)
{
    using namespace std::chrono;
    static time_point<high_resolution_clock> s_lastUpdate;

    if (duration_cast<milliseconds>(now - s_lastUpdate) >= g_recalibrationPeriod)
    {
        s_lastUpdate = now;

        //FastTimer::PrepareForCalibration();
        // We don't call the above function here because the goal is to "home in" on the lowest possible overhead value as the game progresses.
        // This will just run the test again and and, if a lower result is made available, it will use it.

        FastTimer::Calibrate(g_calibrationRuns, g_hooks, g_metrics);
    }
}

void Profiler::MainLoopUpdate(Services::Hooks::CallType type, API::CServerExoAppInternal*)
{
    if (type != Services::Hooks::CallType::BEFORE_ORIGINAL)
    {
        return;
    }

    auto now = std::chrono::high_resolution_clock::now();

    if (g_recalibrate)
    {
        HandleRecalibration(now);
    }

    if (g_tickrate)
    {
        HandleTickrateReporting(now);
    }
}

}
