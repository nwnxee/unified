#include "Assert.hpp"
#include "Platform/Debug.hpp"

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

#if TAR_DEBUG && !TAR_RELEASE
static bool crashOnFailure = true;
#else
static bool crashOnFailure = false;
#endif

void SetCrashOnFailure(bool crash)
{
    crashOnFailure = crash;
}

void Fail(const char* condition, const char* file, int line, const char* message)
{
    char buffer[64*1024];

    if (condition)
    {
        std::snprintf(buffer, sizeof(buffer), "ASSERTION FAILURE\n  Summary: (%s) failed at (%s:%d)", condition, file, line);
    }
    else
    {
        std::snprintf(buffer, sizeof(buffer), "ASSERTION FAILURE\n  Summary: Failed at (%s:%d)", file, line);
    }

    if (message)
    {
        std::strncat(buffer, "\n  Message: ", sizeof(buffer)-1);
        std::strncat(buffer, message, sizeof(buffer)-1);
    }

    std::strncat(buffer, Platform::Debug::GetStackTrace(20).c_str(), sizeof(buffer)-1);
    std::fputs(buffer, stderr);
    std::fflush(stderr);

    bool skipCrash = !crashOnFailure;
    bool skipBreak = !Platform::Debug::IsDebuggerPresent();

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
