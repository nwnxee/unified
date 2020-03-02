#pragma once

#include "Services/Services.hpp"
#include <string>
#include <unordered_map>
#include <deque>
#include <set>
#include <mutex>

namespace NWNXLib::Services {

class Commands
{
public:
    using CommandFunc = void (*)(std::string& command, std::string& args);

    Commands();
    ~Commands();

    bool RegisterCommand(const std::string& cmd, CommandFunc func);
    void UnregisterCommand(const std::string& cmd);

    bool ScheduleCommand(std::string cmdline);
    void RunScheduledCommands();

private:
    std::unordered_map<std::string, CommandFunc> m_commandMap;
    std::deque<std::pair<std::string,std::string>> m_commandQueue;
    std::mutex m_queueLock;
};

class CommandsProxy : public ServiceProxy<Commands>
{
public:
    CommandsProxy(Commands&);
    ~CommandsProxy();

    bool RegisterCommand(const std::string& cmd, Commands::CommandFunc func);
    void UnregisterCommand(const std::string& cmd);

private:
    std::set<std::string> m_RegisteredCommands;
};

}
