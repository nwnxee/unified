#include "Assert.hpp"

#include <cstdlib>
#include <cstring>

#ifdef _WIN32
    #include "Windows.h"
#else
    #include <execinfo.h>
    #include <signal.h>
#endif

namespace NWNXLib {

namespace Assert {

void Fail(const char* condition, const char* file, int line, const char* message)
{
    char buffer[2048];

    if (condition)
    {
        std::sprintf(buffer, "ASSERTION FAILURE\n  Summary: (%s) failed at (%s:%d)", condition, file, line);
    }
    else
    {
        std::sprintf(buffer, "ASSERTION FAILURE\n  Summary: Failed at (%s:%d)", file, line);
    }

    if (message)
    {
        std::strcat(buffer, "\n  Message: ");
        std::strcat(buffer, message);
    }

#ifdef _WIN32
    void* stackTrace[20];
    int numCapturedFrames = CaptureStackBackTrace(0, 20, stackTrace, NULL);

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
    void* stackTrace[20];
    int numCapturedFrames = backtrace(stackTrace, 20);

    if (numCapturedFrames)
    {
        char** resolvedFrames = backtrace_symbols(stackTrace, 20);
        std::strcat(buffer, "\n  Backtrace:\n");
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            char backtraceBuffer[256];
            std::sprintf(backtraceBuffer, "    %s\n", resolvedFrames[i]);
            std::strcat(buffer, backtraceBuffer);
        }
    }
#endif // _WIN32

    std::fprintf(stderr, buffer);
    std::fflush(stderr);

    bool skipCrash = false;
    bool skipBreak = false;

#ifdef _WIN32
    int response = MessageBox(GetActiveWindow(), buffer, "ASSERTION FAILURE", MB_ABORTRETRYIGNORE);

    switch (response)
    {
    case IDRETRY: // No crash, but break.
        skipCrash = true;
        break;

    case IDIGNORE: // No crash or break.
        skipCrash = true;
        skipBreak = true;
        break;

    case IDABORT:
    default: // Crash and break
        break;
    }
#endif // _WIN32

    if (!skipBreak)
    {
#ifdef _WIN32
        __debugbreak();
#else
        raise(SIGTRAP);
#endif
    }

    if (!skipCrash)
    {
        std::abort();
    }
}

}

}
