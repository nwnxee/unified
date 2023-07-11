#include "nwnx.hpp"

#include <cstring>

#if !WIN32
#include <signal.h>
#endif

namespace NWNXLib::Assert {


void FailInternal(const char* condition, const char* file, int line, const char* message)
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

    std::string stackTrace = Platform::GetStackTrace(20);
    MessageBus::Broadcast("NWNX_ASSERT_FAIL", { buffer, stackTrace });
    std::strncat(buffer, stackTrace.c_str(), sizeof(buffer)-1);
    std::fputs(buffer, stdout);
    std::fflush(stdout);
    NWNXLib::Log::WriteToLogFile(buffer);

#if !WIN32
    if (Platform::IsDebuggerPresent())
    {
        raise(SIGTRAP);
    }
#endif
}

}
