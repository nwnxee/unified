#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoFileInternal;
struct CExoString;

struct CExoFile
{
    void** m_vtable;
    CExoFileInternal* m_pcExoFileInternal;

    // The below are auto generated stubs.
    CExoFile() = default;
    CExoFile(const CExoFile&) = default;
    CExoFile& operator=(const CExoFile&) = default;

    CExoFile(const CExoString&, const CExoString&);
    CExoFile(const void*, int32_t);
    CExoFile(const CExoString&, uint16_t, const CExoString&);
    ~CExoFile();
    int32_t Eof();
    int32_t FileOpened();
    int32_t Flush();
    uint32_t GetOffset();
    int32_t GetSize();
    int32_t IsMemoryBacked();
    uint32_t Read(CExoString&, uint32_t);
    uint32_t Read(void*, uint32_t, uint32_t);
    void ReadAsync(void*, uint32_t, uint32_t);
    uint32_t ReadAsyncBytesRead();
    int32_t ReadAsyncComplete();
    static int32_t ReadStringLineFromBuffer(unsigned char**, uint32_t*, unsigned char*, uint32_t);
    int32_t Seek(int32_t, int32_t);
    int32_t SeekBeginning();
    int32_t SeekEnd();
    void SetMemoryBuffer(const void*, int32_t);
    uint32_t Write(const CExoString&);
    uint32_t Write(const char*);
    uint32_t Write(const void*, uint32_t, uint32_t);
};

void CExoFile__CExoFileCtor__0(CExoFile* thisPtr, const CExoString&, const CExoString&);
void CExoFile__CExoFileCtor__1(CExoFile* thisPtr, const void*, int32_t);
void CExoFile__CExoFileCtor__2(CExoFile* thisPtr, const CExoString&, uint16_t, const CExoString&);
void CExoFile__CExoFileDtor__0(CExoFile* thisPtr);
int32_t CExoFile__Eof(CExoFile* thisPtr);
int32_t CExoFile__FileOpened(CExoFile* thisPtr);
int32_t CExoFile__Flush(CExoFile* thisPtr);
uint32_t CExoFile__GetOffset(CExoFile* thisPtr);
int32_t CExoFile__GetSize(CExoFile* thisPtr);
int32_t CExoFile__IsMemoryBacked(CExoFile* thisPtr);
uint32_t CExoFile__Read__0(CExoFile* thisPtr, CExoString&, uint32_t);
uint32_t CExoFile__Read__1(CExoFile* thisPtr, void*, uint32_t, uint32_t);
void CExoFile__ReadAsync(CExoFile* thisPtr, void*, uint32_t, uint32_t);
uint32_t CExoFile__ReadAsyncBytesRead(CExoFile* thisPtr);
int32_t CExoFile__ReadAsyncComplete(CExoFile* thisPtr);
int32_t CExoFile__ReadStringLineFromBuffer(unsigned char**, uint32_t*, unsigned char*, uint32_t);
int32_t CExoFile__Seek(CExoFile* thisPtr, int32_t, int32_t);
int32_t CExoFile__SeekBeginning(CExoFile* thisPtr);
int32_t CExoFile__SeekEnd(CExoFile* thisPtr);
void CExoFile__SetMemoryBuffer(CExoFile* thisPtr, const void*, int32_t);
uint32_t CExoFile__Write__0(CExoFile* thisPtr, const CExoString&);
uint32_t CExoFile__Write__1(CExoFile* thisPtr, const char*);
uint32_t CExoFile__Write__2(CExoFile* thisPtr, const void*, uint32_t, uint32_t);

}

}
