#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown__IO_FILE.hpp"

namespace NWNXLib {

namespace API {

struct ICrashReporter
{
    void** m_vtable;
    CExoString m_binaryChecksum;

    static CExoString ChecksumFile(const CExoString&);
    static void ExposeFile(_IO_FILE*, const char*);
    int32_t WriteCallstack(_IO_FILE*);
    int32_t WriteMinidump(_IO_FILE*, int32_t);
    int32_t WriteSystemFiles(_IO_FILE*);
};

CExoString ICrashReporter__ChecksumFile(const CExoString&);
void ICrashReporter__ExposeFile(_IO_FILE*, const char*);
int32_t ICrashReporter__WriteCallstack(ICrashReporter* thisPtr, _IO_FILE*);
int32_t ICrashReporter__WriteMinidump(ICrashReporter* thisPtr, _IO_FILE*, int32_t);
int32_t ICrashReporter__WriteSystemFiles(ICrashReporter* thisPtr, _IO_FILE*);

}

}
