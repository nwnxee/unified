#include "Log.hpp"
#include "Assert.hpp"
#include "Platform/FileSystem.hpp"
#include "Platform/Debug.hpp"


#include <cstring>
#include <unordered_map>

namespace NWNXLib {

namespace Log {


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
    std::sprintf(buffer, "%s [%02d:%02d:%02d] [%s:%d] %s: ",
            SEVERITY_NAMES[static_cast<size_t>(channel)],
            date.m_hour, date.m_minute, date.m_second,
            filename, line, plugin);

    std::printf("%s%s\n", buffer, message);

    // Also write to a file - this could be done in a much nicer way but I just want to retain the old functionality
    // for now. We can change this later if we want or need to.
    using namespace Platform::FileSystem;

    // TODO: This needs to grab the userdirectory and write it there. Doing this is not correct.
    static std::string logPath = CombinePaths(CombinePaths(GetCurExecutablePath(), std::string("logs.0")), "nwnx.txt");

    // TODO: Is this thread safe? This needs to be thread safe
    FILE* logFile = std::fopen(logPath.c_str(), "a+");

    if (logFile)
    {
        std::fprintf(logFile, "%s%s\n", buffer, message);
        std::fclose(logFile);
    }

    Platform::Debug::OutputDebugString(buffer);
    Platform::Debug::OutputDebugString(message);
    Platform::Debug::OutputDebugString("\n");

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
    // TODO: Is this thread safe? I think so if we're just looking up but I don't know.
    auto entry = s_LogLevelMap.find(plugin);
    return entry == std::end(s_LogLevelMap) ? Channel::SEV_NOTICE : entry->second;
}

void SetLogLevel(const char* plugin, Channel::Enum logLevel)
{
    s_LogLevelMap[plugin] = logLevel;
}

}

}
