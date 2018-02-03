#include "CExoKeyTable.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoLinkedListTemplatedCKeyTableInfo.hpp"
#include "CExoPackedFile.hpp"
#include "CExoStringList.hpp"
#include "CKeyTableEntry.hpp"
#include "CRes.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

CExoKeyTable::CExoKeyTable()
{
    CExoKeyTable__CExoKeyTableCtor(this);
}

CExoKeyTable::~CExoKeyTable()
{
    CExoKeyTable__CExoKeyTableDtor(this);
}

int32_t CExoKeyTable::AddDirectoryContents(int32_t a0)
{
    return CExoKeyTable__AddDirectoryContents(this, a0);
}

int32_t CExoKeyTable::AddEncapsulatedContents(int32_t a0)
{
    return CExoKeyTable__AddEncapsulatedContents(this, a0);
}

CKeyTableEntry* CExoKeyTable::AddKey(const CResRef& a0, uint16_t a1, uint32_t a2, int32_t a3)
{
    return CExoKeyTable__AddKey(this, a0, a1, a2, a3);
}

int32_t CExoKeyTable::AddKeyTableContents(int32_t a0)
{
    return CExoKeyTable__AddKeyTableContents(this, a0);
}

int32_t CExoKeyTable::AddResourceImageContents(int32_t a0, unsigned char* a1)
{
    return CExoKeyTable__AddResourceImageContents(this, a0, a1);
}

CKeyTableEntry* CExoKeyTable::AllocateTable(uint32_t a0, int32_t a1)
{
    return CExoKeyTable__AllocateTable(this, a0, a1);
}

int32_t CExoKeyTable::BuildNewTable(uint32_t a0, const CExoString& a1, uint32_t a2, int32_t a3, unsigned char* a4)
{
    return CExoKeyTable__BuildNewTable(this, a0, a1, a2, a3, a4);
}

void CExoKeyTable::DeleteTableList(CExoLinkedListTemplatedCKeyTableInfo* a0)
{
    return CExoKeyTable__DeleteTableList(this, a0);
}

void CExoKeyTable::DestroyTable()
{
    return CExoKeyTable__DestroyTable(this);
}

CKeyTableEntry* CExoKeyTable::FindKey(CRes* a0)
{
    return CExoKeyTable__FindKey__0(this, a0);
}

CKeyTableEntry* CExoKeyTable::FindKey(const CResRef& a0, uint16_t a1)
{
    return CExoKeyTable__FindKey__1(this, a0, a1);
}

int32_t CExoKeyTable::GetEntryCount(int32_t a0)
{
    return CExoKeyTable__GetEntryCount(this, a0);
}

CExoStringList* CExoKeyTable::GetKeysOfType(uint16_t a0)
{
    return CExoKeyTable__GetKeysOfType(this, a0);
}

CRes* CExoKeyTable::GetRes(const CResRef& a0, uint16_t a1)
{
    return CExoKeyTable__GetRes(this, a0, a1);
}

uint32_t CExoKeyTable::GetResID(const CResRef& a0, uint16_t a1)
{
    return CExoKeyTable__GetResID(this, a0, a1);
}

int32_t CExoKeyTable::GetTableEntry(uint32_t a0, CResRef& a1, uint16_t& a2)
{
    return CExoKeyTable__GetTableEntry(this, a0, a1, a2);
}

int32_t CExoKeyTable::GetTableIndex(uint32_t& a0, const CResRef& a1, uint16_t a2)
{
    return CExoKeyTable__GetTableIndex(this, a0, a1, a2);
}

uint32_t CExoKeyTable::Hash(const CResRef& a0, uint16_t a1)
{
    return CExoKeyTable__Hash(this, a0, a1);
}

int32_t CExoKeyTable::LocateBifFile(const CExoString& a0)
{
    return CExoKeyTable__LocateBifFile(this, a0);
}

void CExoKeyTable::RebuildTable(unsigned char* a0)
{
    return CExoKeyTable__RebuildTable(this, a0);
}

