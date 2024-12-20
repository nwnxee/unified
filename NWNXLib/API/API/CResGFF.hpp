#pragma once
#include "nwn_api.hpp"

#include "CExoLocString.hpp"
#include "CExoString.hpp"
#include "CRes.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResGFF)
#endif

struct CExoFile;
struct CResGFFField;
struct CResGFFFileHeader;
struct CResGFFLabel;
struct CResGFFStruct;
struct CResList;
struct CResStruct;


typedef int BOOL;
typedef uint16_t RESTYPE;


struct CResGFF : CRes
{
    uint32_t STRUCT_GROWSIZE;
    uint32_t FIELD_GROWSIZE;
    uint32_t LABEL_GROWSIZE;
    uint32_t DATAFIELD_GROWSIZE;
    uint32_t DATALAYOUTFIELD_GROWSIZE;
    uint32_t DATALAYOUTLIST_GROWSIZE;
    CResGFFFileHeader * m_pFileHeader;
    uint32_t m_nHeaderOffset;
    CResGFFStruct * m_pStruct;
    uint32_t m_nStructAllocated;
    CResGFFField * m_pField;
    uint32_t m_nFieldAllocated;
    CResGFFLabel * m_pLabel;
    uint32_t m_nLabelAllocated;
    uint8_t * m_pDataField;
    uint32_t m_nDataFieldAllocated;
    uint8_t * m_pDataLayoutField;
    uint32_t m_nDataLayoutFieldAllocated;
    uint32_t m_nDataLayoutFieldWasted;
    uint8_t * m_pDataLayoutList;
    uint32_t m_nDataLayoutListAllocated;
    uint32_t m_nDataLayoutListWasted;
    char m_pLabelBuffer[17];
    char m_pFileType[4];
    BOOL m_bLoaded;
    BOOL m_bResourceLoaded;
    BOOL m_bSelfDemanded;
    BOOL m_bDataPtrOwned;
    BOOL m_bValidationFailed;

