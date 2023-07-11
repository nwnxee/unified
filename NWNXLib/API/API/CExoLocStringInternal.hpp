#pragma once
#include "nwn_api.hpp"

#include "CExoLinkedList.hpp"
#include "CExoString.hpp"
#include "EXOLOCSTRING.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoLocStringInternal)
#endif

class CExoLocString;


typedef int BOOL;


class CExoLocStringInternal
{
    CExoLinkedList<EXOLOCSTRING> m_lstString;
    uint32_t m_nStringCount;

    CExoLocStringInternal();
    ~CExoLocStringInternal();
    BOOL AddString(int32_t nID, CExoString sString);
    BOOL Assign(CExoLocStringInternal * pLocStringInternal);
    void ClearLocString();
    int32_t Compare(CExoLocString & LocString);
    BOOL GetString(uint32_t nPos, int32_t * pID, CExoString * pString);
    BOOL GetString(int32_t nID, CExoString * pString);
    uint32_t GetStringCount();
    int32_t GetStringLength(uint32_t nPos);
    void RemoveString(int32_t nID);


#ifdef NWN_CLASS_EXTENSION_CExoLocStringInternal
    NWN_CLASS_EXTENSION_CExoLocStringInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoLocStringInternal)
#endif

