#pragma once

#include <cstdint>

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct CExoCriticalSectionInternal;

struct CExoCriticalSection
{
    CExoCriticalSectionInternal* m_pcExoCriticalSectionInternal;

    // The below are auto generated stubs.
    CExoCriticalSection(const CExoCriticalSection&) = default;
    CExoCriticalSection& operator=(const CExoCriticalSection&) = default;

    CExoCriticalSection();
    ~CExoCriticalSection();
    void EnterCriticalSection();
    void LeaveCriticalSection();
};

void CExoCriticalSection__CExoCriticalSectionCtor__0(CExoCriticalSection* thisPtr);
void CExoCriticalSection__CExoCriticalSectionDtor__0(CExoCriticalSection* thisPtr);
void CExoCriticalSection__EnterCriticalSection(CExoCriticalSection* thisPtr);
void CExoCriticalSection__LeaveCriticalSection(CExoCriticalSection* thisPtr);

}

}
