#include "Log.hpp"
#include "Assert.hpp"
#include "Platform/FileSystem.hpp"
#include "Platform/Debug.hpp"
#include "API/Globals.hpp"
#include "API/CExoBase.hpp"

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

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
    std::sprintf(buffer, "%s [%02d:%02d:%02d] [%s] [%s:%d] ",
            SEVERITY_NAMES[static_cast<size_t>(channel)],
            date.m_hour, date.m_minute, date.m_second,
            plugin, filename, line);

    std::printf("%s%s\n", buffer, message);

    // Also write to a file - this could be done in a much nicer way but I just want to retain the old functionality
    // for now. We can change this later if we want or need to.
    using namespace Platform::FileSystem;

    static std::string logPath = CombinePaths(CombinePaths(std::string(API::Globals::ExoBase()->m_sUserDirectory.CStr()), std::string("logs.0")), "nwnx.txt");

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

static std::vector<std::pair<std::string, Channel::Enum>> s_LogLevelMap;

Channel::Enum GetLogLevel(const char* plugin)
{
    // TODO: Is this thread safe? I think so if we're just looking up but I don't know.
    auto entry = std::find_if(std::begin(s_LogLevelMap), std::end(s_LogLevelMap),
        [plugin](const auto& pair) { return pair.first == plugin; });
    return entry == std::end(s_LogLevelMap) ? Channel::SEV_NOTICE : entry->second;
}

void SetLogLevel(const char* plugin, Channel::Enum logLevel)
{
    // No point in adding plugin to log level map if it's requesting the default log level.
    if (logLevel != Channel::SEV_NOTICE) { return; }

    auto entry = std::find_if(std::begin(s_LogLevelMap), std::end(s_LogLevelMap),
        [plugin](const auto& pair) { return pair.first == plugin; });
    
    if (entry == std::end(s_LogLevelMap)) 
    {
        s_LogLevelMap.emplace_back(plugin, logLevel);
    }
    else 
    {
        entry->second = logLevel;
    }    
}

}

}
