#pragma once

#include <cstdint>
#include <string>

namespace NWNXLib {

namespace Platform {

namespace Debug {

bool IsDebuggerPresent();
void OutputDebugString(const char *str);
std::string GetStackTrace(uint8_t levels);

}
}
}
