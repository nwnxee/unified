#pragma once

#include <cstdint>

#include "CExoFile.hpp"
#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CRes.hpp"
#include "CResRef.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CResGFFField;
struct CResGFFFileHeader;
struct CResGFFLabel;
struct CResGFFStruct;
struct CResList;
struct CResStruct;

struct CResGFF
    : CRes
{
    uint32_t STRUCT_GROWSIZE;
    uint32_t FIELD_GROWSIZE;
    uint32_t LABEL_GROWSIZE;
    uint32_t DATAFIELD_GROWSIZE;
    uint32_t DATALAYOUTFIELD_GROWSIZE;
    uint32_t DATALAYOUTLIST_GROWSIZE;
    CResGFFFileHeader* m_pFileHeader;
    uint8_t* m_pDDFileHeader;
    uint32_t m_nHeaderOffset;
    CResGFFStruct* m_pStruct;
    uint32_t m_nStructAllocated;
    CResGFFField* m_pField;
    uint32_t m_nFieldAllocated;
    CResGFFLabel* m_pLabel;
    uint32_t m_nLabelAllocated;
    uint8_t* m_pDataField;
    uint32_t m_nDataFieldAllocated;
    uint8_t* m_pDataLayoutField;
    uint32_t m_nDataLayoutFieldAllocated;
    uint32_t m_nDataLayoutFieldWasted;
    uint8_t* m_pDataLayoutList;
    uint32_t m_nDataLayoutListAllocated;
    uint32_t m_nDataLayoutListWasted;
    char m_pLabelBuffer[17];
    char m_pFileType[4];
    int32_t m_bLoaded;
    int32_t m_bResourceLoaded;
    int32_t m_bSelfDemanded;
    int32_t m_bDataPtrOwned;
    int32_t m_bReplaceExistingFields;
    int32_t m_bValidationFailed;

    // The below are auto generated stubs.
    CResGFF(const CResGFF&) = default;
    CResGFF& operator=(const CResGFF&) = default;

    CResGFF();
    CResGFF(uint16_t, char*, const CResRef&);
    ~CResGFF();
    unsigned char* AddDataField(uint32_t, uint32_t, uint32_t);
    unsigned char* AddDataLayoutField(uint32_t, uint32_t, uint32_t);
    unsigned char* AddDataLayoutList(uint32_t, uint32_t, uint32_t);
    CResGFFField* AddField(CResStruct*, char*, uint32_t);
    uint32_t AddLabel(char*);
    int32_t AddList(CResList*, CResStruct*, char*);
    int32_t AddListElement(CResStruct*, CResList*, uint32_t);
    uint32_t AddStruct(uint32_t);
    int32_t AddStructToStruct(CResStruct*, CResStruct*, char*, uint32_t);
    int32_t CreateGFFFile(CResStruct*, const CExoString&, const CExoString&);
    int32_t FinalizeSetup();
    unsigned char* GetDataField(CResGFFField*, uint32_t&);
    int32_t GetDataFromFile(char*);
    int32_t GetDataFromPointer(void*, int32_t);
    unsigned char* GetDataLayoutField(CResGFFField*, uint32_t&);
    unsigned char* GetDataLayoutList(CResGFFField*, uint32_t&);
    uint32_t GetElementType(CResStruct*);
    void GetField(CResStruct*, uint32_t);
    uint32_t GetFieldByLabel(CResStruct*, char*);
    uint32_t GetFieldCount(CResStruct*);
    uint32_t GetFieldCount(CResGFFStruct*);
    char* GetFieldLabel(CResStruct*, uint32_t);
    uint32_t GetFieldSize(CResStruct*, char*, uint32_t);
    char* GetFieldStringID(CResStruct*, uint32_t);
    uint32_t GetFieldType(CResStruct*, char*, uint32_t);
    void GetGFFFileInfo(CExoString*, CExoString*);
    CResGFFLabel* GetLabel(CResStruct*, uint32_t);
    int32_t GetList(CResList*, CResStruct*, char*);
    uint32_t GetListCount(CResList*);
    int32_t GetListElement(CResStruct*, CResList*, uint32_t);
    CResGFFStruct* GetStruct(CResStruct*);
    int32_t GetStructFromStruct(CResStruct*, CResStruct*, char*);
    int32_t GetTopLevelStruct(CResStruct*);
    uint32_t GetTotalSize();
    void InitializeForWriting();
    int32_t IsDataInPlace(uint32_t);
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
    void Pack(unsigned char, uint32_t);
    int32_t PrepareHeader();
    unsigned char ReadFieldBYTE(CResStruct*, char*, int32_t&, unsigned char);
    CExoLocString ReadFieldCExoLocString(CResStruct*, char*, int32_t&, const CExoLocString&);
    CExoString ReadFieldCExoString(CResStruct*, char*, int32_t&, const CExoString&);
    char ReadFieldCHAR(CResStruct*, char*, int32_t&, char);
    CResRef ReadFieldCResRef(CResStruct*, char*, int32_t&, const CResRef&);
    double ReadFieldDOUBLE(CResStruct*, char*, int32_t&, double);
    uint32_t ReadFieldDWORD(CResStruct*, char*, int32_t&, uint32_t);
    uint64_t ReadFieldDWORD64(CResStruct*, char*, int32_t&, uint64_t);
    float ReadFieldFLOAT(CResStruct*, char*, int32_t&, float);
    int32_t ReadFieldINT(CResStruct*, char*, int32_t&, int32_t);
    int64_t ReadFieldINT64(CResStruct*, char*, int32_t&, int64_t);
    int16_t ReadFieldSHORT(CResStruct*, char*, int32_t&, int16_t);
    void* ReadFieldVOID(CResStruct*, void*, uint32_t, char*, int32_t&, void*);
    uint16_t ReadFieldWORD(CResStruct*, char*, int32_t&, uint16_t);
    void ReleaseResource();
    int32_t ValidateAndSetup();
    int32_t WriteFieldBYTE(CResStruct*, unsigned char, char*);
    int32_t WriteFieldCExoLocString(CResStruct*, CExoLocString, char*);
    int32_t WriteFieldCExoString(CResStruct*, const CExoString&, char*);
    int32_t WriteFieldCHAR(CResStruct*, char, char*);
    int32_t WriteFieldCResRef(CResStruct*, const CResRef&, char*);
    int32_t WriteFieldDOUBLE(CResStruct*, double, char*);
    int32_t WriteFieldDWORD(CResStruct*, uint32_t, char*);
    int32_t WriteFieldDWORD64(CResStruct*, uint64_t, char*);
    int32_t WriteFieldFLOAT(CResStruct*, float, char*);
    int32_t WriteFieldINT(CResStruct*, int32_t, char*);
    int32_t WriteFieldINT64(CResStruct*, int64_t, char*);
    int32_t WriteFieldSHORT(CResStruct*, int16_t, char*);
    int32_t WriteFieldVOID(CResStruct*, const void*, uint32_t, char*);
    int32_t WriteFieldWORD(CResStruct*, uint16_t, char*);
    int32_t WriteGFFData(CExoFile&, uint32_t&);
    int32_t WriteGFFFile(char*);
    int32_t WriteGFFFile(const CExoString&, uint16_t);
    int32_t WriteGFFToPointer(void**, int32_t&);
};

