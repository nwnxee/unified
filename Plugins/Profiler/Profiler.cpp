#include "Profiler.hpp"

#include "API/Functions.hpp"
#include "ProfilerMacros.hpp"
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

#include <queue>
#include <stack>

using namespace NWNXLib;

static Profiler::Profiler* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Profiler::Profiler(services);
    return g_plugin;
}

namespace Profiler {

static Services::MetricsProxy* g_metrics;

static size_t g_calibrationRuns;
static std::chrono::milliseconds g_recalibrationPeriod;

static bool g_recalibrate = false;
static bool g_tickrate = false;

static Hooks::Hook s_MainLoopHook;

Profiler::Profiler(Services::ProxyServiceList* services)
    : Plugin(services)
{
    g_metrics = GetServices()->m_metrics.get();

    if (Config::Get<bool>("ENABLE_OVERHEAD_COMPENSATION", true))
    {
        auto forcedOverhead = Config::Get<int64_t>("OVERHEAD_COMPENSATION_FORCE");

        if (forcedOverhead)
        {
            FastTimer::PrepareForCalibration(std::chrono::nanoseconds(forcedOverhead.value()));
        }
        else
        {
            FastTimer::PrepareForCalibration();
            g_calibrationRuns = Config::Get<size_t>("OVERHEAD_COMPENSATION_RUNS", 500);
            FastTimer::Calibrate(g_calibrationRuns, GetServices()->m_metrics.get());
        }

        g_recalibrate = Config::Get<bool>("OVERHEAD_COMPENSATION_RECALIBRATE", false);

        if (g_recalibrate)
        {
            g_recalibrationPeriod = std::chrono::milliseconds(Config::Get<uint32_t>("OVERHEAD_COMPENSATION_RECALIBRATION_PERIOD", 1000));
        }
    }

    if (Config::Get<bool>("ENABLE_AI_MASTER_UPDATES", true))
    {
        const bool overkillMode = Config::Get<bool>("AI_MASTER_UPDATES_OVERKILL", false);
        m_aiMasterUpdates = std::make_unique<AIMasterUpdates>(overkillMode, g_metrics);
    }

    if (Config::Get<bool>("ENABLE_MAIN_LOOP", true))
    {
        m_mainLoop = std::make_unique<MainLoop>(g_metrics);
    }

    if (Config::Get<bool>("ENABLE_NET_LAYER", true))
    {
        m_netLayer = std::make_unique<NetLayer>(g_metrics);
    }

    if (Config::Get<bool>("ENABLE_NET_MESSAGES", true))
    {
        m_netMessages = std::make_unique<NetMessages>(g_metrics);
    }

    if (Config::Get<bool>("ENABLE_OBJECT_AI_UPDATES", false))
    {
        m_objectAIUpdates = std::make_unique<ObjectAIUpdates>(g_metrics);
    }

    if (Config::Get<bool>("ENABLE_OBJECT_EVENT_HANDLERS", false))
    {
        m_objectEventHandlers = std::make_unique<ObjectEventHandlers>(g_metrics);
    }

    if (Config::Get<bool>("ENABLE_PATHING", true))
    {
        m_pathing = std::make_unique<Pathing>(g_metrics);
    }

    if (Config::Get<bool>("ENABLE_SCRIPTS", true))
    {
        const bool areaTimings = Config::Get<bool>("SCRIPTS_AREA_TIMINGS", true);
        const bool typeTimings = Config::Get<bool>("SCRIPTS_TYPE_TIMINGS", true);
        m_scripts = std::make_unique<Scripts>(areaTimings, typeTimings, g_metrics);
    }

    g_tickrate = Config::Get<bool>("ENABLE_TICKRATE", true);

    if (g_tickrate)
    {
        Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Mean<uint32_t>;
        GetServices()->m_metrics->SetResampler("GameTickRate", resampler, std::chrono::seconds(1));
    }

    if (g_recalibrate || g_tickrate)
    {
        s_MainLoopHook = Hooks::HookFunction(API::Functions::_ZN21CServerExoAppInternal8MainLoopEv,
                                                      (void*)&MainLoopUpdate, Hooks::Order::Earliest);
    }

    // Resamples all of the automated timing data.
    Services::Resamplers::ResamplerFuncPtr sum = &Services::Resamplers::template Sum<int64_t>;
    GetServices()->m_metrics->SetResampler("TimingEvent", sum, std::chrono::seconds(1));

    {
        MessageBus::Subscribe("NWNX_PROFILER_SET_PERF_SCOPE_RESAMPLER",
        [this, sum](const std::vector<std::string>& message)
        {
            ASSERT(message.size() == 1);
            SetPerfScopeResampler(message[0]);
        });

        MessageBus::Subscribe("NWNX_PROFILER_PUSH_PERF_SCOPE",
            [this](const std::vector<std::string>& message)
            {
                ASSERT(message.size() >= 1);
                ASSERT(message.size() % 2 == 1);

                std::string name = message[0];
                NWNXLib::Services::MetricData::Tags tags;

                for (size_t i = 1; i < message.size(); i += 2)
                {
                    tags.push_back(std::make_pair(message[i], message[i+1]));
                }

                PushPerfScope(std::move(name), std::move(tags));
            });

        MessageBus::Subscribe("NWNX_PROFILER_POP_PERF_SCOPE",
            [this](const std::vector<std::string>&)
            {
                PopPerfScope();
            });
    }

    Events::RegisterEvent(GetName(), "PushPerfScope",
        [this](Events::ArgumentStack&& args)
        {
            std::string scopeName = Events::ExtractArgument<std::string>(args);

            NWNXLib::Services::MetricData::Tags tags;

            while (!args.empty())
            {
                ASSERT(args.size() >= 2);
                std::string tag = Events::ExtractArgument<std::string>(args);
                std::string value = Events::ExtractArgument<std::string>(args);
                tags.emplace_back(std::make_pair(std::move(tag), std::move(value)));
            }

            PushPerfScope(std::move(scopeName), std::move(tags));
            return Events::Arguments();
        });


    Events::RegisterEvent(GetName(), "PopPerfScope",
        [this](Events::ArgumentStack&&)
        {
            PopPerfScope();
            return Events::Arguments();
        });
}

void Profiler::SetPerfScopeResampler(const std::string& name)
{
    Services::Resamplers::ResamplerFuncPtr sum = &Services::Resamplers::template Sum<int64_t>;
    GetServices()->m_metrics->SetResampler(name, sum, std::chrono::seconds(1));
}

static std::stack<FastTimerScope*> s_timerScope;

void Profiler::PushPerfScope(std::string&& name, NWNXLib::Services::MetricData::Tags&& tags)
{
    s_timerScope.emplace(new FastTimerScope(*GetServices()->m_metrics, std::move(name), std::move(tags)));
}

void Profiler::PopPerfScope()
{
    delete s_timerScope.top();
    s_timerScope.pop();
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

        FastTimer::Calibrate(g_calibrationRuns, g_metrics);
    }
}

int32_t Profiler::MainLoopUpdate(CServerExoAppInternal *thisPtr)
{
    auto now = std::chrono::high_resolution_clock::now();

    if (g_recalibrate)
    {
        HandleRecalibration(now);
    }

    if (g_tickrate)
    {
        HandleTickrateReporting(now);
    }

    return s_MainLoopHook->CallOriginal<int32_t>(thisPtr);
}

}
