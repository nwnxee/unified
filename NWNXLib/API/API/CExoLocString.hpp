#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLocString)
#endif

struct CExoLocStringInternal;


typedef uint32_t STRREF;
typedef int BOOL;


struct CExoLocString
{
    CExoLocStringInternal * m_pExoLocStringInternal;
    STRREF m_dwStringRef;

    CExoLocString();
    CExoLocString(const CExoLocString & cLocString);
    ~CExoLocString();
    int32_t operator==(CExoLocString & LocString);
    int32_t operator!=(CExoLocString & LocString);
    CExoLocString & operator=(const CExoLocString & CExoLocString);
    BOOL AddString(int32_t nID, CExoString sString, uint8_t bGender = 0x00);
    void ClearLocString();
    BOOL GetString(uint32_t nPos, int32_t * pID, CExoString * pString, uint8_t * pGender);
    BOOL GetString(int32_t nID, CExoString * pString, uint8_t bGender = 0x00, bool boSearch = true);
    BOOL GetStringLoc(int32_t nID, CExoString * pString, uint8_t bGender);
    uint32_t GetStringCount();
    int32_t GetStringLength(uint32_t nPos);
    BOOL GetStringInternal(int32_t nID, CExoString * pString);
    void RemoveString(int32_t nID);
    void RemoveString(int32_t nID, uint8_t bGender);


#ifdef NWN_CLASS_EXTENSION_CExoLocString
    NWN_CLASS_EXTENSION_CExoLocString
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLocString)
#endif