void CResGFF__CResGFFCtor__0(CResGFF* thisPtr);
void CResGFF__CResGFFCtor__2(CResGFF* thisPtr, uint16_t, char*, const CResRef&);
void CResGFF__CResGFFDtor__0(CResGFF* thisPtr);
unsigned char* CResGFF__AddDataField(CResGFF* thisPtr, uint32_t, uint32_t, uint32_t);
unsigned char* CResGFF__AddDataLayoutField(CResGFF* thisPtr, uint32_t, uint32_t, uint32_t);
unsigned char* CResGFF__AddDataLayoutList(CResGFF* thisPtr, uint32_t, uint32_t, uint32_t);
CResGFFField* CResGFF__AddField(CResGFF* thisPtr, CResStruct*, char*, uint32_t);
uint32_t CResGFF__AddLabel(CResGFF* thisPtr, char*);
int32_t CResGFF__AddList(CResGFF* thisPtr, CResList*, CResStruct*, char*);
int32_t CResGFF__AddListElement(CResGFF* thisPtr, CResStruct*, CResList*, uint32_t);
uint32_t CResGFF__AddStruct(CResGFF* thisPtr, uint32_t);
int32_t CResGFF__AddStructToStruct(CResGFF* thisPtr, CResStruct*, CResStruct*, char*, uint32_t);
int32_t CResGFF__CreateGFFFile(CResGFF* thisPtr, CResStruct*, const CExoString&, const CExoString&);
int32_t CResGFF__FinalizeSetup(CResGFF* thisPtr);
unsigned char* CResGFF__GetDataField(CResGFF* thisPtr, CResGFFField*, uint32_t&);
int32_t CResGFF__GetDataFromFile(CResGFF* thisPtr, char*);
int32_t CResGFF__GetDataFromPointer(CResGFF* thisPtr, void*, int32_t);
unsigned char* CResGFF__GetDataLayoutField(CResGFF* thisPtr, CResGFFField*, uint32_t&);
unsigned char* CResGFF__GetDataLayoutList(CResGFF* thisPtr, CResGFFField*, uint32_t&);
uint32_t CResGFF__GetElementType(CResGFF* thisPtr, CResStruct*);
void CResGFF__GetField(CResGFF* thisPtr, CResStruct*, uint32_t);
uint32_t CResGFF__GetFieldByLabel(CResGFF* thisPtr, CResStruct*, char*);
uint32_t CResGFF__GetFieldCount__0(CResGFF* thisPtr, CResStruct*);
uint32_t CResGFF__GetFieldCount__1(CResGFF* thisPtr, CResGFFStruct*);
char* CResGFF__GetFieldLabel(CResGFF* thisPtr, CResStruct*, uint32_t);
uint32_t CResGFF__GetFieldSize(CResGFF* thisPtr, CResStruct*, char*, uint32_t);
char* CResGFF__GetFieldStringID(CResGFF* thisPtr, CResStruct*, uint32_t);
uint32_t CResGFF__GetFieldType(CResGFF* thisPtr, CResStruct*, char*, uint32_t);
void CResGFF__GetGFFFileInfo(CResGFF* thisPtr, CExoString*, CExoString*);
CResGFFLabel* CResGFF__GetLabel(CResGFF* thisPtr, CResStruct*, uint32_t);
int32_t CResGFF__GetList(CResGFF* thisPtr, CResList*, CResStruct*, char*);
uint32_t CResGFF__GetListCount(CResGFF* thisPtr, CResList*);
int32_t CResGFF__GetListElement(CResGFF* thisPtr, CResStruct*, CResList*, uint32_t);
CResGFFStruct* CResGFF__GetStruct(CResGFF* thisPtr, CResStruct*);
int32_t CResGFF__GetStructFromStruct(CResGFF* thisPtr, CResStruct*, CResStruct*, char*);
int32_t CResGFF__GetTopLevelStruct(CResGFF* thisPtr, CResStruct*);
uint32_t CResGFF__GetTotalSize(CResGFF* thisPtr);
void CResGFF__InitializeForWriting(CResGFF* thisPtr);
int32_t CResGFF__IsDataInPlace(CResGFF* thisPtr, uint32_t);
int32_t CResGFF__OnResourceFreed(CResGFF* thisPtr);
int32_t CResGFF__OnResourceServiced(CResGFF* thisPtr);
void CResGFF__Pack(CResGFF* thisPtr, unsigned char, uint32_t);
int32_t CResGFF__PrepareHeader(CResGFF* thisPtr);
unsigned char CResGFF__ReadFieldBYTE(CResGFF* thisPtr, CResStruct*, char*, int32_t&, unsigned char);
CExoLocString CResGFF__ReadFieldCExoLocString(CResGFF* thisPtr, CResStruct*, char*, int32_t&, const CExoLocString&);
CExoString CResGFF__ReadFieldCExoString(CResGFF* thisPtr, CResStruct*, char*, int32_t&, const CExoString&);
char CResGFF__ReadFieldCHAR(CResGFF* thisPtr, CResStruct*, char*, int32_t&, char);
CResRef CResGFF__ReadFieldCResRef(CResGFF* thisPtr, CResStruct*, char*, int32_t&, const CResRef&);
double CResGFF__ReadFieldDOUBLE(CResGFF* thisPtr, CResStruct*, char*, int32_t&, double);
uint32_t CResGFF__ReadFieldDWORD(CResGFF* thisPtr, CResStruct*, char*, int32_t&, uint32_t);
uint64_t CResGFF__ReadFieldDWORD64(CResGFF* thisPtr, CResStruct*, char*, int32_t&, uint64_t);
float CResGFF__ReadFieldFLOAT(CResGFF* thisPtr, CResStruct*, char*, int32_t&, float);
int32_t CResGFF__ReadFieldINT(CResGFF* thisPtr, CResStruct*, char*, int32_t&, int32_t);
int64_t CResGFF__ReadFieldINT64(CResGFF* thisPtr, CResStruct*, char*, int32_t&, int64_t);
int16_t CResGFF__ReadFieldSHORT(CResGFF* thisPtr, CResStruct*, char*, int32_t&, int16_t);
void* CResGFF__ReadFieldVOID(CResGFF* thisPtr, CResStruct*, void*, uint32_t, char*, int32_t&, void*);
uint16_t CResGFF__ReadFieldWORD(CResGFF* thisPtr, CResStruct*, char*, int32_t&, uint16_t);
void CResGFF__ReleaseResource(CResGFF* thisPtr);
int32_t CResGFF__ValidateAndSetup(CResGFF* thisPtr);
int32_t CResGFF__WriteFieldBYTE(CResGFF* thisPtr, CResStruct*, unsigned char, char*);
int32_t CResGFF__WriteFieldCExoLocString(CResGFF* thisPtr, CResStruct*, CExoLocString, char*);
int32_t CResGFF__WriteFieldCExoString(CResGFF* thisPtr, CResStruct*, const CExoString&, char*);
int32_t CResGFF__WriteFieldCHAR(CResGFF* thisPtr, CResStruct*, char, char*);
int32_t CResGFF__WriteFieldCResRef(CResGFF* thisPtr, CResStruct*, const CResRef&, char*);
int32_t CResGFF__WriteFieldDOUBLE(CResGFF* thisPtr, CResStruct*, double, char*);
int32_t CResGFF__WriteFieldDWORD(CResGFF* thisPtr, CResStruct*, uint32_t, char*);
int32_t CResGFF__WriteFieldDWORD64(CResGFF* thisPtr, CResStruct*, uint64_t, char*);
int32_t CResGFF__WriteFieldFLOAT(CResGFF* thisPtr, CResStruct*, float, char*);
int32_t CResGFF__WriteFieldINT(CResGFF* thisPtr, CResStruct*, int32_t, char*);
int32_t CResGFF__WriteFieldINT64(CResGFF* thisPtr, CResStruct*, int64_t, char*);
int32_t CResGFF__WriteFieldSHORT(CResGFF* thisPtr, CResStruct*, int16_t, char*);
int32_t CResGFF__WriteFieldVOID(CResGFF* thisPtr, CResStruct*, const void*, uint32_t, char*);
int32_t CResGFF__WriteFieldWORD(CResGFF* thisPtr, CResStruct*, uint16_t, char*);
int32_t CResGFF__WriteGFFData(CResGFF* thisPtr, CExoFile&, uint32_t&);
int32_t CResGFF__WriteGFFFile__0(CResGFF* thisPtr, char*);
int32_t CResGFF__WriteGFFFile__1(CResGFF* thisPtr, const CExoString&, uint16_t);
int32_t CResGFF__WriteGFFToPointer(CResGFF* thisPtr, void**, int32_t&);

}

}
