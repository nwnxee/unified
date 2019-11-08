#include "Platform/Syslog.hpp"

#include <syslog.h>
#include <algorithm>

namespace NWNXLib::Platform::Syslog {

void Emit(Log::Channel::Enum sev, std::string pn, const std::string& message)
{
    std::transform(std::begin(pn), std::end(pn), std::begin(pn), ::tolower);

    // We reopen for every message because we reset the progname depending
    // on the passed-in params. We also can't know what else inside
    // the process is messing with the syslog library.
    openlog(pn.c_str(), LOG_CONS | LOG_NDELAY, LOG_USER);
    syslog(static_cast<int>(sev), "%s", message.c_str());
    closelog();
}

}
