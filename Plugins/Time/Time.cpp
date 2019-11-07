#include "Time.hpp"

#include "API/CAppManager.hpp"
#include "API/Constants.hpp"
#include "API/Globals.hpp"
#include <chrono>
#include <iomanip>

using namespace NWNXLib;
using namespace NWNXLib::API;

static ViewPtr<Time::Time> g_plugin;

NWNX_PLUGIN_ENTRY Plugin::Info* PluginInfo()
{
    return new Plugin::Info
    {
        "Time",
        "Functions exposing system time information",
        "zunath",
        "coolty3001@yahoo.com",
        1,
        true
    };
}

NWNX_PLUGIN_ENTRY Plugin* PluginLoad(Plugin::CreateParams params)
{
    g_plugin = new Time::Time(params);
    return g_plugin;
}


namespace Time {

Time::Time(const Plugin::CreateParams& params)
    : Plugin(params)
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
    ArgumentStack stack;

    auto now = std::chrono::system_clock::now();
    auto dur = now.time_since_epoch();

    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(dur).count();


    Services::Events::InsertArgument(stack, (int)seconds);
    return stack;
}

ArgumentStack Time::GetHighResTimeStamp(ArgumentStack&&)
{
    ArgumentStack stack;

    auto now = std::chrono::system_clock::now();
    auto dur = now.time_since_epoch();

    auto count = std::chrono::duration_cast<std::chrono::microseconds>(dur).count();

    Services::Events::InsertArgument(stack, (int32_t)(count / 1000000));
    Services::Events::InsertArgument(stack, (int32_t)(count % 1000000));
    return stack;
}

ArgumentStack Time::GetSystemDate(ArgumentStack&&)
{
    ArgumentStack stack;

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%m/%d/%Y");

    Services::Events::InsertArgument(stack, ss.str());
    return stack;
}

ArgumentStack Time::GetSystemTime(ArgumentStack&&)
{
    ArgumentStack stack;

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%H:%M:%S");

    Services::Events::InsertArgument(stack, ss.str());
    return stack;
}

}
