#pragma once

#include <cstdint>
#include <string>

#ifdef _WIN32
    #include <windows.h>
#endif

namespace NWNXLib {

namespace Platform {

namespace DynamicLibraries {

#ifdef _WIN32
    using HandleType = HMODULE;
#else
    using HandleType = void*;
#endif

HandleType OpenDll(const std::string& path);
bool CloseDll(HandleType handle);
std::string GetErrorFromHandle(HandleType handle);
uintptr_t GetFuncAddrInDll(const std::string& symbol, HandleType handle);
uintptr_t GetLoadedFuncAddr(const std::string& symbol);
bool IsHandleValid(HandleType handle);
bool IsFuncAddrFromDllValid(uintptr_t func);

}

}

}
