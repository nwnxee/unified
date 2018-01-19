#pragma once

#include <cstdint>

#include "unknown___sFILE.hpp"

namespace NWNXLib {

namespace API {

struct ICrashReporter
{
    void** m_vtable;

    static void ExposeFile(__sFILE*, const char*);
    int32_t WriteMinidump(__sFILE*, int32_t);
};

void ICrashReporter__ExposeFile(__sFILE*, const char*);
int32_t ICrashReporter__WriteMinidump(ICrashReporter* thisPtr, __sFILE*, int32_t);

}

}
