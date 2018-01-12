#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExoLTRHeader_st;

struct CResLTR
    : CRes
{
    float*** m_pStartTripleLetterProb;
    float*** m_pMiddleTripleLetterProb;
    float*** m_pEndTripleLetterProb;
    float** m_pStartDoubleLetterProb;
    float** m_pMiddleDoubleLetterProb;
    float** m_pEndDoubleLetterProb;
    float* m_pStartSingleLetterProb;
    float* m_pMiddleSingleLetterProb;
    float* m_pEndSingleLetterProb;
    ExoLTRHeader_st* m_pLTRHeader;
    uint8_t* m_pLTRData;
    uint32_t m_nLTRNormalSize;
    int32_t m_bLoaded;

    // The below are auto generated stubs.
    CResLTR(const CResLTR&) = default;
    CResLTR& operator=(const CResLTR&) = default;

    CResLTR();
    ~CResLTR();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResLTR__CResLTRCtor__0(CResLTR* thisPtr);
void CResLTR__CResLTRDtor__0(CResLTR* thisPtr);
int32_t CResLTR__OnResourceFreed(CResLTR* thisPtr);
int32_t CResLTR__OnResourceServiced(CResLTR* thisPtr);

}

}
