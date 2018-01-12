#pragma once

#include <cstdint>

#include "ICrashReporter.hpp"
#include "unknown___sFILE.hpp"

namespace NWNXLib {

namespace API {

struct CrashReporter_Linux
    : ICrashReporter
{

    // The below are auto generated stubs.
    CrashReporter_Linux() = default;
    CrashReporter_Linux(const CrashReporter_Linux&) = default;
    CrashReporter_Linux& operator=(const CrashReporter_Linux&) = default;

    CrashReporter_Linux(void*);
    ~CrashReporter_Linux();
    void CanWriteCallstack();
    void CanWriteMinidump();
    void CanWriteSystemFiles();
    void InternalCrashHandler(int32_t);
    void WriteCallstack(__sFILE*);
    void WriteSystemFiles(__sFILE*);
};

void CrashReporter_Linux__CrashReporter_LinuxCtor__0(CrashReporter_Linux* thisPtr, void*);
void CrashReporter_Linux__CrashReporter_LinuxDtor__0(CrashReporter_Linux* thisPtr);
void CrashReporter_Linux__CanWriteCallstack(CrashReporter_Linux* thisPtr);
void CrashReporter_Linux__CanWriteMinidump(CrashReporter_Linux* thisPtr);
void CrashReporter_Linux__CanWriteSystemFiles(CrashReporter_Linux* thisPtr);
void CrashReporter_Linux__InternalCrashHandler(CrashReporter_Linux* thisPtr, int32_t);
void CrashReporter_Linux__WriteCallstack(CrashReporter_Linux* thisPtr, __sFILE*);
void CrashReporter_Linux__WriteSystemFiles(CrashReporter_Linux* thisPtr, __sFILE*);

}

}
