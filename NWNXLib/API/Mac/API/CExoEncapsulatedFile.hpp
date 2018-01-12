#pragma once

#include <cstdint>

#include "CExoLocString.hpp"
#include "CExoPackedFile.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct EncapsulatedHeader_st;
struct EncapsulatedResListEntry_st;

struct CExoEncapsulatedFile
    : CExoPackedFile
{
    CExoLocString m_lsDescription;
    EncapsulatedHeader_st* m_pEncapsulatedHeader;
    EncapsulatedResListEntry_st* m_pResListEntry;
    uint8_t m_nFileType;

    // The below are auto generated stubs.
    CExoEncapsulatedFile(const CExoEncapsulatedFile&) = default;
    CExoEncapsulatedFile& operator=(const CExoEncapsulatedFile&) = default;

    CExoEncapsulatedFile();
    ~CExoEncapsulatedFile();
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

void CExoEncapsulatedFile__CExoEncapsulatedFileCtor__0(CExoEncapsulatedFile* thisPtr);
void CExoEncapsulatedFile__CExoEncapsulatedFileDtor__0(CExoEncapsulatedFile* thisPtr);
void CExoEncapsulatedFile__AddAsyncRefCount(CExoEncapsulatedFile* thisPtr);
void CExoEncapsulatedFile__AddRefCount(CExoEncapsulatedFile* thisPtr);
int32_t CExoEncapsulatedFile__CloseAsyncFile(CExoEncapsulatedFile* thisPtr);
int32_t CExoEncapsulatedFile__CloseFile(CExoEncapsulatedFile* thisPtr);
void CExoEncapsulatedFile__DeleteAsyncRefCount(CExoEncapsulatedFile* thisPtr);
void CExoEncapsulatedFile__DeleteRefCount(CExoEncapsulatedFile* thisPtr);
uint32_t CExoEncapsulatedFile__GetResourceSize(CExoEncapsulatedFile* thisPtr, uint32_t);
int32_t CExoEncapsulatedFile__Initialize(CExoEncapsulatedFile* thisPtr);
int32_t CExoEncapsulatedFile__LoadHeader(CExoEncapsulatedFile* thisPtr, unsigned char);
int32_t CExoEncapsulatedFile__OpenAsyncFile(CExoEncapsulatedFile* thisPtr);
int32_t CExoEncapsulatedFile__OpenFile__0(CExoEncapsulatedFile* thisPtr);
int32_t CExoEncapsulatedFile__OpenFile__1(CExoEncapsulatedFile* thisPtr, unsigned char*);
uint32_t CExoEncapsulatedFile__ReadResource(CExoEncapsulatedFile* thisPtr, uint32_t, void*, uint32_t, uint32_t);
void CExoEncapsulatedFile__ReadResourceAsync(CExoEncapsulatedFile* thisPtr, uint32_t, void*, uint32_t, uint32_t);
int32_t CExoEncapsulatedFile__UnloadHeader(CExoEncapsulatedFile* thisPtr);

}

}
