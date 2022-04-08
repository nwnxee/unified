#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLocString)
#endif

struct CExoLocStringInternal;


typedef int BOOL;
typedef uint32_t STRREF;


struct CExoLocString
{
    CExoLocStringInternal * m_pExoLocStringInternal;
    STRREF m_dwStringRef;

    CExoLocString();
    CExoLocString(const CExoLocString & cLocString);
    ~CExoLocString();
    CExoLocString(STRREF simple);
    CExoLocString(const CExoString & simple, int32_t lang = - 1);
    int32_t operator==(CExoLocString & LocString);
    int32_t operator!=(CExoLocString & LocString);
    CExoLocString & operator=(const CExoLocString & CExoLocString);
    BOOL AddString(int32_t nID, CExoString sString, uint8_t bGender = 0x00);
    void ClearLocString();
    BOOL GetString(uint32_t nPos, int32_t * pID, CExoString * pString, uint8_t * pGender) const;
    BOOL GetString(int32_t nID, CExoString * pString, uint8_t bGender = 0x00, bool boSearch = true) const;
    BOOL GetStringLoc(int32_t nID, CExoString * pString, uint8_t bGender) const;
    uint32_t GetStringCount() const;
    int32_t GetStringLength(uint32_t nPos) const;
    BOOL GetStringInternal(int32_t nID, CExoString * pString) const;
    void RemoveString(int32_t nID);
    void RemoveString(int32_t nID, uint8_t bGender);
    CExoString GetSimple(uint8_t nGender = 0x0) const;


#ifdef NWN_CLASS_EXTENSION_CExoLocString
    NWN_CLASS_EXTENSION_CExoLocString
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLocString)
#endif

