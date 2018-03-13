#include "Trace.hpp"
#include "Assert.hpp"

#ifdef _WIN32
    #include "Windows.h"
#endif

#include <cstring>
#include <unordered_map>

namespace NWNXLib {

namespace Trace {

void InternalOutputDebugString(const char* str)
{
#ifdef _WIN32
    OutputDebugStringA(str);
#else
    (void)str;
#endif
}

void Trace(Channel::Enum channel, const char* plugin, const char* file, int line, const char* message)
{
    InternalTrace(channel, GetLogLevel(plugin), plugin, file, line, message);
}

void InternalTrace(Channel::Enum channel, Channel::Enum allowedChannel, const char* plugin, const char* file, int line, const char* message)
{
    if (channel > allowedChannel)
    {
        // No need to do anything. Our log level is lower.
        return;
    }

    static constexpr const char * SEVERITY_NAMES[] = { "", "", "F", "E", "W", "N", "I", "D" };

    Platform::Time::Date date = Platform::Time::ConstructDateFromSystemTime();

    // Get filename without the full path.
    const char* filename = file;
    const char* filenameTemp = filename;
    while ((filenameTemp = std::strstr(filename, "/")))
    {
        filename = filenameTemp + 1;
    }

    char buffer[2048];
    std::sprintf(buffer, "%s [%02d:%02d:%02d] [%s:%d] %s: %s\n",
            SEVERITY_NAMES[static_cast<size_t>(channel)],
            date.m_hour, date.m_minute, date.m_second,
            filename, line, plugin, message);

    std::printf(buffer);
    InternalOutputDebugString(buffer);

    if (channel == Channel::SEV_FATAL)
    {
        ASSERT_FAIL();
        std::abort();
    }
}

// Unfortunately this needs to be backed by an std::string rather than a const char* because the C++ standard library
// doesn't provide a hashing function for a const char* and I'm too lazy to write or copy/paste one.
// Small perf hit when logging.
static std::unordered_map<std::string, Channel::Enum> s_LogLevelMap;

Channel::Enum GetLogLevel(const char* plugin)
{
    auto entry = s_LogLevelMap.find(plugin);
    return entry == std::end(s_LogLevelMap) ? Channel::SEV_DEBUG : entry->second;
}

void SetLogLevel(const char* plugin, Channel::Enum logLevel)
{
    s_LogLevelMap[plugin] = logLevel;
}

}

}
