#pragma once

#include <string>
#include <functional>

namespace NWNXLib {

class Commands
{
public:
    using CommandFunc = std::function<void(std::string&, std::string&)>;

    static bool RegisterCommand(const std::string& cmd, CommandFunc func);
    static void UnregisterCommand(const std::string& cmd);

    static bool ScheduleCommand(std::string&& cmdline);
    static void RunScheduledCommands();
};

}
