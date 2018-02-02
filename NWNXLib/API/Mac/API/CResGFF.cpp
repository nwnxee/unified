#include "CResGFF.hpp"
#include "API/Functions.hpp"
#include "Platform/ASLR.hpp"

#include "CExoFile.hpp"
#include "CResGFFField.hpp"
#include "CResGFFFileHeader.hpp"
#include "CResGFFLabel.hpp"
#include "CResGFFStruct.hpp"
#include "CResList.hpp"
#include "CResStruct.hpp"

namespace NWNXLib {

namespace API {

CResGFF::CResGFF()
{
    CResGFF__CResGFFCtor__0(this);
}

CResGFF::CResGFF(uint16_t a0, char* a1, const CResRef& a2)
{
    CResGFF__CResGFFCtor__2(this, a0, a1, a2);
}

CResGFF::~CResGFF()
{
    CResGFF__CResGFFDtor__0(this);
}

unsigned char* CResGFF::AddDataField(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CResGFF__AddDataField(this, a0, a1, a2);
}

unsigned char* CResGFF::AddDataLayoutField(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CResGFF__AddDataLayoutField(this, a0, a1, a2);
}

unsigned char* CResGFF::AddDataLayoutList(uint32_t a0, uint32_t a1, uint32_t a2)
{
    return CResGFF__AddDataLayoutList(this, a0, a1, a2);
}

CResGFFField* CResGFF::AddField(CResStruct* a0, char* a1, uint32_t a2)
{
    return CResGFF__AddField(this, a0, a1, a2);
}

uint32_t CResGFF::AddLabel(char* a0)
{
    return CResGFF__AddLabel(this, a0);
}

int32_t CResGFF::AddList(CResList* a0, CResStruct* a1, char* a2)
{
    return CResGFF__AddList(this, a0, a1, a2);
}

int32_t CResGFF::AddListElement(CResStruct* a0, CResList* a1, uint32_t a2)
{
    return CResGFF__AddListElement(this, a0, a1, a2);
}

uint32_t CResGFF::AddStruct(uint32_t a0)
{
    return CResGFF__AddStruct(this, a0);
}

int32_t CResGFF::AddStructToStruct(CResStruct* a0, CResStruct* a1, char* a2, uint32_t a3)
{
    return CResGFF__AddStructToStruct(this, a0, a1, a2, a3);
}

int32_t CResGFF::CreateGFFFile(CResStruct* a0, const CExoString& a1, const CExoString& a2)
{
    return CResGFF__CreateGFFFile(this, a0, a1, a2);
}

int32_t CResGFF::FinalizeSetup()
{
    return CResGFF__FinalizeSetup(this);
}

unsigned char* CResGFF::GetDataField(CResGFFField* a0, uint32_t& a1)
{
    return CResGFF__GetDataField(this, a0, a1);
}

int32_t CResGFF::GetDataFromFile(char* a0)
{
    return CResGFF__GetDataFromFile(this, a0);
}

int32_t CResGFF::GetDataFromPointer(void* a0, int32_t a1)
{
    return CResGFF__GetDataFromPointer(this, a0, a1);
}

unsigned char* CResGFF::GetDataLayoutField(CResGFFField* a0, uint32_t& a1)
{
    return CResGFF__GetDataLayoutField(this, a0, a1);
}

unsigned char* CResGFF::GetDataLayoutList(CResGFFField* a0, uint32_t& a1)
{
    return CResGFF__GetDataLayoutList(this, a0, a1);
}

uint32_t CResGFF::GetElementType(CResStruct* a0)
{
    return CResGFF__GetElementType(this, a0);
}

void CResGFF::GetField(CResStruct* a0, uint32_t a1)
{
    return CResGFF__GetField(this, a0, a1);
}

uint32_t CResGFF::GetFieldByLabel(CResStruct* a0, char* a1)
{
    return CResGFF__GetFieldByLabel(this, a0, a1);
}

uint32_t CResGFF::GetFieldCount(CResStruct* a0)
{
    return CResGFF__GetFieldCount__0(this, a0);
}

uint32_t CResGFF::GetFieldCount(CResGFFStruct* a0)
{
    return CResGFF__GetFieldCount__1(this, a0);
}

char* CResGFF::GetFieldLabel(CResStruct* a0, uint32_t a1)
{
    return CResGFF__GetFieldLabel(this, a0, a1);
}

uint32_t CResGFF::GetFieldSize(CResStruct* a0, char* a1, uint32_t a2)
{
    return CResGFF__GetFieldSize(this, a0, a1, a2);
}

char* CResGFF::GetFieldStringID(CResStruct* a0, uint32_t a1)
{
    return CResGFF__GetFieldStringID(this, a0, a1);
}

uint32_t CResGFF::GetFieldType(CResStruct* a0, char* a1, uint32_t a2)
{
    return CResGFF__GetFieldType(this, a0, a1, a2);
}

void CResGFF::GetGFFFileInfo(CExoString* a0, CExoString* a1)
{
    return CResGFF__GetGFFFileInfo(this, a0, a1);
}

CResGFFLabel* CResGFF::GetLabel(CResStruct* a0, uint32_t a1)
{
    return CResGFF__GetLabel(this, a0, a1);
}

int32_t CResGFF::GetList(CResList* a0, CResStruct* a1, char* a2)
{
    return CResGFF__GetList(this, a0, a1, a2);
}

uint32_t CResGFF::GetListCount(CResList* a0)
{
    return CResGFF__GetListCount(this, a0);
}

int32_t CResGFF::GetListElement(CResStruct* a0, CResList* a1, uint32_t a2)
{
    return CResGFF__GetListElement(this, a0, a1, a2);
}

CResGFFStruct* CResGFF::GetStruct(CResStruct* a0)
{
    return CResGFF__GetStruct(this, a0);
}

int32_t CResGFF::GetStructFromStruct(CResStruct* a0, CResStruct* a1, char* a2)
{
    return CResGFF__GetStructFromStruct(this, a0, a1, a2);
}

int32_t CResGFF::GetTopLevelStruct(CResStruct* a0)
{
    return CResGFF__GetTopLevelStruct(this, a0);
}

uint32_t CResGFF::GetTotalSize()
{
    return CResGFF__GetTotalSize(this);
}

void CResGFF::InitializeForWriting()
{
    return CResGFF__InitializeForWriting(this);
}

int32_t CResGFF::IsDataInPlace(uint32_t a0)
{
    return CResGFF__IsDataInPlace(this, a0);
}

int32_t CResGFF::OnResourceFreed()
{
    return CResGFF__OnResourceFreed(this);
}

int32_t CResGFF::OnResourceServiced()
{
    return CResGFF__OnResourceServiced(this);
}

void CResGFF::Pack(unsigned char a0, uint32_t a1)
{
    return CResGFF__Pack(this, a0, a1);
}

int32_t CResGFF::PrepareHeader()
{
    return CResGFF__PrepareHeader(this);
}

unsigned char CResGFF::ReadFieldBYTE(CResStruct* a0, char* a1, int32_t& a2, unsigned char a3)
{
    return CResGFF__ReadFieldBYTE(this, a0, a1, a2, a3);
}

CExoLocString CResGFF::ReadFieldCExoLocString(CResStruct* a0, char* a1, int32_t& a2, const CExoLocString& a3)
{
    return CResGFF__ReadFieldCExoLocString(this, a0, a1, a2, a3);
}

CExoString CResGFF::ReadFieldCExoString(CResStruct* a0, char* a1, int32_t& a2, const CExoString& a3)
{
    return CResGFF__ReadFieldCExoString(this, a0, a1, a2, a3);
}

char CResGFF::ReadFieldCHAR(CResStruct* a0, char* a1, int32_t& a2, char a3)
{
    return CResGFF__ReadFieldCHAR(this, a0, a1, a2, a3);
}

CResRef CResGFF::ReadFieldCResRef(CResStruct* a0, char* a1, int32_t& a2, const CResRef& a3)
{
    return CResGFF__ReadFieldCResRef(this, a0, a1, a2, a3);
}

double CResGFF::ReadFieldDOUBLE(CResStruct* a0, char* a1, int32_t& a2, double a3)
{
    return CResGFF__ReadFieldDOUBLE(this, a0, a1, a2, a3);
}

uint32_t CResGFF::ReadFieldDWORD(CResStruct* a0, char* a1, int32_t& a2, uint32_t a3)
{
    return CResGFF__ReadFieldDWORD(this, a0, a1, a2, a3);
}

uint64_t CResGFF::ReadFieldDWORD64(CResStruct* a0, char* a1, int32_t& a2, uint64_t a3)
{
    return CResGFF__ReadFieldDWORD64(this, a0, a1, a2, a3);
}

float CResGFF::ReadFieldFLOAT(CResStruct* a0, char* a1, int32_t& a2, float a3)
{
    return CResGFF__ReadFieldFLOAT(this, a0, a1, a2, a3);
}

int32_t CResGFF::ReadFieldINT(CResStruct* a0, char* a1, int32_t& a2, int32_t a3)
{
    return CResGFF__ReadFieldINT(this, a0, a1, a2, a3);
}

int64_t CResGFF::ReadFieldINT64(CResStruct* a0, char* a1, int32_t& a2, int64_t a3)
{
    return CResGFF__ReadFieldINT64(this, a0, a1, a2, a3);
}

int16_t CResGFF::ReadFieldSHORT(CResStruct* a0, char* a1, int32_t& a2, int16_t a3)
{
    return CResGFF__ReadFieldSHORT(this, a0, a1, a2, a3);
}

void* CResGFF::ReadFieldVOID(CResStruct* a0, void* a1, uint32_t a2, char* a3, int32_t& a4, void* a5)
{
    return CResGFF__ReadFieldVOID(this, a0, a1, a2, a3, a4, a5);
}

uint16_t CResGFF::ReadFieldWORD(CResStruct* a0, char* a1, int32_t& a2, uint16_t a3)
{
    return CResGFF__ReadFieldWORD(this, a0, a1, a2, a3);
}

void CResGFF::ReleaseResource()
{
    return CResGFF__ReleaseResource(this);
}

int32_t CResGFF::ValidateAndSetup()
{
    return CResGFF__ValidateAndSetup(this);
}

int32_t CResGFF::WriteFieldBYTE(CResStruct* a0, unsigned char a1, char* a2)
{
    return CResGFF__WriteFieldBYTE(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldCExoLocString(CResStruct* a0, CExoLocString a1, char* a2)
{
    return CResGFF__WriteFieldCExoLocString(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldCExoString(CResStruct* a0, const CExoString& a1, char* a2)
{
    return CResGFF__WriteFieldCExoString(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldCHAR(CResStruct* a0, char a1, char* a2)
{
    return CResGFF__WriteFieldCHAR(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldCResRef(CResStruct* a0, const CResRef& a1, char* a2)
{
    return CResGFF__WriteFieldCResRef(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldDOUBLE(CResStruct* a0, double a1, char* a2)
{
    return CResGFF__WriteFieldDOUBLE(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldDWORD(CResStruct* a0, uint32_t a1, char* a2)
{
    return CResGFF__WriteFieldDWORD(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldDWORD64(CResStruct* a0, uint64_t a1, char* a2)
{
    return CResGFF__WriteFieldDWORD64(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldFLOAT(CResStruct* a0, float a1, char* a2)
{
    return CResGFF__WriteFieldFLOAT(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldINT(CResStruct* a0, int32_t a1, char* a2)
{
    return CResGFF__WriteFieldINT(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldINT64(CResStruct* a0, int64_t a1, char* a2)
{
    return CResGFF__WriteFieldINT64(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldSHORT(CResStruct* a0, int16_t a1, char* a2)
{
    return CResGFF__WriteFieldSHORT(this, a0, a1, a2);
}

int32_t CResGFF::WriteFieldVOID(CResStruct* a0, const void* a1, uint32_t a2, char* a3)
{
    return CResGFF__WriteFieldVOID(this, a0, a1, a2, a3);
}

int32_t CResGFF::WriteFieldWORD(CResStruct* a0, uint16_t a1, char* a2)
{
    return CResGFF__WriteFieldWORD(this, a0, a1, a2);
}

int32_t CResGFF::WriteGFFData(CExoFile& a0, uint32_t& a1)
{
    return CResGFF__WriteGFFData(this, a0, a1);
}

int32_t CResGFF::WriteGFFFile(char* a0)
{
    return CResGFF__WriteGFFFile__0(this, a0);
}

int32_t CResGFF::WriteGFFFile(const CExoString& a0, uint16_t a1)
{
    return CResGFF__WriteGFFFile__1(this, a0, a1);
}

int32_t CResGFF::WriteGFFToPointer(void** a0, int32_t& a1)
{
    return CResGFF__WriteGFFToPointer(this, a0, a1);
}

void CResGFF__CResGFFCtor__0(CResGFF* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__CResGFFCtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr);
}

void CResGFF__CResGFFCtor__2(CResGFF* thisPtr, uint16_t a0, char* a1, const CResRef& a2)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*, uint16_t, char*, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__CResGFFCtor__2);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1, a2);
}

void CResGFF__CResGFFDtor__0(CResGFF* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*, int);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__CResGFFDtor__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, 2);
}

unsigned char* CResGFF__AddDataField(CResGFF* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResGFF*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddDataField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char* CResGFF__AddDataLayoutField(CResGFF* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResGFF*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddDataLayoutField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

unsigned char* CResGFF__AddDataLayoutList(CResGFF* thisPtr, uint32_t a0, uint32_t a1, uint32_t a2)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResGFF*, uint32_t, uint32_t, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddDataLayoutList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CResGFFField* CResGFF__AddField(CResGFF* thisPtr, CResStruct* a0, char* a1, uint32_t a2)
{
    using FuncPtrType = CResGFFField*(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CResGFF__AddLabel(CResGFF* thisPtr, char* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddLabel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__AddList(CResGFF* thisPtr, CResList* a0, CResStruct* a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResList*, CResStruct*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__AddListElement(CResGFF* thisPtr, CResStruct* a0, CResList* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, CResList*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddListElement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CResGFF__AddStruct(CResGFF* thisPtr, uint32_t a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddStruct);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__AddStructToStruct(CResGFF* thisPtr, CResStruct* a0, CResStruct* a1, char* a2, uint32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, CResStruct*, char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__AddStructToStruct);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CResGFF__CreateGFFFile(CResGFF* thisPtr, CResStruct* a0, const CExoString& a1, const CExoString& a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, const CExoString&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__CreateGFFFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__FinalizeSetup(CResGFF* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__FinalizeSetup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char* CResGFF__GetDataField(CResGFF* thisPtr, CResGFFField* a0, uint32_t& a1)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResGFF*, CResGFFField*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetDataField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CResGFF__GetDataFromFile(CResGFF* thisPtr, char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetDataFromFile);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__GetDataFromPointer(CResGFF* thisPtr, void* a0, int32_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, void*, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetDataFromPointer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char* CResGFF__GetDataLayoutField(CResGFF* thisPtr, CResGFFField* a0, uint32_t& a1)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResGFF*, CResGFFField*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetDataLayoutField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

unsigned char* CResGFF__GetDataLayoutList(CResGFF* thisPtr, CResGFFField* a0, uint32_t& a1)
{
    using FuncPtrType = unsigned char*(__attribute__((cdecl)) *)(CResGFF*, CResGFFField*, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetDataLayoutList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CResGFF__GetElementType(CResGFF* thisPtr, CResStruct* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetElementType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

void CResGFF__GetField(CResGFF* thisPtr, CResStruct* a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetField);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    func(thisPtr, a0, a1);
}

uint32_t CResGFF__GetFieldByLabel(CResGFF* thisPtr, CResStruct* a0, char* a1)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldByLabel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CResGFF__GetFieldCount__0(CResGFF* thisPtr, CResStruct* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldCount__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CResGFF__GetFieldCount__1(CResGFF* thisPtr, CResGFFStruct* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResGFFStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldCount__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

char* CResGFF__GetFieldLabel(CResGFF* thisPtr, CResStruct* a0, uint32_t a1)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldLabel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CResGFF__GetFieldSize(CResGFF* thisPtr, CResStruct* a0, char* a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

char* CResGFF__GetFieldStringID(CResGFF* thisPtr, CResStruct* a0, uint32_t a1)
{
    using FuncPtrType = char*(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldStringID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

uint32_t CResGFF__GetFieldType(CResGFF* thisPtr, CResStruct* a0, char* a1, uint32_t a2)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetFieldType);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

void CResGFF__GetGFFFileInfo(CResGFF* thisPtr, CExoString* a0, CExoString* a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*, CExoString*, CExoString*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetGFFFileInfo);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

CResGFFLabel* CResGFF__GetLabel(CResGFF* thisPtr, CResStruct* a0, uint32_t a1)
{
    using FuncPtrType = CResGFFLabel*(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetLabel);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CResGFF__GetList(CResGFF* thisPtr, CResList* a0, CResStruct* a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResList*, CResStruct*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetList);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

uint32_t CResGFF__GetListCount(CResGFF* thisPtr, CResList* a0)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResList*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetListCount);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__GetListElement(CResGFF* thisPtr, CResStruct* a0, CResList* a1, uint32_t a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, CResList*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetListElement);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

CResGFFStruct* CResGFF__GetStruct(CResGFF* thisPtr, CResStruct* a0)
{
    using FuncPtrType = CResGFFStruct*(__attribute__((cdecl)) *)(CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetStruct);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__GetStructFromStruct(CResGFF* thisPtr, CResStruct* a0, CResStruct* a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, CResStruct*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetStructFromStruct);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__GetTopLevelStruct(CResGFF* thisPtr, CResStruct* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetTopLevelStruct);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

uint32_t CResGFF__GetTotalSize(CResGFF* thisPtr)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__GetTotalSize);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CResGFF__InitializeForWriting(CResGFF* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__InitializeForWriting);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResGFF__IsDataInPlace(CResGFF* thisPtr, uint32_t a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__IsDataInPlace);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__OnResourceFreed(CResGFF* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__OnResourceFreed);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResGFF__OnResourceServiced(CResGFF* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__OnResourceServiced);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

void CResGFF__Pack(CResGFF* thisPtr, unsigned char a0, uint32_t a1)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*, unsigned char, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__Pack);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CResGFF__PrepareHeader(CResGFF* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__PrepareHeader);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

unsigned char CResGFF__ReadFieldBYTE(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, unsigned char a3)
{
    using FuncPtrType = unsigned char(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, unsigned char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldBYTE);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

CExoLocString CResGFF__ReadFieldCExoLocString(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, const CExoLocString& a3)
{
    using FuncPtrType = CExoLocString(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, const CExoLocString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldCExoLocString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

CExoString CResGFF__ReadFieldCExoString(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, const CExoString& a3)
{
    using FuncPtrType = CExoString(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, const CExoString&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldCExoString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

char CResGFF__ReadFieldCHAR(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, char a3)
{
    using FuncPtrType = char(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, char);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldCHAR);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

CResRef CResGFF__ReadFieldCResRef(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, const CResRef& a3)
{
    using FuncPtrType = CResRef(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, const CResRef&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldCResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

double CResGFF__ReadFieldDOUBLE(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, double a3)
{
    using FuncPtrType = double(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, double);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldDOUBLE);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint32_t CResGFF__ReadFieldDWORD(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, uint32_t a3)
{
    using FuncPtrType = uint32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, uint32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldDWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

uint64_t CResGFF__ReadFieldDWORD64(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, uint64_t a3)
{
    using FuncPtrType = uint64_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, uint64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldDWORD64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

float CResGFF__ReadFieldFLOAT(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, float a3)
{
    using FuncPtrType = float(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, float);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldFLOAT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CResGFF__ReadFieldINT(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, int32_t a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, int32_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldINT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int64_t CResGFF__ReadFieldINT64(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, int64_t a3)
{
    using FuncPtrType = int64_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, int64_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldINT64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int16_t CResGFF__ReadFieldSHORT(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, int16_t a3)
{
    using FuncPtrType = int16_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, int16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldSHORT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void* CResGFF__ReadFieldVOID(CResGFF* thisPtr, CResStruct* a0, void* a1, uint32_t a2, char* a3, int32_t& a4, void* a5)
{
    using FuncPtrType = void*(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, void*, uint32_t, char*, int32_t&, void*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldVOID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3, a4, a5);
}

uint16_t CResGFF__ReadFieldWORD(CResGFF* thisPtr, CResStruct* a0, char* a1, int32_t& a2, uint16_t a3)
{
    using FuncPtrType = uint16_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char*, int32_t&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReadFieldWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

void CResGFF__ReleaseResource(CResGFF* thisPtr)
{
    using FuncPtrType = void(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ReleaseResource);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResGFF__ValidateAndSetup(CResGFF* thisPtr)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__ValidateAndSetup);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr);
}

int32_t CResGFF__WriteFieldBYTE(CResGFF* thisPtr, CResStruct* a0, unsigned char a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, unsigned char, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldBYTE);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldCExoLocString(CResGFF* thisPtr, CResStruct* a0, CExoLocString a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, CExoLocString, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldCExoLocString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldCExoString(CResGFF* thisPtr, CResStruct* a0, const CExoString& a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, const CExoString&, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldCExoString);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldCHAR(CResGFF* thisPtr, CResStruct* a0, char a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, char, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldCHAR);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldCResRef(CResGFF* thisPtr, CResStruct* a0, const CResRef& a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, const CResRef&, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldCResRef);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldDOUBLE(CResGFF* thisPtr, CResStruct* a0, double a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, double, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldDOUBLE);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldDWORD(CResGFF* thisPtr, CResStruct* a0, uint32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldDWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldDWORD64(CResGFF* thisPtr, CResStruct* a0, uint64_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint64_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldDWORD64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldFLOAT(CResGFF* thisPtr, CResStruct* a0, float a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, float, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldFLOAT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldINT(CResGFF* thisPtr, CResStruct* a0, int32_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, int32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldINT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldINT64(CResGFF* thisPtr, CResStruct* a0, int64_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, int64_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldINT64);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldSHORT(CResGFF* thisPtr, CResStruct* a0, int16_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, int16_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldSHORT);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteFieldVOID(CResGFF* thisPtr, CResStruct* a0, const void* a1, uint32_t a2, char* a3)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, const void*, uint32_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldVOID);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2, a3);
}

int32_t CResGFF__WriteFieldWORD(CResGFF* thisPtr, CResStruct* a0, uint16_t a1, char* a2)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CResStruct*, uint16_t, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteFieldWORD);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1, a2);
}

int32_t CResGFF__WriteGFFData(CResGFF* thisPtr, CExoFile& a0, uint32_t& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, CExoFile&, uint32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteGFFData);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CResGFF__WriteGFFFile__0(CResGFF* thisPtr, char* a0)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, char*);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteGFFFile__0);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0);
}

int32_t CResGFF__WriteGFFFile__1(CResGFF* thisPtr, const CExoString& a0, uint16_t a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, const CExoString&, uint16_t);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteGFFFile__1);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

int32_t CResGFF__WriteGFFToPointer(CResGFF* thisPtr, void** a0, int32_t& a1)
{
    using FuncPtrType = int32_t(__attribute__((cdecl)) *)(CResGFF*, void**, int32_t&);
    uintptr_t address = Platform::ASLR::GetRelocatedAddress(Functions::CResGFF__WriteGFFToPointer);
    FuncPtrType func = reinterpret_cast<FuncPtrType>(address);
    return func(thisPtr, a0, a1);
}

}

}
