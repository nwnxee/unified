#include "Time.hpp"

#include "API/CAppManager.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include <chrono>
#include <iomanip>

using namespace NWNXLib;
using namespace NWNXLib::API;

static Time::Time* g_plugin;

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Services::ProxyServiceList* services)
{
    g_plugin = new Time::Time(services);
    return g_plugin;
}


namespace Time {

Time::Time(Services::ProxyServiceList* services)
    : Plugin(services)
{
#define REGISTER(func) \
    GetServices()->m_events->RegisterEvent(#func, \
        [this](ArgumentStack&& args){ return func(std::move(args)); })

    REGISTER(GetSystemDate);
    REGISTER(GetSystemTime);
    REGISTER(GetTimeStamp);
    REGISTER(GetHighResTimeStamp);


#undef REGISTER
}

Time::~Time()
{
}

ArgumentStack Time::GetTimeStamp(ArgumentStack&&)
{
    auto now = std::chrono::system_clock::now();
    auto dur = now.time_since_epoch();

    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(dur).count();

    return Services::Events::Arguments((int)seconds);
}

ArgumentStack Time::GetHighResTimeStamp(ArgumentStack&&)
{
    auto now = std::chrono::system_clock::now();
    auto dur = now.time_since_epoch();

    auto count = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    return Services::Events::Arguments((int32_t)(count / 1000000), (int32_t)(count % 1000000));
}

ArgumentStack Time::GetSystemDate(ArgumentStack&&)
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%m/%d/%Y");

    return Services::Events::Arguments(ss.str());
}

ArgumentStack Time::GetSystemTime(ArgumentStack&&)
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%H:%M:%S");

    return Services::Events::Arguments(ss.str());
}

}
