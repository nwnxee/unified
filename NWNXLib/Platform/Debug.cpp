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
            char backtraceBuffer[2048];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
        free(resolvedFrames);
    }
    return std::string(buffer);
}

}
