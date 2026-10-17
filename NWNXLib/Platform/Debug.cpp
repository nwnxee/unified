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
    // Nothing large on the stack: this runs from signal handlers, which can be on a small alternate
    // stack - the .NET runtime runs the chained SIGSEGV handler on one after a stack overflow - and a
    // 64 KB frame faulted there before anything was printed.
    void* stackTrace[256];
    std::string trace;

    int numCapturedFrames = backtrace(stackTrace, levels);
    if (numCapturedFrames > 0)
    {
        char** resolvedFrames = backtrace_symbols(stackTrace, numCapturedFrames);
        trace = "\n  Backtrace:\n";
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            trace += "    ";
            trace += resolvedFrames ? resolvedFrames[i] : "?";
            trace += "\n";
        }
        free(resolvedFrames);
    }
    return trace;
}

}
