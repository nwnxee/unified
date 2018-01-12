#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

// Forward class declarations (defined in the source file)
struct SETSection;

struct CResSET
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nSETNormalSize;
    SETSection* m_pSection;
    uint32_t m_nNumSections;
    char* m_sNullTerminated;

    // The below are auto generated stubs.
    CResSET(const CResSET&) = default;
    CResSET& operator=(const CResSET&) = default;

    CResSET();
    ~CResSET();
    int32_t CopySETData(unsigned char*);
    int32_t CreateSectionTable();
    char* GetNextLine(uint32_t, uint32_t*);
    void GetSectionEntryValue(char*, char*, char*);
    char* GetSETDataPtr();
    uint32_t GetSETSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
    char* SkipWhiteSpace(char*);
};

void CResSET__CResSETCtor__0(CResSET* thisPtr);
void CResSET__CResSETDtor__0(CResSET* thisPtr);
int32_t CResSET__CopySETData(CResSET* thisPtr, unsigned char*);
int32_t CResSET__CreateSectionTable(CResSET* thisPtr);
char* CResSET__GetNextLine(CResSET* thisPtr, uint32_t, uint32_t*);
void CResSET__GetSectionEntryValue(CResSET* thisPtr, char*, char*, char*);
char* CResSET__GetSETDataPtr(CResSET* thisPtr);
uint32_t CResSET__GetSETSize(CResSET* thisPtr);
int32_t CResSET__IsLoaded(CResSET* thisPtr);
int32_t CResSET__OnResourceFreed(CResSET* thisPtr);
int32_t CResSET__OnResourceServiced(CResSET* thisPtr);
char* CResSET__SkipWhiteSpace(CResSET* thisPtr, char*);

}

}
