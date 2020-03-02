#include "Services/Commands/Commands.hpp"
#include <stdio.h>
#include <dlfcn.h>

namespace NWNXLib::Services {

static Commands *g_commands;

Commands::Commands()
{
    g_commands = this;
    RegisterCommand("nwnx_commands_test",
            [](std::string& command, std::string& args){ LOG_NOTICE("SelfTest -> Command: '%s', Args: '%s'", command, args); });
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
        LOG_INFO("Registering command '%s'", cmd);
        return true;
    }
    else
    {
        LOG_WARNING("Command '%s' already registered", cmd);
        return false;
    }
}

void Commands::UnregisterCommand(const std::string& cmd)
{
    LOG_INFO("Unregistering command '%s'", cmd);
    m_commandMap.erase(cmd);
}

// This runs on a side thread that processes input.
bool Commands::ScheduleCommand(std::string cmdline)
{
    auto trim = [](std::string &s)
    {
        s.erase(0, s.find_first_not_of(" \n\r\t"));
        s.erase(s.find_last_not_of(" \n\r\t") + 1);
    };

    trim(cmdline);
    std::string cmd, args;
    size_t space = cmdline.find(' ');

    cmd = cmdline.substr(0, space);
    args = (space == std::string::npos) ? "" : cmdline.substr(space, std::string::npos);

    trim(cmd); trim(args);

    std::lock_guard<std::mutex> guard(m_queueLock);
    auto it = m_commandMap.find(cmd);
    if (it != m_commandMap.end())
    {
        m_commandQueue.emplace_back(cmd, args);
        LOG_DEBUG("Scheduled command '%s' with args '%s'", cmd, args);
        return true;
    }

    return false;
}

void Commands::RunScheduledCommands()
{
    std::lock_guard<std::mutex> guard(m_queueLock);
    for (auto item: m_commandQueue)
    {
        LOG_DEBUG("Running command '%s', args: '%s'", item.first, item.second);
        auto it = m_commandMap.find(item.first);
        if (it != m_commandMap.end())
        {
            auto func = it->second;
            func(item.first, item.second);
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
    for (const std::string& cmd : m_RegisteredCommands)
    {
        m_proxyBase.UnregisterCommand(cmd);
    }
}

bool CommandsProxy::RegisterCommand(const std::string& cmd, Commands::CommandFunc func)
{
    if (m_proxyBase.RegisterCommand(cmd, func))
    {
        m_RegisteredCommands.emplace(cmd);
        return true;
    }
    return false;
}

void CommandsProxy::UnregisterCommand(const std::string& cmd)
{
    if (m_RegisteredCommands.find(cmd) != m_RegisteredCommands.end())
    {
        m_proxyBase.UnregisterCommand(cmd);
        m_RegisteredCommands.erase(cmd);
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
