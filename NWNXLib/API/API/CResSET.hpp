#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResSET)
#endif

class SETSection;


typedef int BOOL;


class CResSET : public CRes
{
public:
    BOOL m_bLoaded;
    uint32_t m_nSETNormalSize;
    SETSection * m_pSection;
    uint32_t m_nNumSections;
    char * m_sNullTerminated;

    CResSET();
    ~CResSET();
    BOOL CopySETData(uint8_t * pSETData);
    char * GetSETDataPtr();
    uint32_t GetSETSize();
    BOOL IsLoaded();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();
    void GetSectionEntryValue(char * szSection, char * szEntry, char * szValue);
    BOOL CreateSectionTable();
    char * GetNextLine(uint32_t nOffsetStart, uint32_t * pOffsetEnd);
    char * SkipWhiteSpace(char * pLine);


#ifdef NWN_CLASS_EXTENSION_CResSET
    NWN_CLASS_EXTENSION_CResSET
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResSET)
#endif

