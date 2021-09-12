#pragma once
#include "nwn_api.hpp"

#include "CExoArrayList.hpp"
#include "CExoLinkedList.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CNWSync.hpp"
#include "CRes.hpp"
#include "CResRef.hpp"
#include "RESID.hpp"

#include <memory>

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoResMan)
#endif

struct CExoFile;
struct CExoKeyTable;
struct CExoKeyTable;
struct CExoStringList;
struct CKeyTableEntry;
struct SHA1;
namespace Hash {
    struct SHA1;
}

typedef int BOOL;
typedef uint16_t RESTYPE;


struct CExoResMan
{
    int64_t m_nTotalPhysicalMemory;
    int64_t m_nTotalAvailableMemory;
    int64_t m_nAvailableMemory;
    CExoArrayList<CExoKeyTable *> m_pKeyTables;
    CExoLinkedList<CRes> m_lstToBeFreed;
    CExoLinkedList<CRes> m_lstAsyncResQueue;
    CRes * m_pCurrentAsyncRes;
    CExoFile * m_pAsyncFile;
    BOOL m_bAsyncSuspended;
    uint32_t m_nTotalDemands;
    uint32_t m_nTotalCacheHits;
    uint32_t m_nTotalOldReleases;
    uint32_t m_nTotalNewReleases;
    uint32_t m_nTotalLookupFailures;
    bool m_bLogLookupFailures;
    CResRef m_cLastFailedLookup;
    RESTYPE m_nLastFailedLookupType;
    BOOL m_bOverrideAll;
    CNWSync m_pNWSync;
    void * m_pResourceOverrideMap;

    CExoResMan();
    ~CExoResMan();
    void SetupDefaultSearchPath();
    BOOL AddEncapsulatedResourceFile(const CExoString & sName, uint32_t nPriority);
    BOOL AddResourceImageFile(const CExoString & sName, uint8_t * pCipher = nullptr, uint32_t nPriority = (60*1000000));
    BOOL AddFixedKeyTableFile(const CExoString & sName, uint32_t nPriority = (1*1000000));
    BOOL AddResourceDirectory(const CExoString & sName, uint32_t nPriority, BOOL bDetectChanges = false);
    BOOL AddManifest(const Hash::SHA1 & manifestHash, uint32_t nPriority);
    void DumpAll();
    void DumpAllOfType(RESTYPE nType);
    void FreeResourceData(CRes * pRes);
    BOOL Exists(const CResRef & cResRef, RESTYPE nType, uint32_t * pTableType = nullptr);
    std::shared_ptr<void*> Get(const CResRef & cResRef, RESTYPE nType);
    CExoLocString GetEncapsulatedFileDescription(const CExoString & sFileName);
    CRes * GetResObject(const CResRef & cResRef, RESTYPE nType);
    CExoStringList * GetResOfType(RESTYPE nType, BOOL bERFOnly = false);
    CExoStringList * GetResOfType(RESTYPE nType, CRes * pRes);
    RESID GetResID(const CResRef & cResRef, RESTYPE nType);
    int64_t GetTotalPhysicalMemory();
    int32_t ReleaseResObject(CRes * pRes, bool bDontCache = false);
    BOOL RemoveEncapsulatedResourceFile(const CExoString & sName, BOOL bEmitWarningOnFailure = true);
    BOOL RemoveResourceImageFile(const CExoString & sName);
    BOOL RemoveFixedKeyTableFile(const CExoString & sName);
    BOOL RemoveResourceDirectory(const CExoString & sName);
    BOOL RemoveManifest(const Hash::SHA1 & sManifestHash);
    void ResumeServicing();
    void SetResObject(const CResRef & cResRef, RESTYPE nType, CRes * pNewRes);
    BOOL SetTotalResourceMemory(int64_t totalAvailableMemory);
    void SuspendServicing();
    void Update(uint32_t nTimeSlice);
    BOOL UpdateEncapsulatedResourceFile(const CExoString & sName);
    BOOL UpdateFixedKeyTableFile(const CExoString & sName);
    BOOL UpdateResourceDirectory(const CExoString & sName);
    BOOL UpdateManifest(const CExoString & sManifestHash);
    RESTYPE GetResTypeFromFile(const CExoString & sName);
    void GetResRefFromFile(CResRef & cResRef, const CExoString & sName);
    BOOL GetKeyEntry(const CResRef & cResRef, RESTYPE nType, CExoKeyTable * * pNewTable, CKeyTableEntry * * pNewKey, bool bLogFailure = true);
    int32_t CancelRequest(CRes * pRes);
    void * Demand(CRes * pRes);
    void Dump(CRes * pRes, BOOL bRemove = false);
    int32_t Release(CRes * pRes);
    int32_t Request(CRes * pRes);
    BOOL ReadRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL GetNewResRef(const CResRef & cResRef, RESTYPE nType, CResRef & cTarget);
    BOOL CreateDirectory(CExoString sDirectory);
    BOOL NukeDirectory(CExoString sDirectory, BOOL bDeleteAllFiles = false, BOOL bDeleteAllSubDirectories = false);
    BOOL CleanDirectory(CExoString sDirectory, BOOL bDeleteSubDirectories = false, BOOL bCleanSubDirectories = false, RESTYPE restype = 0xFFFF);
    BOOL RemoveFile(const CExoString & sFile, RESTYPE nResType);
    BOOL GetFreeDiskSpace(const CExoString & sDirectory, uint64_t * pSpaceAvailable);
    BOOL ServiceCurrentAsyncRes();
    int32_t GetTableCount(CRes * pRes, BOOL bCountStatic);
    BOOL GetIsStaticType(RESTYPE nType);
    void RemoveFromToBeFreedList(CRes * pRes);
    BOOL AddKeyTable(uint32_t nPriority, const CExoString & sName, uint32_t nTableType, uint8_t * pCipher = nullptr, BOOL bDetectChanges = false);
    BOOL RemoveKeyTable(const CExoString & sName, uint32_t nTableType, BOOL bEmitWarningOnFailure = true);
    size_t CountKeyTablesOf(int32_t type, const CExoString & sName = "");
    void AddOverride(const CResRef & oldname, const CResRef & newname, RESTYPE restype);
    void RemoveOverride(const CResRef & name, RESTYPE restype);
    void ClearOverrides();
    BOOL WipeDirectory(CExoString sDirectory, BOOL bDeleteAllFiles, BOOL bRemoveDirectory, BOOL bDeleteAllSubDirectoryFiles, BOOL bDeleteAllSubDirectories, RESTYPE restype = 0xFFFF);
    BOOL Free(CRes * pRes);
    BOOL FreeChunk();
    CExoKeyTable * GetTable(CRes * pRes);
    BOOL Malloc(CRes * pRes);
    BOOL ServiceFromDirectory(CRes * pRes, BOOL bAsync = false);
    BOOL ServiceFromEncapsulated(CRes * pRes, BOOL bAsync = false);
    BOOL ServiceFromResFile(CRes * pRes, BOOL bAsync = false);
    BOOL ServiceFromImage(CRes * pRes, BOOL bAsync = false);
    BOOL ServiceFromManifest(CRes * pRes, BOOL bAsync = false);
    BOOL UpdateKeyTable(const CExoString & sName, uint32_t nTableType);
    BOOL ServiceFromDirectoryRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL ServiceFromEncapsulatedRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL ServiceFromResFileRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL ServiceFromImageRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    CResRef GetOverride(const CResRef & name, RESTYPE restype);


#ifdef NWN_CLASS_EXTENSION_CExoResMan
    NWN_CLASS_EXTENSION_CExoResMan
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoResMan)
#endif

