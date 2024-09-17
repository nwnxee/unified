#include "nwnx.hpp"
#include "API/Globals.hpp"
#include "API/CExoBase.hpp"

#include <cstring>
#include <unordered_map>

#include "External/rang/rang.hpp"

namespace NWNXLib::Log {

static bool s_PrintTimestamp;
static bool s_PrintDate;
static bool s_PrintPlugin;
static bool s_PrintSource;
static bool s_ColorOutput;
static bool s_ForceColor;
static std::string s_LogFile;

void SetPrintTimestamp(bool value)
{
    s_PrintTimestamp = value;
}
bool GetPrintTimestamp()
{
    return s_PrintTimestamp;
}
void SetPrintDate(bool value)
{
    s_PrintDate = value;
}
bool GetPrintDate()
{
    return s_PrintDate;
}
void SetPrintPlugin(bool value)
{
    s_PrintPlugin = value;
}
bool GetPrintPlugin()
{
    return s_PrintPlugin;
}
void SetPrintSource(bool value)
{
    s_PrintSource = value;
}
bool GetPrintSource()
{
    return s_PrintSource;
}
void SetColorOutput(bool value)
{
    s_ColorOutput = value;
    rang::setControlMode(s_ColorOutput ? s_ForceColor ? rang::control::Force : rang::control::Auto : rang::control::Off);
}
bool GetColorOutput()
{
    return s_ColorOutput;
}
void SetForceColor(bool value)
{
    s_ForceColor = value;
    rang::setControlMode(s_ColorOutput ? s_ForceColor ? rang::control::Force : rang::control::Auto : rang::control::Off);
}
bool GetForceColor()
{
    return s_ForceColor;
}
void SetLogFile(const std::string& logfilepath)
{
    s_LogFile = logfilepath;
}

void InternalTrace(Channel::Enum channel, Channel::Enum allowedChannel, const char* message)
{
    if (channel > allowedChannel)
    {
        // No need to do anything. Our log level is lower.
        return;
    }

    INSTR_MESSAGE(message, strlen(message));

    switch (channel)
    {
        case Channel::SEV_DEBUG:   std::cout << rang::fg::cyan << rang::style::dim;  break;
        case Channel::SEV_INFO:    std::cout << rang::fg::gray;                      break;
        case Channel::SEV_NOTICE:  /*default*/                                       break;
        case Channel::SEV_WARNING: std::cout << rang::fg::yellow;                    break;
        case Channel::SEV_ERROR:   std::cout << rang::fg::red;                       break;
        case Channel::SEV_FATAL:   std::cout << rang::fg::red << rang::style::bold;  break;
    }
    std::cout << message << rang::style::reset << rang::fg::reset  << std::endl;

    // Also write to a file if configured
    WriteToLogFile(message);

    if (channel == Channel::SEV_FATAL)
    {
        ASSERT_FAIL();
        std::abort();
    }
}

void WriteToLogFile(const char* message)
{
    static FILE* logFile;

    if (!logFile && s_LogFile != "")
    {
        logFile = std::fopen(s_LogFile.c_str(), "a+");
        if (logFile)
        {
            std::fprintf(logFile,
        "=====================================================================\n"
        "       NWNX secondary log file. This log file may be incomplete!     \n"
        " Please attach stdout output instead of this file to any bug reports.\n"
        "=====================================================================\n");
        }
    }
    if (logFile)
    {
        std::fprintf(logFile, "%s\n", message);
        std::fflush(logFile);
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

#include "API/API/CExoString.hpp"
#include "API/API/CResRef.hpp"

std::ostream& operator<<(std::ostream& out, const CExoString& str)
{
    out << str.CStr();
    return out;
}

std::ostream& operator<<(std::ostream& out, const CResRef& str)
{
    out << str.GetResRefStr();
    return out;
}
