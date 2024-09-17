#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"
#include "CRes2DA.hpp"
#include "CResHelper.hpp"
#include "CResRef.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(C2DA)
#endif



typedef int BOOL;


struct C2DA : CResHelper<CRes2DA, 2017>
{
    CExoString m_sDefaultValue;
    CExoString * m_pRowLabel;
    CExoString * m_pColumnLabel;
    CExoString * * m_pArrayData;
    int32_t m_nNumRows;
    int32_t m_nNumColumns;
    BOOL m_bLoaded;

    C2DA(CResRef cResRef, BOOL bSetAutoRequest);
    C2DA();
    ~C2DA();
    BOOL GetCExoStringEntry(int32_t nRow, int32_t nColumn, CExoString * pString);
    BOOL GetCExoStringEntry(const CExoString & sRowLabel, const CExoString & sColumnLabel, CExoString * pString);
    BOOL GetCExoStringEntry(int32_t nRow, const CExoString & sColumnLabel, CExoString * pString);
    BOOL GetCExoStringEntry(const CExoString & sRowLabel, int32_t nColumn, CExoString * pString);
    BOOL SetCExoStringEntry(int32_t nRow, int32_t nColumn, CExoString sString);
    BOOL SetCExoStringEntry(CExoString sRowLabel, CExoString sColumnLabel, CExoString sString);
    BOOL SetCExoStringEntry(int32_t nRow, CExoString sColumnLabel, CExoString sString);
    BOOL SetCExoStringEntry(CExoString sRowLabel, int32_t nColumn, CExoString sString);
    BOOL GetFLOATEntry(int32_t nRow, int32_t nColumn, float * pFloat);
    BOOL GetFLOATEntry(const CExoString & sRowLabel, const CExoString & sColumnLabel, float * pFloat);
    BOOL GetFLOATEntry(int32_t nRow, const CExoString & sColumnLabel, float * pFloat);
    BOOL GetFLOATEntry(const CExoString & sRowLabel, int32_t nColumn, float * pFloat);
    BOOL SetFLOATEntry(int32_t nRow, int32_t nColumn, float fFloat);
    BOOL SetFLOATEntry(CExoString sRowLabel, CExoString sColumnLabel, float fFloat);
    BOOL SetFLOATEntry(int32_t nRow, CExoString sColumnLabel, float fFloat);
    BOOL SetFLOATEntry(CExoString sRowLabel, int32_t nColumn, float fFloat);
    BOOL GetINTEntry(int32_t nRow, int32_t nColumn, int32_t * pInt);
    BOOL GetINTEntry(const CExoString & sRowLabel, const CExoString & sColumnLabel, int32_t * pInt);
    BOOL GetINTEntry(int32_t nRow, const CExoString & sColumnLabel, int32_t * pInt);
    BOOL GetINTEntry(const CExoString & sRowLabel, int32_t nColumn, int32_t * pInt);
    BOOL SetINTEntry(int32_t nRow, int32_t nColumn, int32_t nInt);
    BOOL SetINTEntry(CExoString sRowLabel, CExoString sColumnLabel, int32_t nInt);
    BOOL SetINTEntry(int32_t nRow, CExoString sColumnLabel, int32_t nInt);
    BOOL SetINTEntry(CExoString sRowLabel, int32_t nColumn, int32_t nInt);
    BOOL SetBlankEntry(int32_t nRow, int32_t nColumn);
    BOOL SetBlankEntry(CExoString sRowLabel, CExoString sColumnLabel);
    BOOL SetBlankEntry(int32_t nRow, CExoString sColumnLabel);
    BOOL SetBlankEntry(CExoString sRowLabel, int32_t nColumn);
    BOOL Load2DArray(BOOL optional = false);
    void Unload2DArray();
    int32_t GetColumnIndex(const CExoString & sColumn);
    uint32_t GetNextLineLength(char * pBuffer, uint32_t nBufferSize);
    BOOL GetNextToken(char * * pBuffer, uint32_t * pBufferSize, char * pToken, uint32_t nMaxTokenSize, uint32_t * pLeadingWhiteSpaceSize);
    int32_t GetRowIndex(const CExoString & sRow);
    BOOL SkipNewLines(char * * pBuffer, uint32_t * pBufferSize);


#ifdef NWN_CLASS_EXTENSION_C2DA
    NWN_CLASS_EXTENSION_C2DA
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(C2DA)
#endif

