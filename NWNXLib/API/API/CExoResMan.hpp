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
#include "CNWSync.hpp"
#include "SHA1.hpp"

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoResMan)
#endif

struct CExoFile;
struct CExoKeyTable;
struct CExoStringList;
struct CKeyTableEntry;

typedef int BOOL;
typedef uint16_t RESTYPE;
typedef bool (*ResourceAccessCheckFn)(CExoKeyTable*, const CResRef&, RESTYPE);

struct CExoResMan
{
    int64_t m_nTotalPhysicalMemory;
    int64_t m_nTotalAvailableMemory;
    int64_t m_nAvailableMemory;
    CExoArrayList<CExoKeyTable *> m_pKeyTables;
    CExoLinkedList<CRes> m_lstToBeFreed;
    uint32_t m_nTotalDemands;
    uint32_t m_nTotalCacheHits;
    uint32_t m_nTotalOldReleases;
    uint32_t m_nTotalNewReleases;
    uint32_t m_nTotalLookupFailures;
    bool m_bLogLookupFailures;
    CResRef m_cLastFailedLookup;
    RESTYPE m_nLastFailedLookupType;
    BOOL m_bOverrideAll;
    NWSync::CNWSync m_cNWSync;
    void * m_pResourceOverrideMap;

    CExoResMan();
    ~CExoResMan();
    void SetupDefaultSearchPath();
    BOOL AddEncapsulatedResourceFile(const CExoString & sName, uint32_t nPriority);
    BOOL AddFixedKeyTableFile(const CExoString & sName, uint32_t nPriority = (1*1000000));
    BOOL AddResourceDirectory(const CExoString & sName, uint32_t nPriority, BOOL bDetectChanges = false, const ResourceAccessCheckFn accessCheck = nullptr);
    BOOL AddManifest(const Hash::SHA1 & manifestHash, uint32_t nPriority);
    void DumpAll();
    void DumpAllOfType(RESTYPE nType);
    void FreeResourceData(CRes * pRes);
    BOOL Exists(const CResRef & cResRef, RESTYPE nType, uint32_t * pTableType = nullptr);
    DataBlockRef Get(const CResRef & cResRef, RESTYPE nType);
    CExoLocString GetEncapsulatedFileDescription(const CExoString & sFileName);
    CRes * GetResObject(const CResRef & cResRef, RESTYPE nType);
    CExoStringList * GetResOfType(RESTYPE nType, BOOL bERFOnly = false);
    CExoStringList * GetResOfType(RESTYPE nType, CRes * pRes);
    RESID GetResID(const CResRef & cResRef, RESTYPE nType);
    int64_t GetTotalPhysicalMemory();
    int32_t ReleaseResObject(CRes * pRes, bool bDontCache = false);
    BOOL RemoveEncapsulatedResourceFile(const CExoString & sName, BOOL bEmitWarningOnFailure = true);
    BOOL RemoveFixedKeyTableFile(const CExoString & sName);
    BOOL RemoveResourceDirectory(const CExoString & sName);
    BOOL RemoveManifest(const Hash::SHA1 & sManifestHash);
    void SetResObject(const CResRef & cResRef, RESTYPE nType, CRes * pNewRes);
    BOOL SetTotalResourceMemory(int64_t totalAvailableMemory);
    void Update(uint32_t nTimeSlice);
    BOOL UpdateEncapsulatedResourceFile(const CExoString & sName);
    BOOL UpdateFixedKeyTableFile(const CExoString & sName);
    BOOL UpdateResourceDirectory(const CExoString & sName);
    BOOL UpdateManifest(const CExoString & sManifestHash);
    RESTYPE GetResTypeFromFile(const CExoString & sName);
    void GetResRefFromFile(CResRef & cResRef, const CExoString & sName);
    BOOL GetKeyEntry(const CResRef & cResRef, RESTYPE nType, CExoKeyTable * * pNewTable, CKeyTableEntry * * pNewKey, bool bLogFailure = true);
    void * Demand(CRes * pRes);
    void Dump(CRes * pRes, BOOL bRemove = false);
    int32_t Release(CRes * pRes);
    BOOL ReadRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL GetNewResRef(const CResRef & cResRef, RESTYPE nType, CResRef & cTarget);
    BOOL CreateDirectory(CExoString sDirectory);
    BOOL NukeDirectory(CExoString sDirectory, BOOL bDeleteAllFiles = false, BOOL bDeleteAllSubDirectories = false);
    BOOL CleanDirectory(CExoString sDirectory, BOOL bDeleteSubDirectories = false, BOOL bCleanSubDirectories = false, RESTYPE restype = 0xFFFF);
    BOOL RemoveFile(const CExoString & sFile, RESTYPE nResType);
    BOOL GetFreeDiskSpace(const CExoString & sDirectory, uint64_t * pSpaceAvailable);
    int32_t GetTableCount(CRes * pRes, BOOL bCountStatic);
    BOOL GetIsStaticType(RESTYPE nType);
    void RemoveFromToBeFreedList(CRes * pRes);
    BOOL AddKeyTable(uint32_t nPriority, const CExoString & sName, uint32_t nTableType, BOOL bDetectChanges = false, const ResourceAccessCheckFn accessCheck = nullptr);
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
    BOOL ServiceFromDirectory(CRes * pRes);
    BOOL ServiceFromEncapsulated(CRes * pRes);
    BOOL ServiceFromResFile(CRes * pRes);
    BOOL ServiceFromManifest(CRes * pRes);
    BOOL UpdateKeyTable(const CExoString & sName, uint32_t nTableType);
    BOOL ServiceFromDirectoryRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL ServiceFromEncapsulatedRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    BOOL ServiceFromResFileRaw(CRes * pRes, int32_t nSize, char * pBuffer);
    CResRef GetOverride(const CResRef & name, RESTYPE restype);


#ifdef NWN_CLASS_EXTENSION_CExoResMan
    NWN_CLASS_EXTENSION_CExoResMan
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoResMan)
#endif
