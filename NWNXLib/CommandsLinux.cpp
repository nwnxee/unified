#include "nwnx.hpp"
#include <stdio.h>
#include <dlfcn.h>
#include <unordered_map>
#include <deque>
#include <set>
#include <mutex>

namespace NWNXLib::Commands
{

using CommandFunc = std::function<void(std::string&, std::string&)>;

static std::unordered_map<std::string, CommandFunc> s_commandMap;
static std::deque<std::pair<std::string,std::string>> s_commandQueue;
static std::mutex s_queueLock;

bool Register(const std::string& cmd, CommandFunc func)
{
    auto it = s_commandMap.find(cmd);
    if (it == s_commandMap.end())
    {
        s_commandMap[cmd] = func;
        LOG_INFO("Registering command '%s'", cmd);
        return true;
    }
    else
    {
        LOG_WARNING("Command '%s' already registered", cmd);
        return false;
    }
}

void Unregister(const std::string& cmd)
{
    LOG_INFO("Unregistering command '%s'", cmd);
    s_commandMap.erase(cmd);
}

// This runs on a side thread that processes input.
bool Schedule(std::string&& cmdline)
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

    std::lock_guard<std::mutex> guard(s_queueLock);
    auto it = s_commandMap.find(cmd);
    if (it != s_commandMap.end())
    {
        s_commandQueue.emplace_back(cmd, args);
        LOG_DEBUG("Scheduled command '%s' with args '%s'", cmd, args);
        return true;
    }

    return false;
}

void RunScheduled()
{
    std::lock_guard<std::mutex> guard(s_queueLock);
    for (auto item: s_commandQueue)
    {
        LOG_DEBUG("Running command '%s', args: '%s'", item.first, item.second);
        auto it = s_commandMap.find(item.first);
        if (it != s_commandMap.end())
        {
            auto func = it->second;
            func(item.first, item.second);
        }
    }
    s_commandQueue.clear();
}

}


extern "C" char *fgets(char * str, int num, FILE *stream)
{
    using Type = char*(*)(char*,int,FILE*);
    static Type real;
    if (!real)
        real = (Type)NWNXLib::Platform::GetSymbol(RTLD_NEXT, "fgets");

    char *ret = real(str, num, stream);
    if (ret && stream == stdin && num == 1024)
    {
        if (NWNXLib::Commands::Schedule(std::string(str)))
        {
            // Clear command line so server doesn't run it.
            str[0] = '\0';
        }
    }
    return ret;
}
