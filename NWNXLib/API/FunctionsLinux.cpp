#include <dlfcn.h>
#include <stdio.h>

#include "Functions.hpp"

#define NWNXLIB_FUNCTION_NO_VERSION_CHECK

#define NWNXLIB_FUNCTION(symgcc, symmsvc) \
    void* NWNXLib::API::Functions::symgcc;
#include "FunctionsList.hpp"
#undef NWNXLIB_FUNCTION

void NWNXLib::API::Functions::Initialize()
{
#define NWNXLIB_FUNCTION(symgcc, symmsvc)              \
    symgcc = const_cast<void*>(dlsym(RTLD_DEFAULT, #symgcc )); \
    if (!symgcc)                                             \
    {                                                      \
        printf("dlsym(%s) = null\n", #symgcc);             \
    }

#include "FunctionsList.hpp"
#undef NWNXLIB_FUNCTION
}
