#include "Platform/DynamicLibraries.hpp"
#include "Assert.hpp"

#ifndef _WIN32
    #include <dlfcn.h>
#endif

namespace NWNXLib {

namespace Platform {

namespace DynamicLibraries {

HandleType OpenDll(const std::string& path)
{
    HandleType handle;

#ifdef _WIN32
    handle = LoadLibraryA(path.c_str());
#else
    handle = dlopen(path.c_str(), RTLD_NOW | RTLD_NODELETE);
#endif

    return handle;
}

bool CloseDll(HandleType handle)
{
#ifdef _WIN32
    return FreeLibrary(handle);
#else
    return !dlclose(handle);
#endif
}

std::string GetErrorFromHandle(HandleType handle)
{
    ASSERT(!IsHandleValid(handle));

    std::string error;

#ifdef _WIN32
    throw std::runtime_error("GetErrorFromHandle is unimplemented on Windows.");
#else
    (void)handle; // Suppress unused variable warning.
    error = dlerror();
#endif

    return error;
}

uintptr_t GetFuncAddrInDll(const std::string& symbol, HandleType handle)
{
    ASSERT(IsHandleValid(handle));
    uintptr_t pointer;

#ifdef _WIN32
    FARPROC test = GetProcAddress(handle, symbol.c_str());
    pointer = reinterpret_cast<uintptr_t>(GetProcAddress(handle, symbol.c_str()));
#else
    pointer = reinterpret_cast<uintptr_t>(dlsym(handle, symbol.c_str()));
#endif

    return pointer;
}

uintptr_t GetLoadedFuncAddr(const std::string& symbol)
{
    uintptr_t ret;

#ifdef _WIN32
    ret = 0x0;
#else
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
#endif

    return ret;
}

bool IsHandleValid(HandleType handle)
{
    bool valid;

#ifdef _WIN32
    valid = handle != NULL;
#else
    valid = handle != nullptr;
#endif

    return valid;
}

bool IsFuncAddrFromDllValid(uintptr_t func)
{
    bool valid;

#ifdef _WIN32
    valid = func != 0;
#else
    valid = func != 0;
#endif

    return valid;
}

}

}

}
