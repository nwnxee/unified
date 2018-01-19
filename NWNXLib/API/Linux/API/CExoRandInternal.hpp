#pragma once

#include <cstdint>

#include "CExoString.hpp"

namespace NWNXLib {

namespace API {

struct CExoRandInternal
{
    uint32_t m_s1;
    uint32_t m_s2;
    uint32_t m_s3;
    uint32_t m_s4;
    uint32_t m_mask1;
    uint32_t m_mask2;
    uint32_t m_mask3;
    uint32_t m_mask4;
    int32_t m_shft1;
    int32_t m_shft2;
    int32_t m_shft3;
    int32_t m_shft4;
    int32_t m_k1;
    int32_t m_k2;
    int32_t m_k3;
    int32_t m_k4;
    int32_t m_q1;
    int32_t m_q2;
    int32_t m_q3;
    int32_t m_q4;
    int32_t m_p1;
    int32_t m_p2;
    int32_t m_p3;
    int32_t m_p4;
    int32_t m_bSeeded;
    uint8_t* m_pBuffer;
    uint16_t m_pBufIndex;
    uint64_t m_nEvent1;
    uint64_t m_nEvent2;
    uint64_t m_nEvent3;
    uint64_t m_nEvent4;
    uint32_t m_nEvent5;

    // The below are auto generated stubs.
    CExoRandInternal(const CExoRandInternal&) = default;
    CExoRandInternal& operator=(const CExoRandInternal&) = default;

    CExoRandInternal();
    ~CExoRandInternal();
    void Add(unsigned char*, int32_t);
    void GenSeed();
    CExoString GetString(uint16_t);
    uint32_t Rand();
    void ReSeed(uint32_t, uint32_t, uint32_t, uint32_t);
    void SignalEvent();
    void SignalEvent(uint32_t);
};

void CExoRandInternal__CExoRandInternalCtor(CExoRandInternal* thisPtr);
void CExoRandInternal__CExoRandInternalDtor(CExoRandInternal* thisPtr);
void CExoRandInternal__Add(CExoRandInternal* thisPtr, unsigned char*, int32_t);
void CExoRandInternal__GenSeed(CExoRandInternal* thisPtr);
CExoString CExoRandInternal__GetString(CExoRandInternal* thisPtr, uint16_t);
uint32_t CExoRandInternal__Rand(CExoRandInternal* thisPtr);
void CExoRandInternal__ReSeed(CExoRandInternal* thisPtr, uint32_t, uint32_t, uint32_t, uint32_t);
void CExoRandInternal__SignalEvent__0(CExoRandInternal* thisPtr);
void CExoRandInternal__SignalEvent__1(CExoRandInternal* thisPtr, uint32_t);

}

}
