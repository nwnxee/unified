#pragma once

#include "Log.hpp"

#include <string>

namespace NWNXLib {

namespace Platform {

namespace Syslog {

// Emits a syslog message. Right now, only local on UNIX is supported.
void Emit(const Log::Channel::Enum sev, std::string progName, const std::string& message);

}

}

}