    CResGFF();
    CResGFF(RESTYPE nType, const char * cIDStr, const CResRef & cResRef);
    virtual ~CResGFF();
    BOOL OnResourceServiced();
    BOOL OnResourceFreed();
    BOOL GetDataFromFile(const char * pFileName);
    BOOL GetDataFromPointer(void * pData, int32_t nDataSize, bool bTakeOwnership);
    void GetGFFFileInfo(CExoString * pFileType, CExoString * pVersion);
    uint32_t GetElementType(CResStruct * pStructure);
    uint32_t GetFieldCount(CResStruct * pStructure);
    uint32_t GetFieldType(CResStruct * pStructure, const char * szFieldID, uint32_t nFieldIndex = 0xffffffff);
    char * GetFieldStringID(CResStruct * pStructure, uint32_t nFieldIndex);
    uint32_t GetFieldSize(CResStruct * pStructure, const char * szFieldID, uint32_t nFieldIndex = 0xffffffff);
    BOOL GetList(CResList * pList, CResStruct * pStructure, const char * szFieldID);
    uint32_t GetListCount(CResList * pList);
    BOOL GetListElement(CResStruct * pStruct, CResList * pList, uint32_t nIndex);
    BOOL GetStructFromStruct(CResStruct * pStruct, CResStruct * pParentStruct, const char * szFieldID);
    BOOL GetTopLevelStruct(CResStruct * pStructure);
    uint8_t ReadFieldBYTE(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, uint8_t nDefault = 0);
    char ReadFieldCHAR(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, char nDefault = 0);
    uint16_t ReadFieldWORD(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, uint16_t nDefault = 0);
    int16_t ReadFieldSHORT(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, int16_t nDefault = 0);
    uint32_t ReadFieldDWORD(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, uint32_t nDefault = 0);
    int32_t ReadFieldINT(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, int32_t nDefault = 0);
    uint64_t ReadFieldDWORD64(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, uint64_t nDefault = 0);
    int64_t ReadFieldINT64(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, int64_t nDefault = 0);
    float ReadFieldFLOAT(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, float fDefault = 0.0f);
    double ReadFieldDOUBLE(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, double fDefault = 0.0);
    CResRef ReadFieldCResRef(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, const CResRef & sDefault = "");
    CExoString ReadFieldCExoString(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, const CExoString & sDefault = "");
    CExoLocString ReadFieldCExoLocString(CResStruct * pStructure, const char * szFieldID, BOOL & bSuccess, const CExoLocString & sDefault = CExoLocString());
    void * ReadFieldVOID(CResStruct * pStructure, void * pVariable, uint32_t nSize, const char * szFieldID, BOOL & bSuccess, void * pDefault = nullptr);
    BOOL AddList(CResList * pList, CResStruct * pStructure, const char * szFieldID);
    BOOL AddListElement(CResStruct * pStruct, CResList * pList, uint32_t nType);
    BOOL AddStructToStruct(CResStruct * pNewStruct, CResStruct * pParentStruct, const char * szFieldID, uint32_t nType);
    BOOL CreateGFFFile(CResStruct * pStruct, const CExoString & sFileType, const CExoString & sVersion);
    BOOL WriteFieldBYTE(CResStruct * pStructure, uint8_t nVariable, const char * szFieldID);
    BOOL WriteFieldCHAR(CResStruct * pStructure, char nVariable, const char * szFieldID);
    BOOL WriteFieldWORD(CResStruct * pStructure, uint16_t nVariable, const char * szFieldID);
    BOOL WriteFieldSHORT(CResStruct * pStructure, int16_t nVariable, const char * szFieldID);
    BOOL WriteFieldDWORD(CResStruct * pStructure, uint32_t nVariable, const char * szFieldID);
    BOOL WriteFieldINT(CResStruct * pStructure, int32_t nVariable, const char * szFieldID);
    BOOL WriteFieldDWORD64(CResStruct * pStructure, uint64_t nVariable, const char * szFieldID);
    BOOL WriteFieldINT64(CResStruct * pStructure, int64_t nVariable, const char * szFieldID);
    BOOL WriteFieldFLOAT(CResStruct * pStructure, float fVariable, const char * szFieldID);
    BOOL WriteFieldDOUBLE(CResStruct * pStructure, double fVariable, const char * szFieldID);
    BOOL WriteFieldCResRef(CResStruct * pStructure, const CResRef & sVariable, const char * szFieldID);
    BOOL WriteFieldCExoString(CResStruct * pStructure, const CExoString & sVariable, const char * szFieldID);
    BOOL WriteFieldCExoLocString(CResStruct * pStructure, CExoLocString sVariable, const char * szFieldID);
    BOOL WriteFieldVOID(CResStruct * pStructure, const void * pVariable, uint32_t nSize, const char * szFieldID);
    BOOL WriteGFFFile(const CExoString & sFileName, RESTYPE nType);
    BOOL WriteGFFFile(char * szFileName);
    BOOL WriteGFFData(CExoFile & cFile, uint32_t & nBytesWritten);
    BOOL WriteGFFToPointer(void * * pData, int32_t & nLength);
    void Pack(uint8_t nPercentThreshold = 0, uint32_t nByteThreshold = 0);
    uint32_t GetTotalSize();
    void InitializeForWriting();
    BOOL PrepareHeader();
    BOOL FinalizeSetup();
    BOOL ValidateAndSetup();
    void ReleaseResource();
    CResGFFStruct * GetStruct(CResStruct * pStructure);
    CResGFFField * GetField(CResStruct * pStructure, uint32_t nFieldIndex);
    CResGFFLabel * GetLabel(CResStruct * pStructure, uint32_t nFieldIndex);
    uint8_t * GetDataField(CResGFFField * pField, uint32_t & nMaxSize);
    uint8_t * GetDataLayoutField(CResGFFField * pField, uint32_t & nMaxSize);
    uint8_t * GetDataLayoutList(CResGFFField * pField, uint32_t & nMaxSize);
    uint32_t GetFieldByLabel(CResStruct * pStructure, const char * szFieldID);
    BOOL IsDataInPlace(uint32_t nType);
    char * GetFieldLabel(CResStruct * pStructure, uint32_t nFieldIndex);
    uint32_t GetFieldCount(CResGFFStruct * pStruct);
    uint32_t AddStruct(uint32_t nType);
    CResGFFField * AddField(CResStruct * pStructure, const char * szFieldID, uint32_t nType);
    uint32_t AddLabel(const char * szFieldID);
    uint8_t * AddDataField(uint32_t nCurrentOffset, uint32_t nCurrentSize, uint32_t nNewSize);
    uint8_t * AddDataLayoutField(uint32_t nCurrentOffset, uint32_t nCurrentSize, uint32_t nNewSize);
    uint8_t * AddDataLayoutList(uint32_t nCurrentOffset, uint32_t nCurrentSize, uint32_t nNewSize);


#ifdef NWN_CLASS_EXTENSION_CResGFF
    NWN_CLASS_EXTENSION_CResGFF
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResGFF)
#endif