void CExoKeyTable__CExoKeyTableCtor(CExoKeyTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoKeyTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__CExoKeyTableCtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CExoKeyTable__CExoKeyTableDtor(CExoKeyTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoKeyTable*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__CExoKeyTableDtor);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

int32_t CExoKeyTable__AddDirectoryContents(CExoKeyTable* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__AddDirectoryContents);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoKeyTable__AddEncapsulatedContents(CExoKeyTable* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__AddEncapsulatedContents);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CKeyTableEntry* CExoKeyTable__AddKey(CExoKeyTable* thisPtr, const CResRef& a0, uint16_t a1, uint32_t a2, int32_t a3)
{
    using FuncPtrType = CKeyTableEntry*(__attribute__((cdecl)) *)(CExoKeyTable*, const CResRef&, uint16_t, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__AddKey);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CExoKeyTable__AddKeyTableContents(CExoKeyTable* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__AddKeyTableContents);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CExoKeyTable__AddResourceImageContents(CExoKeyTable* thisPtr, int32_t a0, unsigned char* a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, int32_t, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__AddResourceImageContents);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CKeyTableEntry* CExoKeyTable__AllocateTable(CExoKeyTable* thisPtr, uint32_t a0, int32_t a1)
{
    using FuncPtrType = CKeyTableEntry*(__attribute__((cdecl)) *)(CExoKeyTable*, uint32_t, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__AllocateTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoKeyTable__BuildNewTable(CExoKeyTable* thisPtr, uint32_t a0, const CExoString& a1, uint32_t a2, int32_t a3, unsigned char* a4)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, uint32_t, const CExoString&, uint32_t, int32_t, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__BuildNewTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4);
}

void CExoKeyTable__DeleteTableList(CExoKeyTable* thisPtr, CExoLinkedListTemplatedCKeyTableInfo* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoKeyTable*, CExoLinkedListTemplatedCKeyTableInfo*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__DeleteTableList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoKeyTable__DestroyTable(CExoKeyTable* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoKeyTable*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__DestroyTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

CKeyTableEntry* CExoKeyTable__FindKey__0(CExoKeyTable* thisPtr, CRes* a0)
{
    using FuncPtrType = CKeyTableEntry*(__attribute__((cdecl)) *)(CExoKeyTable*, CRes*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__FindKey__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CKeyTableEntry* CExoKeyTable__FindKey__1(CExoKeyTable* thisPtr, const CResRef& a0, uint16_t a1)
{
    using FuncPtrType = CKeyTableEntry*(__attribute__((cdecl)) *)(CExoKeyTable*, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__FindKey__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoKeyTable__GetEntryCount(CExoKeyTable* thisPtr, int32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__GetEntryCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CExoStringList* CExoKeyTable__GetKeysOfType(CExoKeyTable* thisPtr, uint16_t a0)
{
    using FuncPtrType = CExoStringList*(__attribute__((cdecl)) *)(CExoKeyTable*, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__GetKeysOfType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

CRes* CExoKeyTable__GetRes(CExoKeyTable* thisPtr, const CResRef& a0, uint16_t a1)
{
    using FuncPtrType = CRes*(__attribute__((cdecl)) *)(CExoKeyTable*, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__GetRes);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CExoKeyTable__GetResID(CExoKeyTable* thisPtr, const CResRef& a0, uint16_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoKeyTable*, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__GetResID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoKeyTable__GetTableEntry(CExoKeyTable* thisPtr, uint32_t a0, CResRef& a1, uint16_t& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, uint32_t, CResRef&, uint16_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__GetTableEntry);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CExoKeyTable__GetTableIndex(CExoKeyTable* thisPtr, uint32_t& a0, const CResRef& a1, uint16_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, uint32_t&, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__GetTableIndex);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CExoKeyTable__Hash(CExoKeyTable* thisPtr, const CResRef& a0, uint16_t a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CExoKeyTable*, const CResRef&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__Hash);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CExoKeyTable__LocateBifFile(CExoKeyTable* thisPtr, const CExoString& a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CExoKeyTable*, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__LocateBifFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CExoKeyTable__RebuildTable(CExoKeyTable* thisPtr, unsigned char* a0)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CExoKeyTable*, unsigned char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CExoKeyTable__RebuildTable);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

}

}
