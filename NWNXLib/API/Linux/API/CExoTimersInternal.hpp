#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

struct CExoTimersInternal
{
    int32_t m_bQPCActive;
    int32_t m_bQPCAlgorithm2;
    uint64_t m_nQPFrequency;
    uint64_t m_nQPCMicroSecFrequency;
    double m_fQPCMicroSecFrequency;

    // The below are auto generated stubs.
    CExoTimersInternal(const CExoTimersInternal&) = default;
    CExoTimersInternal& operator=(const CExoTimersInternal&) = default;

    CExoTimersInternal();
    ~CExoTimersInternal();
    uint64_t GetHighResolutionTimer();
    uint32_t GetLowResolutionTimer();
};

void CExoTimersInternal__CExoTimersInternalCtor(CExoTimersInternal* thisPtr);
void CExoTimersInternal__CExoTimersInternalDtor(CExoTimersInternal* thisPtr);
uint64_t CExoTimersInternal__GetHighResolutionTimer(CExoTimersInternal* thisPtr);
uint32_t CExoTimersInternal__GetLowResolutionTimer(CExoTimersInternal* thisPtr);

}

}
