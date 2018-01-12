#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown__IO_FILE.hpp"

namespace NWNXLib {

namespace API {

struct CExoFileInternal
{
    _IO_FILE* m_pFileHandle;
    CExoString m_sFileName;
    uint32_t m_nFileSize;

    // The below are auto generated stubs.
    CExoFileInternal() = default;
    CExoFileInternal(const CExoFileInternal&) = default;
    CExoFileInternal& operator=(const CExoFileInternal&) = default;

    CExoFileInternal(const CExoString&, uint16_t, const CExoString&);
    ~CExoFileInternal();
    uint32_t GetOffset();
    int32_t GetSize();
    void Read(CExoString*, uint32_t);
    void ReadAsync(void*, uint32_t, uint32_t);
    uint32_t ReadAsyncBytesRead();
    int32_t ReadAsyncComplete();
    void Write(const char*);
};

void CExoFileInternal__CExoFileInternalCtor__0(CExoFileInternal* thisPtr, const CExoString&, uint16_t, const CExoString&);
void CExoFileInternal__CExoFileInternalDtor__0(CExoFileInternal* thisPtr);
uint32_t CExoFileInternal__GetOffset(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__GetSize(CExoFileInternal* thisPtr);
void CExoFileInternal__Read(CExoFileInternal* thisPtr, CExoString*, uint32_t);
void CExoFileInternal__ReadAsync(CExoFileInternal* thisPtr, void*, uint32_t, uint32_t);
uint32_t CExoFileInternal__ReadAsyncBytesRead(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__ReadAsyncComplete(CExoFileInternal* thisPtr);
void CExoFileInternal__Write(CExoFileInternal* thisPtr, const char*);

}

}
