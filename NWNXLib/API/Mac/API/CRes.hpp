#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListNode;
struct CKeyTableEntry;

struct CRes
{
    void** m_vtable;
    uint16_t m_nDemands;
    uint16_t m_nRequests;
    uint32_t m_nID;
    uint32_t m_status;
    void* m_pResource;
    CKeyTableEntry* m_pKeyEntry;
    uint32_t m_nSize;
    uint32_t m_nRefs;
    int32_t m_bAllocHeaderData;
    int32_t m_bAllocTrailingData;
    CExoLinkedListNode* m_pos;

    // The below are auto generated stubs.
    CRes(const CRes&) = default;
    CRes& operator=(const CRes&) = default;

    CRes();
    CRes(uint32_t);
    ~CRes();
    int32_t CancelRequest();
    void* Demand();
    void Dump(int32_t);
    void* GetData();
    int32_t GetDemands();
    int32_t GetFixedResourceDataOffset();
    int32_t GetFixedResourceSize();
    int32_t GetID();
    int32_t GetRequests();
    int32_t GetSize();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
    int32_t ReadRaw(int32_t, char*);
    int32_t Release();
    int32_t Request();
    void SetID(uint32_t);
};

void CRes__CResCtor__0(CRes* thisPtr);
void CRes__CResCtor__2(CRes* thisPtr, uint32_t);
void CRes__CResDtor__0(CRes* thisPtr);
int32_t CRes__CancelRequest(CRes* thisPtr);
void* CRes__Demand(CRes* thisPtr);
void CRes__Dump(CRes* thisPtr, int32_t);
void* CRes__GetData(CRes* thisPtr);
int32_t CRes__GetDemands(CRes* thisPtr);
int32_t CRes__GetFixedResourceDataOffset(CRes* thisPtr);
int32_t CRes__GetFixedResourceSize(CRes* thisPtr);
int32_t CRes__GetID(CRes* thisPtr);
int32_t CRes__GetRequests(CRes* thisPtr);
int32_t CRes__GetSize(CRes* thisPtr);
int32_t CRes__OnResourceFreed(CRes* thisPtr);
int32_t CRes__OnResourceServiced(CRes* thisPtr);
int32_t CRes__ReadRaw(CRes* thisPtr, int32_t, char*);
int32_t CRes__Release(CRes* thisPtr);
int32_t CRes__Request(CRes* thisPtr);
void CRes__SetID(CRes* thisPtr, uint32_t);

}

}
