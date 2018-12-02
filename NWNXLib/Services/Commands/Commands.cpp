#include "Services/Commands/Commands.hpp"
#include <stdio.h>
#include <dlfcn.h>

namespace NWNXLib {
namespace Services {

static Commands *g_commands;

Commands::Commands()
{
    g_commands = this;
    RegisterCommand("nwnx_commands_test", [](std::string& s){ LOG_NOTICE("Selftest command. Args: '%s'", s.c_str()); });
}

Commands::~Commands()
{
    g_commands = nullptr;

}

bool Commands::RegisterCommand(const std::string& cmd, CommandFunc func)
{
    auto it = m_commandMap.find(cmd);
    if (it == m_commandMap.end())
    {
        m_commandMap[cmd] = func;
        LOG_INFO("Registering command '%s'", cmd.c_str());
        return true;
    }
    else
    {
        LOG_WARNING("Command '%s' already registered", cmd.c_str());
        return false;
    }
}

void Commands::UnregisterCommand(const std::string& cmd)
{
    LOG_INFO("Unregistering command '%s'", cmd.c_str());
    m_commandMap.erase(cmd);
}

bool Commands::ScheduleCommand(const std::string& cmdline)
{
    std::string cmd, args;
    size_t space = cmdline.find(' ');

    if (space == std::string::npos) // No args
    {
        cmd = cmdline.substr(0, cmdline.length() - 1);
        args = "";
    }
    else
    {
        cmd = cmdline.substr(0, space);
        args = cmdline.substr(space+1, cmdline.length()-space-2);
    }

    auto it = m_commandMap.find(cmd);
    if (it != m_commandMap.end())
    {
        std::lock_guard<std::mutex> guard(m_queueLock);
        m_commandQueue.push_back(std::make_pair(cmd, args));
        LOG_DEBUG("Scheduled command '%s' with args '%s'", cmd.c_str(), args.c_str());
        return true;
    }

    return false;
}

void Commands::RunScheduledCommands()
{
    std::lock_guard<std::mutex> guard(m_queueLock);
    for (auto item: m_commandQueue)
    {
        LOG_DEBUG("Running command '%s', args: '%s'", item.first.c_str(), item.second.c_str());
        auto it = m_commandMap.find(item.first);
        if (it != m_commandMap.end())
        {
            auto func = it->second;
            func(item.second);
        }
    }
    m_commandQueue.clear();
}


CommandsProxy::CommandsProxy(Commands& commands)
    : ServiceProxy<Commands>(commands)
{
}
CommandsProxy::~CommandsProxy()
{
}


bool CommandsProxy::RegisterCommand(const std::string& cmd, Commands::CommandFunc func)
{
    return m_proxyBase.RegisterCommand(cmd, func);
}
void CommandsProxy::UnregisterCommand(const std::string& cmd)
{
    m_proxyBase.UnregisterCommand(cmd);
}

}
}


extern "C" char *fgets(char * str, int num, FILE *stream)
{
    using Type = char*(*)(char*,int,FILE*);
    static Type real;
    if (!real)
        real = (Type)dlsym(RTLD_NEXT, "fgets");

    char *ret = real(str, num, stream);
    if (ret && stream == stdin && num == 1024 && NWNXLib::Services::g_commands)
    {
        if (NWNXLib::Services::g_commands->ScheduleCommand(std::string(str)))
        {
            // Clear command line so server doesn't run it.
            str[0] = '\0';
        }
    }
    return ret;
}
