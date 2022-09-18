#include <dlfcn.h>
#include <stdio.h>

#include "Functions.hpp"

#define NWNXLIB_FUNCTION_NO_VERSION_CHECK

#define NWNXLIB_FUNCTION(name) \
    void* NWNXLib::API::Functions::name;
#include "FunctionsLinux.hpp"
#undef NWNXLIB_FUNCTION

void NWNXLib::API::Functions::Initialize()
{
#define NWNXLIB_FUNCTION(name)                             \
    name = const_cast<void*>(dlsym(RTLD_DEFAULT, #name )); \
    if (!name)                                             \
    {                                                      \
        printf("dlsym(%s) = null\n", #name);               \
    }

#include "FunctionsLinux.hpp"
#undef NWNXLIB_FUNCTION
}
