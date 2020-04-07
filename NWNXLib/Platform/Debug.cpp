#include "Platform/Debug.hpp"
#include <cstring>
#include <cstdio>

#include <execinfo.h>
#include <signal.h>

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
            char backtraceBuffer[2048];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
    }
    return std::string(buffer);
}

static struct {
    uintptr_t address;
    std::string name;
} s_FunctionMap[] =
{
#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNXLIB_FUNCTION(name, address) { address, #name},
#include "API/FunctionsLinux.hpp"
};

using namespace NWNXLib::Platform::Debug;
std::string ResolveAddress(uintptr_t address)
{
    uint32_t best = 0;
    for (uint32_t i = 1; i < sizeof(s_FunctionMap) / sizeof(s_FunctionMap[0]); i++)
    {
        if (address < s_FunctionMap[i].address && s_FunctionMap[best].address > s_FunctionMap[i].address)
            best  = i;
    }

    return s_FunctionMap[best].name;
}

uintptr_t GetFunctionAddress(const std::string& mangledname)
{
    for (uint32_t i = 0; i < sizeof(s_FunctionMap) / sizeof(s_FunctionMap[0]); i++)
    {
        if (s_FunctionMap[i].name == mangledname)
            return s_FunctionMap[i].address;
    }
    return 0;
}


}
