#include "Log.hpp"
#include "Assert.hpp"
#include "Platform/Debug.hpp"
#include "API/Globals.hpp"
#include "API/CExoBase.hpp"

#include <cstring>
#include <unordered_map>

namespace NWNXLib {

namespace Log {

void InternalTrace(Channel::Enum channel, Channel::Enum allowedChannel, const char* message)
{
    if (channel > allowedChannel)
    {
        // No need to do anything. Our log level is lower.
        return;
    }

    std::printf("%s\n", message);

    // Also write to a file - this could be done in a much nicer way but I just want to retain the old functionality
    // for now. We can change this later if we want or need to.

    static std::string logPath = API::Globals::ExoBase()->m_sUserDirectory.CStr() + std::string("/logs.0/nwnx.txt");
    static FILE* logFile = std::fopen(logPath.c_str(), "a+");

    if (logFile)
    {
        std::fprintf(logFile, "%s\n", message);
        std::fflush(logFile);
    }

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

#include "API/API/CExoString.hpp"
#include "API/API/CResRef.hpp"

std::ostream& operator<<(std::ostream& out, const CExoString& str)
{
    out << str.m_sString;
    return out;
}

std::ostream& operator<<(std::ostream& out, const CResRef& str)
{
    char buffer[17] = {0};
    std::memcpy(buffer, str.m_resRefLowerCase, 16);
    out << buffer;
    return out;
}
