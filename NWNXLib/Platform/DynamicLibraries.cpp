#include "Platform/DynamicLibraries.hpp"
#include "Assert.hpp"

#include <dlfcn.h>

namespace NWNXLib::Platform::DynamicLibraries {

HandleType OpenDll(const std::string& path)
{
    return dlopen(path.c_str(), RTLD_NOW | RTLD_NODELETE);
}

bool CloseDll(HandleType handle)
{
    return !dlclose(handle);
}

std::string GetErrorFromHandle(HandleType handle)
{
    ASSERT(!IsHandleValid(handle));
    return std::string(dlerror());
}

uintptr_t GetFuncAddrInDll(const std::string& symbol, HandleType handle)
{
    ASSERT(IsHandleValid(handle));
    return reinterpret_cast<uintptr_t>(dlsym(handle, symbol.c_str()));
}

uintptr_t GetLoadedFuncAddr(const std::string& symbol)
{
    uintptr_t ret;

    HandleType handle = dlopen(nullptr, RTLD_LAZY);

    if (handle)
    {
        ret = reinterpret_cast<uintptr_t>(dlsym(handle, symbol.c_str()));

        if (!ret)
        {
            printf("dlsym failed: %s\n", dlerror());
        }

        dlclose(handle);
    }
    else
    {
        ret = 0x0;
        printf("dlopen failed: %s\n", dlerror());
    }

    return ret;
}

bool IsHandleValid(HandleType handle)
{
    return handle != nullptr;
}

bool IsFuncAddrFromDllValid(uintptr_t func)
{
    return func != 0;
}

}
