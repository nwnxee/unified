#include "nwnx.hpp"
#include <cstring>
#include <cstdio>

#include <execinfo.h>
#include <signal.h>
#include <map>

namespace NWNXLib::Platform
{

bool IsDebuggerPresent()
{
    bool present = false;
    char buf[1024] = {};

    FILE *f = fopen("/proc/self/status", "r");
    if (f == NULL)
        return false;

    if (fread(buf, 1, sizeof(buf)-1, f))
    {
        char *tracer_pid = strstr(buf, "TracerPid:");
        if (tracer_pid)
            present = !!atoi(tracer_pid + sizeof("TracerPid:") - 1);
    }
    fclose(f);
    return present;
}

std::string GetStackTrace(uint8_t levels)
{
    char buffer[64*1024];
    void* stackTrace[256];

    buffer[0] = 0;
    int numCapturedFrames = backtrace(stackTrace, levels);

    if (numCapturedFrames)
    {
        char** resolvedFrames = backtrace_symbols(stackTrace, levels);
        std::strncat(buffer, "\n  Backtrace:\n", sizeof(buffer)-1);
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            uintptr_t addr, addr2;
            char path[64];
            char backtraceBuffer[2048];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            if (std::sscanf(backtraceBuffer, "    %63[^(](+%lx) [%lx]", path, &addr, &addr2) == 3)
            {
                std::snprintf(backtraceBuffer, sizeof(backtraceBuffer),
                    "    %s(%s) [0x%lx]\n", path, ResolveAddress(addr).c_str(), addr2);
            }
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
        free(resolvedFrames);
    }
    return std::string(buffer);
}

static std::map<uintptr_t, std::string> s_FunctionMap;
static void InitFunctionMap()
{
    if (s_FunctionMap.size()) return;

#undef NWNXLIB_FUNCTION
#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNXLIB_FUNCTION(name, address) s_FunctionMap[address] = #name;
#include "API/FunctionsLinux.hpp"
#undef NWNXLIB_FUNCTION
}

std::string ResolveAddress(uintptr_t address)
{
    InitFunctionMap();

    if (address > GetRelocatedAddress(0))
        address -= GetRelocatedAddress(0);

    auto it = s_FunctionMap.upper_bound(address);
    if (it != s_FunctionMap.begin())
    {
        --it;
        char offset[64];
        std::snprintf(offset, sizeof(offset), "+0x%lx", address - it->first);
        return it->second + offset;
    }
    return "<UNKNOWN>";
}

uintptr_t GetFunctionAddress(const std::string& mangledname)
{
    InitFunctionMap();
    for (auto it: s_FunctionMap)
    {
        if (it.second == mangledname)
            return it.first;
    }
    return 0;
}


}
