#include "Platform/Debug.hpp"
#include <cstring>
#include <cstdio>

#ifdef _WIN32
    #include "Windows.h"
#else
    #include <execinfo.h>
    #include <signal.h>
#endif

namespace NWNXLib {

namespace Platform {

namespace Debug {

bool IsDebuggerPresent()
{
#ifdef _WIN32
    return ::IsDebuggerPresent();
#else
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
#endif
}

void OutputDebugString(const char *str)
{
#ifdef _WIN32
    OutputDebugStringA(str);
#else
    (void)str;
#endif
}

std::string GetStackTrace(uint8_t levels)
{
    char buffer[2048] = {};
    void* stackTrace[256];

#ifdef _WIN32
    int numCapturedFrames = CaptureStackBackTrace(0, levels, stackTrace, NULL);

    if (numCapturedFrames)
    {
        std::strcat(buffer, "\n  Backtrace:\n");
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            char backtraceBuffer[32];
            std::sprintf(backtraceBuffer, "    [0x%p]\n", stackTrace[i]);
            std::strcat(buffer, backtraceBuffer);
        }
    }
#else
    int numCapturedFrames = backtrace(stackTrace, levels);

    if (numCapturedFrames)
    {
        char** resolvedFrames = backtrace_symbols(stackTrace, levels);
        std::strcat(buffer, "\n  Backtrace:\n");
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            char backtraceBuffer[256];
            std::sprintf(backtraceBuffer, "    %s\n", resolvedFrames[i]);
            std::strcat(buffer, backtraceBuffer);
        }
    }
#endif // _WIN32
    return std::string(buffer);
}

}

}

}
