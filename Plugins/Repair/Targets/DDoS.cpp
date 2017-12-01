#include "Targets/DDoS.hpp"
#include "API/Version.hpp"
#include "Services/Log/Log.hpp"
#include "Services/Metrics/Metrics.hpp"
#include "Services/Metrics/Resamplers.hpp"
#include "Services/Patching/Patching.hpp"
#include "Services/Tasks/Tasks.hpp"

#include <cstring>
#include <sys/types.h>

// Enable the below define if you want to print out all network traffic every second.
// #define PRINT_STATS_NET

#if defined(PRINT_STATS_NET)
#include <arpa/inet.h>
#include <netinet/in.h>

#include <chrono>
#include <unordered_map>
#include <string>
#endif

using namespace NWNXLib;
using namespace API;

namespace Repair {

static bool g_netMetrics;
static bool g_ddosMetrics;

static ViewPtr<Services::MetricsProxy> g_metrics;
static ViewPtr<Services::TasksProxy> g_tasks;
static ViewPtr<Services::LogProxy> g_log;

DDoS::DDoS(bool netMetrics,
    bool ddosMetrics,
    ViewPtr<Services::MetricsProxy> metrics,
    ViewPtr<Services::PatchingProxy> patcher,
    ViewPtr<Services::TasksProxy> tasks,
    ViewPtr<Services::LogProxy> log)
{
    g_netMetrics = netMetrics;
    g_ddosMetrics = ddosMetrics;

    g_metrics = metrics;
    g_tasks = tasks;
    g_log = log;

    patcher->PatchWithCall(0x082C7821, 0x082C7826 - 0x082C7821, &RecvFromPatch); NWNX_EXPECT_VERSION(8109);

    if (g_netMetrics)
    {
        {
            Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Sum<uint32_t>;
            metrics->SetResampler("PacketCount", resampler, std::chrono::seconds(1));
        }

        {
            Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Mean<uint32_t>;
            metrics->SetResampler("PacketLength", resampler, std::chrono::seconds(1));
        }
    }

    if (g_ddosMetrics)
    {
        {
            Services::Resamplers::ResamplerFuncPtr resampler = &Services::Resamplers::template Sum<uint32_t>;
            metrics->SetResampler("PacketDropDDOS", resampler, std::chrono::seconds(1));
        }
    }
}

ssize_t DDoS::RecvFromPatch(int socket, void* buffer, size_t len, int flags, sockaddr* srcAddress, socklen_t* addrLen)
{
    // NOTE: This patch is called from another thread.
    ssize_t received = recvfrom(socket, buffer, len, flags, srcAddress, addrLen);

#if defined(PRINT_STATS_NET)
    static std::unordered_map<std::string, std::pair<uint64_t, uint64_t>> ipMap;
    std::string ip = inet_ntoa((static_cast<sockaddr_in*>(srcAddress))->sin_addr);
    ipMap[ip].first += 1;
    ipMap[ip].second += received;

    using namespace std::chrono;
    static time_point<high_resolution_clock> s_lastUpdate;
    auto now = high_resolution_clock::now();

    if (duration_cast<seconds>(now - s_lastUpdate) >= seconds(1))
    {
        s_lastUpdate = std::move(now);

        g_log->Info("START PACKET DATA");
        for (auto& elem : ipMap)
        {
            g_log->Info("IP: %s ; Packets: %llu ; Bytes: %llu", elem.first.c_str(), elem.second.first, elem.second.second);
        }
        g_log->Info("END PACKET DATA");

        ipMap.clear();
    }
#endif

    if (received != -1)
    {
        if (received >= 4 && std::strncmp(static_cast<char*>(buffer), "HTTP", 4) == 0)
        {
            if (g_ddosMetrics)
            {
                g_tasks->QueueOnMainThread([received]()
                {
                    g_metrics->Push("PacketDropDDOS", { { "Count", "1" } });
                });
            }

            return -1;
        }

        if (g_netMetrics)
        {
            g_tasks->QueueOnMainThread([received]()
            {
                g_metrics->Push("PacketCount", { { "Count", "1" } });
                g_metrics->Push("PacketLength", { { "Length", std::to_string(received) } });
            });
        }
    }

    return received;
}

}
