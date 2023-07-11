#include <windows.h>

#include "Functions.hpp"

#define NWNXLIB_FUNCTION_NO_VERSION_CHECK

#define NWNXLIB_FUNCTION(symgcc, symmsvc) \
    void* NWNXLib::API::Functions::symgcc;
#include "FunctionsList.hpp"
#undef NWNXLIB_FUNCTION

void NWNXLib::API::Functions::Initialize()
{
    HMODULE module = GetModuleHandle(nullptr);

#define NWNXLIB_FUNCTION(symgcc, symmsvc)                        \
    symgcc = reinterpret_cast<void*>(GetProcAddress(module, #symmsvc )); \
    if (!symgcc)                                          \
    {                                                      \
        printf("GetProcAddress(%s) = null\n", #symmsvc);   \
    }

#include "FunctionsList.hpp"
#undef NWNXLIB_FUNCTION
}
