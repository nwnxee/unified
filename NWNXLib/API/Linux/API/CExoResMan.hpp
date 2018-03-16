#pragma once

#include <cstdint>

#include "CExoLinkedListTemplatedCExoKeyTable.hpp"
#include "CExoLinkedListTemplatedCRes.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoFile;
struct CExoKeyTable;
struct CExoStringList;
struct CKeyTableEntry;
struct CRes;
struct CResRef;

struct CExoResMan
{
    int32_t m_nTotalPhysicalMemory;
    int32_t m_nTotalAvailableMemory;
    int32_t m_nAvailableMemory;
    CExoKeyTable* m_pKeyTable;
    CExoLinkedListTemplatedCExoKeyTable m_lstFixedKeyTables;
    CExoLinkedListTemplatedCExoKeyTable m_lstDirectoryKeyTables;
    CExoLinkedListTemplatedCExoKeyTable m_lstEncapsulatedKeyTables;
    CExoLinkedListTemplatedCExoKeyTable m_lstImageKeyTables;
    CExoLinkedListTemplatedCRes m_lstToBeFreed;
    CExoLinkedListTemplatedCRes m_lstAsyncResQueue;
    CRes* m_pCurrentAsyncRes;
    CExoFile* m_pAsyncFile;
    int32_t m_bAsyncSuspended;
    uint32_t m_nTotalDemands;
    uint32_t m_nTotalCacheHits;
    uint32_t m_nTotalOldReleases;
    uint32_t m_nTotalNewReleases;
    int32_t m_bOverrideAll;

    // The below are auto generated stubs.
    CExoResMan(const CExoResMan&) = default;
    CExoResMan& operator=(const CExoResMan&) = default;

    CExoResMan();
    ~CExoResMan();
    int32_t AddEncapsulatedResourceFile(const CExoString&);
    int32_t AddFixedKeyTableFile(const CExoString&);
    int32_t AddKeyTable(const CExoString&, uint32_t, unsigned char*);
    int32_t AddResourceDirectory(const CExoString&);
    int32_t AddResourceImageFile(const CExoString&, unsigned char*);
    int32_t CancelRequest(CRes*);
    int32_t CleanDirectory(CExoString, int32_t, int32_t);
    int32_t CreateDirectory(CExoString);
    void* Demand(CRes*);
    void Dump(CRes*, int32_t);
    void DumpAll();
    int32_t Exists(const CResRef&, uint16_t, uint32_t*);
    int32_t Free(CRes*);
    int32_t FreeChunk();
    void FreeResourceData(CRes*);
    CExoLocString GetEncapsulatedFileDescription(const CExoString&);
    int32_t GetFreeDiskSpace(const CExoString&, uint64_t*);
    int32_t GetIsStaticType(uint16_t);
    int32_t GetKeyEntry(const CResRef&, uint16_t, CExoKeyTable**, CKeyTableEntry**);
    int32_t GetNewResRef(const CResRef&, uint16_t, CResRef&);
    uint32_t GetResID(const CResRef&, uint16_t);
    CRes* GetResObject(const CResRef&, uint16_t);
    CExoStringList* GetResOfType(uint16_t, CRes*);
    CExoStringList* GetResOfType(uint16_t, int32_t);
    void GetResRefFromFile(CResRef&, const CExoString&);
    uint16_t GetResTypeFromFile(const CExoString&);
    CExoKeyTable* GetTable(CRes*);
    int32_t GetTableCount(CRes*, int32_t);
    uint32_t GetTotalPhysicalMemory();
    int32_t Malloc(CRes*);
    int32_t NukeDirectory(CExoString, int32_t, int32_t);
    int32_t ReadRaw(CRes*, int32_t, char*);
    int32_t Release(CRes*);
    int32_t ReleaseResObject(CRes*);
    int32_t RemoveEncapsulatedResourceFile(const CExoString&, int32_t);
    int32_t RemoveFile(const CExoString&, uint16_t);
    int32_t RemoveFixedKeyTableFile(const CExoString&);
    void RemoveFromToBeFreedList(CRes*);
    int32_t RemoveKeyTable(const CExoString&, uint32_t, int32_t);
    int32_t RemoveResourceDirectory(const CExoString&);
    int32_t RemoveResourceImageFile(const CExoString&);
    int32_t Request(CRes*);
    void ResumeServicing();
    int32_t ServiceCurrentAsyncRes();
    int32_t ServiceFromDirectory(CRes*, int32_t);
    int32_t ServiceFromDirectoryRaw(CRes*, int32_t, char*);
    int32_t ServiceFromEncapsulated(CRes*, int32_t);
    int32_t ServiceFromEncapsulatedRaw(CRes*, int32_t, char*);
    int32_t ServiceFromImage(CRes*, int32_t);
    int32_t ServiceFromImageRaw(CRes*, int32_t, char*);
    int32_t ServiceFromResFile(CRes*, int32_t);
    int32_t ServiceFromResFileRaw(CRes*, int32_t, char*);
    void SetResObject(const CResRef&, uint16_t, CRes*);
    int32_t SetTotalResourceMemory(int32_t);
    void SuspendServicing();
    void Update(uint32_t);
    int32_t UpdateEncapsulatedResourceFile(const CExoString&);
    int32_t UpdateFixedKeyTableFile(const CExoString&);
    int32_t UpdateKeyTable(const CExoString&, uint32_t);
    int32_t UpdateResourceDirectory(const CExoString&);
    int32_t WipeDirectory(CExoString, int32_t, int32_t, int32_t, int32_t);
};

