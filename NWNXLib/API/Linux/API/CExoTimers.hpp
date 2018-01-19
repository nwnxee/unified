#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoTimersInternal;

struct CExoTimers
{
    CExoTimersInternal* m_pcExoTimersInternal;

    // The below are auto generated stubs.
    CExoTimers(const CExoTimers&) = default;
    CExoTimers& operator=(const CExoTimers&) = default;

    CExoTimers();
    ~CExoTimers();
    uint64_t GetHighResolutionTimer();
    uint32_t GetLowResolutionTimer();
};

void CExoTimers__CExoTimersCtor(CExoTimers* thisPtr);
void CExoTimers__CExoTimersDtor(CExoTimers* thisPtr);
uint64_t CExoTimers__GetHighResolutionTimer(CExoTimers* thisPtr);
uint32_t CExoTimers__GetLowResolutionTimer(CExoTimers* thisPtr);

}

}
