#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoDebugInternal;

struct CExoDebug
{
    CExoString m_sLogString;
    CExoDebugInternal* m_pcExoDebugInternal;

    // The below are auto generated stubs.
    CExoDebug(const CExoDebug&) = default;
    CExoDebug& operator=(const CExoDebug&) = default;

    CExoDebug();
    ~CExoDebug();
    void Assert(int32_t, const char*, const char*);
    void CloseLogFiles();
    void FlushErrorFile();
    void FlushLogFile();
    uint32_t GetCurrentAllocatedMemory();
    uint32_t GetCurrentMemoryAllocations();
    void GetCurrentTimestamp(CExoString&);
    uint32_t GetMaxAllocatedMemory();
    uint32_t GetTotalMemoryAllocations();
    void OpenLogFiles(CExoString, int32_t);
    void SetRotateLogFile(int32_t);
    void Warning(int32_t, const char*, const char*);
    void WriteToErrorFile(const CExoString&);
    void WriteToLogFile(const CExoString&);
};

void CExoDebug__CExoDebugCtor(CExoDebug* thisPtr);
void CExoDebug__CExoDebugDtor(CExoDebug* thisPtr);
void CExoDebug__Assert(CExoDebug* thisPtr, int32_t, const char*, const char*);
void CExoDebug__CloseLogFiles(CExoDebug* thisPtr);
void CExoDebug__FlushErrorFile(CExoDebug* thisPtr);
void CExoDebug__FlushLogFile(CExoDebug* thisPtr);
uint32_t CExoDebug__GetCurrentAllocatedMemory(CExoDebug* thisPtr);
uint32_t CExoDebug__GetCurrentMemoryAllocations(CExoDebug* thisPtr);
void CExoDebug__GetCurrentTimestamp(CExoDebug* thisPtr, CExoString&);
uint32_t CExoDebug__GetMaxAllocatedMemory(CExoDebug* thisPtr);
uint32_t CExoDebug__GetTotalMemoryAllocations(CExoDebug* thisPtr);
void CExoDebug__OpenLogFiles(CExoDebug* thisPtr, CExoString, int32_t);
void CExoDebug__SetRotateLogFile(CExoDebug* thisPtr, int32_t);
void CExoDebug__Warning(CExoDebug* thisPtr, int32_t, const char*, const char*);
void CExoDebug__WriteToErrorFile(CExoDebug* thisPtr, const CExoString&);
void CExoDebug__WriteToLogFile(CExoDebug* thisPtr, const CExoString&);

}

}
