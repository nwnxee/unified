#pragma once

#include <cstdint>

#include "pthread_mutex_t.hpp"

namespace NWNXLib {

namespace API {

struct CExoCriticalSectionInternal
{
    pthread_mutex_t m_critSection;

    // The below are auto generated stubs.
    CExoCriticalSectionInternal(const CExoCriticalSectionInternal&) = default;
    CExoCriticalSectionInternal& operator=(const CExoCriticalSectionInternal&) = default;

    CExoCriticalSectionInternal();
    ~CExoCriticalSectionInternal();
    void EnterCriticalSection();
    void LeaveCriticalSection();
};

void CExoCriticalSectionInternal__CExoCriticalSectionInternalCtor__0(CExoCriticalSectionInternal* thisPtr);
void CExoCriticalSectionInternal__CExoCriticalSectionInternalDtor__0(CExoCriticalSectionInternal* thisPtr);
void CExoCriticalSectionInternal__EnterCriticalSection(CExoCriticalSectionInternal* thisPtr);
void CExoCriticalSectionInternal__LeaveCriticalSection(CExoCriticalSectionInternal* thisPtr);

}

}
