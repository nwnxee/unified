#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "unknown__IO_FILE.hpp"

namespace NWNXLib {

namespace API {

struct CExoFileInternal
{
    void** m_vtable;
    int32_t m_nMode;
    const void* m_pBuffer;
    uint32_t m_nBufferSize;
    uint32_t m_nSeekPosition;
    _IO_FILE* m_pFileHandle;
    CExoString m_sFileName;
    uint32_t m_nFileSize;

    // The below are auto generated stubs.
    CExoFileInternal() = default;
    CExoFileInternal(const CExoFileInternal&) = default;
    CExoFileInternal& operator=(const CExoFileInternal&) = default;

    CExoFileInternal(const CExoString&, const CExoString&);
    CExoFileInternal(const void*, int32_t);
    CExoFileInternal(const CExoString&, uint16_t, const CExoString&);
    ~CExoFileInternal();
    int32_t Eof();
    int32_t FileOpened();
    int32_t Flush();
    uint32_t GetOffset();
    int32_t GetSize();
    int32_t IsMemoryBacked();
    uint32_t Read(CExoString*, uint32_t);
    uint32_t Read(void*, uint32_t, uint32_t);
    void ReadAsync(void*, uint32_t, uint32_t);
    uint32_t ReadAsyncBytesRead();
    int32_t ReadAsyncComplete();
    int32_t Seek(int32_t, int32_t);
    int32_t SeekBeginning();
    int32_t SeekEnd();
    void SetMemoryBuffer(const void*, int32_t);
    uint32_t Write(const char*);
};

void CExoFileInternal__CExoFileInternalCtor__0(CExoFileInternal* thisPtr, const CExoString&, const CExoString&);
void CExoFileInternal__CExoFileInternalCtor__1(CExoFileInternal* thisPtr, const void*, int32_t);
void CExoFileInternal__CExoFileInternalCtor__2(CExoFileInternal* thisPtr, const CExoString&, uint16_t, const CExoString&);
void CExoFileInternal__CExoFileInternalDtor__0(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__Eof(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__FileOpened(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__Flush(CExoFileInternal* thisPtr);
uint32_t CExoFileInternal__GetOffset(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__GetSize(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__IsMemoryBacked(CExoFileInternal* thisPtr);
uint32_t CExoFileInternal__Read__0(CExoFileInternal* thisPtr, CExoString*, uint32_t);
uint32_t CExoFileInternal__Read__1(CExoFileInternal* thisPtr, void*, uint32_t, uint32_t);
void CExoFileInternal__ReadAsync(CExoFileInternal* thisPtr, void*, uint32_t, uint32_t);
uint32_t CExoFileInternal__ReadAsyncBytesRead(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__ReadAsyncComplete(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__Seek(CExoFileInternal* thisPtr, int32_t, int32_t);
int32_t CExoFileInternal__SeekBeginning(CExoFileInternal* thisPtr);
int32_t CExoFileInternal__SeekEnd(CExoFileInternal* thisPtr);
void CExoFileInternal__SetMemoryBuffer(CExoFileInternal* thisPtr, const void*, int32_t);
uint32_t CExoFileInternal__Write(CExoFileInternal* thisPtr, const char*);

}

}
