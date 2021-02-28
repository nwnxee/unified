#pragma once

#include "External/tinyformat/tinyformat.hpp"
#include <cstdio>
#include <cstring>
#include <sstream>
#include <ctime>

namespace NWNXLib::Log {

#define LOG_IMPL(sev, format, ...) \
    ::NWNXLib::Log::Trace(::NWNXLib::Log::Channel::sev, PLUGIN_NAME, __FILE__, __LINE__, (format), ##__VA_ARGS__)

struct Channel
{
    enum Enum
    {
        // N.B.: Do not change the enum consts. They map to syslog severities.

        // Debug messages are mainly of use to the developer of a plugin.
        // They should be excessively verbose and should be turned off on production.
        SEV_DEBUG = 7,

        // Info messages are "informational". They contain operational information
        // that will be useful to server admins to see what is happening and can
        // be used to trace events after the fact.
        // These should be very low-volume.
        // This is the default log level for all sources.
        SEV_INFO = 6,

        // This is very similar to INFO, but implies that you want to *notice*
        // the event. This usually means aggregating logs somewhere and mailing
        // them out to you in a timely manner.
        SEV_NOTICE = 5,

        // Warnings are operational issues with the server, the codebase, or
        // the data that could potentially result in ERROR later on, but do not
        // impact the system yet in such a way that users would notice.
        SEV_WARNING = 4,

        // Errors imply user inpact or data loss; for example non-idempotent
        // operations failing. Errors can be recovered from but impact the user.
        SEV_ERROR = 3,

        // Fatals are unrecoverable errors. Use this log message when you want
        // to stop the world. Log messages to FATAL will never return.
        SEV_FATAL = 2
    };
};

template <typename ... Args>
void Trace(Channel::Enum channel, const char* plugin, const char* file, int line, const char* format, Args&& ... args);

Channel::Enum GetLogLevel(const char* plugin);
void SetLogLevel(const char* plugin, Channel::Enum logLevel);
void SetPrintTimestamp(bool value);
bool GetPrintTimestamp();
void SetPrintDate(bool value);
bool GetPrintDate();
void SetPrintPlugin(bool value);
bool GetPrintPlugin();
void SetPrintSource(bool value);
bool GetPrintSource();
void SetColorOutput(bool value);
bool GetColorOutput();
void SetForceColor(bool value);
bool GetForceColor();

//void SetAsync(NWNXLib::Services::Tasks* tasks);

void InternalTrace(Channel::Enum channel, Channel::Enum allowedChannel, const char* message);

template <typename ... Args>
void Trace(Channel::Enum channel, const char* plugin, const char* file, int line, const char* format, Args&& ... args)
{
    Channel::Enum allowedChannel = GetLogLevel(plugin);

    if (channel > allowedChannel)
    {
        // No need to do anything. Our log level is lower.
        return;
    }

    static constexpr const char * SEVERITY_NAMES[] = { "", "", "F", "E", "W", "N", "I", "D" };

    // Get filename without the full path.
    const char* filename = file;
    const char* filenameTemp = filename;
    while ((filenameTemp = std::strstr(filename, "/")))
    {
        filename = filenameTemp + 1;
    }

    std::ostringstream stream;
    stream << SEVERITY_NAMES[static_cast<size_t>(channel)] << " ";
    if (GetPrintTimestamp())
    {
        time_t now = std::time(nullptr);
        tm* timeinfo = std::localtime(&now);

        if (GetPrintDate())
            tfm::format(stream, "[%04d-%02d-%02d %02d:%02d:%02d] ", 1900 + timeinfo->tm_year,  1 + timeinfo->tm_mon,
                    timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        else
            tfm::format(stream, "[%02d:%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    }
    if (GetPrintPlugin())
    {
        tfm::format(stream, "[%s] ", plugin);
    }
    if (GetPrintSource())
    {
        tfm::format(stream, "[%s:%d] ", filename, line);
    }
    tfm::format(stream, format, std::forward<Args>(args)...);

    InternalTrace(channel, allowedChannel, stream.str().c_str());
}

}

struct CExoString;
struct CResRef;

std::ostream& operator<<(std::ostream& out, const CExoString& str);
std::ostream& operator<<(std::ostream& out, const CResRef& str);