void CExoResMan__CExoResManCtor(CExoResMan* thisPtr);
void CExoResMan__CExoResManDtor(CExoResMan* thisPtr);
int32_t CExoResMan__AddEncapsulatedResourceFile(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__AddFixedKeyTableFile(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__AddKeyTable(CExoResMan* thisPtr, const CExoString&, uint32_t, unsigned char*);
int32_t CExoResMan__AddResourceDirectory(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__AddResourceImageFile(CExoResMan* thisPtr, const CExoString&, unsigned char*);
int32_t CExoResMan__CancelRequest(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__CleanDirectory(CExoResMan* thisPtr, CExoString, int32_t, int32_t);
int32_t CExoResMan__CreateDirectory(CExoResMan* thisPtr, CExoString);
void* CExoResMan__Demand(CExoResMan* thisPtr, CRes*);
void CExoResMan__Dump(CExoResMan* thisPtr, CRes*, int32_t);
void CExoResMan__DumpAll(CExoResMan* thisPtr);
int32_t CExoResMan__Exists(CExoResMan* thisPtr, const CResRef&, uint16_t, uint32_t*);
int32_t CExoResMan__Free(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__FreeChunk(CExoResMan* thisPtr);
void CExoResMan__FreeResourceData(CExoResMan* thisPtr, CRes*);
CExoLocString CExoResMan__GetEncapsulatedFileDescription(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__GetFreeDiskSpace(CExoResMan* thisPtr, const CExoString&, uint64_t*);
int32_t CExoResMan__GetIsStaticType(CExoResMan* thisPtr, uint16_t);
int32_t CExoResMan__GetKeyEntry(CExoResMan* thisPtr, const CResRef&, uint16_t, CExoKeyTable**, CKeyTableEntry**);
int32_t CExoResMan__GetNewResRef(CExoResMan* thisPtr, const CResRef&, uint16_t, CResRef&);
uint32_t CExoResMan__GetResID(CExoResMan* thisPtr, const CResRef&, uint16_t);
CRes* CExoResMan__GetResObject(CExoResMan* thisPtr, const CResRef&, uint16_t);
CExoStringList* CExoResMan__GetResOfType__0(CExoResMan* thisPtr, uint16_t, CRes*);
CExoStringList* CExoResMan__GetResOfType__1(CExoResMan* thisPtr, uint16_t, int32_t);
void CExoResMan__GetResRefFromFile(CExoResMan* thisPtr, CResRef&, const CExoString&);
uint16_t CExoResMan__GetResTypeFromFile(CExoResMan* thisPtr, const CExoString&);
CExoKeyTable* CExoResMan__GetTable(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__GetTableCount(CExoResMan* thisPtr, CRes*, int32_t);
uint32_t CExoResMan__GetTotalPhysicalMemory(CExoResMan* thisPtr);
int32_t CExoResMan__Malloc(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__NukeDirectory(CExoResMan* thisPtr, CExoString, int32_t, int32_t);
int32_t CExoResMan__ReadRaw(CExoResMan* thisPtr, CRes*, int32_t, char*);
int32_t CExoResMan__Release(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__ReleaseResObject(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__RemoveEncapsulatedResourceFile(CExoResMan* thisPtr, const CExoString&, int32_t);
int32_t CExoResMan__RemoveFile(CExoResMan* thisPtr, const CExoString&, uint16_t);
int32_t CExoResMan__RemoveFixedKeyTableFile(CExoResMan* thisPtr, const CExoString&);
void CExoResMan__RemoveFromToBeFreedList(CExoResMan* thisPtr, CRes*);
int32_t CExoResMan__RemoveKeyTable(CExoResMan* thisPtr, const CExoString&, uint32_t, int32_t);
int32_t CExoResMan__RemoveResourceDirectory(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__RemoveResourceImageFile(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__Request(CExoResMan* thisPtr, CRes*);
void CExoResMan__ResumeServicing(CExoResMan* thisPtr);
int32_t CExoResMan__ServiceCurrentAsyncRes(CExoResMan* thisPtr);
int32_t CExoResMan__ServiceFromDirectory(CExoResMan* thisPtr, CRes*, int32_t);
int32_t CExoResMan__ServiceFromDirectoryRaw(CExoResMan* thisPtr, CRes*, int32_t, char*);
int32_t CExoResMan__ServiceFromEncapsulated(CExoResMan* thisPtr, CRes*, int32_t);
int32_t CExoResMan__ServiceFromEncapsulatedRaw(CExoResMan* thisPtr, CRes*, int32_t, char*);
int32_t CExoResMan__ServiceFromImage(CExoResMan* thisPtr, CRes*, int32_t);
int32_t CExoResMan__ServiceFromImageRaw(CExoResMan* thisPtr, CRes*, int32_t, char*);
int32_t CExoResMan__ServiceFromResFile(CExoResMan* thisPtr, CRes*, int32_t);
int32_t CExoResMan__ServiceFromResFileRaw(CExoResMan* thisPtr, CRes*, int32_t, char*);
void CExoResMan__SetResObject(CExoResMan* thisPtr, const CResRef&, uint16_t, CRes*);
int32_t CExoResMan__SetTotalResourceMemory(CExoResMan* thisPtr, int32_t);
void CExoResMan__SuspendServicing(CExoResMan* thisPtr);
void CExoResMan__Update(CExoResMan* thisPtr, uint32_t);
int32_t CExoResMan__UpdateEncapsulatedResourceFile(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__UpdateFixedKeyTableFile(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__UpdateKeyTable(CExoResMan* thisPtr, const CExoString&, uint32_t);
int32_t CExoResMan__UpdateResourceDirectory(CExoResMan* thisPtr, const CExoString&);
int32_t CExoResMan__WipeDirectory(CExoResMan* thisPtr, CExoString, int32_t, int32_t, int32_t, int32_t);

}

}
