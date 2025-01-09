#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "CKeyTableInfo.hpp"
#include "RESID.hpp"
#include "CExoResMan.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoKeyTable)
#endif

struct CExoPackedFile;
struct CExoStringList;
struct CKeyTableEntry;
struct CRes;
struct CResRef;


typedef int BOOL;
typedef uint16_t RESTYPE;


struct CExoKeyTable
{
    BOOL m_bLoaded;
    BOOL m_bExcludeFromSearches;
    uint32_t m_nTableEntries;
    CKeyTableEntry * m_pEntries;
    uint32_t m_nSearchs;
    uint32_t m_nWorstSearch;
    uint32_t m_nTableType;
    CExoString m_sName;
    CExoString m_sDirectory;
    uint32_t m_nTableID;
    uint32_t m_nNumPackedFiles;
    CExoPackedFile * * m_pExoPackedFile;
    BOOL m_bIsOverride;
    ResourceAccessCheckFn m_resourceAccessCheck;
    BOOL m_bAllowDynamicReload;
    CExoString m_sResolvedAliasCache;
    long m_nLastModified;

    CExoKeyTable();
    ~CExoKeyTable();
    BOOL AddDirectoryContents(BOOL bPopulateTable = true);
    BOOL AddEncapsulatedContents(BOOL bPopulateTable = true);
    BOOL AddManifestContents(BOOL bPopulateTable = true);
    CKeyTableEntry * AddKey(const CResRef & cNewResRef, RESTYPE nType, RESID nNewResID, BOOL bPopulateEntry);
    BOOL AddKeyTableContents(BOOL bPopulateTable = true);
    CKeyTableEntry * AllocateTable(uint32_t nTableEntries, BOOL bKeepInMemory = false);
    BOOL BuildNewTable(uint32_t nTableType, const CExoString & sName, uint32_t nTableID, BOOL bPopulateTable = true, const ResourceAccessCheckFn accessCheck = nullptr);
    void DeleteTableList(CExoLinkedList<CKeyTableInfo> * lKeyTables);
    void DestroyTable();
    CKeyTableEntry * FindKey(const CResRef & cResRef, RESTYPE nType);
    CKeyTableEntry * FindKey(CRes * pRes);
    CExoStringList * GetKeysOfType(RESTYPE nType);
    CRes * GetRes(const CResRef & cResRef, RESTYPE nType);
    RESID GetResID(const CResRef & cResRef, RESTYPE nType);
    BOOL GetTableEntry(uint32_t nIndex, CResRef & cResRef, RESTYPE & nType);
    BOOL GetTableIndex(uint32_t & nIndex, const CResRef & cResRef, RESTYPE nType);
    uint32_t Hash(const CResRef & cResRef, RESTYPE nType);
    BOOL LocateBifFile(const CExoString & sFileName);
    void RebuildTable();
    int32_t GetEntryCount(BOOL bCountStatic);
    void SetAllowDynamicReload(BOOL v);
    void DropContentsFromCache();
    BOOL CheckForModificationsInStorage();


#ifdef NWN_CLASS_EXTENSION_CExoKeyTable
    NWN_CLASS_EXTENSION_CExoKeyTable
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoKeyTable)
#endif

