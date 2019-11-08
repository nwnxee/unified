#pragma once

#include <cstdint>
#include <string>

namespace NWNXLib::Platform::DynamicLibraries {

using HandleType = void*;

HandleType OpenDll(const std::string& path);
bool CloseDll(HandleType handle);
std::string GetErrorFromHandle(HandleType handle);
uintptr_t GetFuncAddrInDll(const std::string& symbol, HandleType handle);
uintptr_t GetLoadedFuncAddr(const std::string& symbol);
bool IsHandleValid(HandleType handle);
bool IsFuncAddrFromDllValid(uintptr_t func);

}
