#pragma once
#include "nwn_api.hpp"

#include "CExoString.hpp"


#ifdef NWN_API_PROLOGUE
NWN_API_PROLOGUE(CExoRandInternal)
#endif



typedef int BOOL;


class CExoRandInternal
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
    BOOL m_bSeeded;
    uint8_t * m_pBuffer;
    uint16_t m_pBufIndex;
    uint64_t m_nEvent1;
    uint64_t m_nEvent2;
    uint64_t m_nEvent3;
    uint64_t m_nEvent4;
    uint32_t m_nEvent5;

    CExoRandInternal();
    ~CExoRandInternal();
    uint32_t Rand();
    CExoString GetString(uint16_t nLength);
    void SignalEvent();
    void SignalEvent(uint32_t nTimeStamp);
    void ReSeed(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
    void GenSeed();
    void Add(uint8_t * pBuf, int32_t nSize);


#ifdef NWN_CLASS_EXTENSION_CExoRandInternal
    NWN_CLASS_EXTENSION_CExoRandInternal
#endif
};


#ifdef NWN_API_EPILOGUE
NWN_API_EPILOGUE(CExoRandInternal)
#endif

