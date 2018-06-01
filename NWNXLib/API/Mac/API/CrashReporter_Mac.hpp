#pragma once

#include <cstdint>

#include "unknown___sFILE.hpp"

namespace NWNXLib {

namespace API {

struct CrashReporter_Mac
{

    // The below are auto generated stubs.
    CrashReporter_Mac() = default;
    CrashReporter_Mac(const CrashReporter_Mac&) = default;
    CrashReporter_Mac& operator=(const CrashReporter_Mac&) = default;

    CrashReporter_Mac(void*);
    ~CrashReporter_Mac();
    void CanWriteCallstack();
    void CanWriteMinidump();
    void CanWriteSystemFiles();
    void InternalCrashHandler(int32_t);
    void ReportCrashToUser(const char*, const char*);
    void WriteCallstack(__sFILE*);
    void WriteSystemFiles(__sFILE*);
};

void CrashReporter_Mac__CrashReporter_MacCtor__0(CrashReporter_Mac* thisPtr, void*);
void CrashReporter_Mac__CrashReporter_MacDtor__0(CrashReporter_Mac* thisPtr);
void CrashReporter_Mac__CanWriteCallstack(CrashReporter_Mac* thisPtr);
void CrashReporter_Mac__CanWriteMinidump(CrashReporter_Mac* thisPtr);
void CrashReporter_Mac__CanWriteSystemFiles(CrashReporter_Mac* thisPtr);
void CrashReporter_Mac__InternalCrashHandler(CrashReporter_Mac* thisPtr, int32_t);
void CrashReporter_Mac__ReportCrashToUser(CrashReporter_Mac* thisPtr, const char*, const char*);
void CrashReporter_Mac__WriteCallstack(CrashReporter_Mac* thisPtr, __sFILE*);
void CrashReporter_Mac__WriteSystemFiles(CrashReporter_Mac* thisPtr, __sFILE*);

}

}
