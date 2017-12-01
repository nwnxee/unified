#pragma once

#include <cstdint>

namespace NWNXLib {

namespace Services {

enum class LogSeverity : uint8_t
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


enum class LogTarget
{
    CONSOLE,
    LOCALFILE,
    SYSLOG
};

}

}
