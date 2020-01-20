#pragma once

#include <cstdint>
#include <string>

namespace NWNXLib {

namespace Platform {

namespace Debug {

bool IsDebuggerPresent();
std::string GetStackTrace(uint8_t levels);

}
}
}
