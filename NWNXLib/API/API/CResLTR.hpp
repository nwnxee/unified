#pragma once
#include "nwn_api.hpp"

#include "CRes.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CResLTR)
#endif

class EXOLTRHEADER;


typedef int BOOL;


class CResLTR : public CRes
{
public:
    float * * * m_pStartTripleLetterProb;
    float * * * m_pMiddleTripleLetterProb;
    float * * * m_pEndTripleLetterProb;
    float * * m_pStartDoubleLetterProb;
    float * * m_pMiddleDoubleLetterProb;
    float * * m_pEndDoubleLetterProb;
    float * m_pStartSingleLetterProb;
    float * m_pMiddleSingleLetterProb;
    float * m_pEndSingleLetterProb;
    EXOLTRHEADER * m_pLTRHeader;
    uint8_t * m_pLTRData;
    uint32_t m_nLTRNormalSize;
    BOOL m_bLoaded;

    CResLTR();
    ~CResLTR();
    BOOL OnResourceFreed();
    BOOL OnResourceServiced();


#ifdef NWN_CLASS_EXTENSION_CResLTR
    NWN_CLASS_EXTENSION_CResLTR
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CResLTR)
#endif

