#pragma once

#include <cstdint>
#include <string>

namespace NWNXLib::Platform::Debug {

bool IsDebuggerPresent();
std::string GetStackTrace(uint8_t levels);

std::string ResolveAddress(uintptr_t address);
uintptr_t GetFunctionAddress(const std::string& mangledname);

}
