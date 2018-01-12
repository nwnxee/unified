#pragma once

#include <cstdint>

#include "CExoString.hpp"
#include "CRes.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct ExoTGAHeader_st;

struct CResTGA
    : CRes
{
    int32_t m_bDataAllocated;
    int32_t m_bColorMapped;
    int32_t m_bCompressed;
    int32_t m_bLoaded;
    uint32_t m_nTGANormalSize;
    uint32_t m_nTGACompressedSize;
    uint8_t* m_pTGAColorMap;
    uint8_t* m_pTGAData;
    ExoTGAHeader_st* m_pTGAHeader;

    // The below are auto generated stubs.
    CResTGA(const CResTGA&) = default;
    CResTGA& operator=(const CResTGA&) = default;

    CResTGA();
    ~CResTGA();
    int32_t CopyTGAData(unsigned char*);
    int32_t GetTGAAttrib(uint32_t*, uint32_t*, unsigned char*);
    unsigned char* GetTGAColorMapPtr();
    unsigned char* GetTGADataPtr();
    ExoTGAHeader_st* GetTGAHeaderPtr();
    uint32_t GetTGASize();
    int32_t IsColorMapped();
    int32_t IsCompressed();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
    int32_t ReadColorMappedRLETGA();
    int32_t ReadUnmappedRLETGA();
    int32_t Write(CExoString&);
};

void CResTGA__CResTGACtor__0(CResTGA* thisPtr);
void CResTGA__CResTGADtor__0(CResTGA* thisPtr);
int32_t CResTGA__CopyTGAData(CResTGA* thisPtr, unsigned char*);
int32_t CResTGA__GetTGAAttrib(CResTGA* thisPtr, uint32_t*, uint32_t*, unsigned char*);
unsigned char* CResTGA__GetTGAColorMapPtr(CResTGA* thisPtr);
unsigned char* CResTGA__GetTGADataPtr(CResTGA* thisPtr);
ExoTGAHeader_st* CResTGA__GetTGAHeaderPtr(CResTGA* thisPtr);
uint32_t CResTGA__GetTGASize(CResTGA* thisPtr);
int32_t CResTGA__IsColorMapped(CResTGA* thisPtr);
int32_t CResTGA__IsCompressed(CResTGA* thisPtr);
int32_t CResTGA__IsLoaded(CResTGA* thisPtr);
int32_t CResTGA__OnResourceFreed(CResTGA* thisPtr);
int32_t CResTGA__OnResourceServiced(CResTGA* thisPtr);
int32_t CResTGA__ReadColorMappedRLETGA(CResTGA* thisPtr);
int32_t CResTGA__ReadUnmappedRLETGA(CResTGA* thisPtr);
int32_t CResTGA__Write(CResTGA* thisPtr, CExoString&);

}

}
