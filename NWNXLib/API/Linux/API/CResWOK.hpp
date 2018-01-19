#pragma once

#include <cstdint>

#include "CRes.hpp"

namespace NWNXLib {

namespace API {

struct CResWOK
    : CRes
{
    int32_t m_bLoaded;
    uint32_t m_nWOKNormalSize;
    uint8_t* m_pWOKData;

    // The below are auto generated stubs.
    CResWOK(const CResWOK&) = default;
    CResWOK& operator=(const CResWOK&) = default;

    CResWOK();
    ~CResWOK();
    unsigned char* GetWOKDataPtr();
    uint32_t GetWOKSize();
    int32_t IsLoaded();
    int32_t OnResourceFreed();
    int32_t OnResourceServiced();
};

void CResWOK__CResWOKCtor(CResWOK* thisPtr);
void CResWOK__CResWOKDtor__0(CResWOK* thisPtr);
unsigned char* CResWOK__GetWOKDataPtr(CResWOK* thisPtr);
uint32_t CResWOK__GetWOKSize(CResWOK* thisPtr);
int32_t CResWOK__IsLoaded(CResWOK* thisPtr);
int32_t CResWOK__OnResourceFreed(CResWOK* thisPtr);
int32_t CResWOK__OnResourceServiced(CResWOK* thisPtr);

}

}
