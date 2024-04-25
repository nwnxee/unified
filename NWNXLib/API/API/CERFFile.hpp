#pragma once
#include "nwn_api.hpp"

#include "CERFKey.hpp"
#include "CERFRes.hpp"
#include "CERFString.hpp"
#include "CExoLinkedList.hpp"
#include "NWERFHEADER.hpp"
#include <memory>

#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CERFFile)
#endif

struct CExoFile;
struct CExoString;
struct CRes;


typedef int BOOL;
typedef uint16_t RESTYPE;


struct CERFFile
{
    NWERFHEADER m_stHeader;
    CExoLinkedList<CERFString> m_lstStringList;
    CExoLinkedList<CERFKey> m_lstKeyList;
    CExoLinkedList<CERFRes> m_lstResList;
    CExoFile * m_pOutFile;
    uint32_t m_nStringOffset;
    uint32_t m_nKeyOffset;
    uint32_t m_nResOffset;
    uint32_t m_nEntries;
    uint32_t m_nCurEntries;

    CERFFile();
    ~CERFFile();
    void SetVersion(const char * sVersion);
    BOOL AddResource(const CExoString & sResourceName);
    BOOL AddResource(const char * szResName, RESTYPE rtResType, CRes * pRes);
    BOOL RemoveResource(const CExoString & sResourceName, uint16_t a_wResourceType);
    BOOL RemoveResource(CERFRes * pData);
    BOOL AddString(CERFString * pString);
    BOOL Read();
    BOOL Reset();
    BOOL Write(const CExoString & sFilename);
    void RecalculateOffsets();
    BOOL Create(const CExoString & sOutFile);
    BOOL WriteHeader();
    BOOL WriteStringTable();
    BOOL SetNumEntries(uint32_t nEntries);
    BOOL WriteResource(const char * szResName, RESTYPE rtResType, CRes * pRes, BOOL bIsGFF = true);
    BOOL WriteResource(const char * szResName, RESTYPE rtResType, DataViewRef pData);
    BOOL Finish();


#ifdef NWN_CLASS_EXTENSION_CERFFile
    NWN_CLASS_EXTENSION_CERFFile
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CERFFile)
#endif

