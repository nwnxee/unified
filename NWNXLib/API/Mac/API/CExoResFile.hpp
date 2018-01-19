#pragma once

#include <cstdint>

#include "CExoPackedFile.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct BiffFileHeader_st;
struct BiffFileVarResEntry_st;

struct CExoResFile
    : CExoPackedFile
{
    BiffFileHeader_st* m_pBiffHeader;
    BiffFileVarResEntry_st* m_pBiffVarResEntry;

    // The below are auto generated stubs.
    CExoResFile(const CExoResFile&) = default;
    CExoResFile& operator=(const CExoResFile&) = default;

    CExoResFile();
    ~CExoResFile();
    void AddAsyncRefCount();
    void AddRefCount();
    int32_t CloseAsyncFile();
    int32_t CloseFile();
    void DeleteAsyncRefCount();
    void DeleteRefCount();
    uint32_t GetResourceSize(uint32_t);
    int32_t Initialize();
    int32_t LoadHeader(unsigned char);
    int32_t OpenAsyncFile();
    int32_t OpenFile();
    int32_t OpenFile(unsigned char*);
    uint32_t ReadResource(uint32_t, void*, uint32_t, uint32_t);
    void ReadResourceAsync(uint32_t, void*, uint32_t, uint32_t);
    int32_t UnloadHeader();
};

void CExoResFile__CExoResFileCtor__0(CExoResFile* thisPtr);
void CExoResFile__CExoResFileDtor__0(CExoResFile* thisPtr);
void CExoResFile__AddAsyncRefCount(CExoResFile* thisPtr);
void CExoResFile__AddRefCount(CExoResFile* thisPtr);
int32_t CExoResFile__CloseAsyncFile(CExoResFile* thisPtr);
int32_t CExoResFile__CloseFile(CExoResFile* thisPtr);
void CExoResFile__DeleteAsyncRefCount(CExoResFile* thisPtr);
void CExoResFile__DeleteRefCount(CExoResFile* thisPtr);
uint32_t CExoResFile__GetResourceSize(CExoResFile* thisPtr, uint32_t);
int32_t CExoResFile__Initialize(CExoResFile* thisPtr);
int32_t CExoResFile__LoadHeader(CExoResFile* thisPtr, unsigned char);
int32_t CExoResFile__OpenAsyncFile(CExoResFile* thisPtr);
int32_t CExoResFile__OpenFile__0(CExoResFile* thisPtr);
int32_t CExoResFile__OpenFile__1(CExoResFile* thisPtr, unsigned char*);
uint32_t CExoResFile__ReadResource(CExoResFile* thisPtr, uint32_t, void*, uint32_t, uint32_t);
void CExoResFile__ReadResourceAsync(CExoResFile* thisPtr, uint32_t, void*, uint32_t, uint32_t);
int32_t CExoResFile__UnloadHeader(CExoResFile* thisPtr);

}

}
