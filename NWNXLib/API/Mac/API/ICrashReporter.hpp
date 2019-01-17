#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown___sFILE.hpp"

namespace NWNXLib {

namespace API {

struct ICrashReporter
{
    void** m_vtable;
    CExoString m_binaryChecksum;

    // The below are auto generated stubs.
    ICrashReporter() = default;
    ICrashReporter(const ICrashReporter&) = default;
    ICrashReporter& operator=(const ICrashReporter&) = default;

    ~ICrashReporter();
    static CExoString ChecksumFile(const CExoString&);
    static void ExposeFile(__sFILE*, const char*);
    int32_t WriteCallstack(__sFILE*);
    int32_t WriteMinidump(__sFILE*, int32_t);
    int32_t WriteSystemFiles(__sFILE*);
};

void ICrashReporter__ICrashReporterDtor__0(ICrashReporter* thisPtr);
CExoString ICrashReporter__ChecksumFile(const CExoString&);
void ICrashReporter__ExposeFile(__sFILE*, const char*);
int32_t ICrashReporter__WriteCallstack(ICrashReporter* thisPtr, __sFILE*);
int32_t ICrashReporter__WriteMinidump(ICrashReporter* thisPtr, __sFILE*, int32_t);
int32_t ICrashReporter__WriteSystemFiles(ICrashReporter* thisPtr, __sFILE*);

}

}
