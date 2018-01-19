#pragma once

#include <cstdint>

#include "CExoPackedFile.hpp"
#include "EncapsulatedKeyListEntry_st.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct EncapsulatedHeader_st;
struct EncapsulatedResListEntry_st;

struct CExoResourceImageFile
    : CExoPackedFile
{
    void* m_pResourceImage;

    // The below are auto generated stubs.
    CExoResourceImageFile(const CExoResourceImageFile&) = default;
    CExoResourceImageFile& operator=(const CExoResourceImageFile&) = default;

    CExoResourceImageFile();
    ~CExoResourceImageFile();
    void AddRefCount();
    int32_t CloseAsyncFile();
    int32_t CloseFile();
    void DeleteAsyncRefCount();
    void DeleteRefCount();
    EncapsulatedHeader_st* GetHeader();
    EncapsulatedKeyListEntry_st** GetKeyList();
    EncapsulatedKeyListEntry_st GetKeyListEntry(uint32_t);
    void* GetResource(uint32_t);
    EncapsulatedResListEntry_st* GetResourceListEntry(uint32_t);
    uint32_t GetResourceSize(uint32_t);
    int32_t Initialize();
    int32_t LoadHeader(unsigned char);
    int32_t OpenFile();
    int32_t OpenFile(unsigned char*);
    uint32_t ReadResource(uint32_t, void*, uint32_t, uint32_t);
    void ReadResourceAsync(uint32_t, void*, uint32_t, uint32_t);
};

void CExoResourceImageFile__CExoResourceImageFileCtor(CExoResourceImageFile* thisPtr);
void CExoResourceImageFile__CExoResourceImageFileDtor__0(CExoResourceImageFile* thisPtr);
void CExoResourceImageFile__AddRefCount(CExoResourceImageFile* thisPtr);
int32_t CExoResourceImageFile__CloseAsyncFile(CExoResourceImageFile* thisPtr);
int32_t CExoResourceImageFile__CloseFile(CExoResourceImageFile* thisPtr);
void CExoResourceImageFile__DeleteAsyncRefCount(CExoResourceImageFile* thisPtr);
void CExoResourceImageFile__DeleteRefCount(CExoResourceImageFile* thisPtr);
EncapsulatedHeader_st* CExoResourceImageFile__GetHeader(CExoResourceImageFile* thisPtr);
EncapsulatedKeyListEntry_st** CExoResourceImageFile__GetKeyList(CExoResourceImageFile* thisPtr);
EncapsulatedKeyListEntry_st CExoResourceImageFile__GetKeyListEntry(CExoResourceImageFile* thisPtr, uint32_t);
void* CExoResourceImageFile__GetResource(CExoResourceImageFile* thisPtr, uint32_t);
EncapsulatedResListEntry_st* CExoResourceImageFile__GetResourceListEntry(CExoResourceImageFile* thisPtr, uint32_t);
uint32_t CExoResourceImageFile__GetResourceSize(CExoResourceImageFile* thisPtr, uint32_t);
int32_t CExoResourceImageFile__Initialize(CExoResourceImageFile* thisPtr);
int32_t CExoResourceImageFile__LoadHeader(CExoResourceImageFile* thisPtr, unsigned char);
int32_t CExoResourceImageFile__OpenFile__0(CExoResourceImageFile* thisPtr);
int32_t CExoResourceImageFile__OpenFile__1(CExoResourceImageFile* thisPtr, unsigned char*);
uint32_t CExoResourceImageFile__ReadResource(CExoResourceImageFile* thisPtr, uint32_t, void*, uint32_t, uint32_t);
void CExoResourceImageFile__ReadResourceAsync(CExoResourceImageFile* thisPtr, uint32_t, void*, uint32_t, uint32_t);

}

}
