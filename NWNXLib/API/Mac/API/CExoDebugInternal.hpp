#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoFile;

struct CExoDebugInternal
{
    int32_t m_bFilesOpen;
    CExoFile* m_pLogFile;
    CExoFile* m_pErrorFile;
    CExoString m_sExecutableName;
    int32_t m_nMaxLogSize;
    int32_t m_nCurrentLogSize;
    int32_t m_nCurrentErrorSize;
    int32_t m_nCurrentLogFileNumber;
    int32_t m_nCurrentErrorFileNumber;
    int32_t m_bRotateLogFile;

    // The below are auto generated stubs.
    CExoDebugInternal(const CExoDebugInternal&) = default;
    CExoDebugInternal& operator=(const CExoDebugInternal&) = default;

    CExoDebugInternal();
    ~CExoDebugInternal();
    void Assert(int32_t, const char*, const char*);
    void CloseLogFiles();
    int32_t CreateDirectory(CExoString);
    void FlushErrorFile();
    void FlushLogFile();
    void GetCurrentTimestamp(CExoString&);
    void OpenLogFiles(CExoString, int32_t);
    void Warning(int32_t, const char*, const char*);
    void WriteToErrorFile(const CExoString&);
    void WriteToLogFile(const CExoString&);
};

void CExoDebugInternal__CExoDebugInternalCtor__0(CExoDebugInternal* thisPtr);
void CExoDebugInternal__CExoDebugInternalDtor__0(CExoDebugInternal* thisPtr);
void CExoDebugInternal__Assert(CExoDebugInternal* thisPtr, int32_t, const char*, const char*);
void CExoDebugInternal__CloseLogFiles(CExoDebugInternal* thisPtr);
int32_t CExoDebugInternal__CreateDirectory(CExoDebugInternal* thisPtr, CExoString);
void CExoDebugInternal__FlushErrorFile(CExoDebugInternal* thisPtr);
void CExoDebugInternal__FlushLogFile(CExoDebugInternal* thisPtr);
void CExoDebugInternal__GetCurrentTimestamp(CExoDebugInternal* thisPtr, CExoString&);
void CExoDebugInternal__OpenLogFiles(CExoDebugInternal* thisPtr, CExoString, int32_t);
void CExoDebugInternal__Warning(CExoDebugInternal* thisPtr, int32_t, const char*, const char*);
void CExoDebugInternal__WriteToErrorFile(CExoDebugInternal* thisPtr, const CExoString&);
void CExoDebugInternal__WriteToLogFile(CExoDebugInternal* thisPtr, const CExoString&);

}

}
