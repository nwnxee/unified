#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoLinkedListTemplatedCKeyTableInfo;
struct CExoPackedFile;
struct CExoStringList;
struct CKeyTableEntry;
struct CRes;
struct CResRef;

struct CExoKeyTable
{
    int32_t m_bLoaded;
    int32_t m_bExcludeFromSearches;
    uint32_t m_nTableEntries;
    CKeyTableEntry* m_pEntries;
    uint32_t m_nSearchs;
    uint32_t m_nWorstSearch;
    uint32_t m_nTableType;
    CExoString m_sName;
    CExoString m_sDirectory;
    uint32_t m_nTableID;
    uint32_t m_nNumPackedFiles;
    CExoPackedFile** m_pExoPackedFile;

    // The below are auto generated stubs.
    CExoKeyTable(const CExoKeyTable&) = default;
    CExoKeyTable& operator=(const CExoKeyTable&) = default;

    CExoKeyTable();
    ~CExoKeyTable();
    int32_t AddDirectoryContents(int32_t);
    int32_t AddEncapsulatedContents(int32_t);
    CKeyTableEntry* AddKey(const CResRef&, uint16_t, uint32_t, int32_t);
    int32_t AddKeyTableContents(int32_t);
    int32_t AddResourceImageContents(int32_t, unsigned char*);
    CKeyTableEntry* AllocateTable(uint32_t, int32_t);
    int32_t BuildNewTable(uint32_t, const CExoString&, uint32_t, int32_t, unsigned char*);
    void DeleteTableList(CExoLinkedListTemplatedCKeyTableInfo*);
    void DestroyTable();
    CKeyTableEntry* FindKey(CRes*);
    CKeyTableEntry* FindKey(const CResRef&, uint16_t);
    int32_t GetEntryCount(int32_t);
    CExoStringList* GetKeysOfType(uint16_t);
    CRes* GetRes(const CResRef&, uint16_t);
    uint32_t GetResID(const CResRef&, uint16_t);
    int32_t GetTableEntry(uint32_t, CResRef&, uint16_t&);
    int32_t GetTableIndex(uint32_t&, const CResRef&, uint16_t);
    uint32_t Hash(const CResRef&, uint16_t);
    int32_t LocateBifFile(const CExoString&);
    void RebuildTable(unsigned char*);
};

void CExoKeyTable__CExoKeyTableCtor__0(CExoKeyTable* thisPtr);
void CExoKeyTable__CExoKeyTableDtor__0(CExoKeyTable* thisPtr);
int32_t CExoKeyTable__AddDirectoryContents(CExoKeyTable* thisPtr, int32_t);
int32_t CExoKeyTable__AddEncapsulatedContents(CExoKeyTable* thisPtr, int32_t);
CKeyTableEntry* CExoKeyTable__AddKey(CExoKeyTable* thisPtr, const CResRef&, uint16_t, uint32_t, int32_t);
int32_t CExoKeyTable__AddKeyTableContents(CExoKeyTable* thisPtr, int32_t);
int32_t CExoKeyTable__AddResourceImageContents(CExoKeyTable* thisPtr, int32_t, unsigned char*);
CKeyTableEntry* CExoKeyTable__AllocateTable(CExoKeyTable* thisPtr, uint32_t, int32_t);
int32_t CExoKeyTable__BuildNewTable(CExoKeyTable* thisPtr, uint32_t, const CExoString&, uint32_t, int32_t, unsigned char*);
void CExoKeyTable__DeleteTableList(CExoKeyTable* thisPtr, CExoLinkedListTemplatedCKeyTableInfo*);
void CExoKeyTable__DestroyTable(CExoKeyTable* thisPtr);
CKeyTableEntry* CExoKeyTable__FindKey__0(CExoKeyTable* thisPtr, CRes*);
CKeyTableEntry* CExoKeyTable__FindKey__1(CExoKeyTable* thisPtr, const CResRef&, uint16_t);
int32_t CExoKeyTable__GetEntryCount(CExoKeyTable* thisPtr, int32_t);
CExoStringList* CExoKeyTable__GetKeysOfType(CExoKeyTable* thisPtr, uint16_t);
CRes* CExoKeyTable__GetRes(CExoKeyTable* thisPtr, const CResRef&, uint16_t);
uint32_t CExoKeyTable__GetResID(CExoKeyTable* thisPtr, const CResRef&, uint16_t);
int32_t CExoKeyTable__GetTableEntry(CExoKeyTable* thisPtr, uint32_t, CResRef&, uint16_t&);
int32_t CExoKeyTable__GetTableIndex(CExoKeyTable* thisPtr, uint32_t&, const CResRef&, uint16_t);
uint32_t CExoKeyTable__Hash(CExoKeyTable* thisPtr, const CResRef&, uint16_t);
int32_t CExoKeyTable__LocateBifFile(CExoKeyTable* thisPtr, const CExoString&);
void CExoKeyTable__RebuildTable(CExoKeyTable* thisPtr, unsigned char*);

}

}
