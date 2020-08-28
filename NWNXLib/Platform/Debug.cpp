#include "Platform/Debug.hpp"
#include "Platform/ASLR.hpp"
#include <cstring>
#include <cstdio>

#include <execinfo.h>
#include <signal.h>
#include <map>

namespace NWNXLib::Platform::Debug {

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
            char backtraceBuffer[2048];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            if (std::sscanf(backtraceBuffer, "    ./nwserver-linux(+%lx) [%lx]", &addr, &addr2) == 2)
            {
                std::snprintf(backtraceBuffer, sizeof(backtraceBuffer),
                    "    ./nwserver-linux(%s) [0x%lx]\n", ResolveAddress(addr).c_str(), addr2);
            }
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
    }
    return std::string(buffer);
}

static std::map<uintptr_t, std::string> s_FunctionMap;
using namespace NWNXLib::Platform::Debug;

static void InitFunctionMap()
{
    if (s_FunctionMap.size()) return;

#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNXLIB_FUNCTION(name, address) s_FunctionMap[address] = #name;
#include "API/FunctionsLinux.hpp"
}

std::string ResolveAddress(uintptr_t address)
{
    InitFunctionMap();

    if (address > ASLR::GetRelocatedAddress(0))
        address -= ASLR::GetRelocatedAddress(0);

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
