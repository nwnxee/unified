#include "Assert.hpp"
#include "Platform/Debug.hpp"

#include <cstdlib>
#include <cstring>


#include <execinfo.h>
#include <signal.h>

namespace NWNXLib::Assert {

static bool crashOnFailure = false;
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

    if (!skipBreak)
    {
        raise(SIGTRAP);
    }

    if (!skipCrash)
    {
        std::abort();
    }
}

}
