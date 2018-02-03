#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCERFKey.hpp"
#include "CExoLinkedListTemplatedCERFRes.hpp"
#include "CExoLinkedListTemplatedCERFString.hpp"
#include "NWERFHeader_st.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CERFRes;
struct CERFString;
struct CExoFile;
struct CExoString;
struct CRes;

struct CERFFile
{
    NWERFHeader_st m_stHeader;
    CExoLinkedListTemplatedCERFString m_lstStringList;
    CExoLinkedListTemplatedCERFKey m_lstKeyList;
    CExoLinkedListTemplatedCERFRes m_lstResList;
    CExoFile* m_pOutFile;
    uint32_t m_nStringOffset;
    uint32_t m_nKeyOffset;
    uint32_t m_nResOffset;
    uint32_t m_nEntries;
    uint32_t m_nCurEntries;

    // The below are auto generated stubs.
    CERFFile(const CERFFile&) = default;
    CERFFile& operator=(const CERFFile&) = default;

    CERFFile();
    ~CERFFile();
    int32_t AddResource(CExoString&);
    int32_t AddResource(char*, uint16_t, CRes*);
    int32_t AddString(CERFString*);
    int32_t Create(CExoString&);
    int32_t Finish();
    int32_t Read();
    static int32_t ReadModuleDescription(const CExoString&, uint16_t, uint32_t*, CExoString*);
    void RecalculateOffsets();
    int32_t RemoveResource(CERFRes*);
    int32_t RemoveResource(CExoString&, uint16_t);
    int32_t Reset();
    int32_t SetNumEntries(uint32_t);
    void SetVersion(char*);
    int32_t Write(CExoString&);
    int32_t WriteHeader();
    int32_t WriteResource(char*, uint16_t, CRes*, int32_t);
    int32_t WriteStringTable();
};

void CERFFile__CERFFileCtor__0(CERFFile* thisPtr);
void CERFFile__CERFFileDtor__0(CERFFile* thisPtr);
int32_t CERFFile__AddResource__0(CERFFile* thisPtr, CExoString&);
int32_t CERFFile__AddResource__1(CERFFile* thisPtr, char*, uint16_t, CRes*);
int32_t CERFFile__AddString(CERFFile* thisPtr, CERFString*);
int32_t CERFFile__Create(CERFFile* thisPtr, CExoString&);
int32_t CERFFile__Finish(CERFFile* thisPtr);
int32_t CERFFile__Read(CERFFile* thisPtr);
int32_t CERFFile__ReadModuleDescription(const CExoString&, uint16_t, uint32_t*, CExoString*);
void CERFFile__RecalculateOffsets(CERFFile* thisPtr);
int32_t CERFFile__RemoveResource__0(CERFFile* thisPtr, CERFRes*);
int32_t CERFFile__RemoveResource__1(CERFFile* thisPtr, CExoString&, uint16_t);
int32_t CERFFile__Reset(CERFFile* thisPtr);
int32_t CERFFile__SetNumEntries(CERFFile* thisPtr, uint32_t);
void CERFFile__SetVersion(CERFFile* thisPtr, char*);
int32_t CERFFile__Write(CERFFile* thisPtr, CExoString&);
int32_t CERFFile__WriteHeader(CERFFile* thisPtr);
int32_t CERFFile__WriteResource(CERFFile* thisPtr, char*, uint16_t, CRes*, int32_t);
int32_t CERFFile__WriteStringTable(CERFFile* thisPtr);

}

}
