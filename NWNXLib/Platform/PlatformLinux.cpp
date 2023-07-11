#include "nwnx.hpp"
#include <cstring>
#include <cstdio>

#include <execinfo.h>
#include <dlfcn.h>

// Don't allow the -quite flag to close stdout/stderr, we print important info there.
extern "C" FILE *freopen64(const char *filename, const char *mode, FILE *stream)
{
    if ((stream == stdout || stream == stderr) && !strcmp(filename, "/dev/null"))
    {
        if (stream == stdout)
        {
            std::puts("NWNX overriding -quiet flag. Always keep an eye on stdout.\n"
                      "Server will continue in non-interactive mode, but with full output.\n");
        }
        return stream;
    }

    using Type = FILE*(*)(const char*,const char*,FILE*);
    static Type real;
    if (!real)
        real = (Type)dlsym(RTLD_NEXT, "freopen64");
    return real(filename, mode, stream);
}

namespace NWNXLib::Platform
{

void Initialize()
{

}

bool IsDebuggerPresent()
{
    bool present = false;
    char buf[1024] = {};

    FILE *f = fopen("/proc/self/status", "r");
    if (f == NULL)
        return false;

    if (fread(buf, 1, sizeof(buf)-1, f))
    {
        char *tracer_pid = strstr(buf, "TracerPid:");
        if (tracer_pid)
            present = !!atoi(tracer_pid + sizeof("TracerPid:") - 1);
    }
    fclose(f);
    return present;
}

std::string GetStackTrace(uint8_t levels)
{
    char buffer[64*1024];
    void* stackTrace[256];

    buffer[0] = 0;
    int numCapturedFrames = backtrace(stackTrace, levels);

    if (numCapturedFrames)
    {
        char** resolvedFrames = backtrace_symbols(stackTrace, levels);
        std::strncat(buffer, "\n  Backtrace:\n", sizeof(buffer)-1);
        for (int i = 0; i < numCapturedFrames; ++i)
        {
            char backtraceBuffer[2048];
            std::snprintf(backtraceBuffer, sizeof(backtraceBuffer), "    %s\n", resolvedFrames[i]);
            std::strncat(buffer, backtraceBuffer, sizeof(buffer)-1);
        }
        free(resolvedFrames);
    }
    return std::string(buffer);
}

void* OpenLibrary(const char* fileName, int flags)
{
    return dlopen(fileName, flags);
}

int CloseLibrary(void* handle)
{
    return dlclose(handle);
}

void* GetSymbol(void* handle, const char* name)
{
    return dlsym(handle, name);
}

const char* GetError()
{
    return dlerror();
}

std::string PluginExtension()
{
    return "so";
}

std::string PathSeparator()
{
    return "/";
}

}
